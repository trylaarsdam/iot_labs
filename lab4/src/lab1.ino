SYSTEM_MODE(MANUAL);
void setup() {
  pinMode(D6, OUTPUT);
  pinMode(D8, INPUT);
}
void loop() {
  if(digitalRead(D8) == HIGH){
    if(digitalRead(D6) == HIGH){
      digitalWrite(D6, LOW);
    }
    else{
      digitalWrite(D6,HIGH);
    }
  delay(100);
}