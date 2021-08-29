/*
Julkifli Awang Besar
TB6612FNG test for Microbot 10.0
Motordriver test
 */

//Motor A
int PWMA = 5; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 4; //Direction

//Motor B
int PWMB = 6; //Speed control
int BIN1 = 8; //Direction
int BIN2 = 7; //Direction


void setup(){
//pinMode(STBY, OUTPUT);

pinMode(PWMA, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);

pinMode(PWMB, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);

delay(2000);

}

void loop(){

  forward();
  delay (2000);
  brake();
  delay(1000);
  turn_right();
  delay(200);


}

    void forward(){
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 100);  
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, 100);
    }
    
    void backward(){
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, 100);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 100);  
    }

    void turn_right(){
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 100);
    analogWrite(PWMA, 0);
    }

    void turn_left(){
    analogWrite(PWMB, 0);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, 100);
    }

    void brake(){
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    }
