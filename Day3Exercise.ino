int button = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int button_status = LOW;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);
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

  if (digitalRead(button) == HIGH){
    while (digitalRead(button) == HIGH);
    count++;
    
    if (count == 1)
      ledControl(led1);
    else if (count == 2)
      ledControl(led2);
    else if (count == 3)
      ledControl(led3);
    else if (count == 4)
      ledControl(led4);
    else if (count == 5)
      ledControl(led5);
    else if (count == 6){
      for (int i=3; i<=7; i++)
        digitalWrite(i, LOW);
      count = 0;
    }
  }
}

void ledControl(int led){
  for (int i=3; i<=7; i++){
    if (i == led)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}
