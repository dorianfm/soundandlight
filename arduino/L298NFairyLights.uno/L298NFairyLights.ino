// # Description:
// # The sketch for using the driver L298N
// # Run with the PWM mode


void setup()
{
    pinMode(A0, OUTPUT); // Controller 1 IN1 (A)
    pinMode(A1, OUTPUT); // Controller 1 IN2 (A)
    pinMode(A2, OUTPUT); // Controller 1 IN3 (B)
    pinMode(A3, OUTPUT); // Controller 1 IN4 (B)
    pinMode(10, OUTPUT); // Controller 1 ENA
    pinMode(11, OUTPUT); // Controller 1 ENB

    pinMode(0, OUTPUT); // Controller 3 IN1 (A)
    pinMode(1, OUTPUT); // Controller 3 IN2 (A)
    pinMode(2, OUTPUT); // Controller 3 IN3 (B)
    pinMode(4, OUTPUT); // Controller 3 IN4 (B)
    pinMode(3, OUTPUT); // Controller 3 ENA
    pinMode(5, OUTPUT); // Controller 3 ENB

    pinMode(7, OUTPUT); // Controller 2 IN1 (A)
    pinMode(8, OUTPUT); // Controller 2 IN2 (A)
    pinMode(12, OUTPUT); // Controller 2 IN3 (B)
    pinMode(13, OUTPUT); // Controller 2 IN4 (B)
    pinMode(6, OUTPUT); // Controller 2 ENA
    pinMode(9, OUTPUT); // Controller 2 ENB

}

void show1()
{
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);

    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
}

void show2()
{
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);

    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);

    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
}

void pwm(int n)
{
    analogWrite(10, n);
    analogWrite(11, n);
    analogWrite(3, n);
    analogWrite(5, n);
    analogWrite(6, n);
    analogWrite(9, n);
}

void loop()
{
    int bright;
    show1();
    for (bright = 0; bright < 255; bright += 1) {
      pwm(bright);
      delay(10);
    }
    show2();
    for (bright = 255; bright > 0; bright -= 1) {
      pwm(bright);
      delay(10);
    }
}


