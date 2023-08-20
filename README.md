# 2DOF-Solar-Tracker

## Introduction
The objective was to design a two-degree-of-freedom (2-DOF), azimuth and altitude, solar panel tracking system in which a light source from a cellphone or lamp acts as the sun and the two light dependent resistor (also known as a photoresistor or LDR) sensors act as the solar panels. The two photoresistors can establish the direction of light in one direction (azimuth) by comparing the value between them which makes it easy to design a 1-DOF system using one motor, to track light in the second axis, a second motor could be used to sweep over a range to find the maximum light reading.

## Design
### Problem Definition
![Capture2](https://github.com/DylJFern/2DOF-Solar-Tracker/assets/128000630/a43f5dee-1894-45c8-b593-ccba545b75d2)

### Formulation of a Solution
![Capture4](https://github.com/DylJFern/2DOF-Solar-Tracker/assets/128000630/fab0e893-566b-41a6-bab6-52e4de99b7bd)

### Equipment
  - Elegoo Uno R3 controller
  - Breadboard & Mini-breadboard
  - Power supply module
  - 9V 1A adapter
  - Servomotor & Stepper motor
  - ULN2003 stepper motor driver module
  - Two 10kΩ resistors 
  - Male to male jumper wires
  - Female to male dupont wires
  - Two photoresistors
  - Household materials (e.g. cardboard, duct tape)
  - Hot glue gun
  - USB cable

### Set up of Mechanics & Electronics
A transition fit between stepper motor nose and a lid (fixed to a base). Hot glue to secure it and prevent nose rotation. Cardboard strips added to sides on the front face of the motor to provide stable rotation. A piece of cardboard attached to the back of the stepper with a servomotor connected via hot glue and duct tape. The servomotor blade oriented vertically and initialized as 90°, attached to it, an L-shape cardboard structure consisting of hot glue and duct tape. The end of the structure housed the two photoresistors (secured in place) separated by a cardboard wall. 

The circuit consisted of a connection between the stepper motor and a 4-phase stepper motor jack of the ULN2003 driver board. Pins IN1 to IN4 of the ULN2003 were connected to pins 11 to 8 of the Elegoo Uno R3 controller. The power pins of the ULN2003 were connected to their respective terminals on the breadboard to bridge a connection to a 9V 1A adapter (which was connected to an outlet) through the power supply module in order to power the stepper motor. The Elegoo Uno R3 controller connected the supply voltage 5V and GND terminals to the mini-breadboard. The 5V from the mini-breadboard would go through each photoresistor, each photoresistor would then go through a 10 kΩ resistor on the mini-breadboard to a GND connection of the Elegoo Uno R3 controller. The servomotor was connected to 5V and GND through the mini-breadboard and pin 6 of the Elegoo Uno R3 controller.

![20201111_173822 (1)](https://github.com/DylJFern/2DOF-Solar-Tracker/assets/128000630/52b98bb4-2402-4d91-a155-d25d2d123a88)
![20201111_173936](https://github.com/DylJFern/2DOF-Solar-Tracker/assets/128000630/d674c4cd-c783-463c-b1e8-cd9db733a27b)


A sample video showcasing the result can be found [here](https://drive.google.com/file/d/1J0Y9WaO4R7ycdcR4fgk4VDwXFohfOkpg/view?usp=drive_link).

### Program Flowchart
![MEC830 - Project 1 drawio](https://github.com/DylJFern/2DOF-Solar-Tracker/assets/128000630/feb0a1ac-2641-48fb-b465-c0a729f2183e)

The 2-DOF solar panel tracking system mechanism begins by comparing the left and right photoresistor values. If the left photoresistor is greater than the right photoresistor plus a level of uncertainty (the deadband = 50), the stepper motor rotates clockwise. If the right photoresistor is greater than the left photoresistor plus a level of uncertainty, the stepper motor rotates counterclockwise. When the light source is held within the photoresistors deadband range a counter variable called ‘deadzone’ will increment. Any light source movements outside this deadband range before the counter achieves a value greater than 20 will reset deadzone to 0. If deadzone reaches a value greater than 20 (e.g. deadzone = 21), then the servomotor will sweep over a range, starting at 110° and ending at 70° in decrements of 1°, after the sweep the servomotor’s angle is set to a value in that range that gives the highest analog readings.

## Future Recommendations
Although the design was reliable and effective, incorporating additional photoresistors (e.g. four as opposed to two) would improve the accuracy of the readings for locating a light source. It would also eliminate the need for a vertical sweep and more closely mimic a high-end solar panel tracking system that detects sunlight as it changes location from morning to evening. In addition, the use of CAD modelled 3D printed parts to more appropriately model the system would help improve any instabilities or problems associated with movement of the motors as well as readings of the sensors through design of proper housing.
