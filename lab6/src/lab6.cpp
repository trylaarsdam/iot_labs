/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/Users/Nerdom/Desktop/lab6/src/lab6.ino"
#include "Adafruit_SSD1306_RK.h"
void setup();
void loop();
#line 2 "c:/Users/Nerdom/Desktop/lab6/src/lab6.ino"
SYSTEM_MODE(MANUAL);
Adafruit_SSD1306 myDisplay(128,64);
void setup(){
    pinMode(A2, INPUT);
    Serial.begin(9600);
    myDisplay.begin(SSD1306_SWITCHCAPVCC);   
}
void loop(){
    myDisplay.setTextSize(3);
    myDisplay.setTextColor(WHITE);
    myDisplay.setCursor(5,5);
    myDisplay.display();
    float currentTemp = 0;
    currentTemp = analogRead(A2);
    Serial.println(currentTemp);
    myDisplay.clearDisplay();
    float convertedTemp = (currentTemp * (3300.0/4095));
    convertedTemp = ((convertedTemp - 50)/10);
    myDisplay.println(convertedTemp);
}
