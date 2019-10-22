#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);

void setup() {
  // put your setup code here, to run once:
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long cap_input1 =  cs_4_2.capacitiveSensor(30);
  long cap_input2 =  cs_4_5.capacitiveSensor(30);
  long cap_input3 =  cs_4_6.capacitiveSensor(30);
  long cap_input4 =  cs_4_7.capacitiveSensor(30);

  long cap_input[4] = {cap_input1, cap_input2, cap_input3, cap_input4};
  int key_input[4];
  
  cap_to_key(&cap_input[0], &key_input[0]);
  key_to_com(&key_input[0]);
  
  delay(10);
}

void cap_to_key(long * cap_input, int * key_input){
  
}

void key_to_com(int * key_input){
  
}
