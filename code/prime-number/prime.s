@ vim:ft=arm

@ Check whether a word in memory is a prime number or not

@ This is written to the gcc-arm toolchain spec

@ .text is an assembler directive, which says that the following
@ instructions have to be assembled into the code section, rather than the .data
@ section.
.text

/**************************************************************************
 **
 **  Target      : Cortex-M3
 **
 **  Environment : GNU Tools
 **
 **************************************************************************/
	.syntax unified
	.thumb

	.global pfnVectors
	.global Default_Handler

	.equ Top_Of_Stack, 0x20004000    /* end of 16K RAM */

/****************************************************************************
 *
 * The minimal vector table for a Cortex M3.  Note that the proper constructs
 * must be placed on this to ensure that it ends up at physical address
 * 0x0000.0000.
 *
 ****************************************************************************/
	.text

@ I'm setting everything to Default_Handler because we don't need anything else right now
pfnVectors:
	.word Top_Of_Stack          @ msp = 0x20004000
	.word _start                @ Starting Program address
	.word Default_Handler		@ NMI_Handler
	.word Default_Handler		@ HardFault_Handler
	.word Default_Handler		@ MemManage_Handler
	.word Default_Handler		@ BusFault_Handler
	.word Default_Handler		@ UsageFault_Handler
	.word 0                     @ 7
	.word 0                     @ To
	.word 0                     @ 10
	.word 0                     @ Reserved
	.word Default_Handler		@ SVC_Handler
	.word Default_Handler		@ DebugMon_Handler
	.word 0                     @ Reserved
	.word Default_Handler		@ PendSV_Handler
	.word Default_Handler		@ SysTick_Handler
	.word Default_Handler		@ IRQ_Handler
	.word Default_Handler		@ IRQ_andler

/**
 * This is the code that gets called when the processor first
 * starts execution following a reset.
 */

.type _start, %function

_start:                     @ _start label is required by the linker
	LDR R0, =NUM
	LDR R1, [R0] @ Number to check
	MOV R2, #2 @ Current divisor

	MOV R5, #0 @ Return value of myMod

	MOV R10, #0xFFFFFFFF @ 0xFFFFFFFF if prime, 0x0 if not

	TST R1, #1 << 0 @ Check if LSB is set or not (Even or odd?)
	BLS Loop @ Odd
	BHI stop @ Even, so not a prime, end
Loop:
	BL myMod
	CMP R5, #0
	BEQ clr
	ADDS R2, #1
	CMP R2, R1
	BNE Loop
	B stop
clr:
	MOV R10, #0
stop:
	BL stop

myMod: @ Computes R1 % R2
	UDIV R3, R1, R2
	MUL R4, R3, R2
	SUB R5, R1, R4
	BX LR

.data
NUM:
	.word 0x0000000a

/**
 * This is the code that gets called when the processor receives an
 * unexpected interrupt.  This simply enters an infinite loop, preserving
 * the system state for examination by a debugger.
 *
 */
.type Default_Handler, %function

Default_Handler:
Infinite_Loop:
	b Infinite_Loop

.end
