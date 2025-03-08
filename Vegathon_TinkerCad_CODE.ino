#include <LiquidCrystal.h> //LCD library

#define echo 2
#define trig 3
float duration;
float distance;
float temperature;         
int motorSpeed;            

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  
const int motorPin = 4;                   
const int tempPin = A0;                   
const int maxTemp = 100;                  
const int minTemp = 20; 
const int button = 7;
const int buzz = 1;
int press = HIGH;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(motorPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
}

void loop() {
  time_Measurement();
  distance = duration * (0.0343) / 2;  
  display_distance();                  
  temp_monitor();                      
  temp_print();
  button_press();
}

void time_Measurement() { 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);  
}

void display_distance() { 
  lcd.clear();                      
  lcd.setCursor(0, 0);
  Serial.print("Distance in Cm: ");
  Serial.println(distance);
  lcd.print("Distance in Cm: ");
  lcd.setCursor(5, 1);
  lcd.print(distance);              
  delay(1000);                      
}

void temp_monitor() {               
  int tempValue = analogRead(tempPin);  
  temperature = (tempValue / 1024.0) * 500.0;  
  motorSpeed = map(temperature, minTemp, maxTemp, 0, 255);  
  motorSpeed = constrain(motorSpeed, 0, 255);               
  analogWrite(motorPin, motorSpeed);                        
}

void temp_print() {                 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C, Motor Speed: ");
  Serial.println(motorSpeed);
}

void button_press(){
  press = digitalRead(button);
  if(press == LOW){
  digitalWrite(buzz, HIGH);
}
  else{
  digitalWrite(buzz, LOW);}
}
