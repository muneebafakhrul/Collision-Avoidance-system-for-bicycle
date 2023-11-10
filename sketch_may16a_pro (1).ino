#include <Servo.h>
#define trigPin1 8
#define echoPin1 9
#define trigPin2 10
#define echoPin2 11
#define buzzer 5
#define led_green 6
#define led_red 7
Servo servo;
int buttonPin = 2;
boolean buttonstate = LOW;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  servo.attach(12);
  pinMode(buttonPin,INPUT);
}

void loop() {
  long duration1, distance1;
  long duration2, distance2;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
   
  buttonstate = digitalRead(buttonPin);

  if (buttonstate==HIGH) {
      servo.write(0);
  }
  else if (distance1 < 250) {  
    servo.write(140);
    digitalWrite(led_green,HIGH);
    delay(400);
  }
  else {
    servo.write(0);
    digitalWrite(led_green,LOW);
  }
  
  if (distance2 < 150) {  // This is where the Buzzer On/Off happens
    tone(buzzer, 1000); // Send 1KHz sound signal...
    digitalWrite(led_red,HIGH);
    delay(200);
    noTone(buzzer);
  }
  else {
    noTone(buzzer);
    digitalWrite(led_red,LOW);    
  }
  
  delay(200);
}
