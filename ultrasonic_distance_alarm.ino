const byte trigPin = 9;
const byte echoPin = 10;
const byte buzzerPin = 6;
const byte ledPin = 13;
const float warningDistanceCm = 25.0;

float readDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = readDistanceCm();
  if (distance < 0) {
    Serial.println("No echo received");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    bool close = distance <= warningDistanceCm;
    digitalWrite(ledPin, close);
    if (close) tone(buzzerPin, 1200); else noTone(buzzerPin);
  }
  delay(120);
}