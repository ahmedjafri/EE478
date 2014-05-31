; RCS Header $Id: ultoa.asm,v 1.2 2009/02/17 08:16:04 guptan Exp $

#include "P18CXXX.INC"
#include "P18MACRO.INC"

; @name ultoa
;The {\bf ultoa} function converts the {\bf unsigned long} value {\bf value} to 
;a radix 10 string representation, storing the resultant string into
;the location pointed to by {\bf s}.
;The {\bf ultoa} function is an MPLAB-Cxx extension to the ANSI required
;libraries and may not be present in other implementations.
;@param value value to convert
;@param s pointer to destination string object
;@return The {\bf ultoa} function returns the value of {\bf s}.
;
; char *ultoa (unsigned long value, char *s);

STDLIB CODE
ultoa    FUSTART
  global ultoa
  extern ltoBCD

; Proceedure: Use FSR2 for 's'. Call ltoBCD to convert ASCII to BCD.
; Stack Offsets from top:
#define OffValue   -6  ; Value

  ; Save FSR2 on the stack. 

          Stk2PushFromReg FSR2L

  ; Load FSR2 with the 's' pointer
          Stk2CpyToReg -8,FSR2L

  ; Convert number to BCD
  ; void ltoBCD( long Value, unsigned char *pBCD)

  ; Allocate space for BCD[5] on stack
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          movf      POSTINC1, F, ACCESS           ; make space for BCD
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          movf      POSTINC1, F, ACCESS           ; make space for BCD
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          movf      POSTINC1, F, ACCESS           ; make space for BCD
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          movf      POSTINC1, F, ACCESS           ; make space for BCD
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          movf      POSTINC1, F, ACCESS           ; make space for BCD
          StkPushPtrToOffset -5                   ; ptr to BCD
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          Stk1CpyToReg OffValue-7,POSTINC1       ; push ValueL on stack
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          Stk1CpyToReg OffValue-7,POSTINC1       ; push ValueL+1 on stack
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          Stk1CpyToReg OffValue-7,POSTINC1       ; push ValueL+2 on stack
          stkadj    1                    ; added STKADJ PSEUDO-INSTRUCTION for stack analysis
          Stk1CpyToReg OffValue-7,POSTINC1       ; push ValueL+3 on stack
          call      ltoBCD

  ; Set FSR0 == pBCD
          StkSetPtrToOffset FSR0L,-d'11'

          call      TstUpper            ; upper nibble
          bnz       jDo10
          call      TstLower            ; lower nibble
          bnz       jDo9
          call      TstUpper            ; upper nibble
          bnz       jDo8 
          call      TstLower            ; lower nibble
          bnz       jDo7
          call      TstUpper            ; upper nibble
          bnz       jDo6 
          call      TstLower            ; lower nibble
          bnz       jDo5
          call      TstUpper            ; upper nibble
          bnz       jDo4 
          call      TstLower            ; lower nibble
          bnz       jDo3
          call      TstUpper            ; upper nibble
          bnz       jDo2 
          bra       jDo1                ; must have at least one digit



jDo10:    call      ProcUpper           ; upper nibble
jDo9:     call      ProcLower           ; lower nibble
jDo8:     call      ProcUpper           ; upper nibble
jDo7:     call      ProcLower           ; lower nibble
jDo6:     call      ProcUpper           ; upper nibble
jDo5:     call      ProcLower           ; lower nibble
jDo4:     call      ProcUpper           ; upper nibble
jDo3:     call      ProcLower           ; lower nibble
jDo2:     call      ProcUpper           ; upper nibble
jDo1:     call      ProcLower           ; lower nibble

          clrf      POSTINC2,ACCESS     ; terminate string

  ; fixup stack
          StkAddStackPtr -d'11'

  ; Restore FSR2 from stack. 
          Stk2PopToReg FSR2L

  ; Set FSR0 to point to *s
          StkSetPtrToOffset FSR0L,-6
	  
  ; FIXME - temporary solution for change in calling convention
  ; return value in PROD instead of *FSR0
	  movff     POSTINC0, PRODL
	  movff     INDF0, PRODH
	  
          FUEND
          return
	  
; Test for zero nibble
TstUpper  swapf     INDF0,W,ACCESS      ; upper nibble
          andlw     0x0F         
          return


; Test for zero nibble
TstLower  movf      INDF0,W,ACCESS      ; lower nibble
          andlw     0x0F  
          bnz       jTstLowZ1
          movf      POSTINC0,F,ACCESS   ; increment pointer
          bsf       STATUS,Z            ; indicate zero nibble   
jTstLowZ1 return


; Convert nibble to ASCII character
ProcUpper swapf     INDF0,W,ACCESS      ; upper nibble
          andlw     0x0F  
          addlw     0x30                ; make into ASCII
          movwf     POSTINC2,ACCESS     ; put it into string
          return

; Convert nibble to ASCII character
ProcLower movf      POSTINC0,W,ACCESS   ; lower nibble
          andlw     0x0F  
          addlw     0x30                ; make into ASCII
          movwf     POSTINC2,ACCESS     ; put it into string
          return

  end
















