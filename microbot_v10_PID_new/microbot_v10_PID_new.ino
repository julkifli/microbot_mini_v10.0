/*
MiCROBOT V1

Julkifli Awang Besar
PID for MiCROBOT MiNi

Suite with MiCROBOT MINiPCB.

*Required Pololu QTR Sensor 3.0.0 Library: https://github.com/pololu/qtr-sensors-arduino/archive/3.0.0.zip

***RBTX2021****

*/
#include <QTRSensors.h>
#define BUTTON  12

#define NUM_SENSORS 5 
#define TIMEOUT 2500 
#define EMITTER_PIN QTR_NO_EMITTER_PIN 

#define PWMA 5 //M2
#define AIN2 4 //MD22
#define AIN1 9  //MD21

#define PWMB 6 //M1
#define BIN2 8 //MD12
#define BIN1 7 //MD11

//#define motorPower 9


#define A_BaseSpeed 80
#define B_BaseSpeed 80

int PRESS;
int motorSpeed;
int error;
int position;


QTRSensorsAnalog qtra((unsigned char[]) {A0, A1 ,A2 , A3, A6} , NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS]; 

void setup() { 
  Serial.begin(9600);

  pinMode(AIN2, OUTPUT); 
  pinMode(AIN1, OUTPUT); 
  pinMode(PWMA, OUTPUT);
   
  pinMode(BIN2, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(PWMB, OUTPUT);

  pinMode(BUTTON,INPUT);

  
  int i; 
  for (int i = 0; i < 200; i++) 
    { 
    qtra.calibrate(); 
    digitalWrite(13, HIGH); delay(20); 
    
    } 
  
    //digitalWrite(motorPower, LOW);
    digitalWrite(13, LOW); 
    delay(2000); 
    
  } 
    
    
    int lastError = 0; 
    float Kp = 0.06; 
    float Kd = 4; 
    float Ki = 0.000; 
    int MotorA_Speed = 0; 
    int MotorB_Speed = 0; 
    int integral = 0;

    void loop() { 
           


      position = qtra.readLine(sensorValues); 
       
      
      //for white Line
      //unsigned int position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 1);
      
      error = position - 2000; 
 
      
      motorSpeed = Kp * error + Kd * (error - lastError)+ Ki * integral; 
      lastError = error;

      MotorA_Speed = A_BaseSpeed - motorSpeed ; 
      MotorB_Speed = B_BaseSpeed + motorSpeed ;

      if (MotorB_Speed < 0)
         MotorB_Speed = 0;
      if (MotorA_Speed < 0)
         MotorA_Speed = 0;

    
      constrain(MotorA_Speed, 0, 255); 
      constrain(MotorB_Speed, 0, 255);


      digitalWrite(AIN2, HIGH); 
      digitalWrite(AIN1, LOW); 
      analogWrite(PWMA, MotorA_Speed);
       
      digitalWrite(BIN2, HIGH); 
      digitalWrite(BIN1, LOW); 
      analogWrite(PWMB, MotorB_Speed);
    

      
      
  } 
      
      
 //************************ BASE CODE***********\\﻿

//best kp=0.06,kd=4.00 180
//best kp=0.2,kd=4.00 180
//best kp=0.2,kd=5.00 180
//best kp=0.2,kd=4.00 220
