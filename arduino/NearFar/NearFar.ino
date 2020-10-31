  #include <FastLED.h>
  #define LED_PIN     3
  #define LED2_PIN    9
  #define NUM_LEDS    149

  CRGB leds[NUM_LEDS];
  CRGB leds2[NUM_LEDS];

  int g;
  int up;

  void setup() {
      FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
      FastLED.addLeds<WS2812, LED2_PIN, GRB>(leds2, NUM_LEDS);
      g=0;
      up=1;
  }

  void loop() {
      leds[1] = CRGB(g, 0, 0);
      leds2[1] = CRGB(0, 0, g);
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
