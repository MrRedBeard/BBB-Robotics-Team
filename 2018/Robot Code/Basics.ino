

int t = 500;

#define flin1 7
#define flin2 8
#define frin3 9
#define frin4 10

void setup()
{


  pinMode(flin1, OUTPUT);
  pinMode(flin2, OUTPUT);
  pinMode(frin3, OUTPUT);
  pinMode(frin4, OUTPUT);

  
}

void loop()
{

  robotBackward(10);

  robotStop();

  robotForward(10);

  robotStop();

  robotRight(10);

  robotStop();

  robotLeft(10);

  robotStop();

}


void robotStop() {
  digitalWrite(flin1, LOW);
  digitalWrite(flin2, LOW);
  digitalWrite(frin3, LOW);
  digitalWrite(frin4, LOW);

  delay(t);
}

void robotForward(int t) {
  digitalWrite(flin1, LOW);
  digitalWrite(flin2, HIGH);
  digitalWrite(frin3, LOW);
  digitalWrite(frin4, HIGH);
  
  delay(t);
}

void robotBackward(int t) {
  digitalWrite(flin1, HIGH);
  digitalWrite(flin2, LOW);
  digitalWrite(frin3, HIGH);
  digitalWrite(frin4, LOW);
  
  delay(t);
}

void robotLeft(int t) {

  digitalWrite(flin1, LOW);
  digitalWrite(flin2, HIGH);
  digitalWrite(frin3, HIGH);
  digitalWrite(frin4, LOW);
  
  delay(t);
}

void robotRight(int t) {
  digitalWrite(flin1, HIGH);
  digitalWrite(flin2, LOW);
  digitalWrite(frin3, LOW);
  digitalWrite(frin4, HIGH);

  delay(t);
}




