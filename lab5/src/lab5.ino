/*
 * Project lab5
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D6, OUTPUT);
  pinMode(A0, INPUT);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int newValue = map(analogRead(A0), 0, 4095, 0, 255);
  analogWrite(D6, newValue);
}