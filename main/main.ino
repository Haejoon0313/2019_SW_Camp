#define SOUND_SENSOR_PIN A0
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

int sensorValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(SOUND_SENSOR_PIN);
  Serial.println(sensorValue);
  
  ledPrint(sensorValue);
  
  delay(100);
}

void ledPrint(int sensorValue){
  if(sensorValue < 580){
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 50);
    analogWrite(BLUE_PIN, 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  }      
  else if(sensorValue < 600){
    analogWrite(RED_PIN, 40);
    analogWrite(GREEN_PIN, 20);
    analogWrite(BLUE_PIN, 0);
  }
  else{  
    analogWrite(RED_PIN, 50);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0); 
  }
}
