 #include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4.
Adafruit_DCMotor *motorRearLeft = AFMS.getMotor(1);
Adafruit_DCMotor *motorRearRight = AFMS.getMotor(2);
Adafruit_DCMotor *motorFrontRight = AFMS.getMotor(3);
Adafruit_DCMotor *motorFrontLeft = AFMS.getMotor(4);

// PIN tracker sensors
#define Right_Intersection      11
#define Left_Intersection       12
#define leftTrackerLeft         6
#define leftTrackerCenter       7
#define leftTrackerRight        8

//#define rightTrackerLeft       11 
//#define rightTrackerCenter     12 
//#define rightTrackerRight      13 

// PIN tracker sensors

#define trigPin                 9  //Ultrasonic TRIG
#define echoPin                 10 //Ultrasonic ECHO

// defines variables
long duration;
int distance;
int cm;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  //pinMode(rightTrackerLeft, INPUT); //Tracker
  //pinMode(rightTrackerCenter, INPUT); //Tracker
  //pinMode(rightTrackerRight, INPUT); //Tracker
  
  pinMode(leftTrackerLeft, INPUT); //Tracker
  pinMode(leftTrackerCenter, INPUT); //Tracker
  pinMode(leftTrackerRight, INPUT); //Tracker
  
}
unsigned int time_us=0;
unsigned int distance_sm=0;


void loop() {
  int DigitalValue = digitalRead(12);
  Serial.println(DigitalValue);
Serial.println(11);
Serial.println(distance);
scanPlace();
AFMS.begin();

if (digitalRead(12)) {
      do {
        turnLeft2();
        }
        while (digitalRead(6));
    }
    else if (digitalRead(11)) {
      do {
        turnRight2();
        }
        while (digitalRead(6));
    }
if ((!digitalRead(6)) && (!digitalRead(7)) && (!digitalRead(8))) {
  stopMotor(); 
}
 
else if ((digitalRead(7)) && (distance > 15))  {
    startMotor();
     if ((distance < 15) || (!digitalRead(7))) {
      stopMotor();
    }
    
    
}
else if (digitalRead(6)){
    turnLeft2();
    }
    
else if (digitalRead(8)) {
      turnRight2();
    }

    
else if ((digitalRead(6)) && (digitalRead(7))) {
      turnRight2();
    }
    
else if ((digitalRead(8)) && (digitalRead(7))) {
      turnLeft2();
    }   
    
    
/*else {
  for (int i=40; i<=180; i=i+10){
      turnLeft2(); //???????????????????????????? Передача параметра функции
      digitalWrite(Trig, HIGH);
      // delayMicroseconds(10);
      digitalWrite(Trig, LOW);
      time_us=pulseIn(Echo, HIGH);
      distance_sm=time_us/58;
      if (distance_sm<20){
          startMotor();
      }
  }
  }*/
}


void scanPlace() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  
   
}

void startMotor() {
  motorRearLeft->setSpeed(65); // 0...255
  motorRearLeft->run(FORWARD);
  motorRearRight->setSpeed(65); // 0...255
  motorRearRight->run(FORWARD);
  motorFrontRight->setSpeed(65); // 0...255
  motorFrontRight->run(FORWARD);
  motorFrontLeft->setSpeed(65); // 0...255
  motorFrontLeft->run(FORWARD);
}

void stopMotor() {
   motorRearLeft->setSpeed(0); // 0...255
   motorRearLeft->run(RELEASE);
   motorRearRight->setSpeed(0); // 0...255
   motorRearRight->run(RELEASE);
   motorFrontRight->setSpeed(0); // 0...255
   motorFrontRight->run(RELEASE);
   motorFrontLeft->setSpeed(0); // 0...255
   motorFrontLeft->run(RELEASE);
}

void turnRight(){
  motorRearLeft->setSpeed(100);
  motorRearLeft->run(FORWARD);
  motorFrontRight->setSpeed(150);
  motorFrontRight->run(BACKWARD);
}

void turnLeft(){
  motorFrontLeft->setSpeed(100);
  motorFrontLeft->run(BACKWARD);
  motorRearRight->setSpeed(100);
  motorRearRight->run(FORWARD);
}

void turnLeft2(){
  motorFrontLeft->setSpeed(190);
  motorFrontLeft->run(BACKWARD);
  motorFrontRight->setSpeed(190);
  motorFrontRight->run(FORWARD);
  motorRearLeft->setSpeed(190);
  motorRearLeft->run(BACKWARD);
  motorRearRight->setSpeed(190);
  motorRearRight->run(FORWARD);
}

void turnRight2(){
  motorFrontRight->setSpeed(190);
  motorFrontRight->run(BACKWARD);
  motorFrontLeft->setSpeed(190);
  motorFrontLeft->run(FORWARD);
  motorRearRight->setSpeed(190);
  motorRearRight->run(BACKWARD);
  motorRearLeft->setSpeed(190);
  motorRearLeft->run(FORWARD);
}
