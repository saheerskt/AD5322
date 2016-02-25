/***************************************************************************************************************
 *						Digital to Analog Convertor-12bit
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
 * 
 ***************************************************************************************************************
 *
 *   Program Description:
 *
 *   This program illustrates controlling DAC AD5322 using SPI protocol
 *
 ***************************************************************************************************************
 *
 *   -20 MHz crystal oscillator with PLL is being used, thus each
 *   -instruction cycle = 83.33 ns
 *	 -So controller runnning frequency is 48Mhz
	 -This is a Software SPI code.So can connect with any I/O pin of microcontroller.No need of specialised SPI pins
 *
 * I N C L U D E S ********************************************************************************************/

#include "DAC5322.h"



void D2A_convertCh1(unsigned int data)
{
unsigned int loop,DATA_SER1;
	DAC_CTRL_PORT&=0xF0;
/*----------------------------------------*/
	CLK_DAC=1;	
	LDACar=1;
	Delayns(1);
	SYNC_DAC=0;
	Delayns(1);
	SYNC_DAC=1;
	Delayns(100);
	SYNC_DAC=0;	
	Delayns(1);
/*----------------------------------------*/
	CLK_DAC=1;	
	DATA_SER=0; //Channel Selection-a
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
	
for(loop=0;loop<=2;loop++) //Unbuffered, Normal Mode
{
	Nop();
	CLK_DAC=1;	
	DATA_SER=0;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
}

for(loop=11;loop>0;loop--)
{
	Nop();
	CLK_DAC=1;	
	DATA_SER=(data>>loop) & 1;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
}
/*------------------------------------------------*/
	Nop();
	CLK_DAC=1;	
	DATA_SER=data & 0x01;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);	
	SYNC_DAC=1;	
/*------------------------------------------------*/
	
	LDACar=0;
	Delayns(30);
	LDACar=1;
}

void D2A_convertCh2(unsigned int data)
{
unsigned int loop,DATA_SER1;
	unsigned char control_data=0x00;
	DAC_CTRL_PORT=0x00;
/*----------------------------------------*/
	CLK_DAC=1;	
	LDACar=1;
	Delayns(1);
	SYNC_DAC=0;
	Delayns(1);
	SYNC_DAC=1;
	Delayns(100);
	SYNC_DAC=0;	
	Delayns(1);
/*----------------------------------------*/
	CLK_DAC=1;	
	DATA_SER=1; //Channel Selection-a
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
	
for(loop=0;loop<=2;loop++) //Unbuffered, Normal Mode
{
	Nop();
	CLK_DAC=1;	
	DATA_SER=0;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
}

for(loop=11;loop>0;loop--)
{
	Nop();
	CLK_DAC=1;	
	DATA_SER=(data>>loop) & 1;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);
}
/*------------------------------------------------*/
	Nop();
	CLK_DAC=1;	
	DATA_SER=data & 0x01;
	Delayns(20);
	CLK_DAC=0;
	Delayns(20);	
	SYNC_DAC=1;	
/*------------------------------------------------*/
	
	LDACar=0;
	Delayns(30);
	LDACar=1;
}

void Delayns(unsigned int ns)
{
	unsigned int i,j;
	for(j=0;j<ns;j++)
	for(i=0;i<5;i++);
}

