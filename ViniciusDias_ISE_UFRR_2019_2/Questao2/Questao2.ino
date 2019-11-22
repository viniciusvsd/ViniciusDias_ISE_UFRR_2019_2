#include <Servo.h>

int Terreo = 0;
int Andar1 = 90;
int Andar2 = 180;
Servo servo_9;

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  servo_9.write(Terreo);
}

void loop()
{
  if (digitalRead(3) == LOW) {
    servo_9.write(Terreo);
  }
  if (digitalRead(4) == LOW) {
    servo_9.write(Andar1);
  }
  if (digitalRead(5) == LOW) {
    servo_9.write(Andar2);
  }
}
