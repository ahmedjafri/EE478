#include <i2c.h>
#include "p18f25k22.h"
#include "i2c_slave.h"

unsigned char tempAddr, tempData;

extern unsigned char recievedData;

// This is the code for at the high priority vector
#pragma code high_vector = 0x08
void high_vector(void)
{ 
    _asm goto highPriorityISR _endasm
}
#pragma code


unsigned char toggleLED;
extern unsigned char voltage;

// The actual high priority ISR
#pragma interrupt highPriorityISR
void highPriorityISR() {
    // Check for SSP interrupt, reading address
    toggleLED = 1;
    recievedData = RECIEVED;
    if (PIR1bits.SSP1IF == 1 && SSP1STATbits.BF == 1 && SSP1STATbits.D_A == 0) {

        tempAddr = SSP1BUF;  //read addr from buffer
        SSP1STATbits.BF = 0; //clear buffer (unnecessary?)
        if (SSP1STATbits.R_NOT_W == 1)      //master is waiting for a read
        {
            SSP1STATbits.R_NOT_W = 0;
            WriteI2C1(voltage);
            //SSP1BUF = 0xA6;     //write to buffer
        }

    }
    //Check for SSP interrupt, reading data // this works
    else if (PIR1bits.SSP1IF == 1 && SSP1STATbits.BF == 1 && SSP1STATbits.R_NOT_W == 0 && SSP1STATbits.D_A == 1 )
    {
        tempData = SSP1BUF;

    }
    //interrupt for sending data back, getting address // NEVER GETS TO THIS!!
 /* else if ( PIR1bits.SSP1IF == 1 && SSP1STATbits.BF == 1 && SSP1STATbits.R_NOT_W == 1 && SSP1STATbits.D_A == 1 )
    {
        //SSP1STATbits.BF = 0; //clear buffer
        tempData = WriteI2C1(0xA6);  //test with temp data, check return val//-2 = acknowledged
        //SSP1BUF = 0xA6;     //write to buffer

    }
 */

    PIR1bits.SSP1IF = 0; // Clear the interrupt flag
    return;
}

void setupInterrupts(void)
{

   RCONbits.IPEN = 1;       // Enable priority interrupts
   INTCONbits.GIEL = 1;     // Enable global interrupts
   INTCONbits.GIEH = 1;     // Enable global interrupts
   INTCONbits.PEIE = 1;     // peripheral interrupts

   //INTCON &= 0x3f;
   PIE1bits.SSP1IE = 1;      // Enable SSP Interrupt
   IPR1bits.SSP1IP = 1;      // Set SSP interrupt to high


}