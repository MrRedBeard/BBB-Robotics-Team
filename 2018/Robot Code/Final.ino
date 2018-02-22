//#include <Servo.h>
//Servo myservo; // create servo object to control a servo
//int servoPos = 0;


// connect motor controller pins to Arduino digital pins
// motor one
int enA = 7;
int in1 = 8;
int in2 = 9;
// motor two
int in3 = 10;
int in4 = 11;
int enB = 12;
int motorSpeed = 150;

int magnet = 3;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(magnet, OUTPUT);
  //myservo.attach(5);
  
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop()
{
  if(Serial.available()>0)//Checking is Serial data available
  {
    int input = Serial.read(); //Storing value of read data into variable assigned
      if(input != 83)
      {
        Serial.println(input);
      }
    switch(input)
    {
      case 48 : motorSpeed = 150;
      break;
      case 49 : motorSpeed = 160;
      break;
      case 50 : motorSpeed = 170;
      break;
      case 51 : motorSpeed = 180;
      break;
      case 52 : motorSpeed = 190;
      break;
      case 53 : motorSpeed = 200;
      break;
      case 54 : motorSpeed = 210;
      break;
      case 55 : motorSpeed = 220;
      break;
      case 56 : motorSpeed = 230;
      break;
      case 57 : motorSpeed = 240;
      break;
      case 113 : motorSpeed = 255;
      break;
 
      case 70 : moveF();
      break;
      case 82 : moveR();
      break;
      case 76 : moveL();
      break;
      case 66 : moveB();
      break;
      case 83 : stopAll();
      break;
      case 87 : armUp();
      break;
      case 119 : armUp();
      break;
      case 85 : armDown();
      break;
      case 117 : armDown();
      break;
      default : stopAll();
      break;
    }
  }
delay(1);

}


void armUp()
{
  digitalWrite(magnet, HIGH);
//  for (servoPos >= 0; servoPos <= 180; servoPos += 1)
//  {
//    myservo.write(servoPos);
//  }
}
void armDown()
{
  digitalWrite(magnet, LOW);
//  for (servoPos <= 180; servoPos >= 0; servoPos -= 1)
//  {
//  myservo.write(servoPos);
//  }
}


void moveF()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, motorSpeed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, motorSpeed);
}

void moveB()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, motorSpeed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, motorSpeed);
}

void moveR()
{
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveL()
{
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopAll()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
