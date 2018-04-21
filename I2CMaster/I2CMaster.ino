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
    Serial.println(b);
    daljine[i++]=b;

  }

}

void posalji_zaustavi(byte n){
  Wire.beginTransmission(adrese[1]);
  Wire.write('z');
  Wire.endTransmission();
}

void posalji_napred(byte n){
  Wire.beginTransmission(adrese[1]);
  Wire.write('s');
  Wire.write(n);
  Wire.endTransmission();
}

void posalji_nazad(byte n){
  Wire.beginTransmission(adrese[1]);
  Wire.write('b');
  Wire.write(n);
  Wire.endTransmission();
}

void posalji_levo(byte n){
  Wire.beginTransmission(adrese[1]);
  Wire.write('l');
  Wire.write(n);
  Wire.endTransmission();
}

void posalji_desno(byte n){
  Wire.beginTransmission(adrese[1]);
  Wire.write('d');
  Wire.write(n);
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

  //Wire.requestFrom(adrese[1],4);

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

void barataj_voznjom(byte n){
	if (millis() - premili2 >= d){
		int p=proveri_daljine();
		if(p){

			char gde = redosled[p];
			posalji_zaustavi(n);

			switch(gde){
				case 'r' : posalji_desno(n); break;
				case 'l' : posalji_levo(n); break;
				case 'f' : posalji_nazad(n); break;
				case 'b' : posalji_napred(n); break;
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
  //if (millis() - premili >= d)
  //{
    //premili = millis();
  //uzmi_daljine();
  Wire.beginTransmission(adrese[1]);
  Wire.write('s');
  Wire.write((byte)100);
  Wire.endTransmission();
  //}
  //barataj_voznjom(n);
  delay(20000);
}
