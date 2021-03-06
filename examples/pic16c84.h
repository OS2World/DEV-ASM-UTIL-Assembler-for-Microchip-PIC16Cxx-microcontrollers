;
; pic16c84.h
;
; definitions for PIC16C84 registers
;

        if ~defined(__16C84) & ~defined(__16F84)
          error "this include file is for PIC16C84"
        endif

; Page 0 
IND0    equ	00h
TMR0	equ	01h
RTCC    equ	TMR0
PCL     equ	02h
STATUS  equ	03h
FSR     equ	04h     
PORTA   equ	05h
PORTB   equ	06h
EEDATA  equ	08h
EEADR   equ	09h
PCLATH  equ	0ah 
INTCON  equ	0bh

; Page 1

OPTIO   equ	01h
TRISA   equ	05h
TRISB   equ	06h
EECON1  equ	08h
EECON2  equ	09h

;
; STATUS bits
;
IRP     equ	07h
RP1     equ	06h
RP0     equ	05h
TO      equ	04h
PD      equ	03h
Z       equ	02h
DC      equ	01h
C       equ	00h

;
; INTCON bits
;
GIE	equ	7
EEIE	equ	6
RTIE	equ	5
INTE	equ	4
RBIE	equ	3
RTIF	equ	2
INTF	equ	1
RBIF	equ	0

;
; OPTION bits
;
RBPU	equ	7
INTEDG	equ	6
RTS	equ	5
RTE	equ	4
PSA	equ	3
PS2	equ	2
PS1	equ	1
PS0	equ	0

;
; EECON1 bits
;
EEIF	equ	4
WRERR	equ	3
WREN	equ	2
EWR	equ	1
ERD	equ	0

;
; 'direction' flags
;
W	equ	0
F	equ	1


