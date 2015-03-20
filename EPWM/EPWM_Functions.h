/*
 * EPWM_Functions.h
 *
 *  Created on: 20/03/2014
 *      Author: Lorien
 */

void EPWM_Init(){
//-----------------FEED THE MODULE WITH SYSTEM'S CLOCK----------------
	EALLOW;
		PCLKCR0 |= HRPWMENCLK;//ENABLE OR DISABLE HRPWM
		PCLKCR1 |= (ECAP1ENCLK | EPWM1ENCLK | EPWM2ENCLK);	//ENABLE OR DISABLE EACH PWM MODULE (1,2,3,4)
	EDIS;
//------------------------SETUP GPIO FOR EPWM-------------------------

		//GPAPUD |= 0xBB;
		//GPAMUX1 |= 0x55; //SET GPIO 0,1,2,3 TO EPWM1A, EPWM1B, EPWM2A, EPWM2B

		GPIO_setPullUp(0, PULL_DISABLE);
		GPIO_setPullUp(1, PULL_DISABLE);
		GPIO_setPullUp(2, PULL_DISABLE);
		GPIO_setPullUp(3, PULL_DISABLE);

		GPIO_setMUXMode(0, EPWM);
		GPIO_setMUXMode(1, EPWM);
		GPIO_setMUXMode(2, EPWM);
		GPIO_setMUXMode(3, EPWM);

	EALLOW;
	PCLKCR0 &= ~(1<<2); //DISABLE TIME BASE CLOCK

//-----------------------EPWM1 INITIAL SETUP---------------------------
	EPWM1_TBPRD = 0xFFFF;	//SET PERIOD TO COUNT TO 2^16 (65536)
	EPWM1_TBPHS = 0; 		//SET PHASE REGISTER TO ZERO
	EPWM1_TBCTL = (FREESOFT1 | FREESOFT0 | HSPCLKDIV2 | HSPCLKDIV1 | HSPCLKDIV0 | SYNCOSEL1 | SYNCOSEL0); //FREE FROM DEBUGGER, CLK DIVIDER SET TO 14, DISABLE SYNC
	
	EPWM1_CMPCTL =0;
	
	EPWM1_AQCTLA = CAU0 | ZRO1;
	EPWM1_AQCTLB = CBU0 | ZRO1;
	
//-----------------------EPWM2 INITIAL SETUP---------------------------
	EPWM2_TBCTL = (FREESOFT1 | FREESOFT0 | HSPCLKDIV2 | HSPCLKDIV1 | HSPCLKDIV0 | SYNCOSEL1 | SYNCOSEL0); //FREE FROM DEBUGGER, CLK DIVIDER SET TO 14, DISABLE SYNC
	EPWM2_TBPRD = 0xFFFF;	//SET COUNTER TO COUNT TO 2^16 (65536)

	EPWM2_CMPCTL = 0;

	EPWM2_AQCTLA = CAU0 | ZRO1;
	EPWM2_AQCTLB = CBU0 | ZRO1;	

	PCLKCR0 |= (1<<2);

	EDIS;

}

void EPWM_setDuty(uint8_t module, uint8_t duty){
	uint16_t bitDuty=(65535>>4)*((duty>>7)+1);
	
	switch(module){
		case 1:
			EPWM1_CMPA=bitDuty;
			break;
		case 2:
			EPWM1_CMPB=bitDuty;
			break;
		case 3:
			EPWM2_CMPA=bitDuty;
			break;
		case 4:
			EPWM2_CMPB=bitDuty;
			break;
	}

}


