#include "mbed.h"

BusIn bus(PG_0, PG_1, PG_2, PG_3);
int swVal;

DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    // Turn OFF the red LED
    redLED = 0;

    bus[2].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    
    while (true) {
        
        do{
            swVal = bus;
        } while (swVal < 15);

        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        do{
            swVal = bus;
        } while (swVal > 0);

        //Wait for noise to settle
        wait_us(10000);        

    }
}


