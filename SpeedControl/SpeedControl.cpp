/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "SpeedControl.h"
#include <Encoder.h>
#include "PidLib.h"

Encoder NS_L(MOTOR_NS_L_EN0,MOTOR_NS_L_EN1);
Encoder NS_R(MOTOR_NS_R_EN0,MOTOR_NS_R_EN1);
Encoder EW_L(MOTOR_EW_L_EN0,MOTOR_EW_L_EN1);
Encoder EW_R(MOTOR_EW_R_EN0,MOTOR_EW_R_EN1);

long enkoder_NS_L_old = -999;
long enkoder_NS_R_old = -999;
long enkoder_EW_L_old = -999;
long enkoder_EW_R_old = -999;

unsigned long ns_L_pre_millis = 0;
unsigned long ns_R_pre_millis = 0;
unsigned long ew_L_pre_millis = 0;
unsigned long ew_R_pre_millis = 0;

long speed_NS_L = 0;
long speed_NS_R = 0;
long speed_EW_L = 0;
long speed_EW_R = 0;

boolean debug_speed = true;

void racunaj_brzine(){

	racunaj_brzinu_NS_L();
	racunaj_brzinu_NS_R();
	racunaj_brzinu_EW_L();
	racunaj_brzinu_EW_R();

}

void racunaj_brzinu_NS_L(){

	long newPosition = NS_L.read();

  	if (newPosition != enkoder_NS_L_old) {

  		long delta_pos = enkoder_NS_L_old - newPosition;
  		unsigned long delta_millis = millis() - ns_L_pre_millis;
  		speed_NS_L = delta_pos/delta_millis;

    	enkoder_NS_L_old = newPosition;
    	ns_L_pre_millis=millis();

    	if(debug_speed){
    		Serial.println(speed_NS_L);
    	}
  	}

}

void racunaj_brzinu_NS_R(){

	long newPosition = NS_R.read();

  	if (newPosition != enkoder_NS_R_old) {

  		long delta_pos = enkoder_NS_R_old - newPosition;
  		unsigned long delta_millis = millis() - ns_R_pre_millis;
  		speed_NS_R = delta_pos/delta_millis;

    	enkoder_NS_R_old = newPosition;
    	ns_L_pre_millis=millis();

    	if(debug_speed){
    		Serial.println(speed_NS_R);
    	}
  	}

}

void racunaj_brzinu_EW_L(){

	long newPosition = EW_L.read();

  	if (newPosition != enkoder_EW_L_old) {

  		long delta_pos = enkoder_EW_L_old - newPosition;
  		unsigned long delta_millis = millis() - ew_L_pre_millis;
  		speed_EW_L = delta_pos/delta_millis;

    	enkoder_EW_L_old = newPosition;
    	ns_L_pre_millis=millis();

    	if(debug_speed){
    		Serial.println(speed_EW_L);
    	}
  	}

}

void racunaj_brzinu_EW_R(){

	long newPosition = EW_R.read();

  	if (newPosition != enkoder_EW_R_old) {

  		long delta_pos = enkoder_EW_R_old - newPosition;
  		unsigned long delta_millis = millis() - ew_R_pre_millis;
  		speed_EW_R = delta_pos/delta_millis;

    	enkoder_EW_R_old = newPosition;
    	ns_L_pre_millis=millis();

    	if(debug_speed){
    		Serial.println(speed_EW_R);
    	}
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

void citaj_enkoder_NS_L(){

	long newPosition = NS_L.read();

  	if (newPosition != enkoder_NS_L_old) {

    	enkoder_NS_L_old = newPosition;
    	if(debug_speed){
    		Serial.println(newPosition);
    	}
  	}

}
void citaj_enkoder_NS_R(){

	long newPosition = NS_R.read();

  	if (newPosition != enkoder_NS_R_old) {

    	enkoder_NS_R_old = newPosition;
    	if(debug_speed){
    		Serial.println(newPosition);
    	}
  	}
}
void citaj_enkoder_EW_L(){

	long newPosition = EW_L.read();

  	if (newPosition != enkoder_EW_L_old) {

    	enkoder_EW_L_old = newPosition;
    	if(debug_speed){
    		Serial.println(newPosition);
    	}
  	}
}
void citaj_enkoder_EW_R(){

	long newPosition = EW_R.read();

  	if (newPosition != enkoder_EW_R_old) {

    	enkoder_EW_R_old = newPosition;
    	if(debug_speed){
    		Serial.println(newPosition);
    	}
  	}
}