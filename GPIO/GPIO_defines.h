/*
 * GPIO_defines.h
 *
 *  Created on: 22/01/2015
 *      Author: Lorien
 */


#ifndef GPIO_DEFINES_H
#define GPIO_DEFINES_H

#define BASE_GPIO_ADDR 0x6F80
#define GPACTRL		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0000))
#define GPAQSEL1	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0002))
#define GPAQSEL2	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0004))
#define GPAMUX1		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0006))
#define GPAMUX2		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0008))
#define GPADIR		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x000A))
#define GPAPUD		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x000C))
#define GPBCTRL		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0010))
#define GPBQSEL1	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0012))
#define GPBMUX1		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0016))
#define GPBDIR		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x001A))
#define GPBPUD		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x001C))
#define AIOMUX1		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0030))
#define AIODIR		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x003A))

#define GPIOXINT1SEL	*((volatile uint16_t *)(BASE_GPIO_ADDR + 0x0060))
#define GPIOXINT2SEL	*((volatile uint16_t *)(BASE_GPIO_ADDR + 0x0061))
#define GPIOXINT3SEL	*((volatile uint16_t *)(BASE_GPIO_ADDR + 0x0062))
#define GPIOLPMSEL		*((volatile uint16_t *)(BASE_GPIO_ADDR + 0x0068))


#define GPADAT		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0040))
#define GPASET		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0042))
#define GPACLEAR	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0044))
#define GPATOGGLE	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0046))
#define GPBDAT		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0048))
#define GPBSET		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x004A))
#define GPBCLEAR	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x004C))
#define GPBTOGGLE	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x004D))
#define AIODAT		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x0058))
#define AIOSET		*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x005A))
#define AIOCLEAR	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x005C))
#define AIOTOGGLE	*((volatile uint32_t *)(BASE_GPIO_ADDR + 0x005E))


/***********************************************************************************************************/
/******************************************* GPIO MUX MODES ************************************************/
/***********************************************************************************************************/

#define GPIO	 0x00
#define EPWM	 0x01
#define SPISIMOA 0x01
#define SPISOMIA 0x01
#define SPICLKA  0x01
#define SPISTEA  0x01
#define SDAA     0x02
#define SCLA     0x02

/***********************************************************************************************************/
/**************************************** GPIO QUALIFICATION ***********************************************/
/***********************************************************************************************************/

#define SYNC    0x00
#define SAMP3   0x01
#define SAMP6   0x02
#define ASYNC   0x03

/***********************************************************************************************************/
/**************************************** GPIO DIRECTION FLAGS *********************************************/
/***********************************************************************************************************/

#define INPUT  0
#define OUTPUT 1

/***********************************************************************************************************/
/***************************************** GPIO PULLUP FLAGS ***********************************************/
/***********************************************************************************************************/

#define PULL_ENABLE 0
#define PULL_DISABLE 1

/***********************************************************************************************************/
/***************************************** GPIO LEVEL FLAGS ************************************************/
/***********************************************************************************************************/

#define LOW  0
#define HIGH 1

#endif
