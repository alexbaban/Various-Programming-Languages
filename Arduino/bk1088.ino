// BK1088 init

#include <Wire.h>


int channel = 0;

// fm
double frequency = 105.7;
double band = 86.95;

// am
//double frequency = 730;
//double band = 520;


void setup() {
  // put your setup code here, to run once:

  // fm channel
  channel = (frequency - band) * 10;

  // am channel
  //channel = (frequency - band) / 10;
  
  Wire.begin();

  Wire.beginTransmission(0x40);

   // register 02h
   Wire.write(0b00000100);
   // data
   Wire.write(0b00000000);
   Wire.write(0b00000001);
   
   Wire.endTransmission();
   
   delay(100);

   // fm/am receiver
   Wire.beginTransmission(0x40);

   // register 07h
   Wire.write(0b00001110);
   // data
   Wire.write(0b00001001);
   Wire.write(0b00000001);
   
   Wire.endTransmission();
   
   delay(100);
      
     
   Wire.beginTransmission(0x40);

   // register 05h
   Wire.write(0b00001010);
   // data fm
   Wire.write(0b00000001);
   Wire.write(0b11011111);

   // data am
   //Wire.write(0b00011111);
   //Wire.write(0b01111101);
   
   Wire.endTransmission();
   
   delay(100);


   Wire.beginTransmission(0x40);

   // register 03h
   Wire.write(0b00000110);

   // data
   Wire.write(0b00000000);
   Wire.write(0b00000000);

   Wire.endTransmission();
   
   delay(100);
   
   Wire.beginTransmission(0x40);

   // register 03h
   Wire.write(0b00000110);

   // data
   Wire.write(0b10000000);
   Wire.write((byte)channel);
  
   Wire.endTransmission();

   delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
