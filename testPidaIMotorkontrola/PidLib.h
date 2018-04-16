/*
Biblioteka za kontrolu brzine motora koriscenjem PID algoritma na robotu za Eurobot takmicenje.
Koristimo omnidirekcione tockove.

by Nemanja Zaric
 */

#include "Arduino.h"

#ifndef PID_LIB_H
#define PID_LIB_H

#define MOTOR_NS_L 0		//konstante za odabir motora (ovde redudantno verovatno da se prebaci u drugi lib)
#define MOTOR_NS_R 1
#define MOTOR_EW_L 2
#define MOTOR_EW_R 3

#define MAX_PWM 255			//maksimalna vrednost pwm-a koju zelimo

extern float tren_v_0;
extern float tren_v_1;

int pid_const_v_0(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_1(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_2(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_3(int setpoint_v,float kp,float kd,float ki);

#endif
