/*
Biblioteka za kontrolu motora na robotu za Eurobot takmicenje.
Koristimo omnidirekcione tockove.

by Aleksandar Todorovic & Nemanja Zaric
 */

#include "MotorControl.h"
#include "SpeedControl.h"

boolean debug_motor=true;

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

void vozi_nkoraka_napred(uint8_t brzina,long koraka){      //kretanje pravolinijski napred nazad levo desno za odredjeni broj pulseva enkodera :)
                                                              //nisam siguran kako ce da radi, moram da testiram, pa cu da ubacim i pid za brzinu
  koraka*=700;
  resetuj_prethodna_vremena();
  zaustavi();
  long newPosition = NS_L.read();

  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);

  //if (newPosition != enkoder_NS_L_old) {
  while(abs(newPosition - enkoder_NS_L_old) <= koraka){

    racunaj_brzinu_NS_L();
    racunaj_brzinu_NS_R();

    if (debug_motor)
    {
      Serial.print(" newPosition: ");
      Serial.print(newPosition);
      Serial.print(" enkoder_NS_L_old: ");
      Serial.print(enkoder_NS_L_old);
      Serial.print(" delta position= ");
      Serial.println(abs(newPosition- enkoder_NS_L_old));
    }
    newPosition = NS_L.read();
  }
}

void vozi_napred(uint8_t brzina){			//kretanje pravolinijski napred nazad levo desno :)
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_nazad(uint8_t brzina){
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  analogWrite(MOTOR_NS_L_PWM, brzina);
  analogWrite(MOTOR_NS_R_PWM, brzina);
}
void vozi_levo(uint8_t brzina){
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  analogWrite(MOTOR_EW_L_PWM, brzina);
  analogWrite(MOTOR_EW_R_PWM, brzina);
}
void vozi_desno(uint8_t brzina){
  resetuj_prethodna_vremena();
  zaustavi();
  digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  analogWrite(MOTOR_EW_L_PWM, brzina);
  analogWrite(MOTOR_EW_R_PWM, brzina);
}
void rotiraj(boolean dir, uint8_t brzina){		//rotira ulevo ili udesno na osnovu promenljive dir oko centra robota
  resetuj_prethodna_vremena();
  zaustavi();
	if (dir)									                  //trebalo bi da naravimo da se rotira za odredjeni broj stepeni
	{
		digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  		digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  		digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  		digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
	}else{
		digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  		digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  		digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  		digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
	}
	stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_SE(uint8_t brzina){		//dijagonalan pravac jug-istok
  resetuj_prethodna_vremena();
  zaustavi();
	digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  	digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  	digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  	digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  	stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_NE(uint8_t brzina){		//dijagonalan pravac sever-istok
  resetuj_prethodna_vremena();
  zaustavi();
	digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  	digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  	digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  	digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  	stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_SW(uint8_t brzina){		//dijagonalan pravac jug-zapad
  resetuj_prethodna_vremena();
  zaustavi();
	digitalWrite(MOTOR_NS_L_DIR, DIR_CCW);
  	digitalWrite(MOTOR_NS_R_DIR, DIR_CCW);
  	digitalWrite(MOTOR_EW_L_DIR, DIR_CW);
  	digitalWrite(MOTOR_EW_R_DIR, DIR_CW);
  	stavi_brzinu_na_sve(brzina);
}
void vozi_dijagonalno_NW(uint8_t brzina){		//dijagonalan pravac sever-zapad
  resetuj_prethodna_vremena();
  zaustavi();
	digitalWrite(MOTOR_NS_L_DIR, DIR_CW);
  	digitalWrite(MOTOR_NS_R_DIR, DIR_CW);
  	digitalWrite(MOTOR_EW_L_DIR, DIR_CCW);
  	digitalWrite(MOTOR_EW_R_DIR, DIR_CCW);
  	stavi_brzinu_na_sve(brzina);
}
void stavi_brzinu_na_sve(uint8_t brzina){		//setuje pwm na svim motorima
	analogWrite(MOTOR_NS_L_PWM, brzina);
  	analogWrite(MOTOR_NS_R_PWM, brzina);
  	analogWrite(MOTOR_EW_L_PWM, brzina);
  	analogWrite(MOTOR_EW_R_PWM, brzina);
}
void zaustavi(){								//trebalo bi da vidimo kocenje kako cemo
	stavi_brzinu_na_sve(0);
  digitalWrite(MOTOR_NS_L_DIR,0);
  digitalWrite(MOTOR_EW_L_DIR,0);
  digitalWrite(MOTOR_NS_R_DIR,0);
  digitalWrite(MOTOR_EW_R_DIR,0);
}
