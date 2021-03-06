; $Id: scspnpp.asm,v 1.2 2008/04/29 07:37:04 guptan Exp $

#include "P18CXXX.INC"
#include "P18MACRO.INC"

; @name strcspnpgm
;The {\bf strcspnpgm} function performs a {\bf strcspn}.
;@param s1 pointer to string in program memory
;@param s2 pointer to string in program memory
;
;sizerom_t strcspnpgm(const rom char *s1, const rom char *s2);

  extern __AARGB2
STRING CODE
strcspnpgm
  global strcspnpgm


#ifdef __SMALL__
 messg "strcspnpgm - SMALL"

; Proceedure: Use three extra bytes as counter location and one byte as scratch
; Assumes TBLPTRU = 0

  ; Add three extra bytes to stack so we can hold three byte count. Zero it.
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
  ; Add scratch to hold char from s1
          clrf      POSTINC1,ACCESS

          StkSetPtrToOffset FSR0L,-1     ; set FSR0 to point to scratch byte

jOuterLoop:
  ; Load TBLPTR with the 's1' pointer
          Stk2CpyToReg -2-4,TBLPTRL

  ; Test for '\0' in 's1'
          tblrd     *+                  ; read & increment
          movf      TABLAT, W, ACCESS
          bz        jNull               ; found end of 's1'
          movwf     INDF0, ACCESS       ; save in scratch

  ; Save TBLPTR to the 's1' pointer
          Stk2CpyFromReg TBLPTRL,-2-4

  ; Load TABPTR with the 's2' pointer
          Stk2CpyToReg -4-4,TBLPTRL

jInnerLoop:

  ; Test for '\0' in 's2'
          tblrd     *+                  ; read & increment
          movf      TABLAT, W, ACCESS
          bz        jInner1              ; found end of 's2'

  ; Compare 's2' character with 's1' character in scratch
          subwf     INDF0, W, ACCESS
          bz        jMatch               ; match
          bra       jInnerLoop

jInner1:
  ; count match
          Stk3Inc   -4
          bra       jOuterLoop

jNull:
jMatch:
  ; Found match or reached end of 's1'.  Return FSR0 pointing to count.

          movf      POSTDEC1, F, ACCESS ; discard scratch

  ; Move count down to s2
          StkSetPtrToOffset FSR0L,-2-3

          movlw     0xFF
          movff     PLUSW1,POSTDEC0
          movf      POSTDEC1,F,ACCESS

          movlw     0xFF
          movff     PLUSW1,POSTDEC0
          movf      POSTDEC1,F,ACCESS

          movlw     0xFF
          movff     PLUSW1,INDF0        ; leave FSR0 pointing at base of count
          movf      POSTDEC1,F,ACCESS
          return

#else
#ifdef __LARGE__
 messg "strcspnpgm - LARGE"

; Proceedure: Use three extra bytes as counter location and one byte as scratch

  ; Add three extra bytes to stack so we can hold three byte count. Zero it.
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
          clrf      POSTINC1,ACCESS
  ; Add scratch to hold char from s1
          clrf      POSTINC1,ACCESS

          StkSetPtrToOffset FSR0L,-1     ; set FSR0 to point to scratch byte

jOuterLoop:
  ; Load TBLPTR with the 's1' pointer
          Stk3CpyToReg -3-4,TBLPTRL

  ; Test for '\0' in 's1'
          tblrd     *+                  ; read & increment
          movf      TABLAT, W, ACCESS
          bz        jNull               ; found end of 's1'
          movwf     INDF0, ACCESS       ; save in scratch

  ; Save TBLPTR to the 's1' pointer
          Stk3CpyFromReg TBLPTRL,-3-4

  ; Load TABPTR with the 's2' pointer
          Stk3CpyToReg -6-4,TBLPTRL

jInnerLoop:

  ; Test for '\0' in 's2'
          tblrd     *+                  ; read & increment
          movf      TABLAT, W, ACCESS
          bz        jInner1              ; found end of 's2'

  ; Compare 's2' character with 's1' character in scratch
          subwf     INDF0, W, ACCESS
          bz        jMatch               ; match
          bra       jInnerLoop

jInner1:
  ; count match
          Stk3Inc   -4
          bra       jOuterLoop

jNull:
jMatch:
  ; Found match or reached end of 's1'.  Return FSR0 pointing to count.

          movf      POSTDEC1, F, ACCESS ; discard scratch

  ; Copy three bytes from stack frame at offset to __AARGB2
          Stk3CpyToReg -3,__AARGB2

          movlw     0xFF
          movff     PLUSW1,POSTDEC0
          movf      POSTDEC1,F,ACCESS

          movlw     0xFF
          movff     PLUSW1,POSTDEC0
          movf      POSTDEC1,F,ACCESS

          movlw     0xFF
          movff     PLUSW1,INDF0        ; leave FSR0 pointing at base of count
          movf      POSTDEC1,F,ACCESS
          return
#else
 error "No Model Specified"
#endif
#endif
  end

