#include <avr/io.h>
; correct for avr/io.h 0x20 port offset for io instructions
#define i2c_port 	PORTC-0x20
#define SCL			5
#define SDA			4

#define wait_reg 	r18
#define bitcnt		r19
#define byte_nr		r20
#define dataByte	r24
#define	dataByte2	r25
#define delayArg 19

#warning dit compilet ook tesyye

.global exit_testmode
; two sequence bytes in r24 and r25
; 
; i.e. PORTB |= (1<<UART_Tx)
exit_testmode:
		cli		
		; store all the data we will be needing on the stack
		ldi		dataByte, 0x4E
		push	dataByte
		ldi		dataByte, 0x58
		push	dataByte
		ldi		dataByte, 0x50
		
StartSignal:					; SCL LOW; 30 cycles; SDA LOW; 4 cycles; 
		ldi		byte_nr, 3		;[1] keep track of number of bytes
		cbi		i2c_port, SCL 	;[2] SCL line low: start of signal
		ldi		wait_reg, 10	;[1] wait 10*3 cycles
wait_loop_start:
		dec		wait_reg		;[1] decrement wait lop counter
		brne	wait_loop_start	;[1/2] return to loop if counter not zero
		cbi		i2c_port, SDA	;[2] SDA line low
		ldi		bitcnt, 8		;[4*1] wait four cycles, then go to send bit
		nop
		nop
		nop

SendBit:						; 4 cycles; SCL bit; 8 cycles; SDA HIGH; 18 cycles; SDA LOW; 4 cycles
		nop
		lsr 	dataByte		;[1] shift rightmost bit out of byte
		brcc	send_zero		;[1/2] determine whether to send 1 or 0 by carry
send_one:						; this label is only here to make code more readable
		nop						; balance loop
		sbi		i2c_port, SCL	;[2] SCL line high
		rjmp	bit_sent
send_zero:
		cbi		i2c_port, SCL	;[2] SCL line low
		nop
		nop						; balance loop
		
bit_sent:
		ldi		wait_reg, 2		;[1] wait 2*3 = 6 cycles
SDA_high_wait:
		dec		wait_reg		;[1] decrement loop counter
		brne	SDA_high_wait	;[1/2] branch if loop not finished
		sbi		i2c_port, SDA	;[2] SDA HIGH
		
SDA_low_loop:					; this wait should be 18 cycles
		dec 	bitcnt			;[1] we'll use those cycles to test if next byte must be loaded
		brne	no_new_byte		;[1/2] if bitcnt == 0; load second byte 
		dec		byte_nr			;[1] decrease byte count
		breq	end_signal		;[1/2] both bytes are sent: go to end of signal
		pop		dataByte		;[2] fetch the second byte from the stack
		ldi		bitcnt, 8		;[1] reset bit count back to 8
		ldi		wait_reg, 3		;[1] wait loop takes 3*3 = 9 cycles
		rjmp 	SDA_low_wait	;[2]
no_new_byte:
		ldi		wait_reg, 5		;[1] wait 3*5 = 15 cycles
SDA_low_wait:
		dec		wait_reg		;[1] decrement loop counter
		brne	SDA_low_wait	;[1/2] branch if loop not finished
SDA_low:
		cbi		i2c_port, SDA	;[2] SDA LOW
		nop						;[2*1] wait a while
		nop
		rjmp	SendBit			;[2] go to next bit
		
		
;15 cycles; SDA LOW; 6 cycles; SCL LOW; 6 cycles; SDA HIGH; 18 cycles; SCL HIGH
end_signal:						
		ldi 	wait_reg, 5
wait_loop_end:
		dec		wait_reg
		brne	wait_loop_end
		cbi		i2c_port, SDA	; SDA line low
		ldi		wait_reg, 2		; wait 2*3 cycles
wait_loop_end1:
		dec		wait_reg
		brne	wait_loop_end1
		cbi		i2c_port, SCL
		ldi 	wait_reg, 2
wait_loop_end2:
		dec		wait_reg
		brne	wait_loop_end2
		sbi		i2c_port, SDA
		ldi		wait_reg, 6		; wait 6*3 cycles
wait_loop_end3:
		dec		wait_reg
		brne	wait_loop_end3
		sbi		i2c_port, SCL
end_func:
		reti