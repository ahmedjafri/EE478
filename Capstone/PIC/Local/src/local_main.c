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
//#include "../../src/sram.h"

#include "interrupts.h"
#include "local_setup.h"

#define SONG_LENGTH     50



//extern unsigned char temp, commandBuffer, charReceived, screenUpdated;
//
//unsigned char bufferIndex, mode, PORTCtemp, SRAMDataBus, address;    //mode: 0 = null, 1 = Setpoint
//
//unsigned char numOut = 100;         //value the user increments/decrements and sets - 50%duty to begin with
//unsigned char sendVal = 100;        //value that is sent to rhe remote channel - 50%duty to begin with
//unsigned char correctedVal = 100;   //calculated value based on remote channel feedback - 50%duty to begin with
//unsigned char actualVal;            //actual value sent back from remote channel
//
//unsigned char minCycle = 0;             //counter for cycles through while loop. used for error msg timing
//unsigned char majorCycle = 0;
//
//unsigned char uartBuffer[3];        //buff containing char inputs from usart
//unsigned char decBuffer[3];         //buff containing conversions to decimal

#pragma udata userdata

//strings to send to USART
char headerStr[] = "BRIDG \r\n\0";
char numSongsStr[] = "Number of Songs Currently in Playlist: \0";
char perPlayedStr[] = "% Played: \0";
char artistNameStr[] = "Artist: \0";
char songNameStr[] = "Song: \0";
char emptyLine[] = "\r\n\0";
unsigned char strLength;

//keep track of data sent from Pi
int indexRxData;                //0 = # of songs, 1 = %played

//variables for i2c
unsigned char recievedDataFlag;
unsigned char data;

unsigned char playlistSize;
unsigned char percentPlayed;

//external functions
extern void setup();
extern void setupUSARTAndI2C();
extern void storeData();
extern void setupLED_Pins();

//internal functions
void getData();
void UARTSend(char *str, unsigned long strLength);

void main(void)
{
    setup();
    setupUSARTAndI2C();
    setupInterrupts();
    
    setupLED_Pins();

    OpenI2C1(SLAVE_7, SLEW_OFF);
    SSP1ADD = 0xA2;

    Write1USART(0x0c);   // clear hyperterminal
    delay(10);
    puts1USART(headerStr);
    
    while(1)
    {
//        //CHANGE TO Update screen every 5 sec
//        minCycle++;             //increment cycle
//        if(minCycle % 10 == 0)
//        {
//            majorCycle++;
//            if(majorCycle % 50 == 0)
//            {
//                //screenUpdated = NOT_UPDATED;
//            }
//
        if(recievedDataFlag)
        {
            if(indexRxData == 0)    //rewrite header and write playlist
            {
                playlistSize = data;
                Write1USART(0x0c);   // clear hyperterminal
                delay(10);
                puts1USART(headerStr);
                puts1USART(emptyLine);
                delay(20);
                puts1USART(numSongsStr);
                delay(50);
                Write1USART(playlistSize);
                delay(50);
                Write1USART('\r');
                delay(10);
                Write1USART('\n');
                delay(10);
            }
            else if(indexRxData == 1)   //update the LEDs
            {
                percentPlayed = data;

                puts1USART(perPlayedStr);
                delay(50);
                Write1USART(percentPlayed);
                delay(50);
                Write1USART('\r');
                delay(10);
                Write1USART('\n');
                delay(10);


                indexRxData = 0;        //currently only have 2 modes of data
            }
//            else if (indexRxData == 2)
//            {
//                //write artist name header to usart
//                puts1USART(artistNameStr);
//                delay(50);
//
//                //1st char
//                Write1USART(data);
//            }
//            else if( indexRxData < 22)
//            {
//                Write1USART(data);
//            }
//            else if (indexRxData == 22)
//            {
//                //write song name header to usart
//                puts1USART(songNameStr);
//                delay(50);
//                Write1USART(data);
//            }
//            else if (indexRxData < 72)
//            {
//                Write1USART(data);
//
//                indexRxData = 0;
//            }

            recievedDataFlag = 0;
        }

 
    }
    CloseI2C1();
}




