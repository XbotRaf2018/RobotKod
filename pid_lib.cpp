#include "pid_lib.h"

int pid_const_v_0(setpoint_v,kp,kd,ki){

  greska_0=setpoint_v-tren_v_0;
  propo_0=greska_0;
  integral_0+=greska_0;
  derivative_0=greska_0-pre_greska_0;

  pwm_set_0=(kp*greska_0)+(ki*integral_0)+(kd*derivative_0);

  if(debug)
  {
	  Serial.print('Trenutna brzina MOTOR_NS_L: ');
	  Serial.print(tren_v_0);
	  Serial.print(' || ');
	  Serial.print('Pwm koji se setuje na MOTOR_NS_L: ');
	  Serial.print(pwm_set_0);
	  Serial.println(' || ');
  }

  if(pwm_set_0 > MAX_PWM){
  	pwm_set_0 = MAX_PWM;
  }else if (pwm_set_0 < -MAX_PWM)
  {
  	pwm_set_0 = -MAX_PWM
  }

  pre_greska_0 = greska_0;
  pre_p = tren_p;
  pre_v_0 = tren_v_0;

  return pwm_set_0;
}

int pid_const_v_1(setpoint_v,kp,kd,ki){

  greska_1=setpoint_v-tren_v_1;
  propo_1=greska_1;
  integral_1+=greska_1;
  derivative_1=greska_1-pre_greska_1;

  pwm_set_1=(kp*greska_1)+(ki*integral_1)+(kd*derivative_1);

  if(debug)
  {
	  Serial.print('Trenutna brzina MOTOR_NS_R: ');
	  Serial.print(tren_v_1);
	  Serial.print(' || ');
	  Serial.print('Pwm koji se setuje na MOTOR_NS_R: ');
	  Serial.print(pwm_set_1);
	  Serial.println(' || ');
  }

  if(pwm_set_1 > MAX_PWM){
  	pwm_set_1 = MAX_PWM;
  }else if (pwm_set_1 < -MAX_PWM)
  {
  	pwm_set_1 = -MAX_PWM
  }

  pre_greska_1 = greska_1;
  pre_v_1 = tren_v_1;

  return pwm_set_1;
}

int pid_const_v_2(setpoint_v,kp,kd,ki){

  greska_2=setpoint_v-tren_v_2;
  propo_2=greska_2;
  integral_2+=greska_2;
  derivative_2=greska_2-pre_greska_2;

  pwm_set_2=(kp*greska_2)+(ki*integral_2)+(kd*derivative_2);

  if (debug)
  {
  	Serial.print('Trenutna brzina MOTOR_EW_L: ');
	Serial.print(tren_v_2);
	Serial.print(' || ');
	Serial.print('Pwm koji se setuje na MOTOR_EW_L: ');
	Serial.print(pwm_set_2);
	Serial.println(' || ');
  }

  if(pwm_set_2 > MAX_PWM){
  	pwm_set_2=MAX_PWM;
  }else if (pwm_set_2 < -MAX_PWM)
  {
  	pwm_set_2=-MAX_PWM
  }

  pre_greska_2=greska_2;
  pre_v_2=tren_v_2;

  return pwm_set_2;
}

int pid_const_v_3(setpoint_v,kp,kd,ki){

  greska_3=setpoint_v-tren_v_3;
  propo_3=greska_3;
  integral_3+=greska_3;
  derivative_3=greska_3-pre_greska_3;

  pwm_set_3=(kp*greska_3)+(ki*integral_3)+(kd*derivative_3);

  if (debug)
  {
  	Serial.print('Trenutna brzina MOTOR_EW_L: ');
	Serial.print(tren_v_3);
	Serial.print(' || ');
	Serial.print('Pwm koji se setuje na MOTOR_EW_L: ');
	Serial.print(pwm_set_3);
	Serial.println(' || ');
  }

  if(pwm_set_3 > MAX_PWM){
  	pwm_set_3=MAX_PWM;
  }else if (pwm_set_3 < -MAX_PWM)
  {
  	pwm_set_3=-MAX_PWM
  }

  pre_greska_3=greska_3;
  pre_v_3=tren_v_3;

  return pwm_set_3;
}