// RDA5807M 
// TEA5767 compatible mode (chip address == 0x60)

#include <Wire.h>

// frequency in MHz
const double frequency = 105.7;

void setup() {

  Wire.begin();
  delay(500);
  
  // formula to calculate decimal value of PLL word
  // high side injection
  int frequencyB = 4 * (frequency * 1000000 + 225000) / 32768;
  byte frequencyH = frequencyB >> 8;
  byte frequencyL = frequencyB & 0xFF;

  // chip
  Wire.beginTransmission(0x60);

  // data sequence: 
  // byte 1, byte 2, byte 3, byte 4 and byte 5 
  Wire.write(frequencyH & 0b00111111);
  Wire.write(frequencyL);
  Wire.write(0b10110000);
  Wire.write(0b00010000);
  Wire.write(0b01000000);

  Wire.endTransmission();
  
}

void loop() {
  // nothing
  
}
