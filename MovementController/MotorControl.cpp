#include "MotorControl.h"

void inicijalizuj_motore()
{
  pinMode(MOTOR_NS_L_DIR, OUTPUT);
  pinMode(MOTOR_NS_R_DIR, OUTPUT);
  pinMode(MOTOR_EW_L_DIR, OUTPUT);
  pinMode(MOTOR_EW_R_DIR, OUTPUT);

  pinMode(MOTOR_NS_L_PWM, OUTPUT);
  pinMode(MOTOR_NS_R_PWM, OUTPUT);
  pinMode(MOTOR_EW_L_PWM, OUTPUT);
  pinMode(MOTOR_EW_R_PMW, OUTPUT);
}

void vozi_napred(uint8_t brzina){
  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_nazad(uint8_t brzina){
  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_levo(uint8_t brzina);
void vozi_desno(uint8_t brzina);
void rotiraj(boolean dir);
void zaustavi();
