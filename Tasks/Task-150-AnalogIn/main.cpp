#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);

DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

int main()
{

    //Test LED Bar Display
    ledDisp.enable(true);


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        unsigned short micVal   = mic.read_u16(); 

        

        if (potVal > 0x8000){
            ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
            for (unsigned int n=0; n<8; n++) {
                ledDisp = 1 << n;
                wait_us(250000);
            }
            ledDisp = 0;
        }

        if (lightVal < 0x1000){
            ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
            for (unsigned int n=0; n<8; n++) {
                ledDisp = 1 << n;
                wait_us(250000);
            }
            ledDisp = 0;
        }        

        if (micVal > 0x8500){
            ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
            for (unsigned int n=0; n<8; n++) {
                ledDisp = 1 << n;
                wait_us(250000);
            }     
            ledDisp = 0;
        }

        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %X\n", potVal);
        printf("Light Dependant Resistor: %X\n", lightVal);
        printf("Microphone: %X\n", micVal);   

        //Wait 0.25 seconds
        wait_us(250000);

    }
}

