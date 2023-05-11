#include <LiquidCrystal.h>

const int trigPin1 = 6;
const int echoPin1 = 7;
const int trigPin2 = 8;
const int echoPin2 = 9;
long duration1, duration2;
int distance1, distance2;
int current1, current2;
int previous1 = 0;
int previous2 = 0;
int count = 0;
int flag1 = 0;
int flag2 = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2)/29.1;
  current1 = distance1;
  
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2)/29.1;
  current2 = distance2;
 

  bool condition1 = ((current1 >= previous1) && (previous1 > 0) && (abs(current1 - previous1) > 50));
  bool condition2 = ((current2 >= previous2) && (previous2 > 0) && (abs(current2 - previous2) > 50));
  
  if (condition1)
  {
    flag1++;
    if (flag1 > flag2)
    {
      count++;
      Serial.println("Entered in!");
      Serial.println(count);
      Serial.println();
      lcd.clear();
      lcd.print("ENTERED!");
      lcd.setCursor(0, 1);
      lcd.print(count);
    }
  }
  previous1 = current1;
  if (condition2){
    flag2++;
      if (flag2 > flag1){
      count--;
      Serial.println("Gone Out!");
      Serial.println(count);
      Serial.println();
      lcd.clear();
      lcd.print("EXITED!");
      lcd.setCursor(0, 1);
      lcd.print(count);
    }
  }
  previous2 = current2;
  delay(100);
}
