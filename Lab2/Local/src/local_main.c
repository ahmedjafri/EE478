/* 
 * File:   Main.c
 * Author: Ahmed Jafri, Jake Yang, Anna Horstmann
 *
 * Created on April 20, 2014, 6:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p18f25k22.h>
#include <usart.h>
#include <i2c.h>

#include "../../src/utils.h"
#include "local_setup.h"
#include "../../src/sram.h"

#include "uart_interrupts.h"

extern unsigned char temp, commandBuffer, charReceived;

unsigned char bufferIndex, mode, PORTCtemp, SRAMDataBus, address;    //mode: 0 = null, 1 = Setpoint

unsigned char numOut = 0x49;
unsigned char correctedVal = 100; // 50% duty
unsigned char actualVal;
unsigned char uartBuffer[3];        //buff containing char inputs from usart
unsigned char decBuffer[3];         //buff containing conversions to decimal

char str[] = "Welcome to Remote Surgery System!\r\nEnter commands: Setpoint(s), Increment(i), Decrement(d)\r\n\0";
char errMax[] = "Number entered exceeds 100.\r\n\0";
char errMin[] = "Number entered below     0.\r\n\0";
unsigned char strLength;
int i;

extern void setup();
extern void setupUSARTAndI2C();
extern void storeData();
void getData();

extern void correctedIncrement();
extern void correctedDecrement();
extern void increment();
extern void decrement();
extern void sendDataI2C();
void correctedIncrement();
void correctedDecrement();
void increment();
void decrement();
void sendDataI2C();

void sendErrorMessageMin();
extern void sendErrorMessageMin();

void sendErrorMessageMax();
extern void sendErrorMessageMax();


void UARTSend(char *str, unsigned long strLength);

void main(void)
{
    setup();

    setupInterrupts();

    setupUSARTAndI2C();

    bufferIndex = 0;
    mode = 0;
    
    //write initial msg to user on USART        
    strLength = 94;
    i = 0;
    while(strLength > 0)
    {
        strLength--;
        // Write the next character to the UART, then increment
        delay(100);
        Write1USART(str[i]);
        delay(100);
        i++;
    }
    delay(100);

    while(1)
    {
        // Poll the slave if not receiving input from user
        if( 1 != charReceived )
        {
            // Get actual value from motor
            IdleI2C1();         // wait until bus is idle
            StartI2C1();        // send Start Condition
            IdleI2C1();
            WriteI2C1(0xA2 | 0x01);    // write address
            IdleI2C1();
            actualVal = ReadI2C1();         // read data

            StopI2C1();

            //Done getting datas

            //Compute error value
            if(actualVal < numOut)
            {
                //correctedIncrement();
            }
            else
            {
                //correctedDecrement();
            }    
        }
        else
        {
            //reset received flag
            charReceived = 0;        

            //Setpoint case
            if( 's' == commandBuffer )
            {
                mode = 1;       //indicating setpoint
                bufferIndex = 0;

                //clear buffer
                for( i = 0; i <= 2; i++ )
                {
                    decBuffer[i] = '0';
                    uartBuffer[i] = '0';
                }
            }
                
            //if in s mode
            else if (1 == mode)
            {
                //if user pressed enter (in S mode), read buffer, reset index
                if ( '\r' == commandBuffer )
                {   
                    //read buffer and convert to decimal
                    for(i = 0; i <= bufferIndex; i++)
                    {
                        decBuffer[i] = uartBuffer[i] - '0';
                    }

                    //Send msg and don't process number if > 100.
                    if (decBuffer[0] > 1)
                    {
                        sendErrorMessageMax();
                        delay(100);
                    }
                    else 
                    {
                        //convert dec buffer to single character
                        numOut = (decBuffer[0] * 100 + decBuffer[1] * 10 + decBuffer[2]) * 2;
                        correctedVal = numOut;

                        address = 0x6;
                        
                        sendDataI2C();
                    }
                    bufferIndex = 0;
                    mode = 0;   //back to no mode
                    Write1USART('\r');   //send  new line
                    delay(100);
                    Write1USART('\n');   //send  new line
                    delay(100);
                }
                //number entered while in s mode
                else
                {
                    uartBuffer[bufferIndex] = commandBuffer;
                    bufferIndex++;
                }
            }

            //Increment buffer
            else if ( 'i' == commandBuffer )
            {
                increment();
            }
            //Decrement buffer
            else if (commandBuffer == 'd')
            {
                decrement();
            }
            //at this point, data to send is 1 byte from 0 - 200
        }

    } //end of while(1)
    
    CloseI2C1();
}

void sendErrorMessageMax()
{
        strLength = 30;
        i = 0;
        while(strLength > 0)
        {
            strLength--;
            // Write the next character to the UART, then increment
            delay(100);
            Write1USART(errMax[i]);
            delay(100);
            i++;
        }
        delay(100);
}

void sendErrorMessageMin()
{
        strLength = 30;
        i = 0;
        while(strLength > 0)
        {
            strLength--;
            // Write the next character to the UART, then increment
            delay(100);
            Write1USART(errMin[i]);
            delay(100);
            i++;
        }
        delay(100);
}

void correctedIncrement()
{
    if(correctedVal <= 255)
    {
        correctedVal = correctedVal + 1;
        numOut = correctedVal;
    }

    sendDataI2C();
}

void correctedDecrement()
{
    if(correctedVal >= 0)
    {
        correctedVal = correctedVal - 1;
        numOut = correctedVal;
    }

    sendDataI2C();
}

void increment()
{
    if(numOut > 200)
    {
        sendErrorMessageMax();
    }
    else
    {
        numOut = numOut + 1;
        correctedVal = numOut;
    }

    sendDataI2C();

        //*** end of send ***
    Write1USART('\r');   //send  new line
    Write1USART('\n');   //send  new line
    delay(100);
}

void decrement()
{
    if(numOut == 0)
    {
        sendErrorMessageMin();
        correctedVal = numOut;
    }
    else
    {
        numOut = numOut - 1;
    }

    sendDataI2C();

        //*** end of send ***
    Write1USART('\r');   //send  new line
    Write1USART('\n');   //send  new line
    delay(100);
}

void sendDataI2C()
{
    //store in SRAM
    SRAMDataBus = numOut;
    storeData();

    delay(50);

    // retrieve from SRAM
    getData();

    //***Send over I2C
    IdleI2C1();         //wait until bus is idle
    StartI2C1();        //send Start Condition

    IdleI2C1();
    WriteI2C1(0xA2);    //write address

    IdleI2C1();
    WriteI2C1(SRAMDataBus);  //write data

    IdleI2C1();
    StopI2C1();
}
/* NOT USED
void UARTSend(char *str, unsigned long strLength)
{
   // Loop while there are more characters to send
   while(strLength--)
   {
       // Write the next character to the UART, then increment
       Write1USART(*str++);
   }
}
 * */

