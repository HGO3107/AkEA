#include <Servo.h>

//Front Motors
#define   motorFR_1     10
#define   motorFR_2     11

#define   motorFL_1     13
#define   motorFL_2     12


//Back Motors
#define   motorBR_1     7
#define   motorBR_2     8

#define   motorBL_1     4
#define   motorBL_2     2

// Create the object for the four servos
Servo frontRServo;  // front right wheel servo
Servo frontLServo;  // front left wheel servo
Servo backRServo;   // back right wheel servo
Servo backLServo;   // back left wheel servo

///////////////intialize to straight position///////////////
int frontRrotDeg = 90;

int frontLrotDeg = 180;

int backRrotDeg = 90;

int backLrotDeg = 90;
///////////////////////////////////////////////////////////


#define delayLength   300

void setup() {

  Serial.begin(9600);

  //set the pins for the servos
  frontRServo.attach(3);
  frontLServo.attach(5);
  backRServo.attach(9);
  backLServo.attach(6);
  
  pinMode(motorFR_1, OUTPUT);
  pinMode(motorFR_2, OUTPUT);

  //set front motors to off state
  digitalWrite(motorFR_1, LOW);
  digitalWrite(motorFR_2, LOW);

  pinMode(motorFL_1, OUTPUT);
  pinMode(motorFL_2, OUTPUT);

  //set the Front Left motor to off state
  digitalWrite(motorFL_1, LOW);
  digitalWrite(motorFL_2, LOW);

  pinMode(motorBR_1, OUTPUT);
  pinMode(motorBR_2, OUTPUT);
  
  //set back right motors to off state
  digitalWrite(motorBR_1, LOW);
  digitalWrite(motorBR_2, LOW);

  pinMode(motorBL_1, OUTPUT);
  pinMode(motorBL_2, OUTPUT);

  //set the back left motor to off state
  digitalWrite(motorBL_1, LOW);
  digitalWrite(motorBL_2, LOW);
  

  
  servoCont('T'); //initialize the servo position to straight
}


void loop() {

  ////////////////Changing Motor Direction////////////
  //check for the char sent from RC                 //
  ////////////////////////////////////////////////////
  
  if(Serial.available())
  {

    char val = Serial.read();
    
    if(val == 'F' || val == 'B' || val == 'Z' || val == 'L' || val == 'R') // check if the command send is for the car wheel
    {
      
      Serial.write(val);
      motorDir(val); //change char direction either reverse or forward

    }else 
    {
      servoCont(val);
      Serial.write(val);
    }
   }

   stopMotors();
}


void motorDir(char dir)
{
  
  switch(dir)
  {
    case 'B':
      //Front Right Wheel
      digitalWrite(motorFR_1, LOW);
      digitalWrite(motorFR_2, HIGH);

      //back right wheel
      digitalWrite(motorBR_1, LOW);
      digitalWrite(motorBR_2, HIGH);
      
      //Front Left Wheel
      digitalWrite(motorFL_1, LOW);
      digitalWrite(motorFL_2, HIGH);


      //back Left Wheel
      digitalWrite(motorBL_1, LOW);
      digitalWrite(motorBL_2, HIGH);
      

      delay(delayLength);
      
      break;
      
    case 'F':
  
      //Front Right Wheel
      digitalWrite(motorFR_1, HIGH);
      digitalWrite(motorFR_2, LOW);

      //back right wheel
      digitalWrite(motorBR_1, HIGH);
      digitalWrite(motorBR_2, LOW);
      
      //Frnt LEft Wheel
      digitalWrite(motorFL_1, HIGH);
      digitalWrite(motorFL_2, LOW);


      //back Left Wheel
      digitalWrite(motorBL_1, HIGH);
      digitalWrite(motorBL_2, LOW);

      delay(delayLength);
      
      break;

   case 'Z': //360 spot turn
  
      //Front Right Wheel
      digitalWrite(motorFR_1, HIGH);
      digitalWrite(motorFR_2, LOW);



      //back Left Wheel
      digitalWrite(motorBL_1, LOW);
      digitalWrite(motorBL_2, HIGH);
      
      //front left Wheel
      digitalWrite(motorFL_1, LOW);
      digitalWrite(motorFL_2, HIGH);


      //back right Wheel
      digitalWrite(motorBR_1, HIGH);
      digitalWrite(motorBR_2, LOW);

      delay(delayLength);
      
      break;


    case 'L':
  
      //Front Right Wheel
      digitalWrite(motorFR_1, HIGH);
      digitalWrite(motorFR_2, LOW);
      
      //Frnt LEft Wheel
      digitalWrite(motorFL_1, LOW);
      digitalWrite(motorFL_2, HIGH);


      //back right wheel
      digitalWrite(motorBR_1, LOW);
      digitalWrite(motorBR_2, HIGH);
      
      //back Left Wheel
      digitalWrite(motorBL_1, HIGH);
      digitalWrite(motorBL_2, LOW);

      delay(delayLength);
      
      break;


   case 'R':
  
      //Front Right Wheel
     
      //Front Right Wheel
      digitalWrite(motorFR_1, LOW);
      digitalWrite(motorFR_2, HIGH);
      
      //Frnt LEft Wheel
      digitalWrite(motorFL_1, HIGH);
      digitalWrite(motorFL_2, LOW);


      //back right wheel
      digitalWrite(motorBR_1, HIGH);
      digitalWrite(motorBR_2, LOW);
      
      //back Left Wheel
      digitalWrite(motorBL_1, LOW);
      digitalWrite(motorBL_2, HIGH);

      delay(delayLength);
      
      
      break;
}
  
  //////stop motor after 1 sec/////
  /////// front motors
  
  digitalWrite(motorFR_1, LOW);
  digitalWrite(motorFR_2, LOW);

  /////// Back motors
  digitalWrite(motorFL_1, LOW);
  digitalWrite(motorFL_2, LOW);

  ///////////////////////////////////
  
}

void servoCont(char dir)
{

  switch(dir)
  {
    
    case 'T': //straight turn
              frontRrotDeg = 150;
              frontLrotDeg = 80;
              backRrotDeg = 0;
              backLrotDeg = 90;
              break;
              
     
     case 'X': //right turn
              frontRrotDeg = 50;
              frontLrotDeg = 180;
              backRrotDeg = 90;
              backLrotDeg = 0;
              break;

     case 'M': //360 turning short radius
              frontRrotDeg = 90; 
              frontLrotDeg = 150; 
              backRrotDeg = 45;
              backLrotDeg = 45;
              break;

      case 'K': // |/ turn 30 deg right.
              frontRrotDeg = 180; 
              frontLrotDeg = 120; 
              break;

      case 'J':
              frontRrotDeg = 100;  // 
              frontLrotDeg = 50;  //
              break;
  }


  frontRServo.write(frontRrotDeg);                  // sets the servo position according to the scaled value
  frontLServo.write(frontLrotDeg);
  backRServo.write(backRrotDeg);
  backLServo.write(backLrotDeg);
  
  delay(15);                                        // waits for the servo to get there

}



void stopMotors()
{
        //Front Right Wheel
      digitalWrite(motorFR_1, LOW);
      digitalWrite(motorFR_2, LOW);

      //back right wheel
      digitalWrite(motorBR_1, LOW);
      digitalWrite(motorBR_2, LOW);
      
      //Front Left Wheel
      digitalWrite(motorFL_1, LOW);
      digitalWrite(motorFL_2, LOW);


      
      //back Left Wheel
      digitalWrite(motorBL_1, LOW);
      digitalWrite(motorBL_2, LOW);
}
