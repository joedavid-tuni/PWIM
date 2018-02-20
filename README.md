## ELECTRONIC CONTROL OF HYRDRAULIC SYSTEMS


## Description of the Task

As mobile equipment becomes more technologically sophisticated, the need for electronic control of
hydraulic systems is growing.

Electronic components have become more reliable and rugged. They can now withstand the harsh
environmental conditions required for mobile equipment applications. Sophisticated electronic
controllers normally supply only low power control signals.

The goal of the project is to build an electronic driver circuit that compensates the stiction and
hysteresis of a hydraulic valve that makes their behaviour seem erratic and unpredictable. Once we
get over these issues we move on to implement a current sensing mechanism by which the current
in the solenoid circuit is prevented from fluctuating due to varying resistance from varying
temperatures of the coil. We as such are not interested in the position of the spool at any given
point in time but rather only to regulate the current.



## Table of Contents



- Terms of Reference
- Abstract
- Acknowledgement
- 1. Introduction
   - 1.1 Hydraulic Valve
      - 1.1.1 Introduction
      - 1.1.2 Working Principle
      - 1.1.3 Solenoid
      - 1.1.4 Characteristics of Solenoid Coil
   - 1.2 Methods for Proportional Control
      - 1.2.1 Using a potentiometer in Series with the Solenoid
      - 1.2.2 Pulse Width Modulation
      - 1.2.3 Problems associated with Proportional Control of Solenoids
   - 1.3 Solutions to Problems associated with Proportional Control – The Concept of Dither
      - 1.3.1 High frequency PWM
      - 1.3.2 Low frequency PWM
      - 1.3.3 Superimposing Low Frequency Dither on High Frequency Signal
- 2. Current Sensing
   - 2.1 INA219
   - 2.2 PID Algorithm
- 3. Project Work
   - 3.1 Major Hardware Components
   - 3.2 Software
      - 3.2.1 Simulation
      - 3.2.2 Programming IDE
      - 3.2.3 PCB Design Software
   - 3.3 Project Implementation
      - 3.3.1 Basic Circuit
      - 3.3.2 Calculating Inductance
      - 3.3.3 Dither
      - 3.3.4 Current Sensing
      - 3.3.5 Making the PCB
- 4. Project Setup
- 5. Conclusion
- 6. Project Resources
- 7. References
- APPENDIX A: I^2 C Communication Protocol
- APPENDIX B: Setting PWM Frequency on Arduino
- APPENDIX C: The PID Algorithm
- APPENDIX D: TROUBLESHOOTING
- Figure 1: Parts of the Hydraulic Valve List of Figures
- Figure 2: Internal cross section of the Hydraulic Valve
- Figure 3: Coil of Solenoid A energized
- Figure 4: Neutral Position of Valve Plunger
- Figure 5: Testing using mechanical override
- Figure 6: Cross-sectional sketch of Solenoid A of hydraulic valve
- Figure 7: Depiction of the magnetic field around solenoid
- Figure 8: Solenoid current characteristics
- Figure 9: Width of pulses at different duty cycles
- Figure 10: Duty cycle with respective current waveform
- Figure 11: A typical hysteresis curve in an electro hydraulic proportional valve
- Figure 12: Dither as a by-product of low frequency PWM
- Figure 13: Low Frequency Dither superimposed on high frequency PWM
- Figure 14: Functional block diagram of commercially available Solenoid Driver
- Figure 15: Dither Generating Circuitry of a commercially available driver
- Figure 16: Software Code for creating Dither
- Figure 17: Functional Block Diagram of INA219 Sensor
- Figure 18: LCD Display used in the project
- Figure 19: Screenshot of Multisim GUI
- Figure 20: Screenshot of Labcenter Proteus GUI
- Figure 21: Screenshot of Arduino IDE GUI
- Figure 22: Screenshot of Autodesk Eagle GUI
- Figure 23: An FET and a freewheeling diode used to drive the solenoid valve.
- Figure 24: Laboratory setup while calculating inductance
- Figure 25: Oscilloscope Screenshot at resonance
- Figure 26: Multisim simulation circuit
- Figure 27: Breadboard schematic
- Figure 28: General Schematic
- Figure 29: Simulated oscilloscope screenshot (Low frequency)
- Figure 30: Project Implementation waveform from the Arduino (Low frequency)
- Figure 31: Simulated oscilloscope screenshot (High frequency)
- Figure 32: Project Implementation waveform from the Arduino (High frequency)
- Figure 33:: Project Implementation of superimposed waveform from the Arduino.
- Figure 34: Breadboard schematic for current sensing
- Figure 35: Project implemented waveform from the Arduino with current sensing incorporated
- Figure 36: Schematic of Printed Circuit Board of Valve Driver Circuit
- Figure 37: Board Layout of Printed Circuit Board of Valve Driver Circuit
- Figure 38: 3D rendered images of designed Printed Circuit Board
- Figure 39: 3D rendered images of designed Printed Circuit Board
- Figure 40: 3D rendered images of designed Printed Circuit Board
- Figure 41: 3D rendered images of designed Printed Circuit Board
- Figure 42: Project Setup


## 1. Introduction

### 1.1 Hydraulic Valve

#### 1.1.1 Introduction

The Hydraulic Valve used for this Project is a bi-directional solenoid valve from BOSCH.

These are designed to perform any of three actions. They direct the flow of fluid in a hydraulic
system in a particular direction. They can halt or initiate the flow of fluid in a system. Directional
valves can also change the direction in which a fluid flows within a circuit. Various directional valves
are incorporated in hydraulic systems to enable proper flow of fluids. Spool valves in particular are
designed to block and allow the flow of fluid within a hydraulic system.

Parts of the Hydraulic Valve (as labelled in Figure 1)

1. 3 port/chamber system with spool guidance
2. Pressure tight solenoid
3. Optimized flow paths
4. Manual override with return spring


#### Figure 1 : Parts of the Hydraulic Valve

<a href="https://drive.google.com/uc?export=view&id=103Zk_Gb4QrChb2lCu6mXjAdsSugn9ifj"><img src="https://drive.google.com/uc?export=view&id=103Zk_Gb4QrChb2lCu6mXjAdsSugn9ifj" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


#### 1.1.2 Working Principle

#### Figure 2: Internal cross section of the Hydraulic Valve

<a href="https://drive.google.com/uc?export=view&id=1MhIU9a9HzgaAY-1frNQojasQYRDYau8C"><img src="https://drive.google.com/uc?export=view&id=1MhIU9a9HzgaAY-1frNQojasQYRDYau8C" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

The valve contains two coils on its either end and together with the valve tube that contains an  armature and a push pin make up what is known as a solenoid.

In the main body of the valve there are two springs that help return the spool when no solenoids are
energized. The lines with the gauges labelled A and B are the work ports that typically connect to a
hydraulic cylinder or a motor.

When Solenoid A of the valve is energized an electromagnetic field is created (Figure1). The field
pulls the armature in towards the centre of the winding which causes the armature to slide easily in
a tube that is internally lubricated with hydraulic oil. The armature moves the push pin and
ultimately the push pin moves the valve spool towards the right and now there will be a flow from
the pump directed to work port B. Likewise when Solenoid B is energized, the spool moves to the
left.

#### Figure 3: Coil of Solenoid A energized

<a href="https://drive.google.com/uc?export=view&id=1noz2zwyRv9kF4yIksqgTtab-pTfS3ick"><img src="https://drive.google.com/uc?export=view&id=1noz2zwyRv9kF4yIksqgTtab-pTfS3ick" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


Notice that when Solenoid A is energised the movement of the spool towards the right also causes
the pushpin and armature in Solenoid B is pushed to the right as well.

Also notice that in Figure 2 there is a gap present between the pushpin on the left side of the spool.
When Solenoid A is energized the armature and the push pin gets a running start against the spool
as the gap is closed.

When the solenoid returns to the neutral position after Solenoid A is energized the gap is present
with the Solenoid B. Whichever side of the valve has the pushpin gap has a slight force advantage
when that Solenoid is next energized (Figure 4 ).

#### Figure 4: Neutral Position of Valve Plunger

<a href="https://drive.google.com/uc?export=view&id=1vX9gAe1uKFn87bVOUZPevz9T227o3frZ"><img src="https://drive.google.com/uc?export=view&id=1vX9gAe1uKFn87bVOUZPevz9T227o3frZ" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

In order to help with troubleshooting and basic valve testing, the valve is provided with a mechanical
override (Figure 5), A mechanical override is simply a pin on the outside end of the valve tube in the
centre of the solenoid assembly that can be activated with a small screwdriver or hex key. Pushing
on the mechanical override is a simple way to find out if the internal parts of the valve is still free to
move and operating normally.

#### Figure 5: Testing using mechanical override

<a href="https://drive.google.com/uc?export=view&id=1xGuQGBYz5f1ClA1LN9TVYjQGVeLfPqYV"><img src="https://drive.google.com/uc?export=view&id=1xGuQGBYz5f1ClA1LN9TVYjQGVeLfPqYV" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


#### 1.1.3 Solenoid

The hydraulic solenoid valve as mentioned has two solenoids as actuators mounted on either ends
of the valve body. These linear solenoids are electromechanical devices which convert electrical
energy into a linear mechanical motion which is used to control the hydraulic system.
Figure 6 shows a cross sectional sketch of the electromagnetic solenoid hydraulic valve. The
solenoids consist of an electromagnetically inductive coil wound around a movable armature, or
plunger. The coil is shaped such that the armature can be moved in and out of its centre, altering the
coil’s inductance. The plunger provides mechanical force to activate the control mechanism, for
example opening and closing of a valve.

#### Figure 6: Cross-sectional sketch of Solenoid A of hydraulic valve

<a href="https://drive.google.com/uc?export=view&id=1pHDuV0NiXC4nKBy8d_73bMfwTTyaZYxM"><img src="https://drive.google.com/uc?export=view&id=1pHDuV0NiXC4nKBy8d_73bMfwTTyaZYxM" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

#### 1.1.4 Characteristics of Solenoid Coil

A main electrical characteristic of a solenoid is that of an inductor that opposes any change in
current. This characteristic is why current does not immediately reach a maximum level when a
solenoid is energized. Instead, the current rises at a steady rate until it is limited by the DC resistance
of the solenoid.

#### Figure 7: Depiction of the magnetic field around solenoid

<a href="https://drive.google.com/uc?export=view&id=10Lr9DRpki1RoA1x1QTP7i0Ylmb1DseCf"><img src="https://drive.google.com/uc?export=view&id=10Lr9DRpki1RoA1x1QTP7i0Ylmb1DseCf" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


An inductor (in this case a solenoid) stores energy in the form of a concentrated magnetic field.
Whenever current is present in a wire or conductor, a magnetic field, however small, is created
around the wire. With the wire wound into a coil, such as in the solenoid, the magnetic field
becomes very concentrated. This electromagnet can control a mechanical valve through an electrical
signal.

As soon as the solenoid is energized, the current increases, causing the magnetic field to expand
until it becomes strong enough to move the armature and the corresponding solenoid current is
known as IPEAK.

#### Figure 8: Solenoid current characteristics

<a href="https://drive.google.com/uc?export=view&id=1ldvCfLj_Tx2C3A3EPOGBCEJUdh6es91O"><img src="https://drive.google.com/uc?export=view&id=1ldvCfLj_Tx2C3A3EPOGBCEJUdh6es91O" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

The armature movement increases the concentration of the magnetic field as the armature’s own
magnetic mass moves farther into the magnetic field. Remember, a magnetic field changing in the
same direction of the current creating it induces an opposing voltage into the windings. Because the
magnetic field quickly expands when the armature strokes, the field causes a brief reduction in the
current through the solenoid windings till a minimum known as IVALLEY (Figure 8). Notice the
prominent dip in the rising portion of the current waveform.

After the armature strokes, the current continues on its normal upward path to its maximum level. A
typical current waveform in shown in Figure 8.


### 1.2 Methods for Proportional Control

When voltage is applied to a valve coil, the current flowing through it creates a magnetic field which
provides the force to shift the valve’s spool. The input voltage divided by the resistance of the coil
equals the current draw. This is very straightforward when used with on/off valves, but proportional
valves are only useful if the spool position can be precisely controlled by varying the input current.

#### 1.2.1 Using a potentiometer in Series with the Solenoid

A simple potentiometer can be used to vary the resistance, which then varies the input current. This
is an inefficient method of control, and is not practical when high currents are required. Also, when
an infinitely variable DC signal is used to operate a proportional valve solenoid, the output transistor
functions like a variable resistor. It drops the power supply voltage down to the level required by the
solenoid coil at a particular time. The full coil current, which may be several amps, needs to pass
through this output transistor. The result is that the transistor builds up heat which requires a large
heat sink to dissipate.

#### 1.2.2 Pulse Width Modulation

Pulse Width Modulation (PWM) is a control technique which can overcome the problems described
above. With PWM, the output transistor is used as an on/off switch, feeding the solenoid coil with a
series of on/off pulses at a constant voltage. The pulses are set at a constant frequency, typically 400
to 5000+ Hz. The signal level is determined by varying the duration of the “on” pulses relative to the
“off” pulses.

The advantage of this technique is that during the “off” pulse, the output transistor is not passing
any current, and during the “on” pulse, there is virtually no voltage drop across the transistor and
therefore very little heat is created. In practice, there will be a small voltage drop across the
transistor during the “on” pulses, and it takes a finite amount of time to switch on and off, so a small
amount of heat is created. However, the amount of heat is much smaller than would be produced by
a conventional DC output signal.

PWM has become the standard for all valve amplifiers in order to reduce amplifier size and power
waste. No modifications are required to the valve solenoid in order to use this technique.

PWM is an efficient way to control current to a proportional valve coil. It allows the use of
electronics for current regulation, dither, ramping, short circuit protection, and the elimination of
deadband.

**How PWM Works**

A PWM signal is not constant, it is on for a period of time and off for a period of time (see Figure 9 ).

#### Figure 9: Width of pulses at different duty cycles

<a href="https://drive.google.com/uc?export=view&id=1Hj7wRIMUwGXi5BsZQd7tWuWXpfzszCKg"><img src="https://drive.google.com/uc?export=view&id=1Hj7wRIMUwGXi5BsZQd7tWuWXpfzszCKg" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


The duty cycle “D” refers to the “on” portion of the cycle. The duty cycle can be anywhere from 0
(signal always off) to 1 (signal always on). A 50% “D” results in a perfect square wave.

Inductance is the characteristic of a circuit that opposes the starting, stopping or changing of current
flow. Inductance in an electrical system is similar to inertia in a mechanical system. Its effect is to
introduce a time lag into the duty cycle wave form. In theory, the wave form is perfectly rectangular,
rising immediately when current is applied, and falling immediately when current is withdrawn.
Because of the effects of inductance, the actual wave form rises and falls more gradually (see Figure
10 ).

#### Figure 10: Duty cycle with respective current waveform

<a href="https://drive.google.com/uc?export=view&id=1ye-VUofCY1JmQrYZPyqtdv7DvxmzGXA0"><img src="https://drive.google.com/uc?export=view&id=1ye-VUofCY1JmQrYZPyqtdv7DvxmzGXA0" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

At 25% signal, “D” is shorter than the time it takes the current to reach its maximum value. This
results in reduced current output to the valve coil, and therefore a reduced hydraulic output from
the valve. If the PWM frequency is low enough, the current will fall to zero during the off time. This
is described as “discontinuous current.”

#### 1.2.3 Problems associated with Proportional Control of Solenoids

There are two major problems that are associated with basic proportional control of solenoid.

1. Stiction

Stiction keeps the valve spool from moving when input signal changes are small. When the signal
finally becomes large enough to initiate movement, the spool will tend to overshoot the position
required for accurate control.

2. Hysteresis

#### Figure 11: A typical hysteresis curve in an electro hydraulic proportional valve

<a href="https://drive.google.com/uc?export=view&id=1HjYDC2TtLQYjVnxpmJmntj7FKT0Biom-"><img src="https://drive.google.com/uc?export=view&id=1HjYDC2TtLQYjVnxpmJmntj7FKT0Biom-" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


The spool movement in a proportional valve has to overcome some amount of spring force as well
as static friction when the input signal is applied. These forces produce an effect known as
hysteresis. Additionally, the solenoid has to overcome the magnetic hysteresis due to the cyclic
magnetization and demagnetization of the solenoid core. The spool movement in response to the
increasing input signal is not the same as the spool movement created in response to the decreasing
input signal. Hysteresis as shown in the figure above is defined as the difference in the spool position
produced by a particular input signal when it is increasing and then decreasing.

Stiction and hysteresis can make the behaviour of a hydraulic proportional valve seem erratic and
unpredictable. In the following sections, we will see how to overcome these problems.


### 1.3 Solutions to Problems associated with Proportional Control – The Concept of Dither

Dither is a rapid, small movement of the spool around the desired position. It is intended to keep the
spool moving to avoid stiction and average-out hysteresis. Dither amplitude must be **large enough
and the frequency slow enough for the spool to respond, and yet amplitude small and frequency
fast enough to avoid creating a noticeable pulsation in the hydraulic output of the valve.** Dither is
caused by coil current “ripples”—current variations around the desired control signal value. Due to
inertia, the valve spool will follow low frequency ripples better than it will follow high frequency
ripples. The amplitude of the ripples determines if, or how far, the spool will move at a given
frequency.

#### 1.3.1 High frequency PWM

The solenoid valves are very often operated by means of PWM signals at a frequency that is high for
the solenoid valve, for example at l KHZ, in the linear or analog range. The armature of the solenoid
valve cannot synchronously follow this high control frequency in mechanical terms and assumes an
intermediate position.

#### 1.3.2 Low frequency PWM

Previously these problems Were solved in that the frequency of the control signal has been reduced
to such an extent, for example between 70 - 300 HZ, that the armature can still just about follow and
in the intermediate position or central position is preferably deflected only minimally. This results in
oscillation of the armature, and of the valve connected thereto, about the intermediate position at
low amplitude which is conventionally called dither oscillation (dither signal). This dither oscillation is
desired in principle since the friction resistances at the moving parts of the solenoid valve may be
reduced thereby.

However, it is very difficult to stipulate an optimally constant dither signal amplitude **since the
dither signal depends on the PWM frequency and on the pulse-duty factor (duty cycle)** and
therefore on the coil current flowing in the solenoid valve. With this method, it is therefore **not
possible for the dither signal to form a constant amplitude since the PWM frequency has to be
continuously adjusted as a function of the stipulated desired current value and in the process the
amplitude and the frequency of the dither signal change accordingly.**

#### Figure 12: Dither as a by-product of low frequency PWM

<a href="https://drive.google.com/uc?export=view&id=1ios9JTr9PqKZaDLKV-OdVEeYfnglZrMP"><img src="https://drive.google.com/uc?export=view&id=1ios9JTr9PqKZaDLKV-OdVEeYfnglZrMP" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


#### 1.3.3 Superimposing Low Frequency Dither on High Frequency Signal

A further solution for said problems consists in a low-frequency dither signal being superimposed on
the high frequency of the PWM signal by amplitude modulation. This allows the user to
**independently control** amplitude and frequency of the **solenoid current** and the **dither**. The dither
will therefore be constant for any current level, and its frequency and amplitude can be set by the
user to optimize the function of the particular hydraulic valve. This will be necessary as different
valves from different manufacturers would have different spool dynamics (inertia due to different
size, for example).

#### Figure 13: Low Frequency Dither superimposed on high frequency PWM

<a href="https://drive.google.com/uc?export=view&id=1-vaZGm2uEeG3nVKuvEL_0PmVU9jZDm8H"><img src="https://drive.google.com/uc?export=view&id=1-vaZGm2uEeG3nVKuvEL_0PmVU9jZDm8H" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

The dither is specified by its frequency (Hz) and peak-to-peak current. The dither amplitude is usually
adjustable from 0 to 10% of the rated maximum current of the solenoid.

It is to note that, if the dither frequency is in the range of the control frequency, undesirable low-
frequency beating of the magnetic current can occur. Even the hydraulic system may be damaged
thereby. The beating results because the dither frequency cannot be synchronized with the control
frequency.

**Hardware Techniques**

Most solenoid valve drivers make use of a separate dither generating circuitry and combines it with
the main PWM signal using op-amps. The functional block diagram of one such driver is as shown in
the figure below:

#### Figure 14: Functional block diagram of commercially available Solenoid Driver

<a href="https://drive.google.com/uc?export=view&id=1qd2-SRFe5xwFcBycASi99DSaOHfmeA4B"><img src="https://drive.google.com/uc?export=view&id=1qd2-SRFe5xwFcBycASi99DSaOHfmeA4B" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

A dither generating circuit of a commercially available solenoid driver is shown below. This is capable
of generating triangular and square wave dither.

#### Figure 15: Dither Generating Circuitry of a commercially available driver

<a href="https://drive.google.com/uc?export=view&id=1yqVyhJahEJyZMxh-2SUGGK5sMoNQTPDx"><img src="https://drive.google.com/uc?export=view&id=1yqVyhJahEJyZMxh-2SUGGK5sMoNQTPDx" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

Working principle:

The dither generator consists of a comparator stage (A1A), amplitude limiting stages (A1C/D2 AND
A1D/D1) and an integrating amplifier stage (A1B). In the beginning, A1A will attempt to go to
positive or negative saturation. However, the peak voltage will be restricted by D1/A1D or D2/A1C.
A1B ramps up or down, as whatever the case maybe, until the output voltage is sufficient to cause
the feedback voltage at the comparator (through voltage divider R8, R11) to change polarity. At this
point, the polarity of A1A changes and A1B ramp in the opposite direction. This way, the dither
signal is generated.

Solutions of this nature are cost-intensive.

**Software Technique**

For the context of the project, we focus only on
superimposing the dither on main PWM signal. As
such, the requirements are basic and we do not need
sophisticated electronics for the purpose. All the
hardware needed would be the basic hardware for
the PWM switching of the solenoid and the dither can
be implemented without using the dither circuitry buy
by rather manipulating the switching hardware
through the software. This section is a description of
how it is done.

#### Figure 16: Software Code for creating Dither

<a href="https://drive.google.com/uc?export=view&id=17Wmvigc5C_fGLL_dgWxXKkvWKsJW3kRq"><img src="https://drive.google.com/uc?export=view&id=17Wmvigc5C_fGLL_dgWxXKkvWKsJW3kRq" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


Using software, the microcontroller is programmed so that the duty cycle of the PWM is periodically
oscillated about its set setpoint, by the dither amplitude which in “duty-cycle language” is in effect a
small finite amount of pulse-duty factor. This in effect causes an extended and thereafter a
shortened PWM signal cyclically which emulates dither. This way, the pulse-duty factor is changed
by the desired amplitude of the dither signal exactly every consequent cycle.

A constant amplitude for the dither signal may advantageously be formed thereby, so the armature
of the solenoid valve always oscillates about its central position with identical excursions, without
the control frequency of the PWM signal being able to have an adverse effect. The resulting reduced
friction resistance therefore allows the position of the armature to be advantageously adjusted and
controlled much more accurately as discussed earlier

The low frequency of the dither signal means that the oscillation of the solenoid valve armature can
be individually adjusted to the type of solenoid valve being used, so, compared with the known
hardware solution, a high level of flexibility results because the adaptation to other types of solenoid
valve can take place by way of a simple calibration process by changing a value in the code that the
microcontroller uses to generate the dither. It is also cost efficient in terms of the components used
as the dither circuitry is now replaced by software code.


## 2. Current Sensing

As mentioned in the previous section, the armature of a solenoid provides a mechanical force to
activate the control mechanism. The force applied to the armature is proportional to the coil’s
change in inductance with respect to the armature’s change in position. The electromagnetic force
of a solenoid directly relates to the current. Traditionally, a voltage drive powers the solenoid coils;
Therefore, the coil consumes a continuous power. A negative effect of this power consumption is
the heating of the coil. The coil temperature is a result of many factors: ambient temperature, self-
heating due to the coil’s power consumption (V × I), heating induced by the contact system, and
other heat sources such as components in the vicinity of the relay. Due to coil heating, the coil
resistance increases. The resistance at elevated temperature is expressed by Equation:

where

- RCoil_20°C is the 20°C value for resistance
- kR_T is the thermal coefficient of copper (= 0.00404 per °C) (1)

Typically given in the datasheet of a solenoid coil, RCoil_20°C can calculate the worst-case coil
resistance at high temperatures.

To compensate for temperature induced changes, we have to implement some sort of current
sensing algorithm which essentially is a current feedback. This allows the solenoid current to be
proportional to the input signal voltage, and independent of the solenoid resistance. Power supply
voltage must be sufficient to overcome the increased or decreased resistance

### 2.1 INA219

The current sensor used for the project is the INA219.

The two analog inputs to the INA219, IN+ and IN–, connect to a shunt resistor in the bus of interest.
The INA219 is typically powered by a separate supply from 3 to 5.5 V. The INA219 senses the small
op across the shunt for shunt voltage, and senses the voltage with respect to ground from IN– for
the bus voltage. Figure 13 shows this operation

#### Figure 17: Functional Block Diagram of INA219 Sensor

<a href="https://drive.google.com/uc?export=view&id=1i2oJyiAauu5uhqEkzyX2_yDP42nBgh-j"><img src="https://drive.google.com/uc?export=view&id=1i2oJyiAauu5uhqEkzyX2_yDP42nBgh-j" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


### 2.2 PID Algorithm

The PID Controller is implemented to achieve the current sensing functionality. See APPENDIX C: The
PID Algorithm to see the details of the PID Algorithm.

The PID algorithm consists of three basic coefficients; proportional, integral and derivative which are
varied to get optimal response. The basic idea behind a PID controller is to read the values from the
current sensor, then compute the desired actuator output by calculating proportional, integral, and
derivative responses and summing those three components to compute the output.

**Proportional Response:** The proportional component depends only on the difference between the
set point and the process variable. This difference is referred to as the Error term. The proportional
gain (Kp) determines the ratio of output response to the error signal. Increasing the proportional
gain will increase the speed of the control system response. However, if the proportional gain is too
large, the process variable will begin to oscillate. If Kp is increased further, the oscillations will
become larger and the system will become unstable and may even oscillate out of control.

**Integral Response:** The integral component sums the error term over time. The result is that even a
small error term will cause the integral component to increase slowly. The integral response will
continually increase over time unless the error is zero, so the effect is to drive the Steady-State error
to zero. Steady-State error is the final difference between the process variable and set point. A
phenomenon called integral windup results when integral action saturates a controller without the
controller driving the error signal toward zero.

**Derivative Response:** The derivative component causes the output to decrease if the process
variable is increasing rapidly. The derivative response is proportional to the rate of change of the
process variable. Increasing the derivative time (Td) parameter will cause the control system to react
more strongly to changes in the error term and will increase the speed of the overall control system
response. Most practical control systems use very small derivative time (Td), because the Derivative
Response is highly sensitive to noise in the process variable signal. If the sensor feedback signal is
noisy or if the control loop rate is too slow, the derivative response can make the control system
unstable

**Tuning**

The method used for tuning the PID Controller in this project is the “trial and error” method.

In this method, the I and D terms are set to zero first and the proportional gain is increased until the
output of the loop oscillates. As one increases the proportional gain, the system becomes faster, but
care must be taken not make the system unstable.

Once P has been set to obtain a desired fast response, the integral term is increased to stop the
oscillations. The integral term reduces the steady state error, but increases overshoot. Some amount
of overshoot is always necessary for a fast system so that it could respond to changes immediately.
The integral term is tweaked to achieve a minimal steady state error.

Once the P and I have been set to get the desired fast control system with minimal steady state
error, the derivative term is increased until the loop is acceptably quick to its set point. Increasing
derivative term decreases overshoot and yields higher gain with stability but would cause the system
to be highly sensitive to noise.


## 3. Project Work

### 3.1 Major Hardware Components

<a href="https://drive.google.com/uc?export=view&id=1NwfCsXLhD1eqSOyNHsD_ij0nW3hgjotf"><img src="https://drive.google.com/uc?export=view&id=1NwfCsXLhD1eqSOyNHsD_ij0nW3hgjotf" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

**Arduino**

The Arduino Uno is a microcontroller board based on the
ATmega328. Arduino is an open-source, prototyping
platform. The Arduino Uno has 14 digital input/output
pins (of which 6 can be used as PWM outputs), 6 analog
inputs, a 16 MHz crystal oscillator, a USB connection, a
power jack, an ICSP header, and a reset button. It
contains everything needed to support the
microcontroller; simply connect it to a computer with a
USB cable or power it with a AC-to-DC adapter or battery
to get started.

Features of the Arduino UNO:

- Microcontroller: ATmega328
- Operating Voltage: 5V
- Input Voltage (recommended): 7-12V
- Input Voltage (limits): 6-20V
- Digital I/O Pins: 14 (of which 6 provide PWM output)
- Analog Input Pins: 6
- DC Current per I/O Pin: 40 mA
- DC Current for 3.3V Pin: 50 mA
- Flash Memory: 32 KB of which 0.5 KB used by bootloader
- SRAM: 2 KB (ATmega328)
- EEPROM: 1 KB (ATmega328)

## • Clock Speed: 16 MHz

We use the Arduino to create the appropriate PWM signals for controlling the voltage to the
solenoid and to implement the algorithm for current sensing.

**Bidirectional Hydraulic Vale**

Manufacturer: Bosch Rexroth (BRH)

Part No.: 0810091203

Solenoid Specs:

Rating: 24V, 1.4A


**Power Supply**

Specs:

Rating: 24V,2.5A

**INA219, Bidirectional Current/Power Monitor with I2C Interface**

The INA219 is current shunt and power monitor with and I^2 C
interface. This along with the fact that it could be wired on the high
side were the prime reasons the device was selected to be used with
the I2C compatible Arduino.

The device is capable of monitoring both shunt voltage and the bus
supply voltage. The device uses a 3-5V supply, drawing a maximum of 1 mA of supply current and
operates from -40°C to 125°C.

**16x4 Liquid Crystal Display.**

A 16x4 LCD Display is used to display the circuit parameters such as duty cycle, current, etc. real
time.

The parameters on Display are:

Line 1: Duty cycle (Range: 0- 100 , from setpoint) Voltage: Voltage of the Solenoid Circuit
Line 2: I1 : Current sensed by the I2: Expected Current from duty cycle
current sensor (Feedback for PID)
Line 3: Power: VI Power Dissipated in the Solenoid Circuit
Line 4: PID constants (Kp, Ki, Kd)

#### Figure 18: LCD Display used in the project

<a href="https://drive.google.com/uc?export=view&id=1-ABclzSzZyn64kzNVGeBQozGHO7Giizi"><img src="https://drive.google.com/uc?export=view&id=1-ABclzSzZyn64kzNVGeBQozGHO7Giizi" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

**Other Electrical Components**

<a href="https://drive.google.com/uc?export=view&id=1LpvatdVxXZvamxfx_jg-BhqFKHSA1nNc"><img src="https://drive.google.com/uc?export=view&id=1LpvatdVxXZvamxfx_jg-BhqFKHSA1nNc" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

```
Device Part No. Rating Quantity Remarks
FET IRF3205PbF VDSS = 55V, ID = 110A (n-Ch) 1 Switching Device
Capacitor .001K 63 100nF 1 Noise Filter
Resistor - 12Ω 1 Current Limiter
Diode 1N5400 3A, Rectifier Diode 1 Freewheeling Diode
Potentiometer/
Joystick
```
- 10KΩ 1 Input to the System

### 3.2 Software

#### 3.2.1 Simulation

National Instruments, Multisim v12.0 (used for simulating electrical characteristics)

#### Figure 19: Screenshot of Multisim GUI

<a href="https://drive.google.com/uc?export=view&id=1yDhkocze4_SoT9yiW1kYx1o0pmJ9QOiR"><img src="https://drive.google.com/uc?export=view&id=1yDhkocze4_SoT9yiW1kYx1o0pmJ9QOiR" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


LabCenter, Proteus 8 (used for simulating arduino microcontroller (with code) with electrical circuit)

#### Figure 20: Screenshot of Labcenter Proteus GUI

<a href="https://drive.google.com/uc?export=view&id=1wienvCHE1-AMao52zff7h7abuAwJmdlY"><img src="https://drive.google.com/uc?export=view&id=1wienvCHE1-AMao52zff7h7abuAwJmdlY" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

#### 3.2.2 Programming IDE

##### ARDUINO IDE

#### Figure 21: Screenshot of Arduino IDE GUI

<a href="https://drive.google.com/uc?export=view&id=177bdEXaEHLrz7efpmUK4lLl1IIjE5Dey"><img src="https://drive.google.com/uc?export=view&id=177bdEXaEHLrz7efpmUK4lLl1IIjE5Dey" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


#### 3.2.3 PCB Design Software

#### Figure 22: Screenshot of Autodesk Eagle GUI

<a href="https://drive.google.com/uc?export=view&id=1jIhEK4rQlFEAy6yMQ-lyjC428kQFLo-f"><img src="https://drive.google.com/uc?export=view&id=1jIhEK4rQlFEAy6yMQ-lyjC428kQFLo-f" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


### 3.3 Project Implementation

Before the implementation, the circuit needs to be simulated to study the response of the
circuit beforehand so that time is no wasted during implementation stage. An added benefit would
be familiar results and pre-known reasoning during the implementation phase. As mentioned in the
earlier sections we use MultiSim v12.0 and Proteus 8.0 for simulations. Proteus simulations were
made to study the behaviour while designing the project work and its observations are not recorded
here.

#### 3.3.1 Basic Circuit

Driving a solenoid is a rather simple task with very little need for sophisticated electronics. Still, the
basics of inductive load driving must be taken care of if we are to safely actuate this load. These
requisites are:

- A large enough voltage must be applied across the winding in order to supply a current with
    enough magnitude as to push/pull the piston.
- The switch or power stage must be sized according to the dc current we expect to see
    flowing across the solenoid winding.
- An alternate path must be applied to take care of the flowing current once the switching
    element is disabled.

A normal MOSFET requires around 10V applied to the Base pin to fully turn on. Because driving
anything above 5V with an Arduino requires using a level-shifter or amplifier, we use what is called a
logic-level MOSFET (IRF 3205) for direct integration. A logic-level MOSFET can be turned on with a 5v
“logic level” signal, which can be easily interfaced to the Arduino.

If a normal MOSFET with an amplified input from the Arduino is used, care must be taken not to
exceed the maximum gate-to-source voltages. If the limit is exceeded for even a second, it can
destroy the MOSFET, so care should be taken to work within the voltage limits of the MOSFET. The
maximum voltage that can be applied to the gate pin is listed in the datasheet as the “Gate to Source
Voltage” or “Vgs” —this number is usually between 18vdc and 25vdc.

For the IRF 3205 we the maximum Vgs is 20V, so it is safe as the Arduino cannot prover over 5V with
direct integration.

The typical solenoid driver circuit is a single FET transistor with enough current handling capability to
drive the load (IRF 3205), and a freewheeling diode which is forward biased when the FET is
disabled. When the FET is enabled, it sinks all the current needed to polarize the inductor. When the
transistor is disabled, the current flowing through the inductance must be allowed to decay down to
zero. The freewheeling diode is forward biased taking this current and avoiding damage to the
power FET. Figure 1 9 shows the two possible states a solenoid will experience as it is energized


#### Figure 23: An FET and a freewheeling diode used to drive the solenoid valve.

<a href="https://drive.google.com/uc?export=view&id=1sQTFtrDf82s8IXWCDfRFEJ_FRTnlli9v"><img src="https://drive.google.com/uc?export=view&id=1sQTFtrDf82s8IXWCDfRFEJ_FRTnlli9v" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>

Note that a H-bridge circuit is not used as it’s not a bistable solenoid where the direction of motion
is according to the magnetic field polarity. Hence the direction of current flow is not relevant and
use of an H-bridge would be an overkill as it would need 4 FETs as opposed to one in this case.

All information required to begin simulations is present except one, the inductance of the solenoid
of the hydraulic valve. This was neither found in the product datasheet nor was available with the
Bosch Customer Service personnel on contacting them. So, a basic test is carried out to approximate
the inductance of the solenoid.

#### 3.3.2 Calculating Inductance

To calculate the inductance, connect the solenoid of the hydraulic valve in parallel with a capacitor
to form a tank circuit. Use a function generator to run a small current through the circuit and an
oscilloscope to view the waveform across the solenoid. Next, sweep the function generator
frequency from its lowest top highest range. In this range, the tank's resonant frequency is where
the oscilloscope registers the largest waveform.

#### Figure 24: Laboratory setup while calculating inductance

<a href="https://drive.google.com/uc?export=view&id=1DbEUsarPM3vBnsaWHENC6-nMKgTmmU00"><img src="https://drive.google.com/uc?export=view&id=1DbEUsarPM3vBnsaWHENC6-nMKgTmmU00" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


Resonant Frequency of LC tank circuit is given by the formula:

##### 푓=

##### 1

##### 2 휋√퐿퐶

Equation 1

From the equation 1 the inductance can be found, L, as:

##### 퐿=

##### 1

##### ( 2 휋푓)^2 .퐶

Equation 2

Resonance was found to obtained at around 150Hz using
a capacitor of 10μF.

Substituting in Equation 2, the inductance,

```
L= 0.10554 H or 105.54mH
```
#### 3.3.3 Dither

Now, that the inductance of the solenoid is established, it is simulated in softwares. Next,
simulations at both higher and lower frequencies is carried out and the observations are recorded
below.

**Simulation Circuit**

The circuit built is shown in the figure below.

As can be seen the **voltage across the solenoid is connected to channel A** and **the current in the
solenoid is connected to channel B** of the oscilloscope.

#### Figure 25: Oscilloscope Screenshot at resonance

<a href="https://drive.google.com/uc?export=view&id=1k7YGEA7DGEtcj9yKaFBfLAySiLHO5YZx"><img src="https://drive.google.com/uc?export=view&id=1k7YGEA7DGEtcj9yKaFBfLAySiLHO5YZx" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


#### Figure 26: Multisim simulation circuit

<a href="https://drive.google.com/uc?export=view&id=1Tc4o473i5xGG8D_BdxKo3akBl32X1_w4"><img src="https://drive.google.com/uc?export=view&id=1Tc4o473i5xGG8D_BdxKo3akBl32X1_w4" style="width: 500px; max-width: 100%; height: auto" title="Click for the larger version." /></a>


**Arduino Valve Driver Circuit**

#### Figure 27: Breadboard schematic


## Figure 28: General Schematic

The PWM frequency on most pins is ~490 Hz. However, it's ~980 Hz for pins 5 and 6 on the Uno. To
obtain lower frequencies a deeper understanding on the hardware implementation of the ATMEL
328p Microprocessor that the Arduino uses is necessary.


See APPENDIX B: Setting PWM Frequency on the Arduino to see how a frequency different from that
of the default frequency was obtained.

Also see APPENDIX D: Troubleshooting to see how to eliminate noises in the analog input

The waveforms from the scope are shown in the figure below.

**Low Frequency Dither Observations**

(refer Section 2.3.2 for literature)

Frequency: ( 60 Hz) and PWM with
duty cycle: 80%

**Simulation Results:**

## Figure 29: Simulated oscilloscope screenshot (Low frequency)

As described in Section 2.3.2, low frequency PWM generates dither (current ripple) as a by-product
of the PWM process. The PWM frequency is low enough so that the current has time to decay
before the next rise begins.


**Project Implementation Results**

## Figure 30: Project Implementation waveform from the Arduino (Low frequency)

The above is a plot of instantaneous values of the current (Y-axis) vs time (x-axis) that that micro-
controller records. The blue is the expected current value at 80% duty cycle whereas the redline is
the current values sensed by the sensor in the feedback circuit. It is observed that the frequency of
the PWM is low enough that it reduces to 0 at moments. This is in line with what was expected and
as shown in the simulations

**Valve Behaviour**

As the duty cycle was increased, the plunger of the solenoid began to vibrate with larger amplitude
and finally actuated. This was as expected as mentioned in the Section 2.3.2. Changing the PWM
frequency will allow adjusting the dither, but the amplitude and frequency of the dither cannot be
set independently.

**Results from Test Bench.**

Due to large hysteresis of the solenoid used in the test bench, the dither could be observed in the
initial stages for a brief amount of time but it quickly actuated.


**High Frequency Dither Observations**

(refer Section 2.3.1 for literature)

**Simulation Results:**

Frequency: ( 490 Hz – Arduino Default frequency) and PWM with
duty cycle: 80%

## Figure 31: Simulated oscilloscope screenshot (High frequency)

Here, it is clear that the frequency of the PWM signal is high enough that it does not let the current
to a minimum zero value.

**Valve Behaviour**

The armature of the solenoid valve cannot synchronously follow the current in mechanical terms
and assumes an intermediate position. With a pulse duty factor of 50% of the PWM signal this then
corresponds to the central position of the valve “half open”. But this as discussed in Section 2 .3.1
will be subject to problems of stiction and thereby hysteresis due to lack of dither oscillation.


**Project Implementation Results**

There were no significant dither observations, as expected. The high frequency did not allow the
plunger dither oscillations.

## Figure 32: Project Implementation waveform from the Arduino (High frequency)

The blue is the expected current value at 80% duty cycle whereas the redline is the current values
sensed by the sensor in the feedback circuit. The frequency of the PWM is high enough to produce a
continuous current.

```
-- Input
-- Setpoint
```

**Superimposing Low Frequency Dither on High Frequency Signal**

(refer Section 2.3.3 for literature)

This is obtained in the software implementation by periodically varying the duty cycle.

**The PWM frequency runs at a high frequency, while
the duty cycle oscillation along with a delay in
between produces the effect of low frequency dither.**

**Valve behaviour**

This causes just enough oscillation of the solenoid
plunger, not to keep it stationary as well not to
produce considerable variation in the plunger
displacement.

## Figure 33:: Project Implementation of superimposed waveform from the Arduino.

Here the “dither_time” variable is set to 10ms so 1 complete cycle of the dither wave takes
approximately 20ms. Hence the **dither frequency is 50Hz**

The blue is the expected current value at 80% duty cycle whereas the redline is the current values
sensed by the sensor in the feedback circuit.

At the moment, there isn’t any feedback which is why there is considerable steady state error.

```
-- Input
-- Setpoint
```

#### 3.3.4 Current Sensing

**Introduction**

Here the objective is to implement a PID algorithm, that inputs feedback from a current sensor. As
discussed in Section 3 the objective is to make sure that for a given setpoint from the input joystick,
the output must be the same at all times, irrespective of the varying ambient temperature due
varying weather conditions

**Circuit Diagram**

The circuit is rigged up as per the following diagram,

```
Current sensing
```
## Figure 34: Breadboard schematic for current sensing


**Software Code**

The code begins with the necessary pre-processor directives. They are invoked by the compiler to
process the class definitions before compilation.

Next, initialize objects of these classes, to use them throughout the code.

Initialize Variables for use

Setup Function, that runs once when the Arduino runs the program.


The setup function is used to setup the parameters of the instances of class objects initialized earlier.
This includes the LCD, PID, Current Sensor and the Arduino GPIO Pins.

**Loop Function**

This function is the main function and runs every cycle continuously

See APPENDIX D: Troubleshooting to set a PWM frequency on the fly with carrying setpoint.

**PID Tuning**

See APPENDIX C: The PID Algorithm to see the details of the PID Algorithm.

The procedures taken during tuning were as discussed in Section 3.2.

On starting the tuning the proportional constant the oscillations were already high. Hence it was
decided to keep the Kp parameter near zero or zero. The parameters suitable for the project were
found to be **Kp = 0, Ki = 10 and Kd=0.**


**Project Implementation Results**

## Figure 35: Project implemented waveform from the Arduino with current sensing incorporated

It can be observed that as the duty cycle of the PWM output is varied (blue line), output (green line)
varies almost instantaneously so that the input (current in the solenoid coil) closely follows the
setpoint.

When the current in the solenoid of the hydraulic valve reduces due to the increase in the resistance
the PID controller automatically adjusts the output to achieve the desired current level.

```
-- Output
-- Input
-- Setpoint
```

#### 3.3.5 Making the PCB

Once the objectives of the project have been achieved, it is made permanent by transferring the
breadboard to a Printed Circuit Board.

The software Eagle, from Autodesk is used for the purpose to sketch the PCB.

Features of the PCB

1. Besides the circuit already discussed, an additional power circuit is added that is used to
    power the PCB and provide power to the INA219 sensor. It provides a regulated output of 5V
    (4.8V-5.2V) from an external input voltage (5V-18V) through a DC Barrel Connector (2.1mm
    centre positive).
2. 4 Pairs of 5V power supply headers are provided to power auxiliary devices such as an LCD
    or a variable analog input such as a potentiometer or a joystick. Please note that the current
    sensor is powered from within the PCB and a separate connection is not required.


**Schematic:**

## Figure 36: Schematic of Printed Circuit Board of Valve Driver Circuit


**Board View:**

## Figure 37: Board Layout of Printed Circuit Board of Valve Driver Circuit


##### 43

**Rendering**

## Figure 38: 3D rendered images of designed Printed Circuit Board

## Figure 39: 3D rendered images of designed Printed Circuit Board


## 4. Project Setup

## Figure 42: Project Setup


## 5. Conclusion

The report starts with literature discussing certain important aspects in the electronic control of
hydraulic systems.

Next, the solenoid valve used in the project was characterised by conducting basic tests on it initially
to determine its inductance as it was not provided in the accompanying datasheet. This information
was used to simulate models in softwares Multisim and Proteus to study the Low Frequency and
High Frequency PWM response with reference to the topics discussed in the literature. Its behaviour
during the simulations were studied and a temporary test circuit was built on a breadboard and the
implementation results were compared with that of the simulation.

A software based technique for determining a control signal for a solenoid valve is next discussed,
the control signal being a PWM signal on which a frequency of a dither signal is superimposed and
having a frequency such that the spool of the solenoid valve assumes an intermediate position
between which the armature oscillates with slight excursions at the frequency of the dither signal.

Upon successful implementation of dither, a current sensing circuit was built using a fine tuned PID
algorithm. Finally, after running successful tests, a PCB for the prototype was designed.


## 6. Project Resources

All the files used in this project develop are available online at the GitHub repositories with links
given below.

Arduino Sketch: https://github.com/joedavid91/PWIM/tree/master/Arduino%20Code/PWIM

Simulation Files: https://github.com/joedavid91/PWIM/tree/master/Simulation%20Files

Fritzing Sketches: https://github.com/joedavid91/PWIM/tree/master/Fritzing%20Sketches

Eagle PCB Files: https://github.com/joedavid91/PWIM/tree/master/Eagle%20PCB%20Files

Links to Videos:

Low Frequency Dither: https://youtu.be/j71BZkSpgNY

Laboratory Setup with current sensing: https://youtu.be/wHQWNnsTs0Q

Real time PID Plot with current sensing: https://youtu.be/J_p4m4B9xHs


## 7. References

##### [1] “ ELECTRONIC CONTROL OF HYDRAULIC SYSTEMS”

[http://www.hydraforce.com](http://www.hydraforce.com)

##### [2] “FLOW AND DIRECTIONAL CONTROL VALVES”

[http://www.lunchboxsessions.com](http://www.lunchboxsessions.com)

[3] _“Detection of Plunger Movement in DC Solenoids”_ Manu Balakrishnan, Navaneeth Kumar N
Texas Instruments

[4] _“Method and Device for determining a PWM Signal on which a dither frequency is
superimposed in order to control a solenoid” Jose Cruz Kissler Fernandez, Thomas Rohrl_

[5] _“Driving solenoid coils efficiently in switchgear applications_ ” Sanjay Pithadia, Texas
Instruments

[6] “ _Arduino Robotics”_ John-David Warren, Josh Adams and Harald Molle

[7] “ _Secrets of Arduino PWM”_ Ken Shirriff’s blog


## APPENDIX A: I^2 C Communication Protocol

The INA219 offers compatibility with both I2C and SMBus interfaces of which the I2C will be used as
it is compatible with the Arduino. Two bidirectional lines, SCL and SDA, connect the INA219 to the
bus. Both SCL and SDA are open-drain connections meaning that they can pull the corresponding
signal line low, but cannot drive it high. Thus, there can be no bus contention where one device is
trying to drive the line high while another tries to pull it low, eliminating the potential for damage to
the drivers or excessive power dissipation in the system. Each signal line has a pull-up resistor on it,
to restore the signal to high when no device is asserting it low.

The device that initiates the transfer, the Arduino, is called a master, and the devices controlled by
the master are slaves. The Arduino generates the serial clock (SCL), controls the bus access, and
generates START and STOP conditions.

Messages are broken up into two types of frame: an address frame, where the master indicates the
slave to which the message is being sent, and one or more data frames, which are 8-bit data
messages passed from master to slave or vice versa. Data is placed on the SDA line after SCL goes
low, and is sampled after the SCL line goes high. The time between clock edge and data read/write is
defined by the devices on the bus and will vary from chip to chip.

Start Condition

To initiate the address frame, the master device leaves SCL high and pulls SDA low. This puts all slave
devices on notice that a transmission is about to start. If two master devices wish to take ownership
of the bus at one time, whichever device pulls SDA low first wins the race and gains control of the
bus.

Address Frame

The address frame is always first in any new communication sequence. For a 7-bit address, the
address is clocked out most significant bit (MSB) first, followed by a R/W bit indicating whether this
is a read (1) or write (0) operation.

The 9th bit of the frame is the NACK/ACK bit. This is the case for all frames (data or address). Once
the first 8 bits of the frame are sent, the receiving device is given control over SDA. If the receiving
device does not pull the SDA line low before the 9th clock pulse, it can be inferred that the receiving
device either did not receive the data or did not know how to parse the message. In that case, the
exchange halts, and it’s up to the master of the system to decide how to proceed.

Data Frames


After the address frame has been sent, data can begin being transmitted. The master will simply
continue generating clock pulses at a regular interval, and the data will be placed on SDA by either
the master or the slave, depending on whether the R/W bit indicated a read or write operation. The
number of data frames is arbitrary, and most slave devices will auto-increment the internal register,
meaning that subsequent reads or writes will come from the next register in line.

Stop condition

Once all the data frames have been sent, the master will generate a stop condition. Stop conditions
are defined by a 0->1 (low to high) transition on SDA after a 0 - >1 transition on SCL, with SCL
remaining high. During normal data writing operation, the value on SDA should not change when SCL
is high, to avoid false stop conditions.


## APPENDIX B: Setting PWM Frequency on Arduino.......................................................................

The idea here is not to provide a detailed overview of how the processor manages the register, but
only to provide enough information to understand the code in the context of the project.

The ATmega328P has three timers known as Timer 0, Timer 1, and Timer 2. Each timer has two
outputs compare registers that control the PWM width for the timer's two outputs: when the timer
reaches the compare register value, the corresponding output is toggled. The two outputs for each
timer will normally have the same frequency, but can have different duty cycles (depending on the
respective output compare register).

Each of the timers has a prescaler that generates the timer clock by dividing the system clock by a
prescale factor such as 1, 8, 64, 256, or 1024. The Arduino has a system clock of 16MHz and the
timer clock frequency will be the system clock frequency divided by the prescale factor. Note that
Timer 2 has a different set of prescale values from the other timers.

The timers are complicated by several different modes. The main PWM modes are "Fast PWM" and
"Phase-correct PWM" of which the Fast PWM will be used and is described below

Let’s take Timer 1 for example

The Timer/Counter Control Registers TCCR1A and TCCR1B hold the main control bits for the timer.
(Note that TCCR1A and TCCR1B do not correspond to the outputs A and B.) These registers hold
several groups of bits:

- Waveform Generation Mode bits (WGM): these control the overall mode of the timer.

(These bits are split between TCCR1A and TCCR1B.)

- Clock Select bits (CS): these control the clock prescaler
- Compare Match Output A Mode bits (COM1A): these enable/disable/invert output A
- Compare Match Output B Mode bits (COM1B): these enable/disable/invert output B

The Output Compare Registers OCR1A and OCR1B set the levels at which outputs A and B will be
affected. When the timer value matches the register value, the corresponding output will be
modified as specified by the mode.


**Base frequencies:**

The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.

The base frequency for pins 5 and 6 is 62500 Hz.

**Divisors:**

The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64, 256, and 1024 which are selected by the
mode values and are in hexadecimal format.

The divisors available on pins 3 and 11 are: 1, 8, 32, 64,128, 256, and 1024 which are selected by the
mode values and are in hexadecimal format.

PWM frequencies are tied together in pairs of pins. If one in a pair is changed, the other is also
changed to match:

Pins 5 and 6 are paired on timer0

Pins 9 and 10 are paired on timer1

Pins 3 and 11 are paired on timer2

Below is a code for a function that accepts the Arduino output pin number and the divisor as
arguments which it uses to attain varying frequencies on the Arduino (UNO)

The resulting frequency is equal to the base frequency divided by the given divisor:



## APPENDIX C: The PID Algorithm

Please note that sections of the code that are irrelevant, of negligible importance or self-explanatory
are omitted to keep this section concise.

**The PID class Constructor**

The PID class constructor is used to intialize an instance / obect of the class PID. All the information
regarding the PID object are to be passed as parameters to the constructor. The Input, Output and
the Setpoint variables are pointers, and a reference to these pointer variables are usedwhile creating
the class object as shown below :

The constructor is also used to assign the PID tuning parameters Kp,Ki and Kd using the SetTunings
function (shown in code above). The **step time** is set to **0.1s or 100ms**


The SetOutputLimits function sets the maximum outout of the PID controller. This is necessary as its
intended to control the PWM ouptut of the arduino which is in the range 0-255 as its 8-bit. Without
this function the PID would increase the output beyond 255 and there would be an overflow as the
PWM value is only 8bit.

Lines 67 - 69 of the compute funciton ( code in next page ) ensure that the PID is called only at a
regular interval, based on a **predetermined step time, i.e 100ms**. Once the PID is evaluated at a
constant interval, the derivative and integral calculations can also be simpligfied. As a result of this,
the SampleTimeInSec variable appears in the SetTunings function (code in previous page), which are
multiplied or divided while setting the tuning parameters itself. because it is now known that it’s
going to be the same time between samples,it is unecessary to constantly multiply by time change
which is why time doesn’t appear in the setTunings function. The result is mathematically
equivalent, but more efficient as it saves a multiplication and a division every time the PID is
evaluated

**Compute Function.**

This is where the all the PID computation takes place.

This function should be called every time "void loop()" function of the arduino executes. the
function will decide for itself whether a new pid Output needs to be computed, i.e whether the time
since the previous computation is greater than the constant sample interval defined in the
constructor. It returns true when the output is computed, false when nothing has been done.

**Lines 71- 74** Computes the working error variables.

**Lines 76 and 77** Clamps the Output to its maximum (255) and minimum (0) values respectievely and
make sure there is no over flow.

**Lines 8 0 - 82** , computes the proportional on error output term and adds it to the Final Output on
**lines 8 5**

**Lines 9 7 - 89** , clamps the output to either the maximum or mimnimum values as earlier. This is
necessary to be taken care of at each stage as the variables in the arduino code are referenced as
pointers and any momentary overflow of the PWM register bits can adversely affect the stability of
the system.

**Lines 92 & 93** are used to store the current input time for use in the next computation cycle.



## APPENDIX D: TROUBLESHOOTING

This Section presents few challenges that were faced during the project implementation and how
they were overcome.

**Heating of the MOSFET**

MOSFETs have tiny capacitors attached to their gate pins to maintain the voltage present at the
gate. The capacitor charge enables the MOSFET to stay activated, even after the power is removed
from the gate pin. Each time the MOSFET is switched, the gate capacitor must fully charge and
discharge its current.

As the PWM frequency that is applied to the MOSFET switch increases, the time allowed for the gate
capacitor to charge and discharge decreases. As this happens, the gate-capacitor will require more
current from the driver to fully charge and discharge in the shorter amount of time. If the current
available from the driver is not sufficient to fully charge and discharge between switching cycles, the
gate will be left in a partially conducting state, which can result in excess heating.

Saying that a MOSFET needs a lot of available current to switch quickly might seem puzzling, because
MOSFETs require a specific voltage to turn on and typically very little current. Although the 40mA
that the Arduino PWM output pin can supply is plenty of current to fully switch a MOSFET on or off
slowly, it is not enough to fully charge and discharge the MOSFETs gate-capacitor at high PWM
frequencies where the MOSFET capacitor needs to be fully charged and drained 10,000 (10Khz) to
32,000 (32Khz) times per second!

A solution to this would be using a MOSFET driver IC (specialized signal-buffer) drive the MOSFET
switch because it can provide much more current during each switching cycle than the Arduino is
capable of.

It is also a good idea to ensure that the gate is forced to its off state by using a “pull-down” resistor
to drain the capacitor when not actively powered by the Arduino. Using a 10kOhm pull-down
resistor from the gate pin to the source pin (gate to GND on n-channel, gate to VCC on p-channel)
will be sufficient to keep the MOSFET turned off when not in use.

**Having different frequencies at different duty cycles on the fly**

The code used in the project section sets the main PWM (not dither) of the Arduino in the setup function
and remains the same throughout the execution of the program. Sometimes it may be required that this
PWM signal be changed on the fly with different PWM frequencies at different setpoints. This may be
due an increased stiction at some point or strange hysteresis patterns obtained during the spool
movement. It might be unwieldy to call the setPwmFrequency() method every time this needs to be
done. Rather a more efficient method is presented below.

Here Timer1 is used, which is 16bit, and allows for a number to be stored in a register (ICR1), and the
frequency is calculated based on that number. This gives me outputs on pins 9 and 10.
The number can be any value from 0 – 65535 (size = 16 bits).
The output frequency is given by the formula:

```
표푢푡푝푢푡 푓푟푒푞푢푒푛푐푦=
```
##### 푓

##### 2 푥푁푥푇푂푃

Where f = main clock (16MHz)
N = pre-scalar (see APPENDIX B)


TOP = the value in ICR 1
Based on the values of ICR1 from 1 to 65535 we get a frequency range from 15Hz to 1MHz.
So for example:
ICR1 = 10,000 gives f = 100Hz
ICR1 = 5000 gives f = 200Hz
ICR1 = 2500 gives f = 500Hz and so on..

To do this, the timer is configured to run in phase and frequency correct mode, and can set it to
either inverting or non-inverting mode. The pre-scalar should also be selected.

These configurations are done by adjusting Timer1 registers TCCR1A and TCCR1B.

First thing to adjust is choosing Phase and Frequency correct mode in invert or non-invert mode.


Second thing to adjust is PWM, Phase and Frequency correct mode, with the TOP value determined
by the ICR1 register, which is what determines the PWM Frequency.

The last thing to do is to adjust the pre-scalar.


This is done by choosing the right modes from the above table. As discussed earlier, we shall be
using mode which divides the main clock by 8.

**Smoothing Arduino Analog Input**

While reading the analog input from the joystick or potentiometer it is most likely that the input
behaves like the red line in the below picture. This also partially applies to the analog input of the
feedback sensor

As can be seen, if the fluctuating setpoint drives the PID algorithm crazy. First of all, it’s imperative to
check whether the Arduino and the rest of the circuit have a common ground. This is necessary. A
couple of additional measures were taken to fix this problem

1. Adding a filter capacitor from the analog input pin to ground as shown in Figure 27


2. Using an averaging algorithm. In this project, a basic averaging algorithm is used using a for-
    loop as it was found to suffice. There are however there are more robust algorithms such as
    the moving average or weighted average, the exponential moving average etc.


