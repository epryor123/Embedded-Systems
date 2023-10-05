#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
    red = 0;
    amber = 0;
    green = 0;

    //lcd.cls();
    //lcd.puts("TASK-104");

    while (true)
    {
        red = 1;
        lcd.cls();
        lcd.puts("RED");
        wait_us(10000000);

        amber = 1;
        lcd.cls();
        lcd.puts("Amber");
        wait_us(2000000);
        red = 0;
        amber = 0;

        green = 1;
        lcd.cls();
        lcd.puts("Green");    
        wait_us(10000000);
        green = 0;

        amber = 1;
        lcd.cls();
        lcd.puts("Amber");
        wait_us(2000000);
        amber = 0;



    }
}
