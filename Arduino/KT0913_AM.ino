// KT0913 (AM Radio)

#include <Wire.h>

int channel = 0;

// AM frequency in KHz
double frequency = 690;



void setup() {
  // put your setup code here, to run once:

   // channel index formula
   channel = frequency / 1;

   Wire.begin();

     
   //// AM Mode Control
   Wire.beginTransmission(0x35);

   // register address
   Wire.write(0x16);
       
   // data
   Wire.write(0b10000000);   
   Wire.write(0b00000010); 
      
   Wire.endTransmission();   
   delay(100); 
  
   
   //// AM DSP
   Wire.beginTransmission(0x35);

   // register address
   Wire.write(0x22);
  
   // data
   Wire.write(0b10100010);
   Wire.write(0b00000100);
      
   Wire.endTransmission();   
   delay(100);
  
  
   //// AM Tune Enable, AM Channel Setting
   Wire.beginTransmission(0x35);

   // register address
   Wire.write(0x17);
       
   // data
   Wire.write(0b10000000 | (channel >> 8));
   Wire.write(0b11111111 & channel);
      
   Wire.endTransmission();   
   delay(100);


   //// Standby Mode Enable, Volume Control
   Wire.beginTransmission(0x35);

   // register address
   Wire.write(0x0F);
       
   // data
   Wire.write(0b10001000);   
   Wire.write(0b00011111); 
      
   Wire.endTransmission();   
   delay(100);   
  
}



void loop() {
  // put your main code here, to run repeatedly:

}
