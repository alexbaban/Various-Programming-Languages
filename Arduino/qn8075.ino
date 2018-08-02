// QN8075

#include <Wire.h>

int channel = 0;
double frequency = 96.9;


void setup() {
  // put your setup code here, to run once:

   // channel index formula
   channel = (frequency - 60) / 0.05;

   Wire.begin();
   
   Wire.beginTransmission(0x10);

   // register 00h
   Wire.write(0b00000000);
   // data
   Wire.write(0b11000001);
   
   Wire.endTransmission();   
   delay(100);
   
      
   Wire.beginTransmission(0x10);

   // register 07h
   Wire.write(0b00000111);
   // data
   Wire.write(channel & 0xFF);
   
   Wire.endTransmission();   
   delay(100);
   
       
   Wire.beginTransmission(0x10);

   // register 0Ah
   Wire.write(0b00001010);
   // data
   Wire.write(0b01111000 | (channel >> 8));
   
   Wire.endTransmission();   
   delay(100);


   Wire.beginTransmission(0x10);

   // register 00h
   Wire.write(0b00000000);
   // data
   Wire.write(0b00010001);
   
   Wire.endTransmission();   
   delay(100);
      
}

void loop() {
  // put your main code here, to run repeatedly:

}
