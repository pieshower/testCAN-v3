

#include "FlexCAN_util.hpp"



FlexCAN_T4 <CAN1, RX_SIZE_256, TX_SIZE_16> Inverter_CAN_;

// CAN_message_t tx_msg;
// CAN_message_t rx_msg;


void init_can()
{
    // inverter can must send & receive, 6rx MB and 2tx MB
    Inverter_CAN_.begin();
    Inverter_CAN_.setBaudRate(1000000);
    Inverter_CAN_.setMaxMB(NUM_TX_MAILBOXES + NUM_RX_MAILBOXES);

    for (int i = 0; i < NUM_RX_MAILBOXES; i++)
    {

        Inverter_CAN_.setMB((FLEXCAN_MAILBOX)i, RX, STD);
        
    }

    for (int i = NUM_RX_MAILBOXES; i < (NUM_TX_MAILBOXES + NUM_RX_MAILBOXES); i++)
    {

        Inverter_CAN_.setMB((FLEXCAN_MAILBOX)i, TX, STD);

    }

    // Inverter_CAN_.mailboxStatus();

}


void ReadCAN(CAN_message_t msg)
{

    // msg = rx_msg;

    Inverter_CAN_.read(msg);

}


void WriteCAN(CAN_message_t msg)
{

    // msg = tx_msg;

    Inverter_CAN_.write(msg);

}


void load_can(uint32_t id, bool extended, uint8_t buf[])
{

    CAN_message_t tx_msg;

    tx_msg.id = id;
    tx_msg.flags.extended = extended;

    //memcpy(&tx_msg.buf[0], &buf, 8);

    for (uint8_t i = 0; i < sizeof((int)buf); i++)
    {

        tx_msg.buf[i] = buf[i];

    }

    WriteCAN(tx_msg);

}