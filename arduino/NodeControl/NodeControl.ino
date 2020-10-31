#include <FastLED.h>
#define LED_PIN     3
#define LED2_PIN    9
#define NUM_LEDS    149

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS];

int myR;
int myG;
int myB;

void setup() {
    Serial.begin(57600); // Begin listening for serial at 57600 bps
    Serial.println("Starting");

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.addLeds<WS2812, LED2_PIN, GRB>(leds2, NUM_LEDS);
    myR=0;
    myG=128;
    myB=0;
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].setRGB(0, 128, 0);
        leds2[i].setRGB(myR, myG, myB);
    }
}

void convertToState(char chr) {
  Serial.println(String(chr));
  if(chr=='r'){
    if (myR == 0) {
        myR = 128;
    } else {
        myR = 0;
    }
  }
  if(chr=='g'){
    if (myG == 0) {
        myG = 128;
    } else {
        myG = 0;
    }
  }
  if(chr=='b'){
    if (myB == 0) {
        myB = 128;
    } else {
        myB = 0;
    }
  }
  Serial.println("RGB: "+String(myR)+','+String(myG)+','+String(myB));
}


void loop() {
    if(Serial.available() > 0) {
      char readFromNode;
      readFromNode = (char) Serial.read();
      convertToState(readFromNode); // Convert character to state
    }
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].r = myR;
        leds[i].g = myG;
        leds[i].b = myB;
        leds2[i].setRGB(myR, myG, myB);
    }
    FastLED.show();
    delay(10);
}
