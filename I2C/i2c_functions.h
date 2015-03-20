#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCITONS_H
void setupI2CGpio(){ //Setup GPIO pins 32(as SDAA) and 33(as SCLA)
	EALLOW;
	GPBPUD &= ~((1<<1) | 1);

	GPBQSEL1 |=((1<<3) | (1<<2) | (1<<1) | 1);

	GPBMUX1 |= ((1<<2) | (1<<0));    //SET BIT 0 AND BIT 2 TO 1
	GPBMUX1 &= ~(uint16_t)((1<<3) | (1<<1)); //SET BIT 1 AND BIT 3 TO 0
	EDIS;
}

void setupI2CModule(){
	//configure all the I2C registers for the transfer

/*****************************************************************************
*********************ENABLE CLOCK FOR I2C MODULE*****************************
*****************************************************************************/

	EALLOW;
	PCLKCR0 |= (1<<4);  //SET I2CAENCLK BIT TO 1 (ENABLE I2C CLOCK)
	EDIS;

/*****************************************************************************
*********************I2CPSC / I2C PRESCALER REGISTER**************************
*****************************************************************************/

	I2CPSC = 5; //SET PRESCALER TO DIVIDE 60MHZ BY (5+1)

/*****************************************************************************
****************I2CCLKL / I2C CLOCK DIVIDER LOW REGISTER**********************
*****************************************************************************/

	I2CCLKL = 12; //SET THE DURATION OF CLOCK'S LOW LEVEL TO BE HALF THE PERIOD (FREQ = 400kHz)

/*****************************************************************************
****************I2CCLKL / I2C CLOCK DIVIDER HIGH REGISTER*********************
*****************************************************************************/

	I2CCLKH = 12; //SET THE DURATION OF CLOCK'S HIGH LEVEL TO BE HALF THE PERIOD (FREQ = 400kHz)


/*****************************************************************************
*****************I2CIER / I2C INTERRUPT ENABLE REGISTER***********************
*****************************************************************************/

	I2CIER &= 0; //15 TO 0, DISABLE ALL INTERRUPTS

/*****************************************************************************
*****************************ENABLE FIFO MODE*********************************
******************************************************************************/

	I2CFFTX |= (1<<14);	//SET I2CFFEN TO 1 (ENABLE FIFO MODE)
	I2CFFTX |= (1<<13);	//SET TXFFRST TO 1 (ENABLE TRANSMIT FIFO OPERATION)

	I2CFFRX |= (1<<13); //SET RXFFRST TO 1 (ENABLE RECEIVE FIFO OPERATION)
	I2CFFRX &= ~(1<<7); //CLEAR RXFFINT (SET TO 0)


/*****************************************************************************
*********************I2CMDR / I2C MODE REGISTER*******************************
*****************************************************************************/

	I2CMDR &=~(1<<5);  //RESET AND DISABLE I2C MODULE FOR CONFIGURATION

	I2CMDR &=~(1<<15); //15-NACKMOD SET TO 0
	I2CMDR |=(1<<14);  //14-SET FREE BIT TO 1
					   //13-STT LEFT UNTOUCHED UNTIL START CONDITION REQUIRED
					   //12-RESERVED BIT
					   //11-STP LEFT UNTOUCHED UNTIL STOP CONDITION NEEDED
	I2CMDR |=(1<<10);  //10-MST SET TO 1 (MASTER MODE)
					   //09-TRX TO BE SET TO WHATEVER NEEDED EVERY TIME
	I2CMDR &=~(1<<8);  //08-XA SET TO 0 (7 BIT ADDRESSING MODE)
	I2CMDR &=~(1<<7);  //07-RM SET TO 0 (NON REPEAT MODE)
	I2CMDR &=~(1<<6);  //06-DLB SET TO 0 (DIGITAL LOOPBACK DISABLED)
					   //05-IRS LEFT FOR NOW
	I2CMDR &=~(1<<4);  //04-STB SET TO 0 (START BYTE MODE DISABLED)
	I2CMDR &=~(1<<3);  //03-FDF SET TO 0 (FREE DATA FORMATE MODE DISABLED)
	I2CMDR &=~((1<<2) | (1<<1) | 1); //02,01,00 - BC SET TO 000 MEANING 8 BIT DATA BYTES

/*****************************************************************************
*****************I2CSAR / I2C SLAVE ADDRESS REGISTER**************************
*****************************************************************************/


//************ENABLE AGAIN I2C MODULE********************
 /****/	I2CMDR |=(1<<5);  //***************************
  /**************************************************/
}

void I2CSetup(){
	setupI2CGpio();
	setupI2CModule();
}

void I2CDelay(unsigned long delay){
	int i;
	for(i=0;i<delay;i++);
}

void writeI2CRegister(uint8_t slaveAddress, uint8_t regAddress, uint8_t data){
	I2CSAR = 0x0000 | slaveAddress; //SET SLAVE'S ADDRESS BEFORE SENDING ANY DATA
	I2CCNT = 2;		 //NUMBER OF BYTES TO BE SENT

	I2CDXR = regAddress; 	 //INTRODUCE REGISTER ADDRESS INTO FIFO
	I2CDXR = data; 			 //INTRODUCE DATA TO BE SENT INTO FIFO

	I2CMDR = (FREE | STT | STP | MST | TRX | IRS) ;

	while(!(I2CSTR & (1<<5)));  //WAIT UNTIL STOP CONDITION SENT
	I2CSTR |= (1<<5);			//CLEAR STOP CONDITION DETECTED FLAG

}

uint8_t readI2CRegister(uint8_t slaveAddress, uint8_t regAddress){

	I2CSAR = 0x0000 | slaveAddress; //SET SLAVE'S ADDRESS BEFORE SENDING ANY DATA
	I2CCNT=1;				 //NUMBER OF BYTES TO BE SENT

	I2CDXR = regAddress; 	 //INTRODUCE REGISTER TO BE READ

	I2CMDR = (FREE | STT | MST | TRX | IRS) ;

	while(!(I2CSTR & (1<<2)));//WAIT UNTIL DATA IS SENT (ARDY FLAG)
	I2CSTR |= (1<<2); //CLEAR ARDY BY WRITING 1

	I2CCNT = 1;		//NUMBER OF BYTES TO EXPECT

	I2CMDR = (FREE | STT | STP | MST | IRS) ;


	while(!(I2CSTR & (1<<5))); //WAIT UNTIL STOP CONDITION DETECTED
	I2CSTR |= (1<<5);		   //CLEAR STOP CONDITION DETECTED FLAG

	return (uint8_t)I2CDRR;	  //RETURN DATA RECEIVED
}

void burstI2CRead(uint8_t slaveAddress, uint8_t regAddress, uint8_t numBytes, uint8_t data[]){

	I2CSAR = 0x0000 | slaveAddress; //SET SLAVE'S ADDRESS BEFORE SENDING ANY DATA
	I2CCNT=1;				 //NUMBER OF BYTES TO BE SENT

	I2CDXR = regAddress; 	 //INTRODUCE REGISTER TO BE READ

	I2CMDR = (FREE | STT | MST | TRX | IRS) ;

	while(!(I2CSTR & (1<<2)));//WAIT UNTIL DATA IS SENT (ARDY FLAG)
	I2CSTR |= (1<<2); //CLEAR ARDY BY WRITING 1

	I2CCNT = numBytes;

	I2CMDR = (FREE | STT | STP | MST | IRS) ;
	int i;
	for(i=0;i<numBytes;i++){
		while(!(I2CFFRX & (0xF<<8)));
		data[i] = (uint8_t)I2CDRR;
	}

	while(!(I2CSTR & (1<<5))); //WAIT UNTIL STOP CONDITION DETECTED
	I2CSTR |= (1<<5);		   //CLEAR STOP CONDITION DETECTED FLAG
}

#endif
