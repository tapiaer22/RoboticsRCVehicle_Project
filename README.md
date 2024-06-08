# RoboticsRCVehicle_Project

## Tools
* 1 Racing Car (RC 1/10th Car)
* 1 Servo (for steering control)
* 6 Ultrasonic Sensors HC-SR04 (for detecting distance)
* 1 Arduino MEGA2560 (for code and processing)
* 1 DC motor (speed control)

## Code file
[Code in C++](RoboticsRCVehicle_Code.ino)

## Code explanation
### Vehicle Stopping Distance
**Margin Error on Distance**: Based on some testing with the distance sensors, there was a margin error of 0.2cm. 

<strong>Velocity</strong>: With respect to the vehicle's velocity, it was concluded that keeping the variable `velocity` at 101 was safe enough for the vehicle to react on time and change trajectory.

**Stopping Distance**: After testing the front sensors with `velocity` at 101, the RC Car is able to safely stop without causing a collision once it detects an obstacle that is within 45cm of distance. The variables for the front sensors are `distance3` and `distance4`.

**Multiverse of Scenarions**: There are a massive amounts of scenarios on how the car would or should move. For the sake of this project, we focused on fundamental scenarios that the car should react. A set of solutions were developed and led to successful results.

### Vehicle Steering

### Challenges



