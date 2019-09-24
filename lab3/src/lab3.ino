/*
 * Project lab3
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D4, OUTPUT);


}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  uint32_t red = 0;
  uint32_t green = 0;
  uint32_t blue = 0;
  uint32_t step = 0;
  red = 0;
  green = 0;
  blue = 0;
  uint32_t color_step = 0;
  color_step = 1;
  while(step < 255){
    red =+ 1;
    step =+ 1;
    analogWrite(D4, red);
    delay(100);
  }
}