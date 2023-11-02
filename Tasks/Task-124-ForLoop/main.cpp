#include "mbed.h"

// DigitalOut redLED(PC_2,0);
// DigitalOut yellowLED(PC_3,0);
// DigitalOut greenLED(PC_6,0);
BusOut leds(PC_2, PC_3, PC_6);

// main() runs in its own thread in the OS
int main()
{
    while (true) {

        printf("\n\nEnter pattern between 0 and 7\n");
        int pattern;
        scanf("%d", &pattern);

        printf("\n\nEnter count between 5 and 20\n");
        int count;
        scanf("%d", &count)

        printf("\n\nEnter delay between 50 and 2000\n");
        int delay;
        scanf("%d", &delay)

        //For-Loop
        for (int n=7; n>0; n = n-1) {
            printf("n=%d\n", n);
            leds = n;
            wait_us(delay);
        }

        //2s pause
        wait_us(2000000);
    }
}

