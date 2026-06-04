/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
*************************************************************************
*/
.syntax unified

.global pfnVectors
.global Default_Handler
.global _start
.equ Top_Of_Stack, 0x20002000    /* end of 8K RAM */

.global sdata
.global edata
.global etext
.global sbss
.global ebss

.section .vectors
vectors:
	.word Top_Of_Stack          @ msp = 0x20002000
	.word _start                @ Starting Program address
	.word Default_Handler	    @ NMI_Handler
	.word Default_Handler	    @ HardFault_Handler
	.word Default_Handler	    @ MemManage_Handler
	.word Default_Handler	    @ BusFault_Handler
	.word Default_Handler	    @ UsageFault_Handler
	.word 0                     @ 7
	.word 0                     @ To
	.word 0                     @ 10 
	.word 0                     @ Reserved
	.word Default_Handler	    	@ SVC_Handler
	.word Default_Handler	    @ DebugMon_Handler
	.word 0                     @ Reserved
	.word Default_Handler	    @ PendSV_Handler
	.word Default_Handler	    @ SysTick_Handler
	.word Default_Handler	    @ IRQ_Handler
	.word Default_Handler	    @ IRQ_Handler

.section .rodata


.section .data


.section .bss


.section .text

.thumb
/**
 * This is the code that gets called when the processor first
 * starts execution following a reset. 
*/
.type _start, %function
_start:                              @ _start label is required by the linker

	//init .data section
	ldr r7, =etext
	ldr r6, =sdata
	ldr r5, =edata
	mov r4, #0
data_init:
	cmp r6, r5
	beq data_init_end
	ldrb r4, [r7], #1
	strb r4, [r6], #1
	b data_init
data_init_end:

	//clear .bss section
	ldr r6, =sbss
	ldr r7, =ebss
	mov r4, #0
bss_init:
	cmp r6, r7
	beq bss_init_end
	strb r4, [r6], #1
	b bss_init
bss_init_end:

	bl main
	stop:   b stop

/***************************************************************/
.global main
.type main, %function
main:                              
	mov r1, #12				; r1 = 12
	mov r2, #13				; r2 = 13
	add r0, r1, r2			; r0 = r1 + r2
							//; expected r0 = 25 -- info registers r0 r1 r2
	
	mov r1, #4				; r1 = 4
	mov r2, #7				; r2 = 7
	subs r0, r1, r2			; r0 = r1 - r2
							//; expected r0 = -3 and psr is N=1 -- info registers r0 r1 r2 xpsr
	
	mov r3, #10				; r3 = 10
	mov r4, #4				; r4 = 4
	add r3, r4				; r3 = r3 + r4
							//; expected r3=14 -- info registers r3 r4
	
	mov r1, #23				; r1 = 23
	mov r2, #5				; r2 = 5
	mul r0, r1, r2			; r0 = r1 * r2
							//; expected r0=115 -- info registers r0 r1 r2
	
	mov r1, #23				; r1 = 23
	mov r2, #5				; r2 = 5
	udiv r0, r1, r2			; r0 = r1 / r2
							//; expected r0=4 -- info registers r0 r1 r2

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

