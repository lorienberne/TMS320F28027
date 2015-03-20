/*
 * EPWM_Defines.h
 *
 *  Created on: 20/03/2014
 *      Author: Lorien
 */


/********************************************
*****************EPWM1 REGS*******************
********************************************/
#define EPWM1_START_ADDR 0x6800
//---------TIME-BASE SUBMODULE REGISTERS-------
#define EPWM1_TBCTL 	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0000))
#define EPWM1_TBSTS 	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0001))
#define EPWM1_TBPHSHR	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0002))
#define EPWM1_TBPHS		(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0003))
#define EPWM1_TBCTR		(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0004))
#define EPWM1_TBPRD		(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0005))
#define EPWM1_TBPRDHR	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0006))

//------COUNTER-COMPARE SUBMODULE REGISTERS---
#define EPWM1_CMPCTL	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0007))
#define EPWM1_CMPAHR	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0008))
#define EPWM1_CMPA		(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x0009))
#define EPWM1_CMPB		(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x000A))

//-----ACTION QUALIFIER SUBMODULE REGISTERS---
#define EPWM1_AQCTLA	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x000B))
#define EPWM1_AQCTLB	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x000C))
#define EPWM1_AQSFRC	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x000D))
#define EPWM1_AQCSFRC	(*(volatile uint16_t *) (EPWM1_START_ADDR + 0x000E))

/********************************************
*****************EPWM2 REGS*******************
********************************************/
#define EPWM2_START_ADDR 0x6840
//---------TIME-BASE SUBMODULE REGISTERS-------
#define EPWM2_TBCTL 	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0000))
#define EPWM2_TBSTS 	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0001))
#define EPWM2_TBPHSHR	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0002))
#define EPWM2_TBPHS		(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0003))
#define EPWM2_TBCTR		(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0004))
#define EPWM2_TBPRD		(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0005))
#define EPWM2_TBPRDHR	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0006))

//------COUNTER-COMPARE SUBMODULE REGISTERS---
#define EPWM2_CMPCTL	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0007))
#define EPWM2_CMPAHR	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0008))
#define EPWM2_CMPA		(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x0009))
#define EPWM2_CMPB		(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x000A))

//-----ACTION QUALIFIER SUBMODULE REGISTERS---
#define EPWM2_AQCTLA	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x000B))
#define EPWM2_AQCTLB	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x000C))
#define EPWM2_AQSFRC	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x000D))
#define EPWM2_AQCSFRC	(*(volatile uint16_t *) (EPWM2_START_ADDR + 0x000E))


//------------PCLKR0 BITS--------------------
#define HRPWMENCLK (1<<0)

//------------PCLKR1 BITS--------------------
#define ECAP1ENCLK (1<<8)
#define EPWM4ENCLK (1<<3)
#define EPWM3ENCLK (1<<2)
#define EPWM2ENCLK (1<<1)
#define EPWM1ENCLK (1<<0)

//------------TBCTL BITS---------------------
#define FREESOFT1  (1<<15)
#define FREESOFT0  (1<<14)
#define PHSDIR	   (1<<13)
#define CLKDIV2	   (1<<12)
#define CLKDIV1	   (1<<11)
#define CLKDIV0	   (1<<10)
#define HSPCLKDIV2 (1<<9)
#define HSPCLKDIV1 (1<<8)
#define HSPCLKDIV0 (1<<7)
#define SWFSYNC	   (1<<6)
#define SYNCOSEL1  (1<<5)
#define SYNCOSEL0  (1<<4)
#define PRDLD	   (1<<3)
#define PHSEN	   (1<<2)
#define CTRMODE1   (1<<1)
#define CTRMODE0   (1<<0)

//-------------CMPCTL BITS-----------------------
#define SHDWBFULL	(1<<9)
#define SHDWAFULL	(1<<8)
#define SHDWBMODE	(1<<6)
#define SHDWAMODE	(1<<4)
#define LOADBMODE1	(1<<3)
#define LOADBMODE0	(1<<2)
#define LOADAMODE1	(1<<1)
#define LOADAMODE0	(1<<0)

//-------------AQCTL_ BITS--------------------
#define CBD1	(1<<11)
#define CBD0	(1<<10)
#define CBU1	(1<<9)
#define CBU0	(1<<8)
#define CAD1	(1<<7)
#define CAD0	(1<<6)
#define CAU1	(1<<5)
#define CAU0	(1<<4)
#define PRD1	(1<<3)
#define PRD0	(1<<2)
#define ZRO1	(1<<1)
#define ZRO0	(1<<0) 
