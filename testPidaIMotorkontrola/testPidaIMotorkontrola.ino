
#include "MotorControl.h"
#include "SpeedControl.h"
#include <Encoder.h>

int d=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init();
  inicijalizuj_motore();
  delay(5000);

}

void loop() {
  
  vozi_nkoraka_napred(5,100);
  delay(5000);
 // vozi_napred(40);
  //citaj_sve_enkodere();
  //citaj_enkoder_NS_L();

}

void plotMotor(){
  long enc_old = get_new_pos_NS_L();
  long enc_new = enc_old;
  long print_timer = millis();
  double spd = 0;
  for(int i = 0; i <  256; i++){
    vozi_napred(i);
    delay(50);
    enc_new = get_new_pos_NS_L();
    spd = ((float)(enc_new - enc_old))/(millis() - print_timer);
    enc_old = enc_new;
    print_timer = millis();
    Serial.println(spd);
  }
}

