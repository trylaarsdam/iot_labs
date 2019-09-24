/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/Users/Nerdom/Desktop/lab4/src/lab1.ino"
/*
 * Project lab1
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 7 "c:/Users/Nerdom/Desktop/lab4/src/lab1.ino"
SYSTEM_MODE(MANUAL);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D6, OUTPUT);
  pinMode(D8, INPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  
  if(digitalRead(D8) == HIGH){
    if(digitalRead(D6) == HIGH){
      digitalWrite(D6, LOW);
    }
    else{
      digitalWrite(D6,HIGH);
    }
  delay(100);
}