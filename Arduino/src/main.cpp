#include <Arduino.h>
#include <Servo.h>

const int LED_R_PIN = 5;
const int LED_G_PIN = 4;
const int LED_B_PIN = 3;
const int SERVO_PIN = 2;
Servo doorServo;
const int DOOR_PIN = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_R_PIN, OUTPUT);       // Red LED pin
  pinMode(LED_G_PIN, OUTPUT);       // Green LED pin
  pinMode(LED_B_PIN, OUTPUT);       // Blue LED pin
  doorServo.attach(2);              // Servo pin
  pinMode(DOOR_PIN, INPUT_PULLUP);  // Button pin
  digitalWrite(LED_B_PIN, HIGH);
  doorServo.write(0);
}

void loop() {
  byte buttonState = digitalRead(DOOR_PIN);
  
  if (buttonState == LOW) {
      Serial.println("Button is pressed");
      doorServo.write(360);
  }
  else {
      Serial.println("Button is not pressed");
      doorServo.write(0);
  }
  delay(100);
}

  