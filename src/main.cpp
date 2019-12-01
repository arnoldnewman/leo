#include <Arduino.h>

enum Direction
{
   FWD = 1,
   BACK = 2
};

// motor A
#define PWMA 6
#define AIN1 8
#define AIN2 7

// motor B
#define PWMB 9
#define BIN2 10
#define BIN1 11

class Motor{
    private:
      int ain1, ain2;
    int PWM;

    public:
        Motor(){};
    public:
    Motor(int input1, int input2, int pwmPort){
        ain1 = input1;
        ain2 = input2;
        PWM = pwmPort;
    };
    
    void moveFwd(int speed){
        digitalWrite(ain1, HIGH);
        digitalWrite(ain2, LOW);
        analogWrite(PWM, speed);
    };

    void moveBack(int speed){
        digitalWrite(ain1, LOW);
        digitalWrite(ain2, HIGH);
        analogWrite(PWM, speed);
    }

    void stop() {

    }
};

class Robot
{
   private:
   Motor m1, m2;
   int normalSpeed = 100;

public:
   Robot(Motor motor1, Motor motor2){
      m1 = motor1;
      m2 = motor2;
   }


   void moveForward(int speed){
      m1.moveFwd(speed);
      m2.moveFwd(speed);
   };


   void moveBackward(int speed){
      m1.moveBack(speed);
      m2.moveBack(speed);
   };


   void turnLeft(int k)
   {
      m1.moveBack(normalSpeed);
      m2.moveFwd(normalSpeed);
      delay(k);
      m1.stop();
      m2.stop();
   };
   void turnRight(int k){    
      m1.moveFwd(normalSpeed);
      m2.moveBack(normalSpeed);
      delay(k);
      m1.stop();
      m2.stop();
   };

   void blinkOn()
   {
      digitalWrite(LED_BUILTIN, HIGH);
   }

   void blinkOff()
   {
      digitalWrite(LED_BUILTIN, LOW);
   }
};

void setup()
{
   pinMode(PWMA, OUTPUT);
   pinMode(AIN1, OUTPUT);
   pinMode(AIN2, OUTPUT);
   pinMode(PWMB, OUTPUT);
   pinMode(BIN1, OUTPUT);
   pinMode(BIN2, OUTPUT);
}

void loop(){
   Motor m1(AIN1,AIN2,PWMA);
   Motor m2(BIN1,BIN2,PWMB);
   Robot robot(m1,m2);
   robot.turnLeft(100);
};


