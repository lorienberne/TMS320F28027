/*
 * GPIO_functions.h
 *
 *  Created on: 22/01/2015
 *      Author: Lorien
 */

void GPIO_init(){
	EALLOW;
	//ENABLE CLOCK FEED
	PCLKCR3 |= (1 << 13);
	EDIS;
}

void GPIO_setMUXMode(uint8_t pin, uint8_t mode){
	EALLOW;
	if (pin <= 12){
		GPAMUX1 &= ~((0x03) << (2 * pin));
		GPAMUX1 |=   (mode) << (2 * pin);
	}
	else if (pin >= 16 && pin <= 29){
		GPAMUX2 &= ~((0x03) << (2 * (pin - 16)));
		GPAMUX2 |=   (mode) << (2 * (pin - 16));
	}
	else if (pin >= 32 && pin <= 38){
		GPBMUX1 &= ~((0x03) << (2 * (pin - 32)));
		GPBMUX1 |= (mode) << (2 * (pin - 32));
	}
	EDIS;
}

void GPIO_setQualification(uint8_t pin, uint8_t qual){
	EALLOW;
	if (pin <= 15){
		GPAQSEL1 &= ~((0x03) << (2 * pin));
		GPAQSEL1 |= (qual) << (2 * pin);
	}
	else if (pin >= 16 && pin <= 31){
		GPAQSEL2 &= ~((0x03) << (2 * (pin - 16)));
		GPAQSEL2 |= (qual) << (2 * (pin - 16));
	}
	else if (pin >= 32 && pin <= 38){
		GPBQSEL1 &= ~((0x03) << (2 * (pin - 32)));
		GPBQSEL1 |= (qual) << (2 * (pin - 32));
	}
	EDIS;
}

void GPIO_setDirection(uint8_t pin, bool dir){
	EALLOW;
	if (pin <= 31){
		GPADIR &= ~((0x01) << (pin));
		GPADIR |= (dir) << (pin);
	}
	else if (pin >= 32 && pin <= 38){
		GPBDIR &= ~((0x01) << (pin - 32));
		GPBDIR |= (dir) << (pin - 32);
	}
	EDIS;
}

void GPIO_setPullUp(uint8_t pin, bool en){
	EALLOW;
	if (pin <= 31){
		GPAPUD &= ~((0x01) << (pin));
		GPAPUD |= (en) << (pin);
	}
	else if (pin >= 32 && pin <= 38){
		GPBPUD &= ~((0x01) << (pin - 32));
		GPBPUD |= (en) << (pin - 32);
	}
	EDIS;
}

bool GPIO_read(uint8_t pin){
	EALLOW;
	if (pin <= 31){
		return ((GPADAT & (1 << pin)) >> pin);
	}
	else if (pin >= 32 && pin <= 38){
		return ((GPBDAT & (1 << (pin - 32))) >> (pin - 32));
	}
	EDIS;
	return 0;
}

void GPIO_setLevel(uint8_t pin, bool lvl){
	EALLOW;
	if (lvl){
		if (pin <= 31){
			GPASET &= ~((0x01) << (pin));
			GPASET |= (1) << (pin);
		}
		else if (pin >= 32 && pin <= 38){
			GPBSET &= ~((0x01) << (pin - 32));
			GPBSET |= (1) << (pin - 32);
		}

	}else {
		if (pin <= 31){
			GPACLEAR &= ~((0x01) << (pin));
			GPACLEAR |= (1) << (pin);
		}
		else if (pin >= 32 && pin <= 38){
			GPBCLEAR &= ~((0x01) << (pin - 32));
			GPBCLEAR |= (1) << (pin - 32);
		}
	}
	EDIS;
}

void GPIO_toggle(uint8_t pin){
	EALLOW;
	if (pin <= 31){
		GPATOGGLE &= ~((0x01) << (pin));
		GPATOGGLE |= (1) << (pin);
	}
	else if (pin >= 32 && pin <= 38){
		GPBTOGGLE &= ~((0x01) << (pin - 32));
		GPBTOGGLE |= (1) << (pin - 32);
	}
	EDIS;
}

void GPIO_interruptSelect(uint8_t pin, uint8_t inter){
	EALLOW;
	switch (inter){
	case 1:
		GPIOXINT1SEL &= ~(0x1F);
		GPIOXINT1SEL |= (pin);
		break;
	case 2:
		GPIOXINT2SEL &= ~(0x1F);
		GPIOXINT2SEL |= (pin);
		break;
	case 3:
		GPIOXINT3SEL &= ~(0x1F);
		GPIOXINT3SEL |= (pin);
		break;
	}
	EDIS;
}
