/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/Users/Nerdom/Desktop/final-lab/src/final-lab.ino"
#include <blynk.h>
#include <Adafruit_SSD1306_RK.h>

//definitions
void send_temp();
void app_sync();
void calc_temp();
void evening_lux();
void lux_updater();
void night_lux();
void state_test();
void setup();
void loop();
#line 5 "c:/Users/Nerdom/Desktop/final-lab/src/final-lab.ino"
#define TEMP_SENSOR_INPUT A1
#define LUX_SENSOR_INPUT A2
#define RED_LED_OUTPUT D2
#define GREEN_LED_OUTPUT D3
#define BLUE_LED_OUTPUT D4
#define blynk_virtual_button V0
#define blynk_red_zergba V2
#define blynk_green_zergba V3
#define blynk_blue_zergba V4
#define blynk_temp_readout V1
//global variables
float currentTemp = 0;
float convertedTemp = 0; 
bool night_state = false;
float lux_level = 0;
float lux_alert_threshold = 1000.0;
uint16_t blynk_red = 0; //blynk read variables
uint16_t blynk_green = 0; //these are updated continously in app_sync()
uint16_t blynk_blue = 0;
bool blynk_buttonState = FALSE; //for the state trigger

//blynk other stuff (from the api, still no clue how this works, imo it is counter intuitive)
BLYNK_WRITE(blynk_virtual_button) //button for mode switching
{
  blynk_buttonState = param.asDouble();
}
BLYNK_WRITE(blynk_red_zergba) //red part of zeRGBa
{
  blynk_red = param.asInt(); 
}
BLYNK_WRITE(blynk_green_zergba) //green part of zeRGBa
{
  blynk_green = param.asInt();
}
BLYNK_WRITE(blynk_blue_zergba) //blue part of zeRGBa
{
  blynk_blue = param.asInt();
}

//screen crap
Adafruit_SSD1306 myDisplay(128, 64);

//abusing the blynk library instead of writing a function to time things
BlynkTimer timer;

void send_temp() {
  /* float currentTemp = 0;
  currentTemp = analogRead(TEMP_SENSOR_INPUT);
  float convertedTemp = (currentTemp * (3300.0/4095));
  convertedTemp = ((convertedTemp - 50)/10);*/
  Blynk.virtualWrite(blynk_temp_readout, convertedTemp);
}

void app_sync() {
  Blynk.syncAll();
}

void calc_temp() {
  myDisplay.setTextSize(3);
  myDisplay.setTextColor(WHITE);
  myDisplay.setCursor(5,5);
  myDisplay.display();
  convertedTemp = (currentTemp * (3300.0/4095));
  currentTemp = analogRead(TEMP_SENSOR_INPUT);
  Serial.println(currentTemp);
  convertedTemp = ((convertedTemp - 50)/10);
  myDisplay.clearDisplay();
  myDisplay.println(convertedTemp);
  myDisplay.display();
}

void evening_lux() {
  //TEST FOR VIRTUAL PINS 2:4 AND SET THEM TO VARIABLES
  analogWrite(RED_LED_OUTPUT, blynk_red);
  analogWrite(GREEN_LED_OUTPUT, blynk_green);
  analogWrite(BLUE_LED_OUTPUT, blynk_blue);
}

void lux_updater(){
  lux_level = analogRead(A2);
}

void night_lux() {
  //night mode
  analogWrite(RED_LED_OUTPUT, 0);
  analogWrite(GREEN_LED_OUTPUT, 0);
  analogWrite(BLUE_LED_OUTPUT, 255);
  if (lux_level > lux_alert_threshold){
    delay(10000);
    Blynk.notify("Your lighting threshold has been exceeded");
  }
  else if (lux_level <= lux_alert_threshold){
    // do nothing
  }
}

void state_test(){
  //test for button state on pin V0 and set night_state based on state
  if (blynk_buttonState == TRUE){
    night_state = TRUE;
  }
  else if(blynk_buttonState == FALSE){
    night_state = FALSE;
  }
}

void setup() {
  pinMode(TEMP_SENSOR_INPUT, INPUT); //TEMP SENSOR INPUT
  pinMode(LUX_SENSOR_INPUT, INPUT); //LUX SENSOR INPUT
  pinMode(RED_LED_OUTPUT, OUTPUT); //RED RGB LED OUTPUT
  pinMode(GREEN_LED_OUTPUT, OUTPUT); //GREEN RGB LED OUTPUT
  pinMode(BLUE_LED_OUTPUT, OUTPUT); //BLUE RGB LED OUTPUT
  myDisplay.begin(SSD1306_SWITCHCAPVCC); //STARTING DISPLAY
  Blynk.begin("be2716a90e7c49dc8063fb7c0616500a",IPAddress(167,99,150,124),8080); //blynk config
  Serial.begin();
  timer.setInterval(100L, send_temp);
}

void loop() {
  Blynk.run();
  calc_temp();
  timer.run();
  app_sync();
  state_test();
  lux_updater();
  if (night_state == TRUE){
    night_lux();
  }
  else if(night_state == FALSE){
    evening_lux();
  }
}