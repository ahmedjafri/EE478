; RCS Header $Id: atol.asm,v 1.2 2006/02/04 00:06:53 nairnj Exp $

#include "P18CXXX.INC"
#include "P18MACRO.INC"


; @name atol
; The {\bf atol} function converts the initial portion of the string pointed
; to by {\bf s} into a {\bf long} integer representation. The initial portion 
; of the string is assumed to be in radix 10.
; @param s pointer to the string to convert
; @return The {\bf atol} function returns the converted value
;
; long atol (const char *s);


STDLIB CODE
atol
  global atol

; Proceedure: Use FSR0 for 's'.
; Stack Offsets from top:
#define OffSign    -1  ; Sign Flag 
#define OffScratch -5  ; Scratch
;                  -7  ; Save FSR2 
#define OffResult  -d'11' ; Results to be return


  ; Load FSR0 with the 's' pointer
          Stk2PopToReg FSR0L

  ; Backup two bytes assuming the compiler has supplied additional stack space.
  ; Push four zeroes onto stack for return value.

;          movlw     -2
;          clrf      PLUSW1,ACCESS
;          movlw     -1
;          clrf      PLUSW1,ACCESS
; In v2.0, 32-bit return values are returned in __AARGB3, not on the stack.
; So the above two bytes were not allocated on the stack.
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS

  ; Save FSR2 on the stack. 
          Stk2PushFromReg FSR2L

  ; Load FSR2 with pointer to OffResult
          StkSetPtrToOffset FSR2L,-6

  ; Push long zero onto stack for scratch
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS

  ; Push zero onto stack for sign flag
          clrf      POSTINC1,ACCESS
  
jSkipWS:
  ; Skip over white space, i.e. spaces and tabs

  ; Compare with space
          movlw     ' '
          subwf     INDF0, W, ACCESS
          bz        jSkipWS1            ; match

  ; Compare with tab
          movlw     '\t'
          subwf     INDF0, W, ACCESS
          bz        jSkipWS1            ; match

  ; Test for '\0'
          tstfsz    INDF0,ACCESS
          bra       jTstSign
          bra       jEnd                ; found terminator

jSkipWS1:
  ; next character
          movf      POSTINC0, W, ACCESS ; increment pointer
          bra       jSkipWS

jTstSign:
  ; Test for sign
          movlw     '-'
          subwf     INDF0, W, ACCESS
          bnz       jTstSign1

  ; Found minus sign.  
          Stk1Inc    -1       ; record it in sign flag
          bra       jTstSign2

jTstSign1:
          movlw     '+'
          subwf     INDF0, W, ACCESS
          bnz       jTstSign3

  ; Skip plus sign

jTstSign2:
  ; Skip character
          movf      POSTINC0, W, ACCESS

jTstSign3:
jLoop:

  ; If the next character is not 0 ->9 then terminate
          jmpFleL   INDF0,ACCESS,'0'-1,jEndLoop
          jmpFgeL   INDF0,ACCESS,'9'+1,jEndLoop


  ; Multiply Result value by 10 and move it to Scratch
          Stk4ShiftLeft       OffResult
          Stk4CpyFromFSR2     OffScratch
          Stk4ShiftLeft       OffResult
          Stk4ShiftLeft       OffResult
          Stk4AddToFSR2       OffScratch


  ; Convert ASCII character to binary and add to Result
          movlw     '0'
          subwf     POSTINC0,W,ACCESS
          addwf     POSTINC2,F,ACCESS
          movlw     0
          addwfc    POSTINC2,F,ACCESS
          addwfc    POSTINC2,F,ACCESS
          addwfc    POSTDEC2,F,ACCESS
          movf      POSTDEC2,F,ACCESS
          movf      POSTDEC2,F,ACCESS
          bra       jLoop

jEndLoop:
  ; Get Sign flag and fixup stack
          Stk1CpyToReg OffSign,WREG
          jmpWeqZ   jEnd

  ; Negative sign.  Negate result.
          Stk4Negate OffResult

jEnd:
  ; Adjust stack
          movf      POSTDEC1,F,ACCESS
          movf      POSTDEC1,F,ACCESS
          movf      POSTDEC1,F,ACCESS
          movf      POSTDEC1,F,ACCESS
          movf      POSTDEC1,F,ACCESS

  ; Set FSR0 equal to Results which is FSR2
          movff     FSR2L,FSR0L
          movff     FSR2H,FSR0H
	 
; In v2.0, 32-bit return values are returned in __AARGB3.	  
	  EXTERN __AARGB3  
          movff     POSTINC0, __AARGB3
	  movff	    POSTINC0, __AARGB3+1	  
	  movff	    POSTINC0, __AARGB3+2	  
	  movff	    INDF0,    __AARGB3+3	  

  ; Restore FSR2 from stack. 
          Stk2PopToReg FSR2L
	 
; These were allocated at the start of the routine as a temp location
; for the return value. 
          movf      POSTDEC1,F,ACCESS
          movf      POSTDEC1,F,ACCESS
	  
          return
  end

