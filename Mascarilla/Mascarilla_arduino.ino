// defines pins numbers
const int grnLed = 5;
const int ylwLed = 6;
const int redLed = 7;
const int vcc = 8;
const int gnd = 11;
const int trigPin = 9;
const int echoPin = 10;
int incomingByte;

// defines variables
long duration;
int distance;
void setup() {
  pinMode(gnd, OUTPUT);
  pinMode(vcc, OUTPUT);
  digitalWrite(gnd, LOW);
  digitalWrite(vcc, HIGH);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(grnLed, OUTPUT);
  pinMode(ylwLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration*0.0343/2);
  // Prints the distance on the Serial Monitor
  delay(200);
  Serial.println(distance);
  //Check if serial communication is available
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer
    incomingByte = Serial.read();
    // if it's a capital W (ASCII 87), turn on the green LED
    if (incomingByte == 'W') {
      digitalWrite(grnLed, HIGH);
      digitalWrite(ylwLed, LOW);
      digitalWrite(redLed, LOW);
    }
    // if it's a capital I (ASCII 73), turn on the yellow LED
    if (incomingByte == 'I') {
      digitalWrite(grnLed, LOW);
      digitalWrite(ylwLed, HIGH);
      digitalWrite(redLed, LOW);
    }
    // if it's a capital N (ASCII 78), turn on the red LED
    if (incomingByte == 'N') {
      digitalWrite(grnLed, LOW);
      digitalWrite(ylwLed, LOW);
      digitalWrite(redLed, HIGH);
    }
    // if it's a capital O (ASCII 79), turn off all LED
    if (incomingByte == 'O') {
      digitalWrite(grnLed, LOW);
      digitalWrite(ylwLed, LOW);
      digitalWrite(redLed, LOW);
    }
  }
}
