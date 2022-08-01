


// Libraries for the project
#include<Servo.h>


// Motor of the thrusters
int motorPropeller1 = 3;
//int motorPropeller2 = 2;


// Servos of the shield chassis
Servo servoAxis1;
Servo servoAxis2;


// Servos for control the direction
Servo servoDirection1;
Servo servoDirection2;


// The Joystick parameters for control the direction
int angleX = 0;
int axis_X1 = A1;


// The Joystick parameters for the speed of the machine
int angleY = 0;
int axis_Y2 = A2; 


// Led's for indicate where it is
int ledRed1 = 22;
int ledRed2 = 23;
int ledGreen1 = 24;
int ledGreen2 = 25;


// Led's for night vision
int ledWhite1 = 26;
int ledWhite2 = 27;


// Botton for turn the shield Axis
int botton1 = 11;
int statusbotton1 = 0;


// Set the pins for the light intensity sensor
int sensorLight = A0;
int valueSensorLight = 0;







void setup() {

  // Set up the pins of the Servos 
  servoAxis1.attach(5);
  servoAxis2.attach(6);
  servoDirection1.attach(9);
  servoDirection2.attach(10);


  // Set up the Led's pins 
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledWhite1, OUTPUT);
  pinMode(ledWhite2, OUTPUT);


  // Set up the motor's pins
  pinMode(motorPropeller1, OUTPUT);
  //pinMode(motorPropeller2, OUTPUT);


  // Set up the pins of the Bottons for the Axis
  pinMode(botton1, INPUT);


  // Set up the pins of the sensor Light intensity
  pinMode(sensorLight, INPUT);
  Serial.begin(9600);


  // Set up the pins of the Joystick
  pinMode(axis_Y2, INPUT);
  pinMode(axis_X1, INPUT);
  
  
}






void loop() {

  //digitalWrite(motorPropeller1, HIGH);
  
  // Value to the status of the botton
  statusbotton1 = digitalRead(botton1);


  // Value to the sensor light intensity
  valueSensorLight = analogRead(sensorLight);
  
  

  // Give the value of angle to 'angle1'
  angleX = analogRead(axis_X1);


  // Give the value of angle2 for speed
  angleY = analogRead(axis_Y2);
  Serial.println(angleX);
  Serial.println(angleY);


  // Conditional for known if I press the botton
  if(statusbotton1 == LOW){
    servoAxis1.write(180);
    servoAxis2.write(180);
    }else {
      servoAxis1.write(0);
      servoAxis2.write(0);
      }

      
  // Turn on the lights according to the light value
  digitalWrite(ledWhite1, HIGH);
  digitalWrite(ledWhite2, HIGH);
  digitalWrite(ledRed1, HIGH);
  digitalWrite(ledRed2, HIGH);
  delay(500);
  digitalWrite(ledRed1, LOW);
  digitalWrite(ledRed2, LOW);
  delay(1000);
  digitalWrite(ledGreen1, HIGH);
  digitalWrite(ledGreen2, HIGH);
  delay(500);
  digitalWrite(ledGreen1, LOW);
  digitalWrite(ledGreen2, LOW);

  
  // Take the angle of the first joystick for change of the direction
  servoDirection1.write(angleX);
  servoDirection2.write(angleX);

  
  // Take the angle of the second joystick for change the speed
  digitalWrite(motorPropeller1, 1000-(angleY / 2));
  //digitalWrite(motorPropeller2, 1000-(angleY / 2));
  



}
