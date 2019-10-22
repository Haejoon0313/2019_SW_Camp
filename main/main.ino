#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);

void setup() {
  // put your setup code here, to run once:
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  
  Serial.println(total1);                  // print sensor output 1
  
  delay(1000);
}
