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

int rsPin = 9;
int enablePin = 5;

int D7 = 4;
int D6 = 3;
int D5 = 2;
int D4 = A5;

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
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("HI");
  lcd.setCursor(0, 1);
  lcd.print("YO");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (start == true) {
    digitalWrite(redPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press the button");
    lcd.setCursor(0, 1);
    lcd.print("in 3");

    delay(startSpeed);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin1, HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press the button");
    lcd.setCursor(0, 1);
    lcd.print("in 2");

    delay(startSpeed);
    digitalWrite(yellowPin1, LOW);

    digitalWrite(yellowPin2, HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press the button");
    lcd.setCursor(0, 1);
    lcd.print("in 1");

    delay(startSpeed);

    lcd.clear();
    lcd.setCursor(0 ,0);
    lcd.print("Press the button");
    lcd.setCursor(0, 1);
    lcd.print("GO!");

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

  start = true;
  iteration = 1;
  digitalWrite(greenPin, LOW);
}
