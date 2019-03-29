// RDA5807M 
// TEA5767 compatible mode (chip address == 0x60)

#include <Wire.h>

// frequency in MHz
const double frequency = 105.7;

void setup() {

  Serial.begin(9600);
  Serial.println("RDA5807M FM Tuner Example\n");

  Wire.begin();
  delay(500);

  // formula to calculate decimal value of PLL word
  // high side injection
  int frequencyB = 4 * (frequency * 1000000 + 225000) / 32768;
  byte frequencyH = frequencyB >> 8;
  byte frequencyL = frequencyB & 0xFF;

  // chip
  Wire.beginTransmission(0x60);

  // write data sequence: 
  // byte 1, byte 2, byte 3, byte 4 and byte 5 
  Wire.write(frequencyH & 0b00111111);
  Wire.write(frequencyL);
  Wire.write(0b10110000);
  Wire.write(0b00010000);
  Wire.write(0b01000000);

  Wire.endTransmission();

  delay(1000);
  
}

void loop() {

  // unsigned char frequencyH = 0;
  // unsigned char frequencyL = 0;
  double freqHz = 0; 

  unsigned char aBuffer[5];
  memset (aBuffer, 0, 5);
  
  // read
  Wire.requestFrom(0x60, 5);
  
  if (Wire.available()) {
    
    for (int i=0; i<5; i++) {
      aBuffer[i]= Wire.read();
    }

    freqHz = (((aBuffer[0] & 0b00111111) << 8) + aBuffer[1]) * 32768 / 4 - 225000;

    Serial.print("\nFM: ");
    Serial.print((freqHz / 1000000));
    Serial.println(" MHz");

    // frequencyH = ((aBuffer[0] & 0b00111111));
    // frequencyL = aBuffer[1];
   
    if (aBuffer[2] & 0b10000000) {
      Serial.println("STEREO");
    } else {
      Serial.println("MONO");
    }

    Serial.print("Level: ");
    Serial.println((aBuffer[3] & 0b11110000) >> 4, DEC);

    // search mode
    // (aBuffer[0] & 0b10000000)

  }

  delay(5000);
  
}
