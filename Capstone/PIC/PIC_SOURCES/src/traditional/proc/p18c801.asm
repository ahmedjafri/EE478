        LIST P=18C801
        NOLIST
;-------------------------------------------------------------------------
; MPLAB-Cxx  PIC18C801 processor definition module
; 
; (c) Copyright 1999-2013 Microchip Technology, All rights reserved
;-------------------------------------------------------------------------

SFR_UNBANKED0       UDATA_ACS H'F80'

PORTA               
PORTAbits           RES 1     ; 0xF80
PORTB               
PORTBbits           RES 1     ; 0xF81
PORTC               
PORTCbits           RES 1     ; 0xF82
PORTD               
PORTDbits           RES 1     ; 0xF83
PORTE               
PORTEbits           RES 1     ; 0xF84
PORTF               
PORTFbits           RES 1     ; 0xF85
PORTG               
PORTGbits           RES 1     ; 0xF86
PORTH               
PORTHbits           RES 1     ; 0xF87
PORTJ               
PORTJbits           RES 1     ; 0xF88
LATA                
LATAbits            RES 1     ; 0xF89
LATB                
LATBbits            RES 1     ; 0xF8A
LATC                
LATCbits            RES 1     ; 0xF8B
LATD                
LATDbits            RES 1     ; 0xF8C
LATE                
LATEbits            RES 1     ; 0xF8D
LATF                
LATFbits            RES 1     ; 0xF8E
LATG                
LATGbits            RES 1     ; 0xF8F
LATH                
LATHbits            RES 1     ; 0xF90
LATJ                
LATJbits            RES 1     ; 0xF91
DDRA                
DDRAbits            
TRISA               
TRISAbits           RES 1     ; 0xF92
DDRB                
DDRBbits            
TRISB               
TRISBbits           RES 1     ; 0xF93
DDRC                
DDRCbits            
TRISC               
TRISCbits           RES 1     ; 0xF94
DDRD                
DDRDbits            
TRISD               
TRISDbits           RES 1     ; 0xF95
DDRE                
DDREbits            
TRISE               
TRISEbits           RES 1     ; 0xF96
DDRF                
DDRFbits            
TRISF               
TRISFbits           RES 1     ; 0xF97
DDRG                
DDRGbits            
TRISG               
TRISGbits           RES 1     ; 0xF98
DDRH                
DDRHbits            
TRISH               
TRISHbits           RES 1     ; 0xF99
DDRJ                
DDRJbits            
TRISJ               
TRISJbits           RES 1     ; 0xF9A
                    RES 1
MEMCON              
MEMCONbits          RES 1     ; 0xF9C
PIE1                
PIE1bits            RES 1     ; 0xF9D
PIR1                
PIR1bits            RES 1     ; 0xF9E
IPR1                
IPR1bits            RES 1     ; 0xF9F
PIE2                
PIE2bits            RES 1     ; 0xFA0
PIR2                
PIR2bits            RES 1     ; 0xFA1
IPR2                
IPR2bits            RES 1     ; 0xFA2
                    RES 3
CSELIO              
CSELIObits          RES 1     ; 0xFA6
CSEL2               
CSEL2bits           RES 1     ; 0xFA7
                    RES 3
RCSTA               
RCSTAbits           RES 1     ; 0xFAB
TXSTA               
TXSTAbits           RES 1     ; 0xFAC
TXREG               RES 1     ; 0xFAD
RCREG               RES 1     ; 0xFAE
SPBRG               RES 1     ; 0xFAF
PSPCON              
PSPCONbits          RES 1     ; 0xFB0
T3CON               
T3CONbits           RES 1     ; 0xFB1
TMR3L               RES 1     ; 0xFB2
TMR3H               RES 1     ; 0xFB3
                    RES 6
CCP2CON             
CCP2CONbits         RES 1     ; 0xFBA
CCPR2               
CCPR2L              RES 1     ; 0xFBB
CCPR2H              RES 1     ; 0xFBC
CCP1CON             
CCP1CONbits         RES 1     ; 0xFBD
CCPR1               
CCPR1L              RES 1     ; 0xFBE
CCPR1H              RES 1     ; 0xFBF
ADCON2              
ADCON2bits          RES 1     ; 0xFC0
ADCON1              
ADCON1bits          RES 1     ; 0xFC1
ADCON0              
ADCON0bits          RES 1     ; 0xFC2
ADRES               
ADRESL              RES 1     ; 0xFC3
ADRESH              RES 1     ; 0xFC4
SSPCON2             
SSPCON2bits         RES 1     ; 0xFC5
SSPCON1             
SSPCON1bits         RES 1     ; 0xFC6
SSPSTAT             
SSPSTATbits         RES 1     ; 0xFC7
SSPADD              RES 1     ; 0xFC8
SSPBUF              RES 1     ; 0xFC9
T2CON               
T2CONbits           RES 1     ; 0xFCA
PR2                 RES 1     ; 0xFCB
TMR2                RES 1     ; 0xFCC
T1CON               
T1CONbits           RES 1     ; 0xFCD
TMR1L               RES 1     ; 0xFCE
TMR1H               RES 1     ; 0xFCF
RCON                
RCONbits            RES 1     ; 0xFD0
WDTCON              
WDTCONbits          RES 1     ; 0xFD1
LVDCON              
LVDCONbits          RES 1     ; 0xFD2
OSCCON              
OSCCONbits          RES 1     ; 0xFD3
                    RES 1
T0CON               
T0CONbits           RES 1     ; 0xFD5
TMR0L               RES 1     ; 0xFD6
TMR0H               RES 1     ; 0xFD7
STATUS              
STATUSbits          RES 1     ; 0xFD8
FSR2                
FSR2L               RES 1     ; 0xFD9
FSR2H               RES 1     ; 0xFDA
PLUSW2              RES 1     ; 0xFDB
PREINC2             RES 1     ; 0xFDC
POSTDEC2            RES 1     ; 0xFDD
POSTINC2            RES 1     ; 0xFDE
INDF2               RES 1     ; 0xFDF
BSR                 RES 1     ; 0xFE0
FSR1                
FSR1L               RES 1     ; 0xFE1
FSR1H               RES 1     ; 0xFE2
PLUSW1              RES 1     ; 0xFE3
PREINC1             RES 1     ; 0xFE4
POSTDEC1            RES 1     ; 0xFE5
POSTINC1            RES 1     ; 0xFE6
INDF1               RES 1     ; 0xFE7
W                   
WREG                RES 1     ; 0xFE8
FSR0                
FSR0L               RES 1     ; 0xFE9
FSR0H               RES 1     ; 0xFEA
PLUSW0              RES 1     ; 0xFEB
PREINC0             RES 1     ; 0xFEC
POSTDEC0            RES 1     ; 0xFED
POSTINC0            RES 1     ; 0xFEE
INDF0               RES 1     ; 0xFEF
INTCON3             
INTCON3bits         RES 1     ; 0xFF0
INTCON2             
INTCON2bits         RES 1     ; 0xFF1
INTCON              
INTCONbits          
INTCON1             
INTCON1bits         RES 1     ; 0xFF2
PROD                
PRODL               RES 1     ; 0xFF3
PRODH               RES 1     ; 0xFF4
TABLAT              RES 1     ; 0xFF5
TBLPTR              
TBLPTRL             RES 1     ; 0xFF6
TBLPTRH             RES 1     ; 0xFF7
TBLPTRU             RES 1     ; 0xFF8
PC                  
PCL                 RES 1     ; 0xFF9
PCLATH              RES 1     ; 0xFFA
PCLATU              RES 1     ; 0xFFB
STKPTR              
STKPTRbits          RES 1     ; 0xFFC
TOS                 
TOSL                RES 1     ; 0xFFD
TOSH                RES 1     ; 0xFFE
TOSU                RES 1     ; 0xFFF


;*** Set all of memory to zeroes ***/
; Use FSR0 to increment through memory from address 0x0
; to the end of the last bank skipping sfrs and
; unimplemented addresses.

    CODE
__zero_memory
    movlw  0x0       ;low byte of (end address + 1)
    movwf  PRODL, 0
    lfsr   0, 0x0    ;start address
    movlw  0x6       ;high byte of (end address + 1)
    rcall zero_block
    return 0
zero_block
loop_h
    cpfslt FSR0H, 0
    bra    compare_l
    clrf   POSTINC0, 0
    bra    loop_h
compare_l
    movf   PRODL, 0, 0
loop_l
    cpfslt FSR0L, 0
    return 0
    clrf   POSTINC0, 0
    bra    loop_l

        GLOBAL __zero_memory

        GLOBAL PORTAbits
        GLOBAL PORTA
        GLOBAL PORTBbits
        GLOBAL PORTB
        GLOBAL PORTCbits
        GLOBAL PORTC
        GLOBAL PORTDbits
        GLOBAL PORTD
        GLOBAL PORTEbits
        GLOBAL PORTE
        GLOBAL PORTFbits
        GLOBAL PORTF
        GLOBAL PORTGbits
        GLOBAL PORTG
        GLOBAL PORTHbits
        GLOBAL PORTH
        GLOBAL PORTJbits
        GLOBAL PORTJ
        GLOBAL LATAbits
        GLOBAL LATA
        GLOBAL LATBbits
        GLOBAL LATB
        GLOBAL LATCbits
        GLOBAL LATC
        GLOBAL LATDbits
        GLOBAL LATD
        GLOBAL LATEbits
        GLOBAL LATE
        GLOBAL LATFbits
        GLOBAL LATF
        GLOBAL LATGbits
        GLOBAL LATG
        GLOBAL LATHbits
        GLOBAL LATH
        GLOBAL LATJbits
        GLOBAL LATJ
        GLOBAL DDRAbits
        GLOBAL DDRA
        GLOBAL TRISAbits
        GLOBAL TRISA
        GLOBAL DDRBbits
        GLOBAL DDRB
        GLOBAL TRISBbits
        GLOBAL TRISB
        GLOBAL DDRCbits
        GLOBAL DDRC
        GLOBAL TRISCbits
        GLOBAL TRISC
        GLOBAL DDRDbits
        GLOBAL DDRD
        GLOBAL TRISDbits
        GLOBAL TRISD
        GLOBAL DDREbits
        GLOBAL DDRE
        GLOBAL TRISEbits
        GLOBAL TRISE
        GLOBAL DDRFbits
        GLOBAL DDRF
        GLOBAL TRISFbits
        GLOBAL TRISF
        GLOBAL DDRGbits
        GLOBAL DDRG
        GLOBAL TRISGbits
        GLOBAL TRISG
        GLOBAL DDRHbits
        GLOBAL DDRH
        GLOBAL TRISHbits
        GLOBAL TRISH
        GLOBAL DDRJbits
        GLOBAL DDRJ
        GLOBAL TRISJbits
        GLOBAL TRISJ
        GLOBAL MEMCONbits
        GLOBAL MEMCON
        GLOBAL PIE1bits
        GLOBAL PIE1
        GLOBAL PIR1bits
        GLOBAL PIR1
        GLOBAL IPR1bits
        GLOBAL IPR1
        GLOBAL PIE2bits
        GLOBAL PIE2
        GLOBAL PIR2bits
        GLOBAL PIR2
        GLOBAL IPR2bits
        GLOBAL IPR2
        GLOBAL CSELIObits
        GLOBAL CSELIO
        GLOBAL CSEL2bits
        GLOBAL CSEL2
        GLOBAL RCSTAbits
        GLOBAL RCSTA
        GLOBAL TXSTAbits
        GLOBAL TXSTA
        GLOBAL TXREG
        GLOBAL RCREG
        GLOBAL SPBRG
        GLOBAL PSPCONbits
        GLOBAL PSPCON
        GLOBAL T3CONbits
        GLOBAL T3CON
        GLOBAL TMR3L
        GLOBAL TMR3H
        GLOBAL CCP2CONbits
        GLOBAL CCP2CON
        GLOBAL CCPR2
        GLOBAL CCPR2L
        GLOBAL CCPR2H
        GLOBAL CCP1CONbits
        GLOBAL CCP1CON
        GLOBAL CCPR1
        GLOBAL CCPR1L
        GLOBAL CCPR1H
        GLOBAL ADCON2bits
        GLOBAL ADCON2
        GLOBAL ADCON1bits
        GLOBAL ADCON1
        GLOBAL ADCON0bits
        GLOBAL ADCON0
        GLOBAL ADRES
        GLOBAL ADRESL
        GLOBAL ADRESH
        GLOBAL SSPCON2bits
        GLOBAL SSPCON2
        GLOBAL SSPCON1bits
        GLOBAL SSPCON1
        GLOBAL SSPSTATbits
        GLOBAL SSPSTAT
        GLOBAL SSPADD
        GLOBAL SSPBUF
        GLOBAL T2CONbits
        GLOBAL T2CON
        GLOBAL PR2
        GLOBAL TMR2
        GLOBAL T1CONbits
        GLOBAL T1CON
        GLOBAL TMR1L
        GLOBAL TMR1H
        GLOBAL RCONbits
        GLOBAL RCON
        GLOBAL WDTCONbits
        GLOBAL WDTCON
        GLOBAL LVDCONbits
        GLOBAL LVDCON
        GLOBAL OSCCONbits
        GLOBAL OSCCON
        GLOBAL T0CONbits
        GLOBAL T0CON
        GLOBAL TMR0L
        GLOBAL TMR0H
        GLOBAL STATUSbits
        GLOBAL STATUS
        GLOBAL FSR2
        GLOBAL FSR2L
        GLOBAL FSR2H
        GLOBAL PLUSW2
        GLOBAL PREINC2
        GLOBAL POSTDEC2
        GLOBAL POSTINC2
        GLOBAL INDF2
        GLOBAL BSR
        GLOBAL FSR1
        GLOBAL FSR1L
        GLOBAL FSR1H
        GLOBAL PLUSW1
        GLOBAL PREINC1
        GLOBAL POSTDEC1
        GLOBAL POSTINC1
        GLOBAL INDF1
        GLOBAL W
        GLOBAL WREG
        GLOBAL FSR0
        GLOBAL FSR0L
        GLOBAL FSR0H
        GLOBAL PLUSW0
        GLOBAL PREINC0
        GLOBAL POSTDEC0
        GLOBAL POSTINC0
        GLOBAL INDF0
        GLOBAL INTCON3bits
        GLOBAL INTCON3
        GLOBAL INTCON2bits
        GLOBAL INTCON2
        GLOBAL INTCONbits
        GLOBAL INTCON
        GLOBAL INTCON1bits
        GLOBAL INTCON1
        GLOBAL PROD
        GLOBAL PRODL
        GLOBAL PRODH
        GLOBAL TABLAT
        GLOBAL TBLPTR
        GLOBAL TBLPTRL
        GLOBAL TBLPTRH
        GLOBAL TBLPTRU
        GLOBAL PC
        GLOBAL PCL
        GLOBAL PCLATH
        GLOBAL PCLATU
        GLOBAL STKPTRbits
        GLOBAL STKPTR
        GLOBAL TOS
        GLOBAL TOSL
        GLOBAL TOSH
        GLOBAL TOSU

;-------------------------------------------------------------------------

        LIST
        END
