/*
 * CLK_defines.h
 *
 *  Created on: 11 Feb 2015
 *      Author: Lorien
 */

#ifndef CLK_DEFINES_H_
#define CLK_DEFINES_H_

#define XCLK		*((volatile uint16_t *)0x7010) //XCLKOUT/XCLKIN Control
#define PLLSTS		*((volatile uint16_t *)0x0711) //PLL Status Register
#define CLKCTL		*((volatile uint16_t *)0x7012) //Clock Control Register
#define PLLLOCKPRD	*((volatile uint16_t *)0x7013) //PLL Lock Period Register
#define INTOSC1TRIM *((volatile uint16_t *)0x7014) //Internal Oscillator 1 Trim Register
#define INTOSC2TRIM *((volatile uint16_t *)0x7016) //Internal Oscillator 2 Trim Register
#define LOSPCP		*((volatile uint16_t *)0x701B) //Low-Speed Peripheral Clock Pre-Scaler Register
#define PCLKCR0		*((volatile uint16_t *)0x701C) //Peripheral Clock Control Register 0
#define PCLKCR1		*((volatile uint16_t *)0x701D) //Peripheral Clock Control Register 1
#define LPMCR0		*((volatile uint16_t *)0x701E) //Low Power Mode Control Register 0
#define PCLKCR3		*((volatile uint16_t *)0x7020) //Peripheral Clock Control Register 3
#define PLLCR		*((volatile uint16_t *)0x7021) //PLL Control Register
#define SCSR		*((volatile uint16_t *)0x7022) //System Control and Status Register
#define WDCNTR		*((volatile uint16_t *)0x7023) //Watchdog Counter Register
#define WDKEY		*((volatile uint16_t *)0x7025) //Watchdog Reset Key Register
#define WDCR		*((volatile uint16_t *)0x7029) //Watchdog Control Register
#define BORCFG		*((volatile uint16_t *)0x0985) //BOR Configuration Register

//------------PCLKCR0--------------------------------------
#define SCIAENCLK	(1<<10)
#define SPIAENCLK	(1<<8)
#define I2CAENCLK	(1<<4)
#define ADCENCLK	(1<<3)
#define TBCLKSYNC	(1<<2)
#define HRPWMENCLK	(1<<0)

//------------PCLKCR1--------------------------------------
#define ECAP1ENCLK	(1<<8)
#define EPWM4ENCLK	(1<<3)
#define EPWM3ENCLK	(1<<2)
#define EPWM2ENCLK	(1<<1)
#define EPWM1ENCLK	(1<<0)

//------------PCLKCR3---------------------------------------
#define GPIOINENCLK		(1<<13)
#define CPUTIMER2ENCLK	(1<<10)
#define CPUTIMER1ENCLK	(1<<9)
#define CPUTIMER0ENCLK	(1<<8)
#define COMP2ENCLK		(1<<1)
#define COMP1ENCLK		(1<<0)

//------------DIVISOR DE FRECUENCIAS PERIFERICOS------------
#define PDIV_1	0x0
#define PDIV_2	0x1
#define PDIV_4	0x2
#define PDIV_6	0x3
#define PDIV_8	0x4
#define PDIV_10	0x5
#define PDIV_12	0x6
#define PDIV_14	0x8

//-------------MULTIPLOS MAINCLK FRECUENCIA------------------
#define PLLBYPASS	0x00
#define MULT_1		0x01
#define MULT_2		0x02
#define MULT_3		0x03
#define MULT_4		0x04
#define MULT_5		0x05
#define MULT_6		0x06
#define MULT_7		0x07
#define MULT_8		0x08
#define MULT_9		0x09
#define MULT_10		0x10
#define MULT_11		0x11
#define MULT_12		0x12
#define DIV_1		0x03
#define DIV_2		0x02
#define DIV_4		0x01




#endif /* CLK_DEFINES_H_ */
