/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "Arduino.h"

#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

#define MOTOR_NS_L_EN0 22		//pinovi za enkodere motora
#define MOTOR_NS_L_EN1 23
#define MOTOR_NS_R_EN0 2
#define MOTOR_NS_R_EN1 11
#define MOTOR_EW_L_EN0 15
#define MOTOR_EW_L_EN1 16
#define MOTOR_EW_R_EN0 20
#define MOTOR_EW_R_EN1 21

extern long enkoder_NS_L;
extern long enkoder_NS_R;
extern long enkoder_EW_L;
extern long enkoder_EW_R;

void inicijalizuj_sve_pinove();
void racunaj_brzine();
void citaj_enkoder_NS_L();
void citaj_enkoder_NS_R();
void citaj_enkoder_EW_L();
void citaj_enkoder_EW_R();

#endif