//CONTROLLER ONE
// motor set one
int CNT1_enA = 10;
int CNT1_in1 = 9;
int CNT1_in2 = 8;
// motor set two
int CNT1_enB = 5;
int CNT1_in3 = 7;
int CNT1_in4 = 6;

int magnet_pin = 2;

//char buffer[];

void setup(){
  //CONTROLLER ONE
  pinMode(CNT1_enA, OUTPUT);
  pinMode(CNT1_enB, OUTPUT);
  pinMode(CNT1_in1, OUTPUT);
  pinMode(CNT1_in2, OUTPUT);
  pinMode(CNT1_in3, OUTPUT);
  pinMode(CNT1_in4, OUTPUT);

  Serial.begin(9600);
}


//void line_processer(line);{

void magnet(int speed){
  if (speed == 1){
    digitalWrite(magnet_pin, HIGH);
  }
  
  else if(speed == 0){
    digitalWrite(magnet_pin, LOW);
  }
}
  

void left(int speed){
  Serial.println("left bro");
  digitalWrite(CNT1_in1, LOW);
  digitalWrite(CNT1_in2, HIGH);
  
  digitalWrite(CNT1_in3, HIGH);
  digitalWrite(CNT1_in4, LOW);

  analogWrite(CNT1_enA, speed);
  analogWrite(CNT1_enB, speed);
}

void right(int speed){
  Serial.println("right bro");
  digitalWrite(CNT1_in1, HIGH);
  digitalWrite(CNT1_in2, LOW);

  digitalWrite(CNT1_in3, LOW);
  digitalWrite(CNT1_in4, HIGH);

  analogWrite(CNT1_enA, speed);
  analogWrite(CNT1_enB, speed);
}

void forward(int speed){
  Serial.println("forward");
  digitalWrite(CNT1_in1, HIGH);
  digitalWrite(CNT1_in2, LOW);
  
  digitalWrite(CNT1_in3, HIGH);
  digitalWrite(CNT1_in4, LOW);
  
  analogWrite(CNT1_enA, speed);
  analogWrite(CNT1_enB, speed);
}

void backward(int speed){
  Serial.println("backwards");
  digitalWrite(CNT1_in1, LOW);
  digitalWrite(CNT1_in2, HIGH);
  
  digitalWrite(CNT1_in3, LOW);
  digitalWrite(CNT1_in4, HIGH);
  
  analogWrite(CNT1_enA, speed);
  analogWrite(CNT1_enB, speed);
}

void loop(){
  
  //Serial.readBytesUntil("\n", buffer, 20)
    
  boolean cmd_left = Serial.find("left", 4);
  if (cmd_left == true){
    int speed = Serial.parseInt();
    left(speed);
  }
    
  boolean cmd_right = Serial.find("right", 5);
  if (cmd_right == true){
    int speed = Serial.parseInt();
    right(speed);
  }
  
  boolean cmd_forward = Serial.find("forward", 7);
  if (cmd_forward == true){
    int speed = Serial.parseInt();
    forward(speed);
  }
    
  boolean cmd_backward = Serial.find("backward", 8);
  if (cmd_backward == true){
    int speed = Serial.parseInt();
    backward(speed);
  }
  
}



