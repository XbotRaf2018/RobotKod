#include "MotorControl.h"
#include "SpeedControl.h"
#include <Encoder.h>
#include <Wire.h>

int d = 10;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(10);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  init();
  inicijalizuj_motore();

}

void loop() {
  //vozi_cm_napred(3,100);
  //delay(5000);
}

void plotMotor() {
  long enc_old = get_new_pos_NS_R();
  long enc_new = enc_old;
  long print_timer = millis();
  double spd = 0;
  for (int i = 0; i <  256; i++) {
    vozi_napred(i);
    delay(50);
    enc_new = get_new_pos_NS_R();
    spd = ((float)(enc_new - enc_old)) / (millis() - print_timer);
    enc_old = enc_new;
    print_timer = millis();
    Serial.println(enc_new);
  }
}

void receiveEvent(int n) {

  Serial.println("HELLO");
  char cmd;
  byte dist;
  if (Wire.available()) {
    cmd = Wire.read();
    dist = Wire.read();
    switch (cmd) {
      case 's': vozi_cm_napred(3, 100); Serial.println(dist); break;
    }
  }


}

