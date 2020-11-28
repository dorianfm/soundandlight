// # Description:
// # The sketch for using the motor driver L298N
// # Run with the PWM mode

// # Connection:
// #        M1 pin  -> Digital pin 4
// #        E1 pin  -> Digital pin 5
// #        M2 pin  -> Digital pin 7
// #        E2 pin  -> Digital pin 6
// #        Motor Power Supply -> Centor blue screw connector(5.08mm 3p connector)
// #        Motor A  ->  Screw terminal close to E1 driver pin
// #        Motor B  ->  Screw terminal close to E2 driver pin
// #
// # Note: You should connect the GND pin from the DF-MD v1.3 to your MCU controller. They should share the GND pins.
// #

int In1 = 4;
int In2 = 5;
int In3 = 6;
int In4 = 7;

void setup()
{
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
}

void loop()
{
  int value;
  for (value = 1; value < 2000; value += value) 
  {
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW);
    delay(value);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);
    delay(value);
  }
}
