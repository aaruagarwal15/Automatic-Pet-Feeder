# Automatic-Pet-Feeder

Through this project we want to make human life a little bit more easier. This project works on human instruction. Whenever user will give a command through the webpage to the development board used in the project, the pet feeder will be able to provide food and water to the pet after detecting that the pet had arrived at that particular area. The pet will arrive at that area when a particular noise will be made through buzzer in prior with user’s command through webpage. 

Working of the project:

In the specific project, we set the feeder to start beeping when the microcontroller used in the project ,i.e., Arduino Uno receives signal through the webpage. The instruction is given by the user through the webpage. The internet connection is provided to the project through Arduino Uno which is attached to the Ethernet shield. The Ethernet shield is connected to the laptop through LAN(Local Area Network) wire. The pet will receive instruction as soon as the buzzer beeps on the command of the user.  Once the pet comes closer to the device, the ultrasonic sensor measures the distance of the pet from the sensor and when the pet comes at the suitable distance both servo motors are triggered ,i.e., one for food and the other one for water.

Components used:

1 Arduino Uno

2 Ultrasonic sensor

3 Servo Motors

4 IC 7805

5 Ethernet Shield

6 L293D
