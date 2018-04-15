/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "Arduino.h"
#include <Encoder.h>

#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

#define MOTOR_NS_L_EN0 22		//pinovi za enkodere motora
#define MOTOR_NS_L_EN1 23
#define MOTOR_NS_R_EN0 21
#define MOTOR_NS_R_EN1 20
#define MOTOR_EW_L_EN0 15
#define MOTOR_EW_L_EN1 16
#define MOTOR_EW_R_EN0 17
#define MOTOR_EW_R_EN1 18

extern Encoder NS_L;
extern Encoder NS_R;
extern Encoder EW_L;
extern Encoder EW_R;

extern long enkoder_NS_L_old;
extern long enkoder_NS_R_old;
extern long enkoder_EW_L_old;
extern long enkoder_EW_R_old;

extern long speed_NS_L;
extern long speed_NS_R;
extern long speed_EW_L;
extern long speed_EW_R;

void racunaj_brzine();
void resetuj_prethodna_vremena();
void citaj_sve_enkodere();
void citaj_enkoder_NS_L();
void citaj_enkoder_NS_R();
void citaj_enkoder_EW_L();
void citaj_enkoder_EW_R();
void racunaj_brzinu_NS_L();
void racunaj_brzinu_NS_R();
void racunaj_brzinu_EW_L();
void racunaj_brzinu_EW_R();

#endif