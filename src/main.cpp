
#include <Arduino.h>
#include "FlexCAN_util.hpp"



// void clock();
void heartBeat();

CAN_message_t msg;

uint8_t buf[] = {0x0A, 0x14, 0x00, 0x64, 0x80, 0x40, 0x20, 0x10};



int main(void)
{


    init_can();

    // load_can(0x100, true, buf);

    

    while (true)
    {

        // WriteCAN(msg);

        load_can(0x100, true, buf);

        heartBeat();

    }
    
}

// -------------------------------------------------------
// Lets me know that the teensy is still working

void heartBeat()
{

    digitalWrite(13, HIGH);

    delay(100);

    digitalWrite(13, LOW);

    delay(100);

    digitalWrite(13, HIGH);

    delay(100);

    digitalWrite(13, LOW);

    delay(1200);
}

// rudamentary clock
void clock()
{

    digitalWrite(13, HIGH);

    delayMicroseconds(100);

    digitalWrite(13, LOW);

    delayMicroseconds(100);

}