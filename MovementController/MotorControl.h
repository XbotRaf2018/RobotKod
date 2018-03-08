#include "Arduino.h"

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define MOTOR_NS_L_DIR 5
#define MOTOR_NS_R_DIR 6
#define MOTOR_EW_L_DIR 7
#define MOTOR_EW_R_DIR 8

#define MOTOR_NS_L_PWM 3
#define MOTOR_NS_R_PWM 4
#define MOTOR_EW_L_PWM 9
#define MOTOR_EW_R_PMW 10

#define ROT_L 0
#define ROT_R 1

#define DIR_CW 0
#define DIR_CCW 1

void inicijalizuj_motore();
void vozi_napred(uint8_t brzina);
void vozi_nazad(uint8_t brzina);
void vozi_levo(uint8_t brzina);
void vozi_desno(uint8_t brzina);
void rotiraj(boolean dir);
void zaustavi();

#endif //MOTOR_CONTROL_H

