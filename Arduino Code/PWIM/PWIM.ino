
//------- CLASSES ------- //

#include <PID_v1.h>           // Class Definition for the PID Algorithm
#include <LiquidCrystal.h>    // Class Definition for the 16x4 LCD
#include <Wire.h>             // Class Definition to communicate via I2C with the sensor
#include <Adafruit_INA219.h>  // Class Definition for the Sensor


// ---- ARDUINO GPIO PINS ---- //

const int joystick = A0;      // analog pin used to connect the JOYSTICK
const int pwm = 9;            //pin to drive mosfet which in return drives the solenoid  

// ---- VARIABLES ---- //
 
float dutycycle;                // variable to read the duty cycle from joystick         
float amps;                     // variable to store the current
double Setpoint, Input, Output; //setpoint, input and output parameters of the controller
double Kp=0, Ki=10, Kd=0;       //Specify initial tuning parameters
int avg = 0;

// ------ CREATING OBJECTS OF CLASSES ------//

Adafruit_INA219 ina219;             // Object of Class Adafruit_INA219
LiquidCrystal lcd(12,11,5,4,3,2);   // Object Of Class LiquidCrystal

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd,P_ON_E,DIRECT);   // Object of Class PID


// ---- SETUP FUCNCTION ---- //

void setup() {
  
  #ifndef ESP8266
    while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
  #endif
  
  ina219.begin();       // Initialize first board (default address 0x40)

  // Setting LCD Parameters
  lcd.begin(16,4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Duty:");
  lcd.setCursor(9,0);
  lcd.print("V:");
  lcd.setCursor(0,1);
  lcd.print("I1:");
  lcd.setCursor(7,1);
  lcd.print("I2:");
  lcd.setCursor(14,1);
  lcd.print("mA");
  lcd.setCursor(0,2);
  lcd.print("Power: ");
  lcd.setCursor(15,2);
  lcd.print("W");
  lcd.setCursor(0,3);
  lcd.print("Kp:");
  lcd.setCursor(3,3);
  lcd.print((int)Kp);
  lcd.setCursor(5,3);
  lcd.print("Ki:");
  lcd.setCursor(9,3);
  lcd.print((int)Ki);
  lcd.setCursor(12,3);
  lcd.print("Kd:");
  lcd.setCursor(15,3);
  lcd.print((int)Kd);

  // Setting PID Parameters
  myPID.SetOutputLimits(0, 255);    //  set PWM output limit
  myPID.SetMode(AUTOMATIC);         //  Set PID mode as Automatic

  // Setting Arduino Parameters
  pinMode(pwm, OUTPUT);                 //Set PIN 9 as Output
  setPwmFrequency(9,2); // setting frequency to 3Khz
 // TCCR1A = _BV(COM1A1) | _BV(COM1B1) ; // phase and frequency correct mode. NON-inverted mode
 // TCCR1B = _BV(WGM13) | _BV(CS11);
  
  // Setting Serial Communication Parameters.
  Serial.begin(115200);
}


// ---- LOOP FUCNCTION ---- //

void loop() {
  // Variables
  int pwmspan;
  int Setpoint_;
  long int total = 0, total1 = 0;

  // Reading average Analog Input from Joystick
  for ( int i = 0; i < 100; i++)
  {
    total+= analogRead(joystick);
  }
  avg = total / 100;

  //Mappin the Input to PWM Value
  Setpoint=map(avg,0,1023, 0,255); // Setpoint is dutycycle (range 0-255

  // Reading average input from the current sensor
  for ( int i = 0; i < 100; i++)
  {
    total1+= ina219.getCurrent_mA();
  }
  amps = total1 / 100;

  if(amps<0)
  amps=0;
 
  Input = amps/950*255;  // current with all components on board taking into account
                        // the voltage drops across all componenets is 0.99A
  myPID.Compute();      // Computes the PID Output
  delay(1);             // 1 millisecond delay for PID Stability
  
  // Writing PID Computed Output (with Dither) to the Valve 
  analogWrite(pwm,Output);
 

  // Plotting the Setpoint Input and Output
  Serial.print(Setpoint);
  Serial.print(" ");
  Serial.print(Input);
  Serial.print(" ");
  Serial.println(Output);
  
  // Printing Relevant information in the LCD
  printlcd();

  delay(10);
}



void printlcd() {
  
  int duty_,e_curr_;
  char e_curr[5],duty[5],amps_[5];
  float shuntvoltage = 0;
  float busvoltage = 0;
  float loadvoltage = 0;
  float power=0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  lcd.setCursor(4,0);
  duty_ = (float)avg/1023*100;

  snprintf(duty, 5, "%4d", duty_); // %4d = 4 digits, right aligned
  lcd.print(duty);

  lcd.setCursor(10,1);
  e_curr_ = (float)duty_/100.0 * 950;
  snprintf(e_curr, 5, "%4d", e_curr_); // %4d = 4 digits, right aligned
  lcd.print(e_curr);
  
  lcd.setCursor(3,1);
  lcd.print((int)amps);
  //delay(500);

   power = loadvoltage * amps/1000.0;
   
  lcd.setCursor(7,2);
  lcd.print(power);
  

 

  lcd.setCursor(11,0);
  lcd.print(loadvoltage);

}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 2: mode = 0x02; break;
      case 3: mode = 0x03; break;
      case 4: mode = 0x04; break;
      case 5: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 2: mode = 0x02; break;
      case 3: mode = 0x03; break;
      case 4: mode = 0x04; break;
      case 5: mode = 0x05; break;
      case 6: mode = 0x06; break;
      case 7: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;

}}

