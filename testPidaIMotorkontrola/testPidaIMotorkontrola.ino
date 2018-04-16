
#include "MotorControl.h"
#include "SpeedControl.h"
#include <Encoder.h>

int d=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init();
  //inicijalizuj_motore();

}

void loop() {
  
  vozi_nkoraka_napred(40,5);
  delay(5000);
  //citaj_sve_enkodere();
  //citaj_enkoder_NS_L();

}
