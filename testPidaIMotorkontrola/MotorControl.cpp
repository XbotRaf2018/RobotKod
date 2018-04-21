/*
  Biblioteka za kontrolu motora na robotu za Eurobot takmicenje.
  Koristimo omnidirekcione tockove.

  by Aleksandar Todorovic & Nemanja Zaric
*/

#include "MotorControl.h"
#include "SpeedControl.h"
#include "PidLib.h"

boolean debug_motor = false;

float kp0 = 100;
float kp1 = 100;
float kp2 = 100;
float kp3 = 100;

float kd0 = 20;
float kd1 = 20;
float kd2 = 20;
float kd3 = 20;

float ki0 = 0;
float ki1 = 0;
float ki2 = 0;
float ki3 = 0;

void inicijalizuj_motore()					//inicijalizacija motora
{
  pinMode(MOTOR_NS_L_DIR, OUTPUT);
  pinMode(MOTOR_NS_R_DIR, OUTPUT);
  pinMode(MOTOR_EW_L_DIR, OUTPUT);
  pinMode(MOTOR_EW_R_DIR, OUTPUT);

  pinMode(MOTOR_NS_L_PWM, OUTPUT);
  pinMode(MOTOR_NS_R_PWM, OUTPUT);
  pinMode(MOTOR_EW_L_PWM, OUTPUT);
  pinMode(MOTOR_EW_R_PWM, OUTPUT);
}

void vozi_nkoraka_napred(uint8_t brzina, long koraka) {    //kretanje pravolinijski napred nazad levo desno za odredjeni broj pulseva enkodera :)
  //nisam siguran kako ce da radi, moram da testiram, pa cu da ubacim i pid za brzinu
  resetuj_prethodna_vremena();
  zaustavi();

  citaj_enkoder_NS_L();
  citaj_enkoder_NS_R();

  int brz0 = brzina * kp0;
  int brz1 = brzina * kp1;

  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);

  long newPosition0 = get_new_pos_NS_L();
  long oldPos0 = newPosition0;


  long newPosition1 = get_new_pos_NS_R();
  long oldPos1 = newPosition1;

  Serial.print(" newPosition: ");
  Serial.print(newPosition0);
  Serial.print(" enkoder_NS_L_old: ");
  Serial.print(oldPos0);
  Serial.print(" delta position= ");
  Serial.println(abs(newPosition0 - oldPos0));
  //if (newPosition != enkoder_NS_L_old) {
  unsigned long timer = millis();
  int sample_time = 20;
  float current_speed = 0;
  long currPos = 0;
  while (abs(newPosition0 - oldPos0) <= koraka) {
    if ((millis() - timer) >= sample_time) {
      currPos = abs(newPosition0 - oldPos0);
      current_speed = ((float)(currPos - 0)) * (brzina - 1) / (koraka / 3 - 0) + 1;

      if ((float)currPos / koraka > 0.7) {
        current_speed = brzina -  ((float)(currPos - 0.7 * koraka)) * (brzina - 0) / (koraka - 0.7 * koraka) + 1;

        //        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
      }

      if (current_speed > brzina) current_speed = brzina;
//      Serial.print("Current speed ");
//      Serial.println(current_speed);



      timer = millis();

      tren_v_0 = racunaj_brzinu_NS_L();
      tren_v_1 = racunaj_brzinu_NS_R();

      brz0 = pid_const_v_0(current_speed, kp0, kd0, ki0);
      brz1 = pid_const_v_1(current_speed, kp1, kd1, ki1);

//      Serial.print("Brz 0 - ");
//      Serial.println(brz0);
//
//      Serial.print("Brz 1 - ");
//      Serial.println(brz1);

      analogWrite(MOTOR_NS_L_PWM, brz0);
      analogWrite(MOTOR_NS_R_PWM, brz1);

      if (debug_motor)
      {
        Serial.print(" Debug MotorControl -- ");
        Serial.print(" newPosition: ");
        Serial.print(newPosition0);
        Serial.print(" enkoder_NS_L_old: ");
        Serial.print(oldPos0);
        Serial.print(" delta position= ");
        Serial.println(abs(newPosition0 - oldPos0));
      }

      newPosition0 = get_new_pos_NS_L();
      newPosition1 = get_new_pos_NS_R();
    }
  }
  zaustavi();
}

void vozi_cm_napred(uint8_t brzina, long cm) {
  int cm_u_korake = cm * (float)KORAKA_U_KRUGU / OBIM_TOCKA;
  Serial.println(cm_u_korake);
  vozi_nkoraka_napred(brzina, cm_u_korake);
}


void pid_napred_nazad(uint8_t brzina) {
  int nova_brz0 = pid_const_v_0(brzina, kp0, kd0, ki0);
  int nova_brz1 = pid_const_v_1(brzina, kp1, kd1, ki1);

  analogWrite(MOTOR_NS_L_PWM, nova_brz0);
  analogWrite(MOTOR_NS_R_PWM, nova_brz1);
}

void vozi_napred(uint8_t brzina) {			//kretanje pravolinijski napred nazad levo desno :)
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_nazad(uint8_t brzina) {
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_levo(uint8_t brzina) {
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  analogWrite(MOTOR_EW_L_PWM, brzina);
  analogWrite(MOTOR_EW_R_PWM, brzina);
}
void vozi_desno(uint8_t brzina) {
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  analogWrite(MOTOR_EW_L_PWM, brzina);
  analogWrite(MOTOR_EW_R_PWM, brzina);
}
void rotiraj(boolean dir, uint8_t brzina) {		//rotira ulevo ili udesno na osnovu promenljive dir oko centra robota
  resetuj_prethodna_vremena();
  zaustavi();
  if (dir)									                  //trebalo bi da naravimo da se rotira za odredjeni broj stepeni
  {
    digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
    digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
    digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
    digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  } else {
    digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
    digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
    digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
    digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  }
  stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_SE(uint8_t brzina) {		//dijagonalan pravac jug-istok
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_NE(uint8_t brzina) {		//dijagonalan pravac sever-istok
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_SW(uint8_t brzina) {		//dijagonalan pravac jug-zapad
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_NW(uint8_t brzina) {		//dijagonalan pravac sever-zapad
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  stavi_brzinu_na_sve(brzina);
}
void stavi_brzinu_na_sve(uint8_t brzina) {		//setuje pwm na svim motorima
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
  analogWrite(MOTOR_EW_L_PWM, brzina);
  analogWrite(MOTOR_EW_R_PWM, brzina);
}
void zaustavi() {								//trebalo bi da vidimo kocenje kako cemo
  stavi_brzinu_na_sve(0);
  digitalWrite(MOTOR_NS_L_DIR, 0);
  digitalWrite(MOTOR_EW_L_DIR, 0);
  digitalWrite(MOTOR_NS_R_DIR, 0);
  digitalWrite(MOTOR_EW_R_DIR, 0);
}

void rotiraj_nkoraka(uint8_t brzina, int koraka, int direction) {
  resetuj_prethodna_vremena();
  zaustavi();
  citaj_enkoder_NS_L();
  citaj_enkoder_NS_R();
  citaj_enkoder_EW_L();
  citaj_enkoder_EW_R();


  int brz0 = brzina * kp0;
  int brz1 = brzina * kp1;
  int brz2 = brzina * kp2;
  int brz3 = brzina * kp3;
  int dir = DIR_CW;
  if (direction) {
    dir = DIR_CCW;
  }

  digitalWrite(MOTOR_NS_L_DIR, dir);
  digitalWrite(MOTOR_NS_R_DIR, dir);
  digitalWrite(MOTOR_EW_L_DIR, dir);
  digitalWrite(MOTOR_EW_R_DIR, dir);

  long newPosition = get_new_pos_NS_L();

  long oldPos = newPosition;

  if (debug_motor) {
    Serial.print(" newPosition: ");
    Serial.print(newPosition);
    Serial.print(" enkoder_NS_L_old: ");
    Serial.print(oldPos);
    Serial.print(" delta position= ");
    Serial.println(abs(newPosition - oldPos));
  }

  unsigned long timer = millis();
  int sample_time = 20;


  float current_speed = 0;
  long currPos = 0;

  while (abs(newPosition - oldPos) <= koraka) {

    currPos = abs(newPosition - oldPos);
    current_speed = ((float)(currPos - 0)) * (brzina - 1) / (koraka / 2 - 0) + 1;
    if (current_speed > brzina) current_speed = brzina;

    if ((float)currPos / koraka > 0.6) {
      current_speed = brzina -  ((float)(currPos - 0.6 * koraka)) * (brzina - 0) / (koraka - 0.6 * koraka) + 1;

      //        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    if (millis() - timer >= sample_time) {

      timer = millis();

      tren_v_0 = racunaj_brzinu_NS_L();
      tren_v_1 = racunaj_brzinu_NS_R();
      tren_v_2 = racunaj_brzinu_EW_L();
      tren_v_3 = racunaj_brzinu_EW_R();
      brz0 = pid_const_v_0(current_speed, kp0, kd0, ki0);
      brz1 = pid_const_v_1(current_speed, kp1, kd1, ki1);
      brz2 = pid_const_v_2(current_speed, kp2, kd2, ki2);
      brz3 = pid_const_v_3(current_speed, kp3, kd3, ki3);
      analogWrite(MOTOR_NS_L_PWM, brz0);
      analogWrite(MOTOR_NS_R_PWM, brz1);
      analogWrite(MOTOR_EW_L_PWM, brz2);
      analogWrite(MOTOR_EW_R_PWM, brz3);

      if (debug_motor)
      {
        Serial.print(" Debug MotorControl -- ");
        Serial.print(" newPosition: ");
        Serial.print(newPosition);
        Serial.print(" enkoder_NS_L_old: ");
        Serial.print(oldPos);
        Serial.print(" delta position= ");
        Serial.println(abs(newPosition - oldPos));
      }

      newPosition = get_new_pos_NS_L();
    }
  }
  zaustavi();
}
