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


void setup()
{
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop()
{
  int bright, i;
    analogWrite(10,0);
    digitalWrite(A0,HIGH);
    digitalWrite(A1,LOW);
    for (bright = 0; bright < 255; bright += 1) {
	analogWrite(10, bright);
	delay(10);
    }
    analogWrite(10, 0);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    for (bright = 0; bright < 255; bright += 1) {
	analogWrite(10, bright);
	delay(10);
    }
    analogWrite(10,0);
    for (bright = 0; bright < 255; bright += 1) {
		analogWrite(10, bright);
		for (i=0; i < 5; i += 1) {
			digitalWrite(A0, HIGH);
			digitalWrite(A1, LOW);
			delay(1);
			digitalWrite(A0, LOW);
			digitalWrite(A1, HIGH);
			delay(1);
		}
    }
}
