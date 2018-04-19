/*
Biblioteka za kontrolu brzine

by Nemanja Zaric
 */

#include "Arduino.h"
#include <Encoder.h>

#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

#define MOTOR_NS_L_EN0 14	//pinovi za enkodere motora
#define MOTOR_NS_L_EN1 15	// Narandzsti nula
#define MOTOR_NS_R_EN0 12
#define MOTOR_NS_R_EN1 11
#define MOTOR_EW_L_EN0 20
#define MOTOR_EW_L_EN1 21
#define MOTOR_EW_R_EN0 22
#define MOTOR_EW_R_EN1 23

extern long enkoder_NS_L_old;
extern long enkoder_NS_R_old;
extern long enkoder_EW_L_old;
extern long enkoder_EW_R_old;

extern float speed_NS_L;
extern float speed_NS_R;
extern float speed_EW_L;
extern float speed_EW_R;

void init();
long get_new_pos_NS_L();
long get_new_pos_NS_R();
long get_new_pos_EW_L();
long get_new_pos_EW_R();
void racunaj_brzine();
void resetuj_prethodna_vremena();
void citaj_sve_enkodere();
void citaj_enkoder_NS_L();
void citaj_enkoder_NS_R();
void citaj_enkoder_EW_L();
void citaj_enkoder_EW_R();
float racunaj_brzinu_NS_L();
float racunaj_brzinu_NS_R();
float racunaj_brzinu_EW_L();
float racunaj_brzinu_EW_R();

#endif
