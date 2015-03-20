#ifndef I2C_DEFINES_H
#define I2C_FUNCITONS_H

/*****************************************************************************
********************CLOCK PERIPHERIALS REGISTERS******************************
*****************************************************************************/

#define PCLKCR0 (*(volatile uint16_t *)0x701C) //PERIPHERIAL CLOCK CONTROL REGISTER

/*****************************************************************************
**************************GPIO I2C PINS REGISTERS*****************************
*****************************************************************************/

#define GPBMUX1  (*(volatile uint32_t *)0x6F96) //GPIO MULTIPLEXER SELECTION
#define GPBPUD 	 (*(volatile uint32_t *)0x6F9C) //GPIO PULL UP DISABLE REGISTER
#define GPBQSEL1 (*(volatile uint32_t *)0x6F92) //GPIO QUALIFICATION SELECTION REGISTER

/*****************************************************************************
****************I2C DEFAULT SLAVE ADDRESS DEFINE******************************
*****************************************************************************/

#define SLAVE_ADDRESS 0x00

/*****************************************************************************
**************************I2C Registers Defines*******************************
*****************************************************************************/

#define I2COAR		 (*(volatile uint16_t *)0x7900) //I2C Own address register
#define I2CIER		 (*(volatile uint16_t *)0x7901) //I2C Interrupt enable register
#define I2CSTR 		 (*(volatile uint16_t *)0x7902) //I2C Status Register
#define I2CCLKL 	 (*(volatile uint16_t *)0x7903) //I2C Clock Low-Time Divider
#define I2CCLKH 	 (*(volatile uint16_t *)0x7904) //I2C Clock High-Time Divider
#define I2CCNT 		 (*(volatile uint16_t *)0x7905) //I2c Data Count Register
#define I2CDRR 		 (*(volatile uint16_t *)0x7906) //I2C Data Receive Register
#define I2CSAR 		 (*(volatile uint16_t *)0x7907) //I2C Slave Address Register
#define I2CDXR 		 (*(volatile uint16_t *)0x7908) //I2C Data Transmit Register
#define I2CMDR 		 (*(volatile uint16_t *)0x7909) //I2C Mode Register
#define I2CISRC 	 (*(volatile uint16_t *)0x790A) //I2C Interrupt Source Register
#define I2CEMDR 	 (*(volatile uint16_t *)0x790B) //I2C Extended Mode Register
#define I2CPSC 		 (*(volatile uint16_t *)0x790C) //I2C Prescaler Register 
#define I2CFFTX 	 (*(volatile uint16_t *)0x7920) //I2C FIFO Transmit Register
#define I2CFFRX 	 (*(volatile uint16_t *)0x7921) //I2C FIFO Receive Register  

/*****************************************************************************
**************************I2C Registers Bits**********************************
*****************************************************************************/

//-----------I2CMDR BITS----------------
#define NACKMOD (1<<15)
#define FREE 	(1<<14)
#define STT		(1<<13)
#define MDRRSVD	(1<<12)
#define STP		(1<<11)
#define MST		(1<<10)
#define TRX 	(1<<9)
#define XA		(1<<8)
#define RM		(1<<7)
#define DLB		(1<<6)
#define IRS		(1<<5)
#define STB		(1<<4)
#define FDF		(1<<3)
#define BC2		(1<<2)
#define BC1		(1<<1)
#define BC0		(1<<0)


//---------I2CSTR BITS-----------------
#define STRRSVD1 (1<<15)
#define SDIR 	 (1<<14)
#define NACKSNT  (1<<13)
#define BB		 (1<<12)
#define RSFULL	 (1<<11)
#define XSMT	 (1<<10)
#define AAS		 (1<<9)
#define AD0		 (1<<8)
#define STRRSVD2 (1<<7)
#define STRRSVD3 (1<<6)
#define SCD		 (1<<5)
#define XRDY	 (1<<4)
#define RRDY	 (1<<3)
#define ARDY	 (1<<2)
#define NACK	 (1<<1)
#define	AL		 (1<<0)


#endif
