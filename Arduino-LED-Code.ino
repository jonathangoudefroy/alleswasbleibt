#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#ifdef AVR
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN1    3
#define LED_PIN2    4
#define LED_PIN3    5
#define LED_PIN4    6
#define LED_PIN5    7
#define LED_PIN6    8
#define LED_PIN7    9

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 30

unsigned long rgb = 0x6f56a3;
byte red = rgb >> 16;
byte green = (rgb & 0x00ff00) >> 8;
byte blue = (rgb & 0x0000ff);
byte up = 0, down = 0;
int arr[150], index1 = 0;

Adafruit_NeoPixel strip1(LED_COUNT, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, LED_PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, LED_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(LED_COUNT, LED_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6(6, LED_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7(24, LED_PIN7, NEO_GRB + NEO_KHZ800);

int white = 20;
float white1 = 20.0;
byte button1 = 0, button2 = 0;
void setup() {

  Serial.begin(9600);
  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();            // Turn OFF all pixels ASAP
  strip1.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  strip2.setBrightness(150);
  strip3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip3.show();            // Turn OFF all pixels ASAP
  strip3.setBrightness(150);
  strip4.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip4.show();            // Turn OFF all pixels ASAP
  strip4.setBrightness(150);
  strip5.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip5.show();            // Turn OFF all pixels ASAP
  strip5.setBrightness(150);
  strip6.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip6.show();            // Turn OFF all pixels ASAP
  strip6.setBrightness(150);
  strip7.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip7.show();            // Turn OFF all pixels ASAP
  strip7.setBrightness(150);


  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  digitalWrite(30, HIGH);
  digitalWrite(31, LOW);

}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  int sensorValue1 = analogRead(A8);
  // print out the value you read:
  //  Serial.print("value 8:::" );
  //  Serial.println(sensorValue1);
  int sensorValue2 = analogRead(A9);
  // print out the value you read:
  //  Serial.print("value 9:::");
  //  Serial.println(sensorValue2);

  //breathAll();
  if (sensorValue2 < 1022) {
    strip1.setBrightness(0);
    strip2.setBrightness(0);
    strip3.setBrightness(0);
    strip4.setBrightness(0);
    strip5.setBrightness(0);
    strip6.setBrightness(0);
    strip7.setBrightness(250);
    strip1.show();
    strip2.show();
    strip3.show();
    strip4.show();
    strip5.show();
    strip6.show();
    strip7.show();

    scan(100);
  }
  else {

    if (down == 1) {
      down = 0;
      strip6.setBrightness(250);
      strip6.show();
      greenWay();
      int r = random(0, 150);
      r = check(r);
      arr[index1] = r;
      Serial.println(arr[index1]);
      index1++;
      strip6.setBrightness(0);
      strip6.show();
      strip1.setBrightness(200);
      strip2.setBrightness(200);
      strip3.setBrightness(200);
      strip4.setBrightness(200);
      strip5.setBrightness(200);
      for (int i = 0; i < index1 ; i++) {

        if (arr[i] / 15 < 2) {
          strip1.setPixelColor(arr[i], 255, 255, 255);
          strip1.show();
        }
        else if (arr[i] / 15 < 4) {
          strip2.setPixelColor(arr[i] - 30, 255, 255, 255);
          strip2.show();
        }
        else if (arr[i] / 15 < 6) {
          strip3.setPixelColor(arr[i] - 60, 255, 255, 255);
          strip3.show();

        }
        else if (arr[i] / 15 < 8) {
          strip4.setPixelColor(arr[i] - 90, 255, 255, 255);
          strip4.show();
        }
        else if (arr[i] / 15 < 10) {
          strip5.setPixelColor(arr[i] - 120, 255, 255, 255);
          strip5.show();
        }
      }


      strip7.setBrightness(0);
      strip7.show();
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();

      delay(8000);   ///// 5000 is 5 sec,
    }
    strip1.setBrightness(150);
    strip2.setBrightness(150);
    strip3.setBrightness(150);
    strip4.setBrightness(150);
    strip5.setBrightness(150);
    strip7.setBrightness(0);
    strip7.show();

    colorWipe(100);
    up = 1;
  }

  if ((sensorValue1 > 1022)) {
    if (up == 1) {
      down = 1;
    }
  }


}




void colorWipe( int wait) {
  white = (int) 50 * sin(white1) * sin(white1);

  for (int i = 0; i < LED_COUNT; i++) { // For each pixel in strip...
    strip1.setPixelColor(i, white, white, white);      //  Set pixel's color (in RAM)
    strip2.setPixelColor(i, white, white, white);
    strip3.setPixelColor(i, white, white, white);
    strip4.setPixelColor(i, white, white, white);
    strip5.setPixelColor(i, white, white, white);
    //  Pause for a moment
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  delay(wait);
  white1 = white1 + .1;

}

void scan( int wait) {
  white = (int) 200 * sin(white1) * sin(white1);

  for (int i = 0; i < LED_COUNT; i++) { // For each pixel in strip...
    //  Set pixel's color (in RAM)
    strip7.setPixelColor(i, white, white, white);
  }

  strip7.show();
  delay(wait);
  white1 = white1 + .1;

}

void greenWay() {
  strip6.setBrightness(150);
  for (int i = 0; i < 6; i++) {
    strip6.setPixelColor(i, 255, 255, 255);
    strip6.show();
    delay(200);
  }

}

int check(int rr) {

  for (int i = 0; i < index1; i++ ) {
    if (rr == arr[i]) {
      rr = random(0, 150);
      rr = check(rr);
    }
  }
  return rr;
}




void image(int wait, const unsigned long var[150] ) {

  strip2.clear();         //   Set all pixels in RAM to 0 (off)
  strip3.clear();         //   Set all pixels in RAM to 0 (off)
  strip4.clear();         //   Set all pixels in RAM to 0 (off)
  strip5.clear();         //   Set all pixels in RAM to 0 (off)
  for (int i = 0; i < 150; i++) {
    rgb = var[i];
    red = rgb >> 16;
    green = (rgb & 0x00ff00) >> 8;
    blue = (rgb & 0x0000ff);

    if (i / 15 < 2) {
      strip1.setPixelColor(i, red, green, blue);
    }
    else if (i / 15 < 4) {
      if (i == 30) {
        strip1.show();
        strip1.clear();         //   Set all pixels in RAM to 0 (off)
      }

      strip2.setPixelColor(i - 30, red, green, blue);
    }
    else if (i / 15 < 6) {
      if (i == 60) {
        strip2.show();
        strip2.clear();         //   Set all pixels in RAM to 0 (off)
      }
      strip3.setPixelColor(i - 60, red, green, blue);

    }
    else if (i / 15 < 8) {
      if (i == 90) {
        strip3.show();
        strip3.clear();         //   Set all pixels in RAM to 0 (off)
      }
      strip4.setPixelColor(i - 90, red, green, blue);
    }
    else if (i / 15 < 10) {
      if (i == 120) {
        strip4.show();
        strip4.clear();         //   Set all pixels in RAM to 0 (off)
      }
      strip5.setPixelColor(i - 120, red, green, blue);
    }
  }
  strip5.show(); // Update strip with new contents
  strip5.clear();
  delay(wait);  // Pause for a moment
}
