
   
   *** Piezoelectric buzzer ***
   Connections:
   Buzzer     Aries Board
   VCC      -   3.3V
   GND      -   GND
   IN       -   GPIO14

   *** Touch Sensor ***
   Connections:
   Touch Sensor   Aries Board
   VCC          -   3.3V
   GND          -   GND
   SIG          -   GPIO0
*/

#define TOUCH_PIN 0  
#define BUZZER 14    


void setup() {
  
  Serial.begin(115200);
  delay(1000);

  pinMode(TOUCH_PIN, INPUT); 
  pinMode(BUZZER, OUTPUT);   
}


void loop() {
  
  if (digitalRead(TOUCH_PIN) == HIGH) {
    Serial.println("Sensor is touched");
    digitalWrite(BUZZER, LOW);  
  } else {
    Serial.println("Sensor is not touched");
    
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW); 
    delay(100);
  }
  
  delay(20); 
}
