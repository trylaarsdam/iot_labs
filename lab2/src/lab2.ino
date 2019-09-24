/*
 * Project lab1
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
   pinMode(D8, OUTPUT);
    pinMode(A4, INPUT);
  Serial.begin(9600);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  float value = analogRead(A4);
  Serial.println(value);
  digitalWrite(D8,HIGH);
  delay(value);
  digitalWrite(D8,LOW);
  delay(value);
}