#include <LiquidCrystal.h>

const int trigPin = 6;
const int echoPin = 7;
long duration;
int distance;
int current;
int previous = 0;
int counter = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  
  current = distance;
  bool condition = ((current >= previous) && (previous > 0) && (abs(current - previous) > 50));
  if (condition)
  {
    counter++;
    lcd.clear();
    lcd.print("Count:");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    Serial.println(counter);
  }
  previous = current;
}
