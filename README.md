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

**Multiverse of Scenarions**: There are a massive amounts of scenarios on how the car would or should move. For the sake of this project, we focused on fundamental scenarios that the car should react. A set of solutions were developed and led to successful results in the project.

### Vehicle Steering
**Steering Left and Right**: the vehicle should turn only when it detects a distance that is too close to one of its sides. For example, if a vehicle it too close to the left, it should avoid a collision by turning right. Analogously, the vehicle should turn left if it is too close to the right. To solve this problem, add the distances from each side:

+ `distance1` + `distance2` = sum of distance on left<br>
+ `distance5` + `distance6` = sum of distance on right<br>

>Note: It is better to avoid dividing by 2 to decrease the number of operations, which could slow down the vehicle reaction time

Based on the results of some testing, it was concluded that the safe distance would be 5cm. In the model, that would imply the following:

+ Safe distance on sides: `distance1` + `distance2` < 10<br>(The same applies to `distance5` and `distance6`)<br>

+ If the obstacle crosses the safe distance --> turn on the other side<br>

**Steering Angle**: Using degrees, notice that the angle to go straight is 90. In order to turn left, the angle has to be less than 90, and to turn right the angle has to be greater than 90. The question is by how many degrees should the vehicle turn? this varies based on the vehicle's `distance` to an obstacle and the vehicle's `velocity`. For the sake of this project, the change in angle will be 30 to either side.

+ If we want to turn left --> set angle to 90 - 30 = 60<br>
+ If we want to turn right --> set angle to 90 + 30 = 120<br>

**Model of Vehicle's Safe Area**: It was necessary to establish a vehicle's safe area. The codee was designed so that if an obstacle is detected WITHIN the safe aream then the vehicle has to take action to avoid it.

(Image of model here) 
  
### Challenges



