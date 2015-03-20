/*
 * SPI_Functions
 *
 *  Created on: 11/04/2014
 *      Author: Lorien
 */

#ifndef SPI_FUNCTIONS_H
#define SPI_FUNCTIONS_H

/* USEFUL IN INTERRUPT MODE
void SPI_setFIFOTHR(uint8_t thr){
	SPIFFRX = RXFIFORST | RXFFINEN | thr;
}*/

void SPI_Write(uint8_t slaveReg, uint8_t data){
	uint8_t dummy; //TEMPORAL VARIABLE TO TRASH SPI RESPONSE

//LOAD FIFO WITH TX BYTES
	SPITXBUF = (slaveReg << 8);//WRITE 1 BYTE LEFT JUSTIFIED
	SPITXBUF = (data << 8);//WRITE 1 BYTE LEFT JUSTIFIED

	//WAIT FOR RESPONSE
	while(!(SPIFFRX & (1<<9)));
	dummy = SPIRXBUF && 0x00FF; //PULL 1 BYTE RIGHT JUSTIFIED
	dummy = SPIRXBUF && 0x00FF; //PULL 1 BYTE RIGHT JUSTIFIED

}

void SPI_Strobe(uint8_t strobe, uint8_t * reg){
//CHECK IF REG IS PROVIDED IF NOT TRASH SPI RESPONSE
//INTO DUMMY VARIABLE
	uint8_t dummy;
	if(reg == NULL){
		reg = &dummy;
	}

//LOAD FIFO WITH TX BYTES
	SPITXBUF = (strobe << 8);

//WAIT FOR RESPONSE
	while(!(SPIFFRX & (1<<8)));
	*reg = SPIRXBUF & 0x00FF; //PULL 1 BYTE RIGHT JUSTIFIED
}

void SPI_Read(uint8_t slaveReg, uint8_t * reg){
//CHECK IF REG IS PROVIDED IF NOT TRASH SPI RESPONSE
//INTO DUMMY VARIABLE
	uint8_t dummy;
	if(reg == NULL){
		reg = &dummy;
	}

//LOAD FIFO WITH TX BYTES
	SPITXBUF = (slaveReg << 8);	//WRITE 1 BYTE LEFT JUSTIFIED
	SPITXBUF = (0x00 << 8);	//WRITE 1 BYTE LEFT JUSTIFIED

//WAIT FOR RESPONSE
	while(!(SPIFFRX & (1<<9)));
	*reg = SPIRXBUF & 0x00FF; //PULL 1 BYTE RIGHT JUSTIFIED
	*reg = SPIRXBUF & 0x00FF; //PULL 1 BYTE RIGHT JUSTIFIED
}

/*INTERRUPT MODE IS DISABLED, UNCOMMENT TO ENABLE
__interrupt void SPI_receiveData(){
	//READ BYTES FROM SPI FIFO
	uint8_t i = 0;
	for(i = 0; i<spi.numBytes;i++){
		*(spi.reg) = SPIRXBUF & 0x00FF;
	}

	//FLAG SPI.REG AS FREE TO CHANGE
	spi.readPending = false;

	//ACKNOWLEDGE INTERRUPT IN PIE MODULE
	PIE_ackInt(6);

	//ACKNOWLEDGE INTERRUPT IN SPI MODULE
	SPIFFRX |= RXFFINT_CLR;

}
*/

void SPI_init(uint8_t baudRate){
/*INTERRUPT MODE IS DISABLED, UNCOMMENT TO ENABLE
//------INTERRUPT SETUP-----------------------------------------------------------------------------
	//-LOAD FUNTION INTO PIE VECTOR
	EALLOW;
	INT6_1 = (uint32_t)&SPI_receiveData;
	EDIS;
	//-ENABLE INTERRUPTS
	PIE_enInterrupt(6,1);
	PIE_enCPUInterrupt(6);
	PIE_enCPUglobalInterrupts();

//---------------------------------------------------------------------------------------------------
*/


//--------ENABLE CLOCK FEED--------------------------------------------------------------------------
CLK_enModule(SPIAENCLK, (uint16_t *) &(PCLKCR0));
//---------------------------------------------------------------------------------------------------

//--------SETUP GPIO---------------------------------------------------------------------------------
	GPIO_setPullUp(16, PULL_DISABLE);
	GPIO_setPullUp(17, PULL_DISABLE);
	GPIO_setPullUp(18, PULL_DISABLE);
	GPIO_setPullUp(19, PULL_DISABLE);

	GPIO_setMUXMode(16, SPISIMOA);
	GPIO_setMUXMode(17, SPISOMIA);
	GPIO_setMUXMode(18, SPICLKA);
	GPIO_setMUXMode(19, SPISTEA);

	GPIO_setQualification(16, ASYNC);
	GPIO_setQualification(17, ASYNC);
	GPIO_setQualification(18, ASYNC);
	GPIO_setQualification(19, ASYNC);

//---------------------------------------------------------------------------------------------------




//--------SETUP FIFOS--------------------------------------------------------------------------------
//----TX FIFO----------------------------------------------------------------------------------------
	SPIFFTX = (SPIRST | SPIFFENA | TXFIFORST); //RE ENABLE Tx FIFO
//----RX FIFO----------------------------------------------------------------------------------------
	SPIFFRX = (RXFIFORST); //RE ENABLE Rx FIFO
//---------------------------------------------------------------------------------------------------


	
//-----GENERAL SPI MODULE SETUP----------------------------------------------------------------------
	SPICCR = SPI_CHAR0 | SPI_CHAR1 | SPI_CHAR2;
	SPICTL = CLOCK_PHASE | MASTER_SLAVE | TALK;
	SPIBBR = baudRate;
	SPICCR = SPI_SW_RESET | SPI_CHAR0 | SPI_CHAR1 | SPI_CHAR2;	//ENABLE MODULE ONCE DONE WITH CONFIG

	SPIPRI = 1<<5 | 1<<4;
//---------------------------------------------------------------------------------------------------


}


#endif
