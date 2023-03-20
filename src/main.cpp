
#include <Arduino.h>
#include <FlexCAN_T4.h>

#include "FlexCAN_util.hpp"





void heartBeat();




int main(void)
{

    CAN_message_t msg;

    msg.id = 0x100;
    msg.len = 8;
    msg.flags.extended = 0;
    msg.flags.remote = 0;
    msg.flags.overrun = 0;
    msg.flags.reserved = 0;
    msg.buf[0] = 10;
    msg.buf[1] = 20;
    msg.buf[2] = 0;
    msg.buf[3] = 100;
    msg.buf[4] = 128;
    msg.buf[5] = 64;
    msg.buf[6] = 32;
    msg.buf[7] = 16;


    // Serial1.begin(9600);

    init_can();

    while (true)
    {

        WriteCAN(msg);

        //heartBeat();

    }
    
}

// void writeCAN(CAN_message_t msg)
// {

//     //delay(1000);

//     msg.id = 0x2D;
//     msg.len = 8;
//     msg.flags.extended = 0;
//     msg.flags.remote = 0;
//     msg.flags.overrun = 0;
//     msg.flags.reserved = 0;
//     msg.buf[0] = 10;
//     msg.buf[1] = 20;
//     msg.buf[2] = 0;
//     msg.buf[3] = 100;
//     msg.buf[4] = 128;
//     msg.buf[5] = 64;
//     msg.buf[6] = 32;
//     msg.buf[7] = 16;

//     Serial.write(msg.id);
//     Serial1.write(msg.flags.extended);
//     Serial1.write(msg.flags.remote);
//     Serial1.write(msg.flags.overrun);
//     Serial1.write(msg.flags.reserved);
//     //delay(20);

//     for (int i = 0; i < 8; i++)
//     {

//         Serial.write(msg.buf[i]);

//     }

//     //delay(20);

// }

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