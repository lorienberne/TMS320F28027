/*
 * PIE_defines.h
 *
 *  Created on: 25/01/2015
 *      Author: Lorien
 */

#ifndef PIE_DEFINES_H
#define PIE_DEFINES_H

//SPECIAL CPU REGISTERS
extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;


#define INT1_1 *((volatile uint32_t *) 0x0D40)		//ADCINT1
#define INT1_2 *((volatile uint32_t *) 0x0D42)		//ADCINT2
#define INT1_3 *((volatile uint32_t *) 0x0D44)		//Reserved
#define INT1_4 *((volatile uint32_t *) 0x0D46)		//XINT1
#define INT1_5 *((volatile uint32_t *) 0x0D48)		//XINT2
#define INT1_6 *((volatile uint32_t *) 0x0D4A)		//ADCINT9
#define INT1_7 *((volatile uint32_t *) 0x0D4C)		//TINT0
#define INT1_8 *((volatile uint32_t *) 0x0D4E)		//WAKEINT

#define INT2_1 *((volatile uint32_t *) 0x0D50)		//EPWM1_TZINT
#define INT2_2 *((volatile uint32_t *) 0x0D52)		//EPWM2_TZINT
#define INT2_3 *((volatile uint32_t *) 0x0D54)		//EPWM3_TZINT
#define INT2_4 *((volatile uint32_t *) 0x0D56)		//EPWM4_TZINT
#define INT2_5 *((volatile uint32_t *) 0x0D58)		//Reserved
#define INT2_6 *((volatile uint32_t *) 0x0D5A)		//Reserved
#define INT2_7 *((volatile uint32_t *) 0x0D5C)		//Reserved
#define INT2_8 *((volatile uint32_t *) 0x0D5E)		//Reserved

#define INT3_1 *((volatile uint32_t *) 0x0D60)		//EPWM1_INT
#define INT3_2 *((volatile uint32_t *) 0x0D62)		//EPWM2_INT
#define INT3_3 *((volatile uint32_t *) 0x0D64)		//EPWM3_INT
#define INT3_4 *((volatile uint32_t *) 0x0D66)		//EPWM4_INT
#define INT3_5 *((volatile uint32_t *) 0x0D68)		//EPWM4_INT
#define INT3_6 *((volatile uint32_t *) 0x0D6A)		//Reserved
#define INT3_7 *((volatile uint32_t *) 0x0D6C)		//Reserved
#define INT3_8 *((volatile uint32_t *) 0x0D6E)		//Reserved

#define INT4_1 *((volatile uint32_t *) 0x0D70)		//ECAP1_INT
#define INT4_2 *((volatile uint32_t *) 0x0D72)		//Reserved
#define INT4_3 *((volatile uint32_t *) 0x0D74)		//Reserved
#define INT4_4 *((volatile uint32_t *) 0x0D76)		//Reserved
#define INT4_5 *((volatile uint32_t *) 0x0D78)		//Reserved
#define INT4_6 *((volatile uint32_t *) 0x0D7A)		//Reserved
#define INT4_7 *((volatile uint32_t *) 0x0D7C)		//Reserved
#define INT4_8 *((volatile uint32_t *) 0x0D7E)		//Reserved

#define INT5_1 *((volatile uint32_t *) 0x0D80)		//EQEP1_INT (EQEP1)
#define INT5_2 *((volatile uint32_t *) 0x0D82)		//Reserved  (EQEP2)
#define INT5_3 *((volatile uint32_t *) 0x0D84)		//Reserved
#define INT5_4 *((volatile uint32_t *) 0x0D86)		//Reserved
#define INT5_5 *((volatile uint32_t *) 0x0D88)		//Reserved
#define INT5_6 *((volatile uint32_t *) 0x0D8A)		//Reserved
#define INT5_7 *((volatile uint32_t *) 0x0D8C)		//Reserved
#define INT5_8 *((volatile uint32_t *) 0x0D8E)		//Reserved

#define INT6_1 *((volatile uint32_t *) 0x0D90)		//SPIRXINTA (SPI-A)
#define INT6_2 *((volatile uint32_t *) 0x0D92)		//SPITXINTA (SPI-A)
#define INT6_3 *((volatile uint32_t *) 0x0D94)		//Reserved
#define INT6_4 *((volatile uint32_t *) 0x0D96)		//Reserved
#define INT6_5 *((volatile uint32_t *) 0x0D98)		//Reserved
#define INT6_6 *((volatile uint32_t *) 0x0D9A)		//Reserved
#define INT6_7 *((volatile uint32_t *) 0x0D9C)		//Reserved
#define INT6_8 *((volatile uint32_t *) 0x0D9E)		//Reserved

#define INT7_1 *((volatile uint32_t *) 0x0DA0)		//Reserved
#define INT7_2 *((volatile uint32_t *) 0x0DA2)		//Reserved
#define INT7_3 *((volatile uint32_t *) 0x0DA4)		//Reserved
#define INT7_4 *((volatile uint32_t *) 0x0DA6)		//Reserved
#define INT7_5 *((volatile uint32_t *) 0x0DA8)		//Reserved
#define INT7_6 *((volatile uint32_t *) 0x0DAA)		//Reserved
#define INT7_7 *((volatile uint32_t *) 0x0DAC)		//Reserved
#define INT7_8 *((volatile uint32_t *) 0x0DAE)		//Reserved

#define INT8_1 *((volatile uint32_t *) 0x0DB0)		//I2CINT1A (I2C-A)
#define INT8_2 *((volatile uint32_t *) 0x0DB2)		//I2CINT2A (I2C-A)
#define INT8_3 *((volatile uint32_t *) 0x0DB4)		//Reserved
#define INT8_4 *((volatile uint32_t *) 0x0DB6)		//Reserved
#define INT8_5 *((volatile uint32_t *) 0x0DB8)		//Reserved
#define INT8_6 *((volatile uint32_t *) 0x0DBA)		//Reserved
#define INT8_7 *((volatile uint32_t *) 0x0DBC)		//Reserved
#define INT8_8 *((volatile uint32_t *) 0x0DBE)		//Reserved

#define INT9_1 *((volatile uint32_t *) 0x0DC0)		//SCIRXINTA (SCI-A)
#define INT9_2 *((volatile uint32_t *) 0x0DC2)		//SCITXINTA (SCI-A)
#define INT9_3 *((volatile uint32_t *) 0x0DC4)		//Reserved
#define INT9_4 *((volatile uint32_t *) 0x0DC6)		//Reserved
#define INT9_5 *((volatile uint32_t *) 0x0DC8)		//Reserved
#define INT9_6 *((volatile uint32_t *) 0x0DCA)		//Reserved
#define INT9_7 *((volatile uint32_t *) 0x0DCC)		//Reserved
#define INT9_8 *((volatile uint32_t *) 0x0DCE)		//Reserved

#define INT10_1 *((volatile uint32_t *) 0x0DD0)		//ADCINT1 (ADC)
#define INT10_2 *((volatile uint32_t *) 0x0DD2)		//ADCINT2 (ADC)
#define INT10_3 *((volatile uint32_t *) 0x0DD4)		//ADCINT3 (ADC)
#define INT10_4 *((volatile uint32_t *) 0x0DD6)		//ADCINT4 (ADC)
#define INT10_5 *((volatile uint32_t *) 0x0DD8)		//ADCINT5 (ADC)
#define INT10_6 *((volatile uint32_t *) 0x0DDA)		//ADCINT6 (ADC)
#define INT10_7 *((volatile uint32_t *) 0x0DDC)		//ADCINT7 (ADC)
#define INT10_8 *((volatile uint32_t *) 0x0DDE)		//ADCINT8 (ADC)

#define INT11_1 *((volatile uint32_t *) 0x0DE0)		//Reserved
#define INT11_2 *((volatile uint32_t *) 0x0DE2)		//Reserved
#define INT11_3 *((volatile uint32_t *) 0x0DE4)		//Reserved
#define INT11_4 *((volatile uint32_t *) 0x0DE6)		//Reserved
#define INT11_5 *((volatile uint32_t *) 0x0DE8)		//Reserved
#define INT11_6 *((volatile uint32_t *) 0x0DEA)		//Reserved
#define INT11_7 *((volatile uint32_t *) 0x0DEC)		//Reserved
#define INT11_8 *((volatile uint32_t *) 0x0DEE)		//Reserved

#define INT12_1 *((volatile uint32_t *) 0x0DF0)		//XINT3
#define INT12_2 *((volatile uint32_t *) 0x0DF2)		//Reserved
#define INT12_3 *((volatile uint32_t *) 0x0DF4)		//Reserved
#define INT12_4 *((volatile uint32_t *) 0x0DF6)		//Reserved
#define INT12_5 *((volatile uint32_t *) 0x0DF8)		//Reserved
#define INT12_6 *((volatile uint32_t *) 0x0DFA)		//Reserved
#define INT12_7 *((volatile uint32_t *) 0x0DFC)		//Reserved
#define INT12_8 *((volatile uint32_t *) 0x0DFE)		//Reserved


#define PIECTRL  *((volatile uint16_t *) 0x0CE0)	//PIE, Control Register
#define PIEACK   *((volatile uint16_t *) 0x0CE1)	//PIE, Acknowledge Register
#define PIEIER1  *((volatile uint16_t *) 0x0CE2)	//PIE, INT1 Group Enable Register
#define PIEIFR1  *((volatile uint16_t *) 0x0CE3)    //PIE, INT1 Group Flag Register
#define PIEIER2  *((volatile uint16_t *) 0x0CE4)    //PIE, INT2 Group Enable Register
#define PIEIFR2  *((volatile uint16_t *) 0x0CE5)	//PIE, INT2 Group Flag Register
#define PIEIER3  *((volatile uint16_t *) 0x0CE6)	//PIE, INT3 Group Enable Register
#define PIEIFR3  *((volatile uint16_t *) 0x0CE7)	//PIE, INT3 Group Flag Register
#define PIEIER4  *((volatile uint16_t *) 0x0CE8)	//PIE, INT4 Group Enable Register	
#define PIEIFR4  *((volatile uint16_t *) 0x0CE9)	//PIE, INT4 Group Flag Register
#define PIEIER5  *((volatile uint16_t *) 0x0CEA)	//PIE, INT5 Group Enable Register
#define PIEIFR5  *((volatile uint16_t *) 0x0CEB)	//PIE, INT5 Group Flag Register	
#define PIEIER6  *((volatile uint16_t *) 0x0CEC)	//PIE, INT6 Group Enable Register	
#define PIEIFR6  *((volatile uint16_t *) 0x0CED)	//PIE, INT6 Group Flag Register			
#define PIEIER7  *((volatile uint16_t *) 0x0CEE)	//PIE, INT7 Group Enable Register		
#define PIEIFR7  *((volatile uint16_t *) 0x0CEF)	//PIE, INT7 Group Flag Register		
#define PIEIER8  *((volatile uint16_t *) 0x0CF0)	//PIE, INT8 Group Enable Register		
#define PIEIFR8  *((volatile uint16_t *) 0x0CF1)	//PIE, INT8 Group Flag Register		
#define PIEIER9  *((volatile uint16_t *) 0x0CF2)	//PIE, INT9 Group Enable Register		
#define PIEIFR9  *((volatile uint16_t *) 0x0CF3)	//PIE, INT9 Group Flag Register		
#define PIEIER10 *((volatile uint16_t *) 0x0CF4)	//PIE, INT10 Group Enable Register
#define PIEIFR10 *((volatile uint16_t *) 0x0CF5)	//PIE, INT10 Group Flag Register		
#define PIEIER11 *((volatile uint16_t *) 0x0CF6)	//PIE, INT11 Group Enable Register		
#define PIEIFR11 *((volatile uint16_t *) 0x0CF7)	//PIE, INT11 Group Flag Register
#define PIEIER12 *((volatile uint16_t *) 0x0CF8)	//PIE, INT12 Group Enable Register		
#define PIEIFR12 *((volatile uint16_t *) 0x0CF9)	//PIE, INT12 Group Flag Register		

#define XINT1CR  *((volatile uint16_t *) 0x7070)
#define XINT2CR  *((volatile uint16_t *) 0x7071)
#define XINT3CR  *((volatile uint16_t *) 0x7072)

#define XINT1CTR  *((volatile uint16_t *) 0x7078)
#define XINT2CTR  *((volatile uint16_t *) 0x7079)
#define XINT3CTR  *((volatile uint16_t *) 0x707A)







#define PIE_ENABLE 1
#define PIE_DISABLE 0

#define FALLEDGE	(0x00<<2)
#define RISEDGE		(0x01<<2)
#define RISFALLEDGE	(0x03<<2)

#endif
