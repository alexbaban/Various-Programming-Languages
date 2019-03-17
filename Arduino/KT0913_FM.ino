// KT0913 (FM Radio)

#include <Wire.h>

int channel = 0;

// FM frequency in MHz
double frequency = 88.1;
//double frequency = 103.5;
//double frequency = 104.3;
//double frequency = 104.9;
//double frequency = 105.7;


void setup() {
  // put your setup code here, to run once:

   // channel index formula
   channel = frequency / 0.05;

   Wire.begin();


   //// FM Mode Control
   Wire.beginTransmission(0x35);

   // register
   Wire.write(0x16);
       
   // data
   Wire.write(0b00000000);   
     
   // data
   Wire.write(0b00000010); 
      
   Wire.endTransmission();   
   delay(100);


   //// FM Tune Enable, FM Channel Setting
   Wire.beginTransmission(0x35);

   // register 
   Wire.write(0x03);
       
   // data 
   Wire.write(0b10000000 | (channel >> 8)); 
        
   // data
   Wire.write(0b11111111 & channel);
      
   Wire.endTransmission();   
   delay(100);


   //// Standby Mode Enable, Volume Control
   Wire.beginTransmission(0x35);

   // register address
   Wire.write(0x0F);
       
   // data
   Wire.write(0b10001000);   
     
   // data
   Wire.write(0b00011111); 
      
   Wire.endTransmission();   
   delay(100);
      
}

void loop() {
  // put your main code here, to run repeatedly:

}
