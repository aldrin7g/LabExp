const int led1 = D1;
const int led2 = D2;
const int led3 = D3;
const int led4 = D4;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void ledCtrl(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(1000);
}

void oddEven(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(1000);
}

void ledChaser(){
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);

  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led2, LOW);
   
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);

  digitalWrite(led4, HIGH);
  delay(1000);
  digitalWrite(led4, LOW);
}

void fading(){
  for(int i=0; i<256; i++){
    analogWrite(led1, i);
    analogWrite(led2, i);
    analogWrite(led3, i);
    analogWrite(led4, i);
    delay(10);
  }
  for(int i=256; i>0; i--){
    analogWrite(led1, i);
    analogWrite(led2, i);
    analogWrite(led3, i);
    analogWrite(led4, i);
    delay(10);
  }
}

void loop() {
  //ledCtrl();
  //oddEven();
  //ledChaser();
  fading();
}
