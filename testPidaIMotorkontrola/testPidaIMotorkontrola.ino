#include "pid_lib.h"
#include "MotorControl.h"
int d=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  inicijalizuj_motore();

}

void loop() {

  vozi_napred(100);
  Serial.println("Napred");
  delay(d);

  vozi_nazad(100);
  Serial.println("Nazad");
  delay(d);

  vozi_levo(100);
  Serial.println("Levo");
  delay(d);

  vozi_desno(100);
  Serial.println("Desno");
  delay(d);

  vozi_dijagonalno_SE(100);
  Serial.println("Dij SE");
  delay(d);

  vozi_dijagonalno_NE(100);
  Serial.println("Dij NE");
  delay(d);

  vozi_dijagonalno_SW(100);
  Serial.println("Dij SW");
  delay(d);

  vozi_dijagonalno_NW(100);
  Serial.println("Dij NW");
  delay(d);

}
