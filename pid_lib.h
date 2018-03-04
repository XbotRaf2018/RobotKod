#include "Arduino.h"

#ifndef PID_LIB.H
#define PID_LIB.H

#define MOTOR_NS_L 0
#define MOTOR_NS_R 1
#define MOTOR_EW_L 2
#define MOTOR_EW_R 3

#define MAX_PWM 255

bool debug = 0;

unsigned long tren_v_0 = 0;
unsigned long pre_v_0 = 0;
int integral_0 = 0;
int derivative_0 = 0;
int propo_0 = 0;
unsigned long greska_0 = 0;
unsigned long pre_greska_0 = 0;
int pwm_set_0 = 0;

unsigned long tren_v_1 = 0;
unsigned long pre_v_1 = 0;
int integral_1 = 0;
int derivative_1 = 0;
int propo_1 = 0;
unsigned long greska_1 = 0;
unsigned long pre_greska_1 = 0;
int pwm_set_1 = 0;

unsigned long tren_v_2 = 0;
unsigned long pre_v_2 = 0;
int integral_2 = 0;
int derivative_2 = 0;
int propo_2 = 0;
unsigned long greska_2 = 0;
unsigned long pre_greska_2 = 0;
int pwm_set_2 = 0;

unsigned long tren_v_3 = 0;
unsigned long pre_v_3 = 0;
int integral_3 = 0;
int derivative_3 = 0;
int propo_3 = 0;
unsigned long greska_3 = 0;
unsigned long pre_greska_3 = 0;
int pwm_set_3 = 0;

int pid_const_v_0(setpoint_v,kp,kd,ki);
int pid_const_v_1(setpoint_v,kp,kd,ki);
int pid_const_v_2(setpoint_v,kp,kd,ki);
int pid_const_v_3(setpoint_v,kp,kd,ki);

#endif