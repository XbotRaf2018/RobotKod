/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "SpeedControl.h"
#include <Encoder.h>
#include "PidLib.h"


Encoder *NS_L;
Encoder *NS_R;
Encoder *EW_L;
Encoder *EW_R;

long enkoder_NS_L_old = 0;
long enkoder_NS_R_old = 0;
long enkoder_EW_L_old = 0;
long enkoder_EW_R_old = 0;

unsigned long ns_L_pre_millis = 0;
unsigned long ns_R_pre_millis = 0;
unsigned long ew_L_pre_millis = 0;
unsigned long ew_R_pre_millis = 0;

float speed_NS_L = 0;
float speed_NS_R = 0;
float speed_EW_L = 0;
float speed_EW_R = 0;

boolean debug_speed = false;

void init(){
  NS_L = new Encoder(MOTOR_NS_L_EN0,MOTOR_NS_L_EN1);
  NS_R = new Encoder(MOTOR_NS_R_EN0,MOTOR_NS_R_EN1);
  EW_L = new Encoder(MOTOR_EW_L_EN0,MOTOR_EW_L_EN1);
  EW_R = new Encoder(MOTOR_EW_R_EN0,MOTOR_EW_R_EN1);
}

void racunaj_brzine(){

	racunaj_brzinu_NS_L();
	racunaj_brzinu_NS_R();
	racunaj_brzinu_EW_L();
	racunaj_brzinu_EW_R();

}

float racunaj_brzinu_NS_L(){

	long newPosition = NS_L->read();

  	//if (newPosition != enkoder_NS_L_old) {

  		float delta_pos = abs(enkoder_NS_L_old - newPosition);
  		unsigned long delta_millis = millis() - ns_L_pre_millis;
  		speed_NS_L = delta_pos/delta_millis;

    	enkoder_NS_L_old = newPosition;
    	ns_L_pre_millis=millis();

    	if(debug_speed){
        Serial.print(" Debug SpeedControl -- ");
        Serial.print(" speed_NS_L: ");
    		Serial.println(speed_NS_L);
    	}
  	//}
   
    return speed_NS_L;
}

float racunaj_brzinu_NS_R(){

	long newPosition = NS_R->read();

  	//if (newPosition != enkoder_NS_R_old) {

  		float delta_pos = abs(enkoder_NS_R_old - newPosition);
  		unsigned long delta_millis = millis() - ns_R_pre_millis;
  		speed_NS_R = delta_pos/delta_millis;

    	enkoder_NS_R_old = newPosition;
    	ns_R_pre_millis=millis();

    	if(debug_speed){
        Serial.print(" Debug SpeedControl -- ");
        Serial.print(" speed_NS_R: ");
    		Serial.println(speed_NS_R);
    	}
  	//}
   Serial.print("Speed_NS_R: ");
   Serial.println(speed_NS_R);
    return speed_NS_R;
}

float racunaj_brzinu_EW_L(){

	long newPosition = EW_L->read();

  	//if (newPosition != enkoder_EW_L_old) {

  		
      float delta_pos = abs(enkoder_EW_L_old - newPosition);
      unsigned long delta_millis = millis() - ew_L_pre_millis;
      speed_EW_L = delta_pos/delta_millis;

      enkoder_EW_L_old = newPosition;
      ew_L_pre_millis=millis();

      if(debug_speed){
        Serial.print(" Debug SpeedControl -- ");
        Serial.print(" speed_EW_L: ");
        Serial.println(speed_EW_L);
      }
    	
  	//}

}

float racunaj_brzinu_EW_R(){

	long newPosition = EW_R->read();

  	
      float delta_pos = abs(enkoder_EW_R_old - newPosition);
      unsigned long delta_millis = millis() - ew_R_pre_millis;
      speed_EW_R = delta_pos/delta_millis;

      enkoder_EW_R_old = newPosition;
      ew_R_pre_millis=millis();

      if(debug_speed){
        Serial.print(" Debug SpeedControl -- ");
        Serial.print(" speed_EW_R: ");
        Serial.println(speed_EW_R);
      }

}

void resetuj_prethodna_vremena(){
	ns_L_pre_millis=millis();
	ns_R_pre_millis=millis();
	ew_L_pre_millis=millis();
	ew_R_pre_millis=millis();
}

void citaj_sve_enkodere(){
	citaj_enkoder_NS_L();
	citaj_enkoder_NS_R();
	citaj_enkoder_EW_L();
	citaj_enkoder_EW_R();
}

long get_new_pos_NS_L(){
  return (long)NS_L->read();
}

long get_new_pos_NS_R(){
  return (long)NS_R->read();
}

long get_new_pos_EW_L(){
  return (long)EW_L->read();
}

long get_new_pos_EW_R(){
  return (long)EW_R->read();
}

void citaj_enkoder_NS_L(){

	long newPosition = NS_L->read();
  	if (newPosition != enkoder_NS_L_old) {
    	enkoder_NS_L_old = newPosition;
    	if(debug_speed){
        Serial.print(" Debug SpeedControl NS_L-- ");
    		Serial.println(newPosition);
    	}
  	}

}
void citaj_enkoder_NS_R(){

	long newPosition = NS_R->read();

  	if (newPosition != enkoder_NS_R_old) {

    	enkoder_NS_R_old = newPosition;
    	if(debug_speed){
        Serial.print(" Debug SpeedControl NS_R-- ");
    		Serial.println(newPosition);
    	}
  	}
}
void citaj_enkoder_EW_L(){

	long newPosition = EW_L->read();

  	if (newPosition != enkoder_EW_L_old) {

    	enkoder_EW_L_old = newPosition;
    	if(debug_speed){
        Serial.print(" Debug SpeedControl EW_L-- ");
    		Serial.println(newPosition);
    	}
  	}
}
void citaj_enkoder_EW_R(){

	long newPosition = EW_R->read();

  	if (newPosition != enkoder_EW_R_old) {

    	enkoder_EW_R_old = newPosition;
    	if(debug_speed){
        Serial.print(" Debug SpeedControl EW_R-- ");
    		Serial.println(newPosition);
    	}
  	}
}
