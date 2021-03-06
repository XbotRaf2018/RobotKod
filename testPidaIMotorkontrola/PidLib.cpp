/*
Biblioteka za kontrolu brzine motora koriscenjem PID algoritma na robotu za Eurobot takmicenje.
Koristimo omnidirekcione tockove.

by Nemanja Zaric
 */

#include "PidLib.h"

boolean debug_pid = 0;                //ako se setuje na serijskom portu ce se ispisivati brzina motora i pwm koji zelimo da setujemo

                                  //slede promenljive za svaki motor posebno
float tren_v_0 = 0;               //trenutna brzina motora 0 ili MOTOR_NS_L
float pre_v_0 = 0;                //prethodna brzina
int integral_0 = 0;               //integralni deo greske
int derivative_0 = 0;             //izvodni deo greske
int propo_0 = 0;                  //proporcionalni deo greske
float greska_0 = 0;               //greska u odnosu na setpoint
float pre_greska_0 = 0;           //prethodna greska
int pwm_set_0 = 0;                //pwm koji treba setovati

float tren_v_1 = 0;
float pre_v_1 = 0;
int integral_1 = 0;
int derivative_1 = 0;
int propo_1 = 0;
float greska_1 = 0;
float pre_greska_1 = 0;
int pwm_set_1 = 0;

float tren_v_2 = 0;
float pre_v_2 = 0;
int integral_2 = 0;
int derivative_2 = 0;
int propo_2 = 0;
float greska_2 = 0;
float pre_greska_2 = 0;
int pwm_set_2 = 0;

float tren_v_3 = 0;
float pre_v_3 = 0;
int integral_3 = 0;
int derivative_3 = 0;
int propo_3 = 0;
float greska_3 = 0;
float pre_greska_3 = 0;
int pwm_set_3 = 0;

int pid_const_v_0(float setpoint_v,float kp,float kd,float ki){   //pid za brzinu za svaki motor ponaosob, mora da se nasteluju kp,kd i ki
  greska_0=setpoint_v-tren_v_0;
  propo_0=greska_0;
  integral_0+=greska_0;
  derivative_0=greska_0-pre_greska_0;

  pwm_set_0=(kp*greska_0)+(ki*integral_0)+(kd*derivative_0);

  if(debug_pid)
  {
  	  Serial.print("Trenutna brzina MOTOR_NS_L: ");
  	  Serial.print(tren_v_0);
  	  Serial.print(" || ");
  	  Serial.print("Pwm koji se setuje na MOTOR_NS_L: ");
  	  Serial.print(pwm_set_0);
  	  Serial.println(" || ");
        Serial.println(tren_v_0);
  }

  if(pwm_set_0 > MAX_PWM){
  	pwm_set_0 = MAX_PWM;
  }else if (pwm_set_0 < 0)
  {
  	pwm_set_0 = 0;
  }

  pre_greska_0 = greska_0;
  pre_v_0 = tren_v_0;

  return pwm_set_0;
}

int pid_const_v_1(float setpoint_v,float kp,float kd,float ki){

  greska_1=setpoint_v-tren_v_1;
  propo_1=greska_1;
  integral_1+=greska_1;
  derivative_1=greska_1-pre_greska_1;

  pwm_set_1=(kp*greska_1)+(ki*integral_1)+(kd*derivative_1);

  if(debug_pid)
  {
      Serial.print("Trenutna brzina MOTOR_NS_R: ");
      Serial.print(tren_v_1);
      Serial.print(" || ");
      Serial.print("Pwm koji se setuje na MOTOR_NS_R: ");
      Serial.print(pwm_set_1);
      Serial.println(" || ");
        Serial.println(tren_v_1);
  }

  if(pwm_set_1 > MAX_PWM){
    pwm_set_1 = MAX_PWM;
  }else if (pwm_set_1 < 0)
  {
    pwm_set_1 = 0;
  }

  pre_greska_1 = greska_1;
  pre_v_1 = tren_v_1;

  return pwm_set_1;
}

int pid_const_v_2(float setpoint_v,float kp,float kd,float ki){

   greska_2=setpoint_v-tren_v_0;
  propo_2=greska_2;
  integral_2+=greska_2;
  derivative_2=greska_2-pre_greska_2;

  pwm_set_2=(kp*greska_2)+(ki*integral_2)+(kd*derivative_2);

  if(debug_pid)
  {
      Serial.print("Trenutna brzina MOTOR_NS_L: ");
      Serial.print(tren_v_2);
      Serial.print(" || ");
      Serial.print("Pwm koji se setuje na MOTOR_NS_L: ");
      Serial.print(pwm_set_2);
      Serial.println(" || ");
        Serial.println(tren_v_2);
  }

  if(pwm_set_2 > MAX_PWM){
    pwm_set_2 = MAX_PWM;
  }else if (pwm_set_2 < 0)
  {
    pwm_set_2 = 0;
  }

  pre_greska_2 = greska_2;
  pre_v_2 = tren_v_2;

  return pwm_set_2;
}

int pid_const_v_3(float setpoint_v,float kp,float kd,float ki){

   greska_3=setpoint_v-tren_v_0;
  propo_3=greska_3;
  integral_3+=greska_3;
  derivative_3=greska_3-pre_greska_3;

  pwm_set_3=(kp*greska_3)+(ki*integral_3)+(kd*derivative_3);

  if(debug_pid)
  {
      Serial.print("Trenutna brzina MOTOR_NS_L: ");
      Serial.print(tren_v_3);
      Serial.print(" || ");
      Serial.print("Pwm koji se setuje na MOTOR_NS_L: ");
      Serial.print(pwm_set_3);
      Serial.println(" || ");
        Serial.println(tren_v_3);
  }

  if(pwm_set_3 > MAX_PWM){
    pwm_set_3 = MAX_PWM;
  }else if (pwm_set_3 < 0)
  {
    pwm_set_3 = 0;
  }

  pre_greska_3 = greska_3;
  pre_v_3 = tren_v_3;

  return pwm_set_3;
}
