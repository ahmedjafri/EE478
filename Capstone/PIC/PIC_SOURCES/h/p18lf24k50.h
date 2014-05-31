/*-------------------------------------------------------------------------
 * PIC18LF24K50 processor header
 *
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * (c) Copyright 1999-2013 Microchip Technology, All rights reserved
 *-------------------------------------------------------------------------*/

#ifndef __18LF24K50_H
#define __18LF24K50_H

extern volatile far  unsigned char       SRCON1;
extern volatile far  struct {
  unsigned SRRC1E:1;
  unsigned SRRC2E:1;
  unsigned SRRCKE:1;
  unsigned SRRPE:1;
  unsigned SRSC1E:1;
  unsigned SRSC2E:1;
  unsigned SRSCKE:1;
  unsigned SRSPE:1;
} SRCON1bits;
extern volatile far  unsigned char       SRCON0;
extern volatile far  union {
  struct {
    unsigned SRPR:1;
    unsigned SRPS:1;
    unsigned SRNQEN:1;
    unsigned SRQEN:1;
    unsigned SRCLK:3;
    unsigned SRLEN:1;
  };
  struct {
    unsigned :4;
    unsigned SRCLK0:1;
    unsigned SRCLK1:1;
    unsigned SRCLK2:1;
  };
} SRCON0bits;
extern volatile far  unsigned char       CCPTMRS;
extern volatile far  struct {
  unsigned C1TSEL:1;
  unsigned :2;
  unsigned C2TSEL:1;
} CCPTMRSbits;
extern volatile far  unsigned char       ANSELA;
extern volatile far  struct {
  unsigned ANSA0:1;
  unsigned ANSA1:1;
  unsigned ANSA2:1;
  unsigned ANSA3:1;
  unsigned :1;
  unsigned ANSA5:1;
} ANSELAbits;
extern volatile far  unsigned char       ANSELB;
extern volatile far  struct {
  unsigned ANSB0:1;
  unsigned ANSB1:1;
  unsigned ANSB2:1;
  unsigned ANSB3:1;
  unsigned ANSB4:1;
  unsigned ANSB5:1;
} ANSELBbits;
extern volatile far  unsigned char       ANSELC;
extern volatile far  struct {
  unsigned :2;
  unsigned ANSC2:1;
  unsigned :3;
  unsigned ANSC6:1;
  unsigned ANSC7:1;
} ANSELCbits;
extern volatile near unsigned char       UCON;
extern volatile near struct {
  unsigned :1;
  unsigned SUSPND:1;
  unsigned RESUME:1;
  unsigned USBEN:1;
  unsigned PKTDIS:1;
  unsigned SE0:1;
  unsigned PPBRST:1;
} UCONbits;
extern volatile near unsigned char       USTAT;
extern volatile near union {
  struct {
    unsigned :1;
    unsigned PPBI:1;
    unsigned DIR:1;
    unsigned ENDP:4;
  };
  struct {
    unsigned :3;
    unsigned ENDP0:1;
    unsigned ENDP1:1;
    unsigned ENDP2:1;
    unsigned ENDP3:1;
  };
} USTATbits;
extern volatile near unsigned char       UCFG;
extern volatile near union {
  struct {
    unsigned PPB:2;
    unsigned FSEN:1;
    unsigned UTRDIS:1;
    unsigned UPUEN:1;
    unsigned :1;
    unsigned UOEMON:1;
    unsigned UTEYE:1;
  };
  struct {
    unsigned PPB0:1;
    unsigned PPB1:1;
  };
} UCFGbits;
extern volatile near unsigned char       UADDR;
extern volatile near union {
  struct {
    unsigned ADDR:7;
  };
  struct {
    unsigned ADDR0:1;
    unsigned ADDR1:1;
    unsigned ADDR2:1;
    unsigned ADDR3:1;
    unsigned ADDR4:1;
    unsigned ADDR5:1;
    unsigned ADDR6:1;
  };
} UADDRbits;
extern volatile near unsigned char       UIE;
extern volatile near struct {
  unsigned URSTIE:1;
  unsigned UERRIE:1;
  unsigned ACTVIE:1;
  unsigned TRNIE:1;
  unsigned IDLEIE:1;
  unsigned STALLIE:1;
  unsigned SOFIE:1;
} UIEbits;
extern volatile near unsigned char       UIR;
extern volatile near struct {
  unsigned URSTIF:1;
  unsigned UERRIF:1;
  unsigned ACTVIF:1;
  unsigned TRNIF:1;
  unsigned IDLEIF:1;
  unsigned STALLIF:1;
  unsigned SOFIF:1;
} UIRbits;
extern volatile near unsigned char       UEIE;
extern volatile near struct {
  unsigned PIDEE:1;
  unsigned CRC5EE:1;
  unsigned CRC16EE:1;
  unsigned DFN8EE:1;
  unsigned BTOEE:1;
  unsigned :2;
  unsigned BTSEE:1;
} UEIEbits;
extern volatile near unsigned char       UEIR;
extern volatile near struct {
  unsigned PIDEF:1;
  unsigned CRC5EF:1;
  unsigned CRC16EF:1;
  unsigned DFN8EF:1;
  unsigned BTOEF:1;
  unsigned :2;
  unsigned BTSEF:1;
} UEIRbits;
extern volatile near unsigned            UFRM;
extern volatile near unsigned char       UFRML;
extern volatile near union {
  struct {
    unsigned FRM:8;
  };
  struct {
    unsigned FRM0:1;
    unsigned FRM1:1;
    unsigned FRM2:1;
    unsigned FRM3:1;
    unsigned FRM4:1;
    unsigned FRM5:1;
    unsigned FRM6:1;
    unsigned FRM7:1;
  };
} UFRMLbits;
extern volatile near unsigned char       UFRMH;
extern volatile near union {
  struct {
    unsigned FRM:3;
  };
  struct {
    unsigned FRM8:1;
    unsigned FRM9:1;
    unsigned FRM10:1;
  };
} UFRMHbits;
extern volatile near unsigned char       UEP0;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP0bits;
extern volatile near unsigned char       UEP1;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP1bits;
extern volatile near unsigned char       UEP2;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP2bits;
extern volatile near unsigned char       UEP3;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP3bits;
extern volatile near unsigned char       UEP4;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP4bits;
extern volatile near unsigned char       UEP5;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP5bits;
extern volatile near unsigned char       UEP6;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP6bits;
extern volatile near unsigned char       UEP7;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP7bits;
extern volatile near unsigned char       UEP8;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP8bits;
extern volatile near unsigned char       UEP9;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP9bits;
extern volatile near unsigned char       UEP10;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP10bits;
extern volatile near unsigned char       UEP11;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP11bits;
extern volatile near unsigned char       UEP12;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP12bits;
extern volatile near unsigned char       UEP13;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP13bits;
extern volatile near unsigned char       UEP14;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP14bits;
extern volatile near unsigned char       UEP15;
extern volatile near struct {
  unsigned EPSTALL:1;
  unsigned EPINEN:1;
  unsigned EPOUTEN:1;
  unsigned EPCONDIS:1;
  unsigned EPHSHK:1;
} UEP15bits;
extern volatile near unsigned char       SLRCON;
extern volatile near struct {
  unsigned SLRA:1;
  unsigned SLRB:1;
  unsigned SLRC:1;
} SLRCONbits;
extern volatile near unsigned char       VREFCON2;
extern volatile near union {
  struct {
    unsigned DACR:5;
  };
  struct {
    unsigned DACR0:1;
    unsigned DACR1:1;
    unsigned DACR2:1;
    unsigned DACR3:1;
    unsigned DACR4:1;
  };
} VREFCON2bits;
extern volatile near unsigned char       VREFCON1;
extern volatile near union {
  struct {
    unsigned DACNSS:1;
    unsigned :1;
    unsigned DACPSS:2;
    unsigned :1;
    unsigned DACOE:1;
    unsigned DACLPS:1;
    unsigned DACEN:1;
  };
  struct {
    unsigned :2;
    unsigned DACPSS0:1;
    unsigned DACPSS1:1;
  };
} VREFCON1bits;
extern volatile near unsigned char       VREFCON0;
extern volatile near union {
  struct {
    unsigned :2;
    unsigned TSRNG:1;
    unsigned TSEN:1;
    unsigned FVRS:2;
    unsigned FVRST:1;
    unsigned FVREN:1;
  };
  struct {
    unsigned :4;
    unsigned FVRS0:1;
    unsigned FVRS1:1;
  };
} VREFCON0bits;
extern volatile near unsigned char       PMD0;
extern volatile near union {
  struct {
    unsigned TMR1MD:1;
    unsigned TMR2MD:1;
    unsigned TMR3MD:1;
    unsigned :1;
    unsigned ACTMD:1;
    unsigned USBMD:1;
    unsigned UARTMD:1;
  };
  struct {
    unsigned :4;
    unsigned STMD:1;
    unsigned :1;
    unsigned UART1MD:1;
  };
} PMD0bits;
extern volatile near unsigned char       PMD1;
extern volatile near union {
  struct {
    unsigned CCP1MD:1;
    unsigned CCP2MD:1;
    unsigned ADCMD:1;
    unsigned CMP1MD:1;
    unsigned CMP2MD:1;
    unsigned CTMUMD:1;
    unsigned MSSPMD:1;
  };
  struct {
    unsigned :6;
    unsigned SSP1MD:1;
  };
  struct {
    unsigned :6;
    unsigned MSSP1MD:1;
  };
} PMD1bits;
extern volatile near unsigned char       PORTA;
extern volatile near union {
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
    unsigned RA7:1;
  };
  struct {
    unsigned AN0:1;
    unsigned AN1:1;
    unsigned AN2:1;
    unsigned AN3:1;
    unsigned T0CKI:1;
    unsigned AN4:1;
    unsigned OSC2:1;
  };
  struct {
    unsigned :2;
    unsigned VREFM:1;
    unsigned VREFP:1;
    unsigned :1;
    unsigned LVDIN:1;
  };
  struct {
    unsigned :5;
    unsigned HLVDIN:1;
  };
} PORTAbits;
extern volatile near unsigned char       PORTB;
extern volatile near union {
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
  struct {
    unsigned INT0:1;
    unsigned INT1:1;
    unsigned INT2:1;
    unsigned :2;
    unsigned PGM:1;
    unsigned PGC:1;
    unsigned PGD:1;
  };
} PORTBbits;
extern volatile near unsigned char       PORTC;
extern volatile near union {
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned :1;
    unsigned RC4:1;
    unsigned RC5:1;
    unsigned RC6:1;
    unsigned RC7:1;
  };
  struct {
    unsigned T1OSO:1;
    unsigned T1OSI:1;
    unsigned CCP1:1;
    unsigned :3;
    unsigned TX:1;
    unsigned RX:1;
  };
  struct {
    unsigned T13CKI:1;
    unsigned :1;
    unsigned P1A:1;
    unsigned :3;
    unsigned CK:1;
    unsigned DT:1;
  };
} PORTCbits;
extern volatile near unsigned char       PORTE;
extern volatile near struct {
  unsigned :3;
  unsigned RE3:1;
} PORTEbits;
extern volatile near unsigned char       WPUB;
extern volatile near struct {
  unsigned WPUB0:1;
  unsigned WPUB1:1;
  unsigned WPUB2:1;
  unsigned WPUB3:1;
  unsigned WPUB4:1;
  unsigned WPUB5:1;
  unsigned WPUB6:1;
  unsigned WPUB7:1;
} WPUBbits;
extern volatile near unsigned char       IOCB;
extern volatile near struct {
  unsigned :4;
  unsigned IOCB4:1;
  unsigned IOCB5:1;
  unsigned IOCB6:1;
  unsigned IOCB7:1;
} IOCBbits;
extern volatile near unsigned char       IOCC;
extern volatile near struct {
  unsigned IOCC0:1;
  unsigned IOCC1:1;
  unsigned IOCC2:1;
  unsigned :1;
  unsigned IOCC4:1;
  unsigned IOCC5:1;
  unsigned IOCC6:1;
  unsigned IOCC7:1;
} IOCCbits;
extern volatile near unsigned char       CTMUICON;
extern volatile near union {
  struct {
    unsigned IRNG:2;
    unsigned ITRIM:6;
  };
  struct {
    unsigned IRNG0:1;
    unsigned IRNG1:1;
    unsigned ITRIM0:1;
    unsigned ITRIM1:1;
    unsigned ITRIM2:1;
    unsigned ITRIM3:1;
    unsigned ITRIM4:1;
    unsigned ITRIM5:1;
  };
} CTMUICONbits;
extern volatile near unsigned char       LATA;
extern volatile near struct {
  unsigned LATA0:1;
  unsigned LATA1:1;
  unsigned LATA2:1;
  unsigned LATA3:1;
  unsigned LATA4:1;
  unsigned LATA5:1;
  unsigned LATA6:1;
  unsigned LATA7:1;
} LATAbits;
extern volatile near unsigned char       LATB;
extern volatile near struct {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
} LATBbits;
extern volatile near unsigned char       LATC;
extern volatile near struct {
  unsigned LATC0:1;
  unsigned LATC1:1;
  unsigned LATC2:1;
  unsigned :1;
  unsigned LATC4:1;
  unsigned LATC5:1;
  unsigned LATC6:1;
  unsigned LATC7:1;
} LATCbits;
extern volatile near unsigned char       CTMUCON1;
extern volatile near union {
  struct {
    unsigned EDG1STAT:1;
    unsigned EDG2STAT:1;
    unsigned EDG1SEL:2;
    unsigned EDG1POL:1;
    unsigned EDG2SEL:2;
    unsigned EDG2POL:1;
  };
  struct {
    unsigned :2;
    unsigned EDG1SEL0:1;
    unsigned EDG1SEL1:1;
    unsigned :1;
    unsigned EDG2SEL0:1;
    unsigned EDG2SEL1:1;
  };
} CTMUCON1bits;
extern volatile near unsigned char       CTMUCONL;
extern volatile near union {
  struct {
    unsigned EDG1STAT:1;
    unsigned EDG2STAT:1;
    unsigned EDG1SEL:2;
    unsigned EDG1POL:1;
    unsigned EDG2SEL:2;
    unsigned EDG2POL:1;
  };
  struct {
    unsigned :2;
    unsigned EDG1SEL0:1;
    unsigned EDG1SEL1:1;
    unsigned :1;
    unsigned EDG2SEL0:1;
    unsigned EDG2SEL1:1;
  };
} CTMUCONLbits;
extern volatile near unsigned char       CTMUCON0;
extern volatile near union {
  struct {
    unsigned CTTRIG:1;
    unsigned IDISSEN:1;
    unsigned EDGSEQEN:1;
    unsigned EDGEN:1;
    unsigned TGEN:1;
    unsigned CTMUSIDL:1;
    unsigned :1;
    unsigned CTMUEN:1;
  };
  struct {
    unsigned TRIGEN:1;
    unsigned :4;
    unsigned SIDL:1;
    unsigned :1;
    unsigned ON:1;
  };
} CTMUCON0bits;
extern volatile near unsigned char       CTMUCONH;
extern volatile near union {
  struct {
    unsigned CTTRIG:1;
    unsigned IDISSEN:1;
    unsigned EDGSEQEN:1;
    unsigned EDGEN:1;
    unsigned TGEN:1;
    unsigned CTMUSIDL:1;
    unsigned :1;
    unsigned CTMUEN:1;
  };
  struct {
    unsigned TRIGEN:1;
    unsigned :4;
    unsigned SIDL:1;
    unsigned :1;
    unsigned ON:1;
  };
} CTMUCONHbits;
extern volatile near unsigned            CCPR2;
extern volatile near unsigned char       CCPR2L;
extern volatile near unsigned char       CCPR2H;
extern volatile near unsigned char       DDRA;
extern volatile near union {
  struct {
    unsigned TRISA0:1;
    unsigned TRISA1:1;
    unsigned TRISA2:1;
    unsigned TRISA3:1;
    unsigned TRISA4:1;
    unsigned TRISA5:1;
    unsigned TRISA6:1;
    unsigned TRISA7:1;
  };
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
  };
} DDRAbits;
extern volatile near unsigned char       TRISA;
extern volatile near union {
  struct {
    unsigned TRISA0:1;
    unsigned TRISA1:1;
    unsigned TRISA2:1;
    unsigned TRISA3:1;
    unsigned TRISA4:1;
    unsigned TRISA5:1;
    unsigned TRISA6:1;
    unsigned TRISA7:1;
  };
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
  };
} TRISAbits;
extern volatile near unsigned char       DDRB;
extern volatile near union {
  struct {
    unsigned TRISB0:1;
    unsigned TRISB1:1;
    unsigned TRISB2:1;
    unsigned TRISB3:1;
    unsigned TRISB4:1;
    unsigned TRISB5:1;
    unsigned TRISB6:1;
    unsigned TRISB7:1;
  };
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
} DDRBbits;
extern volatile near unsigned char       TRISB;
extern volatile near union {
  struct {
    unsigned TRISB0:1;
    unsigned TRISB1:1;
    unsigned TRISB2:1;
    unsigned TRISB3:1;
    unsigned TRISB4:1;
    unsigned TRISB5:1;
    unsigned TRISB6:1;
    unsigned TRISB7:1;
  };
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
} TRISBbits;
extern volatile near unsigned char       DDRC;
extern volatile near union {
  struct {
    unsigned TRISC0:1;
    unsigned TRISC1:1;
    unsigned TRISC2:1;
    unsigned :1;
    unsigned TRISC4:1;
    unsigned TRISC5:1;
    unsigned TRISC6:1;
    unsigned TRISC7:1;
  };
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned :3;
    unsigned RC6:1;
    unsigned RC7:1;
  };
} DDRCbits;
extern volatile near unsigned char       TRISC;
extern volatile near union {
  struct {
    unsigned TRISC0:1;
    unsigned TRISC1:1;
    unsigned TRISC2:1;
    unsigned :1;
    unsigned TRISC4:1;
    unsigned TRISC5:1;
    unsigned TRISC6:1;
    unsigned TRISC7:1;
  };
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned :3;
    unsigned RC6:1;
    unsigned RC7:1;
  };
} TRISCbits;
extern volatile near unsigned char       CCP2CON;
extern volatile near union {
  struct {
    unsigned CCP2M:4;
    unsigned DC2B:2;
  };
  struct {
    unsigned CCP2M0:1;
    unsigned CCP2M1:1;
    unsigned CCP2M2:1;
    unsigned CCP2M3:1;
    unsigned DC2B0:1;
    unsigned DC2B1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP2Y:1;
    unsigned CCP2X:1;
  };
} CCP2CONbits;
extern volatile near unsigned char       ECCP2CON;
extern volatile near union {
  struct {
    unsigned CCP2M:4;
    unsigned DC2B:2;
  };
  struct {
    unsigned CCP2M0:1;
    unsigned CCP2M1:1;
    unsigned CCP2M2:1;
    unsigned CCP2M3:1;
    unsigned DC2B0:1;
    unsigned DC2B1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP2Y:1;
    unsigned CCP2X:1;
  };
} ECCP2CONbits;
extern volatile near unsigned char       CM1CON0;
extern volatile near union {
  struct {
    unsigned C1CH:2;
    unsigned C1R:1;
    unsigned C1SP:1;
    unsigned C1POL:1;
    unsigned C1OE:1;
    unsigned C1OUT:1;
    unsigned C1ON:1;
  };
  struct {
    unsigned C1CH0:1;
    unsigned C1CH1:1;
    unsigned CREF:1;
    unsigned :1;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned COUT1:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH:2;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
  };
} CM1CON0bits;
extern volatile near unsigned char       CM2CON0;
extern volatile near union {
  struct {
    unsigned C2CH:2;
    unsigned C2R:1;
    unsigned C2SP:1;
    unsigned C2POL:1;
    unsigned C2OE:1;
    unsigned C2OUT:1;
    unsigned C2ON:1;
  };
  struct {
    unsigned C2CH0:1;
    unsigned C2CH1:1;
    unsigned CREF:1;
    unsigned :1;
    unsigned CPOL:1;
    unsigned COE:1;
    unsigned COUT2:1;
    unsigned CON:1;
  };
  struct {
    unsigned CCH:2;
  };
  struct {
    unsigned CCH0:1;
    unsigned CCH1:1;
  };
} CM2CON0bits;
extern volatile near unsigned char       CM2CON1;
extern volatile near struct {
  unsigned C2SYNC:1;
  unsigned C1SYNC:1;
  unsigned C2HYS:1;
  unsigned C1HYS:1;
  unsigned C2RSEL:1;
  unsigned C1RSEL:1;
  unsigned MC2OUT:1;
  unsigned MC1OUT:1;
} CM2CON1bits;
extern volatile near unsigned char       OSCTUNE;
extern volatile near union {
  struct {
    unsigned TUN:7;
    unsigned SPLLMULT:1;
  };
  struct {
    unsigned TUN0:1;
    unsigned TUN1:1;
    unsigned TUN2:1;
    unsigned TUN3:1;
    unsigned TUN4:1;
    unsigned TUN5:1;
    unsigned TUN6:1;
  };
} OSCTUNEbits;
extern volatile near unsigned char       HLVDCON;
extern volatile near union {
  struct {
    unsigned HLVDL:4;
    unsigned HLVDEN:1;
    unsigned IRVST:1;
    unsigned BGVST:1;
    unsigned VDIRMAG:1;
  };
  struct {
    unsigned HLVDL0:1;
    unsigned HLVDL1:1;
    unsigned HLVDL2:1;
    unsigned HLVDL3:1;
  };
} HLVDCONbits;
extern volatile near unsigned char       PIE1;
extern volatile near union {
  struct {
    unsigned TMR1IE:1;
    unsigned TMR2IE:1;
    unsigned CCP1IE:1;
    unsigned SSPIE:1;
    unsigned TXIE:1;
    unsigned RCIE:1;
    unsigned ADIE:1;
    unsigned ACTIE:1;
  };
  struct {
    unsigned :3;
    unsigned SSP1IE:1;
    unsigned TX1IE:1;
    unsigned RC1IE:1;
    unsigned :1;
    unsigned STIE:1;
  };
} PIE1bits;
extern volatile near unsigned char       PIR1;
extern volatile near union {
  struct {
    unsigned TMR1IF:1;
    unsigned TMR2IF:1;
    unsigned CCP1IF:1;
    unsigned SSPIF:1;
    unsigned TXIF:1;
    unsigned RCIF:1;
    unsigned ADIF:1;
    unsigned ACTIF:1;
  };
  struct {
    unsigned :3;
    unsigned SSP1IF:1;
    unsigned TX1IF:1;
    unsigned RC1IF:1;
    unsigned :1;
    unsigned STIF:1;
  };
} PIR1bits;
extern volatile near unsigned char       IPR1;
extern volatile near union {
  struct {
    unsigned TMR1IP:1;
    unsigned TMR2IP:1;
    unsigned CCP1IP:1;
    unsigned SSPIP:1;
    unsigned TXIP:1;
    unsigned RCIP:1;
    unsigned ADIP:1;
    unsigned ACTIP:1;
  };
  struct {
    unsigned :3;
    unsigned SSP1IP:1;
    unsigned TX1IP:1;
    unsigned RC1IP:1;
    unsigned :1;
    unsigned STIP:1;
  };
} IPR1bits;
extern volatile near unsigned char       PIE2;
extern volatile near union {
  struct {
    unsigned CCP2IE:1;
    unsigned TMR3IE:1;
    unsigned HLVDIE:1;
    unsigned BCLIE:1;
    unsigned EEIE:1;
    unsigned C2IE:1;
    unsigned C1IE:1;
    unsigned OSCFIE:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIE:1;
    unsigned BCL1IE:1;
    unsigned :1;
    unsigned CM2IE:1;
    unsigned CM1IE:1;
  };
} PIE2bits;
extern volatile near unsigned char       PIR2;
extern volatile near union {
  struct {
    unsigned CCP2IF:1;
    unsigned TMR3IF:1;
    unsigned HLVDIF:1;
    unsigned BCLIF:1;
    unsigned EEIF:1;
    unsigned C2IF:1;
    unsigned C1IF:1;
    unsigned OSCFIF:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIF:1;
    unsigned BCL1IF:1;
    unsigned :1;
    unsigned CM2IF:1;
    unsigned CM1IF:1;
  };
} PIR2bits;
extern volatile near unsigned char       IPR2;
extern volatile near union {
  struct {
    unsigned CCP2IP:1;
    unsigned TMR3IP:1;
    unsigned HLVDIP:1;
    unsigned BCLIP:1;
    unsigned EEIP:1;
    unsigned C2IP:1;
    unsigned C1IP:1;
    unsigned OSCFIP:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIP:1;
    unsigned BCL1IP:1;
    unsigned :1;
    unsigned CM2IP:1;
    unsigned CM1IP:1;
  };
} IPR2bits;
extern volatile near unsigned char       PIE3;
extern volatile near struct {
  unsigned TMR1GIE:1;
  unsigned TMR3GIE:1;
  unsigned USBIE:1;
  unsigned CTMUIE:1;
} PIE3bits;
extern volatile near unsigned char       PIR3;
extern volatile near struct {
  unsigned TMR1GIF:1;
  unsigned TMR3GIF:1;
  unsigned USBIF:1;
  unsigned CTMUIF:1;
} PIR3bits;
extern volatile near unsigned char       IPR3;
extern volatile near struct {
  unsigned TMR1GIP:1;
  unsigned TMR3GIP:1;
  unsigned USBIP:1;
  unsigned CTMUIP:1;
} IPR3bits;
extern volatile near unsigned char       EECON1;
extern volatile near struct {
  unsigned RD:1;
  unsigned WR:1;
  unsigned WREN:1;
  unsigned WRERR:1;
  unsigned FREE:1;
  unsigned :1;
  unsigned CFGS:1;
  unsigned EEPGD:1;
} EECON1bits;
extern volatile near unsigned char       EECON2;
extern volatile near unsigned char       EEDATA;
extern volatile near unsigned char       EEADR;
extern volatile near unsigned char       RCSTA;
extern volatile near union {
  struct {
    unsigned RX9D:1;
    unsigned OERR:1;
    unsigned FERR:1;
    unsigned ADDEN:1;
    unsigned CREN:1;
    unsigned SREN:1;
    unsigned RX9:1;
    unsigned SPEN:1;
  };
  struct {
    unsigned :3;
    unsigned ADEN:1;
  };
} RCSTAbits;
extern volatile near unsigned char       RCSTA1;
extern volatile near union {
  struct {
    unsigned RX9D:1;
    unsigned OERR:1;
    unsigned FERR:1;
    unsigned ADDEN:1;
    unsigned CREN:1;
    unsigned SREN:1;
    unsigned RX9:1;
    unsigned SPEN:1;
  };
  struct {
    unsigned :3;
    unsigned ADEN:1;
  };
} RCSTA1bits;
extern volatile near unsigned char       TXSTA;
extern volatile near struct {
  unsigned TX9D:1;
  unsigned TRMT:1;
  unsigned BRGH:1;
  unsigned SENDB:1;
  unsigned SYNC:1;
  unsigned TXEN:1;
  unsigned TX9:1;
  unsigned CSRC:1;
} TXSTAbits;
extern volatile near unsigned char       TXSTA1;
extern volatile near struct {
  unsigned TX9D:1;
  unsigned TRMT:1;
  unsigned BRGH:1;
  unsigned SENDB:1;
  unsigned SYNC:1;
  unsigned TXEN:1;
  unsigned TX9:1;
  unsigned CSRC:1;
} TXSTA1bits;
extern volatile near unsigned char       TXREG;
extern volatile near unsigned char       TXREG1;
extern volatile near unsigned char       RCREG;
extern volatile near unsigned char       RCREG1;
extern volatile near unsigned char       SPBRG;
extern volatile near union {
  struct {
    unsigned SPBRG1:8;
  };
  struct {
    unsigned BRG0:1;
    unsigned BRG1:1;
    unsigned BRG2:1;
    unsigned BRG3:1;
    unsigned BRG4:1;
    unsigned BRG5:1;
    unsigned BRG6:1;
    unsigned BRG7:1;
  };
} SPBRGbits;
extern volatile near unsigned char       SPBRG1;
extern volatile near union {
  struct {
    unsigned SPBRG1:8;
  };
  struct {
    unsigned BRG0:1;
    unsigned BRG1:1;
    unsigned BRG2:1;
    unsigned BRG3:1;
    unsigned BRG4:1;
    unsigned BRG5:1;
    unsigned BRG6:1;
    unsigned BRG7:1;
  };
} SPBRG1bits;
extern volatile near unsigned char       SPBRGH;
extern volatile near union {
  struct {
    unsigned SPBRGH1:8;
  };
  struct {
    unsigned BRG8:1;
    unsigned BRG9:1;
    unsigned BRG10:1;
    unsigned BRG11:1;
    unsigned BRG12:1;
    unsigned BRG13:1;
    unsigned BRG14:1;
    unsigned BRG15:1;
  };
} SPBRGHbits;
extern volatile near unsigned char       SPBRGH1;
extern volatile near union {
  struct {
    unsigned SPBRGH1:8;
  };
  struct {
    unsigned BRG8:1;
    unsigned BRG9:1;
    unsigned BRG10:1;
    unsigned BRG11:1;
    unsigned BRG12:1;
    unsigned BRG13:1;
    unsigned BRG14:1;
    unsigned BRG15:1;
  };
} SPBRGH1bits;
extern volatile near unsigned char       T3CON;
extern volatile near union {
  struct {
    unsigned TMR3ON:1;
    unsigned RD16:1;
    unsigned NOT_T3SYNC:1;
    unsigned SOSCEN:1;
    unsigned T3CKPS:2;
    unsigned TMR3CS:2;
  };
  struct {
    unsigned :1;
    unsigned T3RD16:1;
    unsigned T3SYNC:1;
    unsigned T3SOSCEN:1;
    unsigned T3CKPS0:1;
    unsigned T3CKPS1:1;
    unsigned TMR3CS0:1;
    unsigned TMR3CS1:1;
  };
  struct {
    unsigned :3;
    unsigned T3OSCEN:1;
  };
} T3CONbits;
extern volatile near unsigned char       TMR3L;
extern volatile near unsigned char       TMR3H;
extern volatile near unsigned char       T3GCON;
extern volatile near union {
  struct {
    unsigned T3GSS:2;
    unsigned T3GVAL:1;
    unsigned T3GGO_NOT_T3DONE:1;
    unsigned T3GSPM:1;
    unsigned T3GTM:1;
    unsigned T3GPOL:1;
    unsigned TMR3GE:1;
  };
  struct {
    unsigned T3GSS0:1;
    unsigned T3GSS1:1;
    unsigned :1;
    unsigned T3GGO:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_T3DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T3DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T3GGO_NOT_DONE:1;
  };
} T3GCONbits;
extern volatile near unsigned char       ACTCON;
extern volatile near union {
  struct {
    unsigned :1;
    unsigned ACTORS:1;
    unsigned :1;
    unsigned ACTLOCK:1;
    unsigned ACTSRC:1;
    unsigned :1;
    unsigned ACTUD:1;
    unsigned ACTEN:1;
  };
  struct {
    unsigned :1;
    unsigned STOR:1;
    unsigned :1;
    unsigned STLOCK:1;
    unsigned STSRC:1;
    unsigned :1;
    unsigned STUD:1;
    unsigned STEN:1;
  };
  struct {
    unsigned :1;
    unsigned ACTOR:1;
    unsigned :4;
    unsigned ACTD:1;
    unsigned ACTSEL:1;
  };
} ACTCONbits;
extern volatile near unsigned char       STCON;
extern volatile near union {
  struct {
    unsigned :1;
    unsigned ACTORS:1;
    unsigned :1;
    unsigned ACTLOCK:1;
    unsigned ACTSRC:1;
    unsigned :1;
    unsigned ACTUD:1;
    unsigned ACTEN:1;
  };
  struct {
    unsigned :1;
    unsigned STOR:1;
    unsigned :1;
    unsigned STLOCK:1;
    unsigned STSRC:1;
    unsigned :1;
    unsigned STUD:1;
    unsigned STEN:1;
  };
  struct {
    unsigned :1;
    unsigned ACTOR:1;
    unsigned :4;
    unsigned ACTD:1;
    unsigned ACTSEL:1;
  };
} STCONbits;
extern volatile near unsigned char       ECCP1AS;
extern volatile near union {
  struct {
    unsigned PSS1BD:2;
    unsigned PSS1AC:2;
    unsigned ECCP1AS:3;
    unsigned ECCP1ASE:1;
  };
  struct {
    unsigned PSS1BD0:1;
    unsigned PSS1BD1:1;
    unsigned PSS1AC0:1;
    unsigned PSS1AC1:1;
    unsigned ECCP1AS0:1;
    unsigned ECCP1AS1:1;
    unsigned ECCP1AS2:1;
    unsigned CCP1ASE:1;
  };
  struct {
    unsigned P1SSBD:2;
    unsigned P1SSAC:2;
    unsigned CCP1AS:3;
  };
  struct {
    unsigned PSSBD0:1;
    unsigned PSSBD1:1;
    unsigned PSSAC0:1;
    unsigned PSSAC1:1;
  };
} ECCP1ASbits;
extern volatile near unsigned char       ECCP1DEL;
extern volatile near union {
  struct {
    unsigned P1DC:7;
    unsigned P1RSEN:1;
  };
  struct {
    unsigned PDC0:1;
    unsigned PDC1:1;
    unsigned PDC2:1;
    unsigned PDC3:1;
    unsigned PDC4:1;
    unsigned PDC5:1;
    unsigned PDC6:1;
    unsigned PR1SEN:1;
  };
} ECCP1DELbits;
extern volatile near unsigned char       PWM1CON;
extern volatile near union {
  struct {
    unsigned P1DC:7;
    unsigned P1RSEN:1;
  };
  struct {
    unsigned PDC0:1;
    unsigned PDC1:1;
    unsigned PDC2:1;
    unsigned PDC3:1;
    unsigned PDC4:1;
    unsigned PDC5:1;
    unsigned PDC6:1;
    unsigned PR1SEN:1;
  };
} PWM1CONbits;
extern volatile near unsigned char       BAUDCON;
extern volatile near union {
  struct {
    unsigned ABDEN:1;
    unsigned WUE:1;
    unsigned :1;
    unsigned BRG16:1;
    unsigned TXCKP:1;
    unsigned RXDTP:1;
    unsigned RCIDL:1;
    unsigned ABDOVF:1;
  };
  struct {
    unsigned :4;
    unsigned CKTXP:1;
    unsigned DTRXP:1;
  };
  struct {
    unsigned :4;
    unsigned SCKP:1;
    unsigned :1;
    unsigned RCMT:1;
  };
} BAUDCONbits;
extern volatile near unsigned char       BAUDCON1;
extern volatile near union {
  struct {
    unsigned ABDEN:1;
    unsigned WUE:1;
    unsigned :1;
    unsigned BRG16:1;
    unsigned TXCKP:1;
    unsigned RXDTP:1;
    unsigned RCIDL:1;
    unsigned ABDOVF:1;
  };
  struct {
    unsigned :4;
    unsigned CKTXP:1;
    unsigned DTRXP:1;
  };
  struct {
    unsigned :4;
    unsigned SCKP:1;
    unsigned :1;
    unsigned RCMT:1;
  };
} BAUDCON1bits;
extern volatile near unsigned char       PSTR1CON;
extern volatile near union {
  struct {
    unsigned STRA:1;
    unsigned STRB:1;
    unsigned STRC:1;
    unsigned STRD:1;
    unsigned STRSYNC:1;
  };
  struct {
    unsigned STR1A:1;
    unsigned STR1B:1;
    unsigned STR1C:1;
    unsigned STR1D:1;
    unsigned STR1SYNC:1;
  };
} PSTR1CONbits;
extern volatile near unsigned char       T2CON;
extern volatile near union {
  struct {
    unsigned T2CKPS:2;
    unsigned TMR2ON:1;
    unsigned T2OUTPS:4;
  };
  struct {
    unsigned T2CKPS0:1;
    unsigned T2CKPS1:1;
    unsigned :1;
    unsigned T2OUTPS0:1;
    unsigned T2OUTPS1:1;
    unsigned T2OUTPS2:1;
    unsigned T2OUTPS3:1;
  };
} T2CONbits;
extern volatile near unsigned char       PR2;
extern volatile near unsigned char       TMR2;
extern volatile near unsigned char       CCP1CON;
extern volatile near union {
  struct {
    unsigned CCP1M:4;
    unsigned DC1B:2;
    unsigned P1M:2;
  };
  struct {
    unsigned CCP1M0:1;
    unsigned CCP1M1:1;
    unsigned CCP1M2:1;
    unsigned CCP1M3:1;
    unsigned DC1B0:1;
    unsigned DC1B1:1;
    unsigned P1M0:1;
    unsigned P1M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP1Y:1;
    unsigned CCP1X:1;
  };
} CCP1CONbits;
extern volatile near unsigned char       ECCP1CON;
extern volatile near union {
  struct {
    unsigned CCP1M:4;
    unsigned DC1B:2;
    unsigned P1M:2;
  };
  struct {
    unsigned CCP1M0:1;
    unsigned CCP1M1:1;
    unsigned CCP1M2:1;
    unsigned CCP1M3:1;
    unsigned DC1B0:1;
    unsigned DC1B1:1;
    unsigned P1M0:1;
    unsigned P1M1:1;
  };
  struct {
    unsigned :4;
    unsigned CCP1Y:1;
    unsigned CCP1X:1;
  };
} ECCP1CONbits;
extern volatile near unsigned            CCPR1;
extern volatile near unsigned char       CCPR1L;
extern volatile near unsigned char       CCPR1H;
extern volatile near unsigned char       ADCON2;
extern volatile near union {
  struct {
    unsigned ADCS:3;
    unsigned ACQT:3;
    unsigned :1;
    unsigned ADFM:1;
  };
  struct {
    unsigned ADCS0:1;
    unsigned ADCS1:1;
    unsigned ADCS2:1;
    unsigned ACQT0:1;
    unsigned ACQT1:1;
    unsigned ACQT2:1;
  };
} ADCON2bits;
extern volatile near unsigned char       ADCON1;
extern volatile near union {
  struct {
    unsigned NVCFG:2;
    unsigned PVCFG:2;
    unsigned :3;
    unsigned TRIGSEL:1;
  };
  struct {
    unsigned NVCFG0:1;
    unsigned NVCFG1:1;
    unsigned PVCFG0:1;
    unsigned PVCFG1:1;
  };
} ADCON1bits;
extern volatile near unsigned char       ADCON0;
extern volatile near union {
  struct {
    unsigned ADON:1;
    unsigned GO_NOT_DONE:1;
    unsigned CHS:5;
  };
  struct {
    unsigned :1;
    unsigned DONE:1;
  };
  struct {
    unsigned :1;
    unsigned GO:1;
  };
  struct {
    unsigned :1;
    unsigned NOT_DONE:1;
  };
} ADCON0bits;
extern volatile near unsigned char       ADRESL;
extern volatile near unsigned char       ADRESH;
extern volatile near unsigned char       SSP1CON2;
extern volatile near struct {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned ACKSTAT:1;
  unsigned GCEN:1;
} SSP1CON2bits;
extern volatile near unsigned char       SSPCON2;
extern volatile near struct {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned ACKSTAT:1;
  unsigned GCEN:1;
} SSPCON2bits;
extern volatile near unsigned char       SSP1CON;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSP1CONbits;
extern volatile near unsigned char       SSP1CON1;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSP1CON1bits;
extern volatile near unsigned char       SSPCON;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSPCONbits;
extern volatile near unsigned char       SSP1STAT;
extern volatile near struct {
  unsigned BF:1;
  unsigned UA:1;
  unsigned R_NOT_W:1;
  unsigned S:1;
  unsigned P:1;
  unsigned D_NOT_A:1;
  unsigned CKE:1;
  unsigned SMP:1;
} SSP1STATbits;
extern volatile near unsigned char       SSPSTAT;
extern volatile near struct {
  unsigned BF:1;
  unsigned UA:1;
  unsigned R_NOT_W:1;
  unsigned S:1;
  unsigned P:1;
  unsigned D_NOT_A:1;
  unsigned CKE:1;
  unsigned SMP:1;
} SSPSTATbits;
extern volatile near unsigned char       SSP1ADD;
extern volatile near union {
  struct {
    unsigned SSP1ADD:8;
  };
  struct {
    unsigned SSP1ADD0:1;
    unsigned SSP1ADD1:1;
    unsigned SSP1ADD2:1;
    unsigned SSP1ADD3:1;
    unsigned SSP1ADD4:1;
    unsigned SSP1ADD5:1;
    unsigned SSP1ADD6:1;
    unsigned SSP1ADD7:1;
  };
} SSP1ADDbits;
extern volatile near unsigned char       SSPADD;
extern volatile near union {
  struct {
    unsigned SSP1ADD:8;
  };
  struct {
    unsigned SSP1ADD0:1;
    unsigned SSP1ADD1:1;
    unsigned SSP1ADD2:1;
    unsigned SSP1ADD3:1;
    unsigned SSP1ADD4:1;
    unsigned SSP1ADD5:1;
    unsigned SSP1ADD6:1;
    unsigned SSP1ADD7:1;
  };
} SSPADDbits;
extern volatile near unsigned char       SSP1BUF;
extern volatile near unsigned char       SSPBUF;
extern volatile near unsigned char       SSP1MSK;
extern volatile near union {
  struct {
    unsigned SSP1MSK:8;
  };
  struct {
    unsigned SSP1MSK0:1;
    unsigned SSP1MSK1:1;
    unsigned SSP1MSK2:1;
    unsigned SSP1MSK3:1;
    unsigned SSP1MSK4:1;
    unsigned SSP1MSK5:1;
    unsigned SSP1MSK6:1;
    unsigned SSP1MSK7:1;
  };
} SSP1MSKbits;
extern volatile near unsigned char       SSPMSK;
extern volatile near union {
  struct {
    unsigned SSP1MSK:8;
  };
  struct {
    unsigned SSP1MSK0:1;
    unsigned SSP1MSK1:1;
    unsigned SSP1MSK2:1;
    unsigned SSP1MSK3:1;
    unsigned SSP1MSK4:1;
    unsigned SSP1MSK5:1;
    unsigned SSP1MSK6:1;
    unsigned SSP1MSK7:1;
  };
} SSPMSKbits;
extern volatile near unsigned char       SSP1CON3;
extern volatile near struct {
  unsigned DHEN:1;
  unsigned AHEN:1;
  unsigned SBCDE:1;
  unsigned SDAHT:1;
  unsigned BOEN:1;
  unsigned SCIE:1;
  unsigned PCIE:1;
  unsigned ACKTIM:1;
} SSP1CON3bits;
extern volatile near unsigned char       SSPCON3;
extern volatile near struct {
  unsigned DHEN:1;
  unsigned AHEN:1;
  unsigned SBCDE:1;
  unsigned SDAHT:1;
  unsigned BOEN:1;
  unsigned SCIE:1;
  unsigned PCIE:1;
  unsigned ACKTIM:1;
} SSPCON3bits;
extern volatile near unsigned char       T1GCON;
extern volatile near union {
  struct {
    unsigned T1GSS:2;
    unsigned T1GVAL:1;
    unsigned T1GGO_NOT_T1DONE:1;
    unsigned T1GSPM:1;
    unsigned T1GTM:1;
    unsigned T1GPOL:1;
    unsigned TMR1GE:1;
  };
  struct {
    unsigned T1GSS0:1;
    unsigned T1GSS1:1;
    unsigned :1;
    unsigned T1GGO:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_T1DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T1DONE:1;
  };
  struct {
    unsigned :3;
    unsigned T1GGO_NOT_DONE:1;
  };
} T1GCONbits;
extern volatile near unsigned char       T1CON;
extern volatile near union {
  struct {
    unsigned TMR1ON:1;
    unsigned RD16:1;
    unsigned NOT_T1SYNC:1;
    unsigned SOSCEN:1;
    unsigned T1CKPS:2;
    unsigned TMR1CS:2;
  };
  struct {
    unsigned :1;
    unsigned T1RD16:1;
    unsigned T1SYNC:1;
    unsigned T1SOSCEN:1;
    unsigned T1CKPS0:1;
    unsigned T1CKPS1:1;
    unsigned TMR1CS0:1;
    unsigned TMR1CS1:1;
  };
  struct {
    unsigned :3;
    unsigned T1OSCEN:1;
  };
} T1CONbits;
extern volatile near unsigned char       TMR1L;
extern volatile near unsigned char       TMR1H;
extern volatile near unsigned char       RCON;
extern volatile near union {
  struct {
    unsigned NOT_BOR:1;
    unsigned NOT_POR:1;
    unsigned NOT_PD:1;
    unsigned NOT_TO:1;
    unsigned NOT_RI:1;
    unsigned :1;
    unsigned SBOREN:1;
    unsigned IPEN:1;
  };
  struct {
    unsigned BOR:1;
    unsigned POR:1;
    unsigned PD:1;
    unsigned TO:1;
    unsigned RI:1;
  };
} RCONbits;
extern volatile near unsigned char       WDTCON;
extern volatile near union {
  struct {
    unsigned SWDTEN:1;
  };
  struct {
    unsigned SWDTE:1;
  };
} WDTCONbits;
extern volatile near unsigned char       OSCCON2;
extern volatile near struct {
  unsigned LFIOFS:1;
  unsigned HFIOFR:1;
  unsigned PRISD:1;
  unsigned SOSCGO:1;
  unsigned PLLEN:1;
  unsigned INTSRC:1;
  unsigned SOSCRUN:1;
  unsigned PLLRDY:1;
} OSCCON2bits;
extern volatile near unsigned char       OSCCON;
extern volatile near union {
  struct {
    unsigned SCS:2;
    unsigned HFIOFS:1;
    unsigned OSTS:1;
    unsigned IRCF:3;
    unsigned IDLEN:1;
  };
  struct {
    unsigned SCS0:1;
    unsigned SCS1:1;
    unsigned FLTS:1;
    unsigned :1;
    unsigned IRCF0:1;
    unsigned IRCF1:1;
    unsigned IRCF2:1;
  };
} OSCCONbits;
extern volatile near unsigned char       T0CON;
extern volatile near union {
  struct {
    unsigned T0PS:3;
    unsigned PSA:1;
    unsigned T0SE:1;
    unsigned T0CS:1;
    unsigned T08BIT:1;
    unsigned TMR0ON:1;
  };
  struct {
    unsigned T0PS0:1;
    unsigned T0PS1:1;
    unsigned T0PS2:1;
  };
} T0CONbits;
extern volatile near unsigned char       TMR0L;
extern volatile near unsigned char       TMR0H;
extern          near unsigned char       STATUS;
extern          near struct {
  unsigned C:1;
  unsigned DC:1;
  unsigned Z:1;
  unsigned OV:1;
  unsigned N:1;
} STATUSbits;
extern          near unsigned            FSR2;
extern          near unsigned char       FSR2L;
extern          near unsigned char       FSR2H;
extern volatile near unsigned char       PLUSW2;
extern volatile near unsigned char       PREINC2;
extern volatile near unsigned char       POSTDEC2;
extern volatile near unsigned char       POSTINC2;
extern          near unsigned char       INDF2;
extern          near unsigned char       BSR;
extern          near unsigned            FSR1;
extern          near unsigned char       FSR1L;
extern          near unsigned char       FSR1H;
extern volatile near unsigned char       PLUSW1;
extern volatile near unsigned char       PREINC1;
extern volatile near unsigned char       POSTDEC1;
extern volatile near unsigned char       POSTINC1;
extern          near unsigned char       INDF1;
extern          near unsigned char       WREG;
extern          near unsigned            FSR0;
extern          near unsigned char       FSR0L;
extern          near unsigned char       FSR0H;
extern volatile near unsigned char       PLUSW0;
extern volatile near unsigned char       PREINC0;
extern volatile near unsigned char       POSTDEC0;
extern volatile near unsigned char       POSTINC0;
extern          near unsigned char       INDF0;
extern volatile near unsigned char       INTCON3;
extern volatile near union {
  struct {
    unsigned INT1IF:1;
    unsigned INT2IF:1;
    unsigned :1;
    unsigned INT1IE:1;
    unsigned INT2IE:1;
    unsigned :1;
    unsigned INT1IP:1;
    unsigned INT2IP:1;
  };
  struct {
    unsigned INT1F:1;
    unsigned INT2F:1;
    unsigned :1;
    unsigned INT1E:1;
    unsigned INT2E:1;
    unsigned :1;
    unsigned INT1P:1;
    unsigned INT2P:1;
  };
} INTCON3bits;
extern volatile near unsigned char       INTCON2;
extern volatile near union {
  struct {
    unsigned IOCIP:1;
    unsigned :1;
    unsigned TMR0IP:1;
    unsigned :1;
    unsigned INTEDG2:1;
    unsigned INTEDG1:1;
    unsigned INTEDG0:1;
    unsigned NOT_RBPU:1;
  };
  struct {
    unsigned :2;
    unsigned T0IP:1;
    unsigned :4;
    unsigned RBPU:1;
  };
} INTCON2bits;
extern volatile near unsigned char       INTCON;
extern volatile near union {
  struct {
    unsigned IOCIF:1;
    unsigned INT0IF:1;
    unsigned TMR0IF:1;
    unsigned IOCIE:1;
    unsigned INT0IE:1;
    unsigned TMR0IE:1;
    unsigned PEIE_GIEL:1;
    unsigned GIE_GIEH:1;
  };
  struct {
    unsigned :1;
    unsigned INT0F:1;
    unsigned T0IF:1;
    unsigned :1;
    unsigned INT0E:1;
    unsigned T0IE:1;
    unsigned PEIE:1;
    unsigned GIE:1;
  };
  struct {
    unsigned :6;
    unsigned GIEL:1;
    unsigned GIEH:1;
  };
} INTCONbits;
extern          near unsigned            PROD;
extern          near unsigned char       PRODL;
extern          near unsigned char       PRODH;
extern volatile near unsigned char       TABLAT;
extern volatile near unsigned short long TBLPTR;
extern volatile near unsigned char       TBLPTRL;
extern volatile near unsigned char       TBLPTRH;
extern volatile near unsigned char       TBLPTRU;
extern volatile near unsigned short long PC;
extern volatile near unsigned char       PCL;
extern volatile near unsigned char       PCLATH;
extern volatile near unsigned char       PCLATU;
extern volatile near unsigned char       STKPTR;
extern volatile near union {
  struct {
    unsigned STKPTR:5;
    unsigned :1;
    unsigned STKUNF:1;
    unsigned STKFUL:1;
  };
  struct {
    unsigned SP0:1;
    unsigned SP1:1;
    unsigned SP2:1;
    unsigned SP3:1;
    unsigned SP4:1;
    unsigned :2;
    unsigned STKOVF:1;
  };
} STKPTRbits;
extern          near unsigned short long TOS;
extern          near unsigned char       TOSL;
extern          near unsigned char       TOSH;
extern          near unsigned char       TOSU;

#pragma varlocate 15 SRCON1
#pragma varlocate 15 SRCON1bits
#pragma varlocate 15 SRCON0
#pragma varlocate 15 SRCON0bits
#pragma varlocate 15 CCPTMRS
#pragma varlocate 15 CCPTMRSbits
#pragma varlocate 15 ANSELA
#pragma varlocate 15 ANSELAbits
#pragma varlocate 15 ANSELB
#pragma varlocate 15 ANSELBbits
#pragma varlocate 15 ANSELC
#pragma varlocate 15 ANSELCbits

/*-------------------------------------------------------------------------
 * Some useful defines for inline assembly stuff
 *-------------------------------------------------------------------------*/
#define ACCESS 0
#define BANKED 1

/*-------------------------------------------------------------------------
 * Some useful macros for inline assembly stuff
 *-------------------------------------------------------------------------*/
#define Nop()    {_asm nop _endasm}
#define ClrWdt() {_asm clrwdt _endasm}
#define Sleep()  {_asm sleep _endasm}
#define Reset()  {_asm reset _endasm}

#define Rlcf(f,dest,access)  {_asm movlb f rlcf f,dest,access _endasm}
#define Rlncf(f,dest,access) {_asm movlb f rlncf f,dest,access _endasm}
#define Rrcf(f,dest,access)  {_asm movlb f rrcf f,dest,access _endasm}
#define Rrncf(f,dest,access) {_asm movlb f rrncf f,dest,access _endasm}
#define Swapf(f,dest,access) {_asm movlb f swapf f,dest,access _endasm }

/*-------------------------------------------------------------------------
 * A fairly inclusive set of registers to save for interrupts.
 * These are locations which are commonly used by the compiler.
 *-------------------------------------------------------------------------*/
#define INTSAVELOCS TBLPTR, TABLAT, PROD


#endif
