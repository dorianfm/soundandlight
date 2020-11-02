# Halloween Sound & Light Controller

A controller to random play audio filesand make sychronised light effects using
a string of controllable leds lights.

The LEDs are WS2181Bs connected to an Arduino, used to be able to not worry about
the clock synch ont he lights. I could have used more expensive LEDS and driven
them from the Pi, but I had an arduino lying around so this was cheaper.

I've put this togehter in Node JS as I've not really done any full projects in
it and wanted to play with it more - I usually write frontend JS.

## Setup

1. Raspberry Pi set up with Raspbian.
2. Install git and other dev requirements of your liking.
3. Arduio IDE installed fron arduino.cc into `/home/pi/arduino-1.8.13`
4. Arduino-mk intalled using `apt install arduino-mk`
5. nodejs and npm installed from https://github.com/nodesource/distributions
    ```
    curl -sL https://deb.nodesource.com/setup_14.x | sudo -E bash -
    sudo apt-get install -y nodejs npm
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

https://github.com/nodesource/distributions

https://www.raspberrypi.org/

https://www.arduino.cc

https://github.com/sudar/Arduino-Makefile

https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices

https://github.com/FastLED/FastLED


