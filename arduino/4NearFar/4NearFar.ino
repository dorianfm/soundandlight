  #include <FastLED.h>
  #define LED1_PIN     3
  #define LED2_PIN    9
  #define FAIRY1_PIN   5
  #define FAIRY2_PIN   6

  #define NUM_LEDS    149

  CRGB leds1[NUM_LEDS];
  CRGB leds2[NUM_LEDS];
  CRGB fairy1[NUM_LEDS];
  CRGB fairy2[NUM_LEDS];

  int g;
  int up;

  void setup() {
      FastLED.addLeds<WS2812, LED1_PIN, GRB>(leds1, NUM_LEDS);
      FastLED.addLeds<WS2812, LED2_PIN, GRB>(leds2, NUM_LEDS);
      FastLED.addLeds<WS2811, FAIRY1_PIN, GRB>(fairy1, NUM_LEDS);
      FastLED.addLeds<WS2811, FAIRY2_PIN, GRB>(fairy2, NUM_LEDS);
      g=0;
      up=1;
  }

  void loop() {
      leds1[1] = CRGB(g, 0, 0);
      leds2[1] = CRGB(0, 0, g);
      fairy1[1] = CRGB(g, 0, 0);
      fairy2[1] = CRGB(0, 0, g);
      FastLED.show();
      if (up) {
        g++;
      } else {
        g--;
      }
      if (g <= 1)
      {
        up = 1;
      } else if (g >= 250) {
        up = 0;
      }
      delay(1);
  }
