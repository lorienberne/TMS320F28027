/*
 * PIE_functions.h
 *
 *  Created on: 25/01/2015
 *      Author: Lorien
 */

#ifndef PIE_FUNCTIONS_H
#define PIE_FUNCTIONS_H

/*****************************************************************************/
//1. PIE_addExtInterrupt();***************************************************/
//2. PIE_enInterrupt();*******************************************************/
//3. CPU_enInterrupt();*******************************************************/
//4. CPU_enGlobalInterrupts();************************************************/
//5. Enable interrupt in module***********************************************/
//6. Raising edge or falling edge if external interrupt***********************/
/*****************************************************************************/






void PIE_init(){
	PIECTRL |= 1;
}

void PIE_enInterrupt(uint8_t group, uint8_t inter){
	EALLOW;
	*((volatile uint16_t *)(0x0CE2 + (2*(group-1)))) &= ~(1<<(inter-1));
	*((volatile uint16_t *)(0x0CE2 + (2*(group-1)))) |= (1<<(inter-1));
	EDIS;
}

void PIE_enCPUInterrupt(uint8_t group){
	EALLOW;
	IER |= (1<<(group-1)); 
	EDIS;
}

void PIE_enCPUglobalInterrupts(){
	__enable_interrupts();
}


void PIE_setPIEInts(bool enabler){
	EALLOW;
	PIECTRL |= enabler;
	EDIS;
}

void PIE_addExtInterrupt(uint8_t inter,void (*function)()){
	EALLOW;
	switch (inter){
	case 1:
		INT1_4 = (uint32_t)function;
		break;
	case 2:
		INT1_5 = (uint32_t)function;
		break;
	case 3:
		INT12_1 = (uint32_t)function;
		break;
	}
	EDIS;
}

void PIE_configExtInt(bool enabler,uint8_t polarity, uint16_t * reg){
	EALLOW;
	*reg = enabler | polarity;
	EDIS;
}


void PIE_ackInt(uint8_t group){
	EALLOW;
	PIEACK &= (1<<(group-1));
	EDIS;
}
#endif
