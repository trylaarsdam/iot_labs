/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/Users/Nerdom/Desktop/lab1/src/lab1.ino"
/*
 * Project lab1
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
void setup();
void loop();
#line 9 "c:/Users/Nerdom/Desktop/lab1/src/lab1.ino"
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D8, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  digitalWrite(D8,HIGH);
  delay(15);
  digitalWrite(D8,LOW);
  delay(15);
}