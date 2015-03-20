/*
 * CLK_functions.h
 *
 *  Created on: 01/02/2015
 *      Author: Lorien
 */

void CLK_setFreq(uint8_t div, uint8_t mult){
	//Procedure Found in Page 49 --> TMS320F2802x/TMS320F2802xx Piccolo System Control and Interrupts
	EALLOW;
	while (PLLSTS & (1 << 3)){
		PLLSTS &= (1 << 4);
	}

	if (((PLLSTS & (3 << 7)) == 3) || ((PLLSTS & (3 << 7)) == 2)) {
		PLLSTS &= ~(3 << 7);
	}

	PLLSTS |= (1 << 6);

	PLLCR = mult;

	while ((PLLSTS & 0x1) == 0); //WAIT FOR PLL TO LOCK
	PLLSTS &= ~(1 << 6);

	PLLSTS &= ~(11 << 7);
	PLLSTS |= (div << 7);
	EDIS;
}

void CLK_setPerFreq(uint8_t div){
	EALLOW;
		LOSPCP = div;
	EDIS;
}

void CLK_enModule(uint8_t mod, uint16_t * reg){
	EALLOW;
	*reg |= mod;
	EDIS;
}

void WDOG_disable(){
	EALLOW;
	WDCR = 0x68;
	EDIS;
}


void WDOG_reset(){
	EALLOW;
	WDKEY = 0x55;
	asm(" NOP");
	WDKEY = 0xAA;
	EDIS;
}

