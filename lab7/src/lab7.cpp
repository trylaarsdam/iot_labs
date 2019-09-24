/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/Users/Nerdom/Desktop/lab7/src/lab7.ino"
#include <blynk.h>
void setup();
void loop();
#line 2 "c:/Users/Nerdom/Desktop/lab7/src/lab7.ino"
void setup() {
  Blynk.begin("f337d291e55f486baed34896ab9c65d5",IPAddress(167,99,150,124),8080);
  pinMode(D8,INPUT);
  pinMode(D6,OUTPUT);
}

void loop() {
  Blynk.run();
  if(digitalRead(D8) == LOW){
    Blynk.notify("Motion Detected!");
    digitalWrite(D6, HIGH);
  }
  else{
    digitalWrite(D6, LOW);
  }
}