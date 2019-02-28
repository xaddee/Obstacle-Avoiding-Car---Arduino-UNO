# Obstacle Avoiding Car - Arduino UNO

A car build from scratch and programmed with Arduino to avoid obstacles.

# Components Used:
- Arduino UNO x1
- Breadboard x1
- Ultrasonic Sensor x2
- DC Motor x2
- L293D Motor driver x1
- 9V battery x1
- 1.5V battery x4
- Battery holder x1
- Support for the ultrasonic sensor x2
- Wheels x2
- Wires (a lot)
- Switch button x1

# Logic of the car

The car has two ultrasonic sensors used for detecting objects in front and to the left of it. If an object was detected at 30cm or less, the car stops and then turns to the left if there is no other object blocking it. If there is an object, it turns to the right. It also has the ability to go backwards if an objects is closer than 15cm.

Example video: https://www.youtube.com/watch?v=sEzWbl8gvcE
