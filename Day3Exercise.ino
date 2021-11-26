int button = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int button_status;
int count = 0;
int preStatus = LOW;
int curStatus;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);

  for (int i=3; i<=7; i++)
    digitalWrite(i, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_status = digitalRead(button);
  /*if (button_status == HIGH){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }*/

  button_recieve();

  if (count == 1){
    digitalWrite(led1, HIGH);
    turnLedOFF(led1);
    count = 0;
  }
  if (count == 2){
    digitalWrite(led2, HIGH);
    turnLedOFF(led2);
    count = 0;
  }
  if (count == 3){
    digitalWrite(led3, HIGH);
    turnLedOFF(led3);
    count = 0;
  }
  if (count == 4){
    digitalWrite(led4, HIGH);
    turnLedOFF(led4);
    count = 0;
  }
  if (count == 5){
    digitalWrite(led5, HIGH);
    turnLedOFF(led5);
    count = 0;
  }
}

void button_recieve(){
  if (digitalRead(button) == HIGH){
    delay(20);
    if (digitalRead(button) == HIGH){
      count++;
    }
    while (digitalRead(button) == HIGH);
  }
}

void turnLedOFF(int led){
  for (int i=3; i<=7; i++){
    if (i == led)
      continue;
    else
      digitalWrite(i, LOW);
  }
}
