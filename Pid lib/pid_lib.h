#include "Arduino.h"

#ifndef PID_LIB.H
#define PID_LIB.H

#define MOTOR_NS_L 0
#define MOTOR_NS_R 1
#define MOTOR_EW_L 2
#define MOTOR_EW_R 3

#define MAX_PWM 255

int pid_const_v_0(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_1(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_2(int setpoint_v,float kp,float kd,float ki);
int pid_const_v_3(int setpoint_v,float kp,float kd,float ki);

#endif
