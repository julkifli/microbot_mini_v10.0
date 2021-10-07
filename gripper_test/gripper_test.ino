#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  myservo.write(90);                  // sets the servo position according to the scaled value
  delay(500);  
  myservo.write(120); // waits for the servo to get there
  delay(500);  
  myservo.write(10);
  delay(2000);  
}
