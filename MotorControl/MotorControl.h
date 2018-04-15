/*
Biblioteka za kontrolu motora na robotu za Eurobot takmicenje.
Koristimo omnidirekcione tockove.

by Aleksandar Todorovic & Nemanja Zaric
 */

#include "Arduino.h"

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define MOTOR_NS_L_DIR 5					//pinovi za smer okretanja motora
#define MOTOR_NS_R_DIR 6
#define MOTOR_EW_L_DIR 7
#define MOTOR_EW_R_DIR 8



#define MOTOR_NS_L_PWM 3					//pwm pinovi motora
#define MOTOR_NS_R_PWM 4
#define MOTOR_EW_L_PWM 9
#define MOTOR_EW_R_PWM 10

#define ROT_L 0								//smer rotacije 0-udesno, 1-ulevo
#define ROT_R 1

#define DIR_CW 0							//smer okretanja motora 0-u smeru kazaljke na satu, 1-suprotno od smera kazaljke na satu
#define DIR_CCW 1

void inicijalizuj_motore();
void vozi_nkoraka_napred(uint8_t brzina,long koraka);
void vozi_napred(uint8_t brzina);
void vozi_nazad(uint8_t brzina);
void vozi_levo(uint8_t brzina);
void vozi_desno(uint8_t brzina);
void vozi_dijagonalno_SE(uint8_t brzina);
void vozi_dijagonalno_NE(uint8_t brzina);
void vozi_dijagonalno_SW(uint8_t brzina);
void vozi_dijagonalno_NW(uint8_t brzina);
void rotiraj(boolean dir);
void stavi_brzinu_na_sve(uint8_t brzina);
void zaustavi();

#endif //MOTOR_CONTROL_H

