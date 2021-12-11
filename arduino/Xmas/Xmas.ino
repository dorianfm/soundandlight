  #include <FastLED.h>
  #define LED1_PIN     3
  #define LED2_PIN    9
  #define FAIRY1_PIN   5
  #define FAIRY2_PIN   6

  #define NUM_LEDS    148
  #define NUM_FAIRY   50

  CRGB leds1[NUM_LEDS];
  CRGB leds2[NUM_LEDS];
  CRGB fairy1[NUM_FAIRY];
  CRGB fairy2[NUM_FAIRY];

  int f;
  int l;
  int fup;
  int lup;

  void setup() {
      FastLED.addLeds<WS2812, LED1_PIN, GRB>(leds1, NUM_LEDS);
      FastLED.addLeds<WS2812, LED2_PIN, GRB>(leds2, NUM_LEDS);
      FastLED.addLeds<WS2811, FAIRY1_PIN, RGB>(fairy1, NUM_FAIRY);
      FastLED.addLeds<WS2811, FAIRY2_PIN, RGB>(fairy2, NUM_FAIRY);
      l=0;
      lup=1;
      f=0;
      fup=1;
  }

  void loop() {
        for(int dot = 0; dot < NUM_FAIRY; dot++) {
	    for (int i = 0; i  <=5 ; i++ ) {
		int idx = dot + i;
		if (idx >= NUM_FAIRY ) {
		 	idx = i;
		}
            	fairy1[idx].r = i * 25;
            	fairy2[idx].r = i * 25;

            	FastLED.show();
            // clear this led for the next time around the loop
	    }
            delay(30);
        }
  }
