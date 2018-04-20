#include <WireKinetis.h>
#include <Wire.h>

#define BYT_DALJINA 4
#define TRESHOLD 15

byte daljine[4] = {255,255,255,255};
int adrese[2] = {9,10};
char redosled[4] = {'l','r','f','b'};
int d=500;
byte zavrsio = 1;
unsigned long premili = 0;
unsigned long premili2 = 0;

void trazi_daljine(){

  Wire.beginTransmission(9);
  Wire.write("dD");
  Wire.endTransmission();

  //delay(20);

}

void uzmi_daljine(){

  int a = Wire.requestFrom(adrese[0],4);
  //Serial.println(a);
  int i = 0;
  while(Wire.available()){

    byte b = Wire.read();
    //Serial.println(b);
    daljine[i++]=b;

  }

}

void posalji_zaustavi(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('z');
  Wire.endTransmission();
}

void posalji_napred(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('s');
  Wire.endTransmission();
}

void posalji_nazad(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('b');
  Wire.endTransmission();
}

void posalji_levo(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('l');
  Wire.endTransmission();
}

void posalji_desno(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('d');
  Wire.endTransmission();
}

void posalji_rotiraj_c(int stepeni){
  Wire.beginTransmission(adrese[1]);
  Wire.write('r');
  Wire.write(stepeni && 0xff);
  Wire.write((stepeni >> 8) && 0xff);
  Wire.endTransmission();
}

void proveri_dal_zavrsio(){
  Wire.beginTransmission(adrese[1]);
  Wire.write('?');
  Wire.endTransmission();

  delay(20);

  Wire.requestFrom(adrese[1]);

  if(Wire.available()){
  	zavrsio = Wire.read();
  }
}

int proveri_daljine(){
	for (int i = 0; i < 4; i++)
	{
		if(daljine[i] <= TRESHOLD){
			return i;
		}
	}
	return 0;
}

void barataj_voznjom(){
	if (millis() - premili2 >= d){
		int p=proveri_daljine();
		if(p){

			char gde = redosled[p];
			posalji_zaustavi();

			switch(gde){
				case 'l' : posalji_desno(); break;
				case 'r' : posalji_levo(); break;
				case 'f' : posalji_nazad(); break;
				case 'b' : posalji_napred(); break;
				default : Serial.println("Pogresan redosled :P"); break;
			}
		}
		premili2=millis();
	}
}

void setup(){
  Serial.begin(9600);
  Wire.begin();
}

void loop(){

  if (millis() - premili >= d)
  {
  	uzmi_daljine();
  }
  barataj_voznjom();
}
