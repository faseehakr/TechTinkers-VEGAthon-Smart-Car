 
   /* Ultrasonic Sensor(HC-SR04) *
   Connections:
   HC-SR04    Aries Board
   VCC      -   5V
   GND      -   GND
   Echo     -   GPIO1
   Trig     -   GPIO0
   
*/

#include <TM1637.h>
#define echoPin 1 
#define trigPin 0 
int CLK = 3;
int DIO = 2; 

long duration; 
int distance;
TM1637 tm(CLK,DIO);

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(115200); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Aries V2.0");
  tm.init();
  tm.set(2);
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  
  
  distance = duration * 0.034 / 2; 
  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance > 9999) {
    distance = 9999;  
  }
  
  int thousands = distance / 1000;
  int hundreds = (distance / 100) % 10;
  int tens = (distance / 10) % 10;
  int ones = distance % 10;
  
  
  tm.display(0, thousands);  
  tm.display(1, hundreds);   
  tm.display(2, tens);       
  tm.display(3, ones);       
  
  delay(100); 
}