void SPI_setupGpio(){
	EALLOW;
		//GPAMUX2  &= ~(0xAA);		//Setup multiplexers values for SPI pins
		GPAMUX2  |= 0x15;
		GPAQSEL2 |= 0x3F;
		GPADIR   |= ((uint32_t)1)<<19;
		GPASET   |= ((uint32_t)1)<<19;

		PCLKCR0 |=(1<<8); //Enable clock feed to SPI module from main clock
	EDIS;
}

void lowSPISTEA(){
	EALLOW;
		GPACLEAR = ((uint32_t)1)<<19;
	EDIS;
}

void highSPISTEA(){
	EALLOW;
		GPASET = ((uint32_t)1)<<19;
	EDIS;
}

void inputSIMO(){
	EALLOW;
		GPAMUX2 &= ~(1<<2);
		GPADIR  &= ~(((uint32_t)1)<<17);
	EDIS;
}

void spiSIMO(){
	EALLOW;
			GPAMUX2 &= ~(1<<3);
			GPAMUX2 |=  (1<<2);
	EDIS;
}

void startSpiCon(){
	EALLOW;
		GPAMUX2 &= ~(1<<2);
		GPADIR  &= ~(((uint32_t)1)<<17);
		GPACLEAR = ((uint32_t)1)<<19;
		while(GPADAT & ((uint32_t)1)<<17);
		GPAMUX2 &= ~(1<<3);
		GPAMUX2 |=  (1<<2);
	EDIS;
}

void SPI_setupModule(uint8_t baudRate){
	
	SPICCR = SPI_CHAR0 | SPI_CHAR1 | SPI_CHAR2;
		SPICTL = CLOCK_PHASE | MASTER_SLAVE | TALK;
		SPIBBR = baudRate;
	SPICCR = SPI_SW_RESET | SPI_CHAR0 | SPI_CHAR1 | SPI_CHAR2;	//ENABLE MODULE ONCE DONE WITH CONFIG

	SPIPRI = 1<<5 | 1<<4;

}

void SPI_setupFIFOS(){
	//----TX FIFO--------------------------------------------------------
		SPIFFTX = (SPIRST | TXFIFORST | SPIFFENA); //RE ENABLE Tx FIFO
	//----RX FIFO--------------------------------------------------------
		SPIFFRX = (RXFIFORST | RXFFIL4 | RXFFIL3 | RXFFIL2 | RXFFIL1 | RXFFIL0); //RE ENABLE Rx FIFO
}

void SPI_init(uint8_t baudRate){
	SPI_setupGpio();
	//SPI_setupFIFOS();
	SPI_setupModule(baudRate);
}

uint8_t xfer(uint16_t byte){
	while(SPIST & 1<<5);
		SPITXBUF = byte<<8;
	while(!(SPIST & 1<<6));
	return SPIRXBUF & 0xFF;

}

uint8_t SPI_Write(uint8_t slaveReg, uint8_t data){
	uint8_t dummyData = 0;

	startSpiCon();
		dummyData = xfer(slaveReg);
		dummyData = xfer(data);
	highSPISTEA();
		return dummyData;
}

uint8_t SPI_Strobe(uint8_t strobe){
	uint8_t dummyData = 0;

	startSpiCon();
		dummyData = xfer(strobe);
	highSPISTEA();
		return dummyData;
}

uint8_t SPI_Read(uint8_t slaveReg){
	uint8_t dummyData = 0;

	startSpiCon();
		dummyData = xfer(slaveReg);
		dummyData = xfer(0x00);
	highSPISTEA();
		return dummyData;
}


/*void burstSPIWrite(uint8_t slaveReg, uint8_t numWords, uint8_t TXData[]){
	int i;
		startSpiCon();
		xfer(slaveReg | BURST_BIT);
	for(i=0;i<numWords;i++){
		while((SPIFFRX & (0xF<<8))>2);
		xfer((uint16_t)TXData[i]);
	}
		highSPISTEA();
}*/

/*void burstSPIRead(uint16_t slaveReg, uint8_t numWords, uint16_t RXData[]){
	int i;
	for(i=0;i<numWords;i++){
		while(!(SPIFFRX & (0xF<<8)));
		RXData[i] = SPIRXBUF;
	}
}*/
