#include <LiquidCrystal.h>

bool start = true;
int iteration = 1;
int startSpeed = 2000;
int blueFlashSpeed = 100;

int redPin = 13;
int yellowPin1 = 12;
int yellowPin2 = 11;
int greenPin = 10;
int bluePin1 = 7;
int bluePin2 = 6;
int bluePin3 = 8;

int rsPin = 10;
int enablePin = 3;

int D7 = 2;
int D6 = A6;
int D5 = A5;
int D4 = A4;

LiquidCrystal lcd(rsPin, enablePin, D4, D5, D6, D7);

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin1, OUTPUT); // yellow
  pinMode(yellowPin2, OUTPUT); // yellow
  pinMode(greenPin, OUTPUT); // green
  pinMode(bluePin1, OUTPUT); // blue
  pinMode(bluePin2, OUTPUT); // blue 
  pinMode(bluePin3, OUTPUT); // blue
  pinMode(redPin, OUTPUT); // red
  //cd.begin(16, 2);
  //lcd.print("Hello!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (start = true) {
    digitalWrite(redPin, HIGH);
    delay(startSpeed);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin1, HIGH);
    delay(startSpeed);
    digitalWrite(yellowPin1, LOW);
    digitalWrite(yellowPin2, HIGH);
    delay(startSpeed);
    digitalWrite(yellowPin2, LOW);
    digitalWrite(greenPin, HIGH);
    delay(100);
    start = false;
  }

  while (iteration < 15) {
    digitalWrite(bluePin1, HIGH);
    delay(blueFlashSpeed);
    digitalWrite(bluePin1, LOW);
    digitalWrite(bluePin2, HIGH);
    delay(blueFlashSpeed);
    digitalWrite(bluePin2, LOW);
    digitalWrite(bluePin3, HIGH);
    delay(blueFlashSpeed);
    digitalWrite(bluePin3, LOW);
    iteration++;
  }

  start = false;
  iteration = 1;
  digitalWrite(greenPin, LOW);
}
