# Festive Sound & Light Controller

A controller to random play audio filesand make sychronised light effects using
a string of controllable leds lights.

The LEDs are WS2181Bs connected to an Arduino, used to be able to not worry about
the clock synch on the lights. I could have used more expensive LEDS and driven
them from the Pi, but I had an arduino lying around so this was cheaper, and
pretty straightforward

I've put this together in Node JS as I've not really done any full projects in
it and wanted to play with it more - I usually write frontend JS.

15/11/2020 - I'm moving this around bit to add in some hacks for christmas lights.

## Setup

1. Raspberry Pi set up with Raspbian.
2. Install git and other dev requirements of your liking.
3. Arduio IDE installed fron arduino.cc into `/home/pi/arduino-1.8.13`
4. Arduino-mk intalled using `apt install arduino-mk`
5. nodejs and npm installed from https://github.com/nodesource/distributions
    ```
    curl -sL https://deb.nodesource.com/setup_14.x | sudo -E bash -
    sudo apt-get install -y nodejs
    ```
6. `~/.profile` extends for arduino-mk

    ```
    export ARDUINO_DIR=/home/pi/arduino-1.8.13
    export ARDMK_DIR=/usr/share/arduino
    ```
7. Download sounds in `sounds/` (Grabbed  from: https://www.freesoundeffects.com/free-sounds/scary-and-horror-10085/20/tot_sold/20/2/ )
8. `cd arduino/NodeControl && make upload && cd ../../` to install arduino code
9. `node js/Controls/Halloween.s` to run

## References

### Halloween Lights / LED Light Strips

https://github.com/nodesource/distributions

https://www.raspberrypi.org/

https://www.arduino.cc

https://github.com/sudar/Arduino-Makefile

https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices

https://github.com/FastLED/FastLED

### Christmas Lights / LED Fairy Lights

Hacking lights, talks about how they work from sending alternating polarity
https://www.youtube.com/watch?v=S1GyCe5a6mM

Ah, bascially we need an H-Bridge:
https://forum.arduino.cc/index.php?topic=498882.0
https://en.wikipedia.org/wiki/H-bridge

Oh, I have a couple of these already:
https://www.amazon.co.uk/dp/B00FR3DFPC/ref=pe_385721_37986871_TE_item

Kinda like this, but with lights instead of motoros:
https://wiki.dfrobot.com/MD1.3_2A_Dual_Motor_Controller_SKU_DRI0002
https://www.instructables.com/Control-DC-and-stepper-motors-with-L298N-Dual-Moto/

Maybe use the old wifly board I have lying to control arduino over wifi:
https://www.sparkfun.com/products/retired/9954
https://github.com/sparkfun/WiFly-Shield/tree/V_H1.7_L1.0.1/Libraries

And I can use some of these I have lying around to hit the correct voltage froma 36V Power Suppy:
https://www.amazon.co.uk/LM2596-Converter-3-0-40V-1-5-35V-Supply/dp/B01GJ0SC2C

I should then be able to hook up a chain of lights to each motor controller channel,
and control which 'channel' of the lights is working, or alternate quickly between the two,
to get the lights to come on as required.

Also look at using the piface I have
http://www.piface.org.uk/products/piface_digital/
To potentially control other lights whcich are more simply on/off.

### Sound to Light / FFT

FFT library for raspberry Pi using GPU:
http://www.aholme.co.uk/GPU_FFT/Main.htm

Existing 'lightshow pi' project, may have useful code sources, Python.
https://bitbucket.org/togiles/lightshowpi/src/master/py/fft.py

Or access the Gstreamer framework via node to get fft from there?
https://github.com/romgrk/node-gtk

