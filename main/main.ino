#include <LiquidCrystal.h>
//Sound_Sensor Pin
#define SOUND_SENSOR_PIN A0
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
//LCD Pin
#define R0S_PIN 13
#define E_PIN 12
#define D4_PIN 11
#define D5_PIN 10
#define D6_PIN 9
#define D7_PIN 8

LiquidCrystal lcd(R0S_PIN,E_PIN,D4_PIN,D5_PIN,D6_PIN,D7_PIN); 

int sensorValue;
unsigned long Ttime = 0;
int Tsec = 0;
int Tmin = 0;
int Thour = 0;

byte myChar1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte myChar2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte myChar3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte myChar4[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte myChar5[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte myChar6[8] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte myChar7[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte myChar8[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("");
  lcd.createChar(0,myChar1);
  lcd.createChar(1,myChar2);
  lcd.createChar(2,myChar3);
  lcd.createChar(3,myChar4);
  lcd.createChar(4,myChar5);
  lcd.createChar(5,myChar6);
  lcd.createChar(6,myChar7);
  lcd.createChar(7,myChar8);
}

void loop() {
  // put your main code here, to run repeatedly:
  Ttime = millis()/1000;
  Tsec = Ttime%60;
  Tmin = Ttime/60%60;
  Thour = Ttime/(60*60)%24;
  print_time();
  if(Tsec == 0) lcd.clear(); 
  print_height(Tsec%8);
  
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

void print_time(){
  lcd.setCursor(0, 0);
  lcd.print(Thour);
  lcd.print("H: ");
  lcd.print(Tmin);
  lcd.print("M: ");
  lcd.print(Tsec);
}

void print_height(int height){
   lcd.setCursor(0, 1);
  for (int i = 0 ; i < height ; i++) { 
   lcd.write(byte(i));
  }
}
