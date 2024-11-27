void setup(){
  //Ultrasonic_1
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  //Ultrasonic_2
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}
 void loop(){
  Ultrasonic_1();
  Ultrasonic_2();
 }
////////////////////////////
////////////////////////////
int distanceThreshold = 0;
int cm = 0;
int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void Ultrasonic_1(){
  // set threshold distance to activate LEDs
  distanceThreshold = 300;
  // calculate the distance to the target in cm
  cm = 0.09923 * readUltrasonicDistance(7, 6); //normal cm 0.01739
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  if (cm > distanceThreshold) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    noTone(3);
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    tone(3, 500);
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 200) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    tone(3, 500);
  }
  if (cm <= distanceThreshold - 200 && cm > distanceThreshold - 300) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    tone(3, 500);
  }
  if (cm <= distanceThreshold - 300) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    tone(3, 500);
  }
  delay(100); // Wait for 100 millisecond(s)
}

////////////////////////////////////////////////////////////////////////////////////////
long readUltrasonicDistance_2(int triggerPin_2, int echoPin_2)
{
  pinMode(triggerPin_2, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin_2, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin_2, LOW);
  pinMode(echoPin_2, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin_2, HIGH);
}
////////
void Ultrasonic_2(){
  // set threshold distance to activate LEDs
  distanceThreshold = 300;
  // calculate the distance to the target in cm
  cm = 0.09923 * readUltrasonicDistance_2(9, 8); //normal cm 0.01739
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  if (cm > distanceThreshold) {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    noTone(12);
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    tone(12, 500);
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 200) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    tone(12, 500);
  }
  if (cm <= distanceThreshold - 200 && cm > distanceThreshold - 300) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    tone(12, 500);
  }
  if (cm <= distanceThreshold - 300) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    tone(12, 500);
  }
  delay(100); // Wait for 100 millisecond(s)
}