#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("%d ", samples[m]);
    }

    float sum;
    float mean;

    greenLED = 0;

    // Automatic headlamp 
    while (true) {

        sum = 0;
        mean = 0;

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            sum += samples[m];
            wait_us(10000);          // 10ms
        }

        // TASK a. Calculate the average value in samples
        mean = sum/100;
        printf("\n%.1f\n", mean);
        // TASK b. Display to 1dp

        // TASK c. Switch green LED on when dark;

        if (mean > 5450) {
            greenLED = 1;
        }

        if (mean < 5500) {
            greenLED = 0;
        }

    }  
}


