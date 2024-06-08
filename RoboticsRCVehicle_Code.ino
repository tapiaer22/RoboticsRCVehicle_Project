#include <Servo.h> //define the servo library
#include <math.h> 

Servo ssm; //define that ssm (steering servo motor) is a servo
Servo esc; //define that esc is (similar to) a servo

#define trigPin1 11  // Trig for sensor 1
#define echoPin1 10  // Echo for sensor 1
#define trigPin2 9  // Trig for sensor 2
#define echoPin2 8  // Echo for sensor 2
#define trigPin3 7  // Trig for sensor 3
#define echoPin3 6  // Echo for sensor 3
#define trigPin4 5  // Trig for sensor 4
#define echoPin4 4  // Echo for sensor 4
#define trigPin5 3  // Trig for sensor 5
#define echoPin5 2  // Echo for sensor 5
#define trigPin6 23  // Trig for sensor 6
#define echoPin6 22  // Echo for sensor 6

float duration, distance;
float distance1, distance2, distance3, distance4, distance5, distance6;

int steering=90,velocity=101; //defining values that we'll use later
int driving_trig = 1;

int i = 1;
int j = 1;

void setup() 
{
  pinMode(trigPin1, OUTPUT);  //Set the trigPin1 as output
  pinMode(echoPin1, INPUT);   //Set the echoPin1 as input
  pinMode(trigPin2, OUTPUT);  //Set the trigPin2 as output
  pinMode(echoPin2, INPUT);   //Set the echoPin2 as input
  pinMode(trigPin3, OUTPUT);  //Set the trigPin3 as output
  pinMode(echoPin3, INPUT);   //Set the echoPin3 as input
  pinMode(trigPin4, OUTPUT);  //Set the trigPin4 as output
  pinMode(echoPin4, INPUT);   //Set the echoPin4 as input
  pinMode(trigPin5, OUTPUT);  //Set the trigPin5 as output
  pinMode(echoPin5, INPUT);   //Set the echoPin5 as input
  pinMode(trigPin6, OUTPUT);  //Set the trigPin6 as output
  pinMode(echoPin6, INPUT);   //Set the echoPin6 as input

  ssm.attach(13); //define that ssm is connected at pin 12, steering
  esc.attach(12); //define that esc is connected at pin 13, driving
  driving_trig = 1;
  
  //****************** Vehicle Initialization ********************//
  //***************** Do not change below part *****************//
  esc.write(90); 
  delay(1000);
  //***************** Do not change above part *****************//
  Serial.begin(9600); // Starts the serial communication, Serial communications at 57600 bps
}


void loop() 
{
//***************** Do not change below part *****************//
  if (driving_trig == 1)
  {
    setVehicle(120,95);
    delay(1000);
    driving_trig = 10;   
  }
//***************** Do not change above part *****************//
//******Please input the code of your approaches/algorithms in the below area*****************//

  FindRange(trigPin1, echoPin1);
  distance1 = distance;
  FindRange(trigPin2, echoPin2);
  distance2 = distance;
  FindRange(trigPin3, echoPin3);
  distance3 = distance;
  FindRange(trigPin4, echoPin4);
  distance4 = distance;
  FindRange(trigPin5, echoPin5);
  distance5 = distance;
  FindRange(trigPin6, echoPin6);
  distance6 = distance;
  
  //Stop Car
  if(distance3 <= 35 && distance4 <=35){
    stopVehicle();
    delay(300);
  }
  //Forward
  else {
    accelerateVehicle();
  }
  //Turn
  if( ((distance1 + distance2) - (distance5 + distance6) < -10 )){//Turn Right
    turnVehicleR();
  }
  else if( ((distance1 + distance2) - (distance5 + distance6) > 10)){//Turn Left
    turnVehicleL();
  }
  else{//Turn straight
    steering = 90;
  }

  setVehicle(steering,velocity);
  Serial.println((distance1 + distance2) - (distance5 + distance6));
  delay(300);
}

//******Please input the code of your approaches/algorithms in the above area*****************************
//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************

//******!!!!!!!!!Please don't change any code below!!!!!!!***********************************
//******!!!!!!!!!Please don't change any code below!!!!!!!***********************************
//******************************************************************************************* 
//***************** Do not change below part *****************//
void setVehicle(int s, int v) 
{
  //********************** Vehicle Control **********************//
  if ((s>=0 && s<=180) && (v>=0&&v<=180))
  {  
    ssm.write(s); //write steering value to steering servo
    esc.write(v); //write velocity value to the ESC unit
  }
  else{}
}
//Actions of vehicle------------------------------
//Stop vehicle
void stopVehicle(){
  velocity = 90;
}
//Move forward
void accelerateVehicle(){
  velocity = 101;
}
//-----------Turn-------------
//Turn Right
void turnVehicleR(){
  steering = 120; 
}
//Turn Left

void turnVehicleL(){
  steering = 60; 
}
//------------------------------------------------
void FindRange(int trigPin, int echoPin) 
{
  //Trigger the sensor by sending a HIGH pulse of 10 microseconds. But, before that, give a short LOW pulse to ensure you’ll get a clean HIGH pulse
  digitalWrite(trigPin, LOW); // Send out a Low trigger
  delayMicroseconds(2); // Wait 2 ms
  digitalWrite(trigPin, HIGH); // Send out a High trigger
  delayMicroseconds(10); // Wait 10 ms
  digitalWrite(trigPin, LOW);  //Send out a Low trigger.
  duration = pulseIn(echoPin, HIGH); //Read the HIGH pulse whose duration is the time (in microseconds) from the sending of the ping to the reception of its echo off of an object.
  distance = (duration / 2) * 0.03435; //Sound speed = 0.03435cm/ct
}
//***************** Do not change above part *****************//