#include <Arduino.h>

//Configure these to fit your design...

// motor A
#define PWMA 6
#define AIN1 8
#define AIN2 7


// motor B
#define PWMB 9
#define BIN2 10
#define BIN1 11 



void setup(){

 pinMode(PWMA,OUTPUT);
 pinMode(AIN1,OUTPUT);
 pinMode(AIN2,OUTPUT);
 pinMode(PWMB,OUTPUT);
 pinMode(BIN1,OUTPUT);
 pinMode(BIN2,OUTPUT);
 
}



void test(){

   
   digitalWrite(AIN1,HIGH);
   digitalWrite(AIN2,LOW);
   analogWrite(PWMA,250);

   delay(1000);
   digitalWrite(LED_BUILTIN,HIGH);
   delay(1000);
   digitalWrite(LED_BUILTIN,LOW);
   digitalWrite(AIN1,LOW);
   digitalWrite(AIN2,LOW);
   delay(1000);
}



void moveForward(){

   digitalWrite(AIN1,HIGH);
   digitalWrite(AIN2,LOW);

   digitalWrite(BIN1,HIGH);
   digitalWrite(BIN2,LOW);
   analogWrite(PWMA,250);
   analogWrite(PWMB,250);
}


void stop(){

   digitalWrite(AIN1,HIGH);
   digitalWrite(AIN2,LOW);

   digitalWrite(BIN1,HIGH);
   digitalWrite(BIN2,LOW);
   analogWrite(PWMA,0);
   analogWrite(PWMB,0);
}


void blinkOn(){
      digitalWrite(LED_BUILTIN,HIGH);
}

void blinkOff(){
      digitalWrite(LED_BUILTIN,LOW);
}


void loop(){
   blinkOn();
   moveForward();
   delay(1000);
   blinkOff();
   stop();
   delay(2000);
}

