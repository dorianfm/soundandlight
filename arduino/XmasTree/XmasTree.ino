  #include <FastLED.h>
  #define FAIRY1_PIN   1

  #define NUM_FAIRY   50

  CRGB fairy1[NUM_FAIRY];

  int f;
  int l;
  int fup;
  int lup;

  void setup() {
      FastLED.addLeds<NEOPIXEL, FAIRY1_PIN, RGB>(fairy1, NUM_FAIRY);
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

            	FastLED.show();
            // clear this led for the next time around the loop
	    }
            delay(30);
        }
  }
