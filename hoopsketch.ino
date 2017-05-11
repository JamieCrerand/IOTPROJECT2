#include "rgb_lcd.h"


int sensorPin = A3; //input pin
int sensorValue = 0; //variable to store value coming from sensor
int score = 0;
int resetButton = A2;
int Buzzer = A1;
int LED = A0;

int buttonState = 0;

rgb_lcd lcd;

void setup() {
  pinMode(resetButton, INPUT);
  Serial.begin(9600); //sets serial port for communication
  lcd.begin(1, 1);
  lcd.setRGB(0,255,0);
  lcd.clear();
  
}
void loop() {
  buttonState = digitalRead(resetButton);

  if (sensorValue < 400){
    digitalWrite(A0, HIGH);
    delay(100);
    digitalWrite(A0, LOW);
    
  }

  if (buttonState == HIGH) {
    (score = 0);
  }

  if (sensorValue < 400){
    tone(Buzzer, 2000, 200);
  }

  if (buttonState == HIGH){
    tone(Buzzer, 250, 1000);
  }
  sensorValue = analogRead(sensorPin); //read the value
  Serial.println(sensorValue); //prints values
  delay(200);
  if (sensorValue < 600)
  
  
  {
    score++;
    //Serial.println(score);
    
    }
  lcd.clear();
  lcd.print(score);
    
    
}

"# IOTPROJECT2" 
