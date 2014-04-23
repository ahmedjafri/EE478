#include <p18f25k22.h>
#include <usart.h>
#include "uart_interrupts.h"

//Interrupt
#pragma code
#pragma interrupthigh low_vector

char Rx1buffer;      // create a buffer for Rx1
char data;

 #pragma code low_vector = 0x08  // jump to the address for the low priority ISR interrupt
 void low_vector(void)
 {
   _asm goto low_isr _endasm
 }

#pragma interrupt low_isr
 void low_isr(void)
 {
   if (PIR1bits.RCIF == 1 )//&& DataRdy1USART() == 1)   // see if there is data in the read buffer for USART1
   {
      Rx1buffer = Read1USART();
      Write1USART(Rx1buffer);
      PIR1bits.RCIF = 0;
   }

   //data = RCREG;
   //PIR1bits.RCIF = 0;
   //INTCONbits.TMR0IF = 0;
 }

void setupInterrupts(void)
{
   
    RCONbits.IPEN = 1;      // Enable priority interrupts
   INTCONbits.GIEL = 1;     // Enable global interrupts
   INTCONbits.GIEH = 1;     // Enable global interrupts
   INTCONbits.PEIE = 1;    // peripheral interrupts
   //INTCON2bits.TMR0IP = 1; // Setting Timer0's interrupt to high priority
   IPR1bits.RC1IP = 0;     // set Rx1 as a low priority interrupt
   PIE1bits.RC1IE = 1;     // Enable Rx1 interrupt
   PIE1bits.TXIE = 1;
   PIE1bits.RCIE = 1;



}