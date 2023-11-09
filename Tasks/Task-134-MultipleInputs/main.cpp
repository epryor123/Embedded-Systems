#include "uop_msb.h"
using namespace uop_msb;

BusIn buttons(BTN1_PIN, BTN2_PIN, BTN3_PIN, BTN4_PIN);
// DigitalIn buttonA(BTN1_PIN);    //ButtonA is synonamous with buttons[0]
// DigitalIn buttonB(BTN2_PIN);
// DigitalIn buttonC(BTN3_PIN);
// DigitalIn buttonD(BTN4_PIN);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    volatile int count = 0;

    // This little C++ trick allows us to use BOTH BusIn and DigitalIn
    DigitalIn& buttonA = buttons[0];    //ButtonA is synonamous with buttons[0]
    DigitalIn& buttonB = buttons[1];
    DigitalIn& buttonC = buttons[2];
    DigitalIn& buttonD = buttons[3];

    //Configure switches
    buttonC.mode(PullDown);
    buttonD.mode(PullDown);

    //Turn ON the 7-segment display
    disp.enable(true);


    // ****************************************
    // THE FOLLOWING CODE IS NOT WELL WRITTEN!
    // IT NEEDS FIXING
    // ****************************************

    int btnA_prev = buttonA;
    int btnB_prev = buttonB;
    int btnA_now;
    int btnB_now;

    while (true) {


        btnA_now = buttonA;
        btnB_now = buttonB;

        //Wait for button A
        if (btnA_now != btnA_prev){
            if (btnA_now == 1) {
                if (count < 99 ) {
                count += 1;
                }
            }

            btnA_prev = btnA_now;
            
            disp = count;
        }


        if (btnB_now != btnB_prev){
            if (btnB_now == 1) {
                if (count > 0){
                    count -= 1;
                }
            }

            btnB_prev = btnB_now;

            disp = count;
        }
        
        //Reset condition
        if ((btnA_now == 1) && (btnB_now == 1)) {
            count = 0;
            disp = count;
        }

        // Slow it down a bit (and debounce the switches)
        wait_us(50000);  
    }
}





