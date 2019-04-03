// BK1088 FM (basic radio)

#include <Wire.h>

#define CHIP_ADDRESS 0x40

// frequency and band in MHz
double frequency = 105.7;
double band = 87;
double spacing = 0.01;

void setup() {

    // fm channel formula
    int channel = (frequency - band) / spacing;

    Wire.begin();

    //// power up config (02h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00000100),
        (0b00000000),
        (0b00000001)
    );
    delay(100);

    //// fm/am receiver mode (07h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00001110),
        (0b00001001),
        (0b00000001)
    );
    delay(100);

    //// band, spacing, volume config (05h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00001010),
        (0b00111101),
        (0b10011111)
    );
    delay(100);

    //// prepare for next tune (03h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00000110),
        (0b00000000),
        (0b00000000)
    );
    delay(100);

    //// tune to channel (03h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00000110),
        (0b10000000 | (channel >> 8)),
        (0b11111111 & channel)
    );
    delay(100);

}

void loop() {
    // nothing

}

void i2cWrite(
    int chipAddress,
    int registerAddress,
    int msbData,
    int lsbData
) {
    Wire.beginTransmission(chipAddress);
    Wire.write(registerAddress);
    delay(5);
    Wire.write(msbData);
    delay(5);
    Wire.write(lsbData);
    delay(5);
    Wire.endTransmission();

}

// end
