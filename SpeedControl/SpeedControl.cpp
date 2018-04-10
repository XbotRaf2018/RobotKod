/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "SpeedControl.h"

#include "MotorControl.h"
#include "pid_lib.h"

long enkoder_NS_L = 0;
long enkoder_NS_R = 0;
long enkoder_EW_L = 0;
long enkoder_EW_R = 0;

void inicijalizuj_sve_pinove(){
	pinMode(MOTOR_NS_L_EN0,OUTPUT);
	pinMode(MOTOR_NS_L_EN1,OUTPUT);

	pinMode(MOTOR_NS_R_EN0,OUTPUT);
	pinMode(MOTOR_NS_R_EN1,OUTPUT);

	pinMode(MOTOR_EW_L_EN0,OUTPUT);
	pinMode(MOTOR_EW_L_EN1,OUTPUT);

	pinMode(MOTOR_EW_R_EN0,OUTPUT);
	pinMode(MOTOR_EW_R_EN1,OUTPUT);

	inicijalizuj_motore();
}

void racunaj_brzine(){

}

void citaj_enkodere(){
	citaj_enkoder_NS_L();
	citaj_enkoder_NS_R();
	citaj_enkoder_EW_L();
	citaj_enkoder_EW_R();
}
void citaj_enkoder_NS_L(){
	if(digitalRead(MOTOR_NS_L_EN0)==1){
		enkoder_NS_L++;
	}else if(digitalRead(MOTOR_NS_L_EN1)==1){
		enkoder_NS_L--;
	}
}
void citaj_enkoder_NS_R(){
	if(digitalRead(MOTOR_NS_R_EN0)==1){
		enkoder_NS_L++;
	}else if(digitalRead(MOTOR_NS_R_EN1)==1){
		enkoder_NS_L--;
	}
}
void citaj_enkoder_EW_L(){
	if(digitalRead(MOTOR_EW_L_EN0)==1){
		enkoder_NS_L++;
	}else if(digitalRead(MOTOR_EW_L_EN1)==1){
		enkoder_NS_L--;
	}
}
void citaj_enkoder_EW_R(){
	if(digitalRead(MOTOR_EW_R_EN0)==1){
		enkoder_NS_L++;
	}else if(digitalRead(MOTOR_EW_R_EN1)==1){
		enkoder_NS_L--;
	}
}