#include "MotorControl.h"

#include <Encoder.h>

unsigned long prev_time = 0;
unsigned long curr_time = 0;
long prev_position;
long newPosition;
int baseVal = 180;
double setpoint = 6;
double error = 0;
double Kp = 50;
int val = 100;

Encoder myEnc(11, 12);

void setup() {

  inicijalizuj_motore();
  Serial.begin(9600);

}

void loop() {

  newPosition= myEnc.read();
  curr_time = millis();
  double brzina = ((double)newPosition - prev_position)/((double)curr_time - prev_time);
  error = setpoint - brzina;
  int output = val + error * Kp ;
  vozi_napred(output);
  Serial.println(output);
  prev_position = newPosition;
  prev_time = curr_time;
  delay(100);

}
