// BK1088 AM (basic radio)

#include <Wire.h>

#define CHIP_ADDRESS 0x40

// frequency and band in kHz
int frequency = 690;
int band = 520;

void setup() {

    // am channel formula
    int channel = (frequency - band) / 1;

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
        (0b00101001),
        (0b00000000)
    );
    delay(100);

    //// band config (05h)
    i2cWrite(
        CHIP_ADDRESS,
        (0b00001010),
        (0b00111100),
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
