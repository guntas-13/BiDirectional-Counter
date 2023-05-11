#define trigPin1 6
#define echoPin1 7
#define trigPin2 11
#define echoPin2 12
int counter = 0;
// int in;
// double current1 = 0;
double previous1 = 0;
// double current2 = 0;
double previous2 = 0;
int first = 0;
int second = 0;
double distance, duration;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);

}

void loop() {
  double current1, current2
  long duration1;
  double distance1;
  distance1 = SonarSensor(trigPin1, echoPin1);
  current1 = distance1;


  long duration2;
  double distance2;
  distance2 = SonarSensor(trigPin2, echoPin2);
  current2 = distance2;

  Serial.print("D1: ");
  Serial.println(current1);
  Serial.print("D2: ");
  Serial.println(current2);
  Serial.println();

  // bool countInc = (current1 >= previous1) && (previous1 > 0) && (abs(current1 - previous1) > 0);
  // bool countDec = (current2 >= previous2) && (previous2 > 0) && (abs(current2 - previous2) > 0);

  // delay(100);
  // if (countInc){
  //   first++;
  //   Serial.println("First:");
  //   if (first > second){
  //     counter++;
  //     Serial.println(counter);
  //   }
    
  // }
  // previous1 = current1;

  // delay(100);
  // if (countDec){
  //   second++;
  //   Serial.println("Second:");
  //   if (second > first){
  //       counter--;
  //       Serial.println(counter);
  //   }
    
  // }
  // previous2 = current2;
}

double SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  double distance = (duration/2) / 29.1;
  return distance;
}