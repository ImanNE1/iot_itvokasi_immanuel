#define trigPin 21
#define echoPin 22

#define redLED 12
#define yellowLED 13

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika nyala lampu
  if (distance > 100) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
  } else if (distance > 50) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
  }

  delay(1000);
}
