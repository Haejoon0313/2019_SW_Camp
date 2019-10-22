#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);

long cap_val[4] = {0};     //input everage value [0]:input1 [1]:input2 ...
long cap_val1[10] = {0};   // last 10 input
long cap_val2[10] = {0};
long cap_val3[10] = {0};
long cap_val4[10] = {0};

void setup() {
  // put your setup code here, to run once:
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
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
  
  //delay(10);
}

void cap_to_key(long * cap_input, int * key_input){ //input to keyboard digital input
  for(int i = 0 ; i < 1 ; i++ ){
  if(cap_input[i] < cap_val[i]){
     key_input[i] = 1; // thouch detected
     Serial.print("\n touch detect");
  }else{
     key_input[i] = 0; // non thouch
     switch(i){
      case 0:
        cap_val[0] = (val_set(cap_val1,cap_input[0])/10)* 8; //set the critical value 80%
        Serial.print("\n cap_val1: ");
        Serial.print(cap_val[0]);
        break;
      case 1:
        cap_val[1] = (val_set(cap_val2,cap_input[1])/10)* 8;
        break;
      case 2:
        cap_val[2] = (val_set(cap_val3,cap_input[2])/10)* 8;
        break;
      case 3:
        cap_val[3] = (val_set(cap_val4,cap_input[3])/10)* 8;
        break;
      }
   }
  }
  
}

long val_set(long *set_val , long input_cap){ //set the critical value
  long tmp = 0;
  for(int i = 0 ; i < 9 ; i++ ){
    set_val[i] = set_val[i+1];
    }
    set_val[9] = input_cap;
   for(int i = 0 ; i < 10 ; i++ ){
    tmp += set_val[i];
    }
   return tmp/10;                      //return value is last10input everage 
}

void key_to_com(int * key_input){
  
}
