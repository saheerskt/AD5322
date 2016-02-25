/****************************************************************************************************************
 *
 *                  External DAC access routines defs
 *
 ****************************************************************************************************************
 *										
 *   Filename:           DAC5322.c	
 *   Dependencies:       DAC5322.h
 *                     	 	
 *                      
 *   Processor:          PIC18F4550
 *   Compiler:           MPLAB C18 3.20 or higher
 *   Assembler:          MPASMWIN 5.20 or higher
 *   Linker:             MPLINK 4.20 or higher
 *   Date:               January  2016
 *   File Version:       1.0
 *
 *   Author:             SAHEER K T
 ***************************************************************************************************************/

#include <p18cxxx.h>

/* 
	1-change the proper pins for any controller
	2-can use for any comiler with small modification
	3-Data write on falling edge of clock, as mentioned in datasheet of AD5322
*/

#define DAC_CTRL_PORT TRISB

#define CLK_DAC LATBbits.LATB0  
#define DATA_SER LATBbits.LATB1
#define LDACar LATBbits.LATB2
#define SYNC_DAC LATBbits.LATB3

void D2A_convertCh1(unsigned int);
void D2A_convertCh2(unsigned int);
void Delayns(unsigned int);




