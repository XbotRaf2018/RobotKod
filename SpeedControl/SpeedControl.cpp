/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "SpeedControl.h"
#include <Encoder.h>
#include "MotorControl.h"
#include "pid_lib.h"

Encoder NS_L(MOTOR_NS_L_EN0,MOTOR_NS_L_EN1);
Encoder NS_R(MOTOR_NS_R_EN0,MOTOR_NS_R_EN1);
Encoder EW_L(MOTOR_EW_L_EN0,MOTOR_EW_L_EN1);
Encoder EW_R(MOTOR_EW_R_EN0,MOTOR_EW_R_EN1);

long enkoder_NS_L = -999;
long enkoder_NS_R = -999;
long enkoder_EW_L = -999;
long enkoder_EW_R = -999;

void inicijalizuj_sve_pinove(){
	// attachInterrupt(digitalPinToInterrupt(MOTOR_NS_L_EN0),citaj_enkoder_NS_L,CHANGE);
	// attachInterrupt(digitalPinToInterrupt(MOTOR_NS_L_EN1),citaj_enkoder_NS_L,CHANGE);
	// attachInterrupt(digitalPinToInterrupt(MOTOR_NS_R_EN0),citaj_enkoder_NS_R,CHANGE);
	// attachInterrupt(digitalPinToInterrupt(MOTOR_EW_L_EN0),citaj_enkoder_EW_L,CHANGE);
	// attachInterrupt(digitalPinToInterrupt(MOTOR_EW_R_EN0),citaj_enkoder_EW_R,CHANGE);

	inicijalizuj_motore();
}

void racunaj_brzine(){

}

void citaj_enkoder_NS_L(){
	if(digitalRead(MOTOR_NS_L_EN0)==digitalRead(MOTOR_NS_L_EN1)){
		enkoder_NS_L++;
	}else{
		enkoder_NS_L--;
	}
}
void citaj_enkoder_NS_R(){
	if(digitalRead(MOTOR_NS_R_EN0)==digitalRead(MOTOR_NS_R_EN1)){
		enkoder_NS_L++;
	}else{
		enkoder_NS_L--;
	}
}
void citaj_enkoder_EW_L(){
	if(digitalRead(MOTOR_EW_L_EN0)==digitalRead(MOTOR_EW_L_EN1)){
		enkoder_NS_L++;
	}else{
		enkoder_NS_L--;
	}
}
void citaj_enkoder_EW_R(){
	if(digitalRead(MOTOR_EW_R_EN0)==digitalRead(MOTOR_EW_R_EN1)){
		enkoder_NS_L++;
	}else{
		enkoder_NS_L--;
	}
}