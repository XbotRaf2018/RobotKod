#include "PidLib.h"
#include "MotorControl.h"
#include "SpeedControl.h"
#include <Encoder.h>
int d=10;
Encoder myEnc(22, 23);
long oldPosition=-999;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //inicijalizuj_motore();

}

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
//  Serial.print("NS_L enkoder: ");
//  Serial.print(enkoder_NS_L);
//  Serial.print(" NS_R enkoder: ");
//  Serial.print(enkoder_NS_R);
//  Serial.print(" EW_L enkoder: ");
//  Serial.print(enkoder_EW_L);
//  Serial.print(" EW_R enkoder: ");
//  Serial.println(enkoder_EW_R);

  //vozi_napred(100);
  //Serial.println("Napred");
  //delay(d);

  //vozi_nazad(100);
  //Serial.println("Nazad");
  //delay(d);

  //vozi_levo(100);
  //Serial.println("Levo");
  //delay(d);

  //vozi_desno(100);
  //Serial.println("Desno");
  //delay(d);

  //vozi_dijagonalno_SE(100);
  //Serial.println("Dij SE");
  //delay(d);

  //vozi_dijagonalno_NE(100);
  //Serial.println("Dij NE");
  //delay(d);

  //vozi_dijagonalno_SW(100);
  //Serial.println("Dij SW");
  //delay(d);

  //vozi_dijagonalno_NW(100);
  //Serial.println("Dij NW");
  //delay(d);

}
