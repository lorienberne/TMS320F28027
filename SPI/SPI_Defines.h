//***************************************************
//*************SPI REGISTERS ADDRESS*****************
//***************************************************

#define SPICCR		(*(volatile uint16_t *) 0x7040)
#define SPICTL		(*(volatile uint16_t *) 0x7041)
#define SPIST		(*(volatile uint16_t *) 0x7042)
#define SPIBBR		(*(volatile uint16_t *) 0x7044)
#define SPIEMU		(*(volatile uint16_t *) 0x7046)
#define SPIRXBUF	(*(volatile uint16_t *) 0x7047)
#define SPITXBUF	(*(volatile uint16_t *) 0x7048)
#define SPIDAT		(*(volatile uint16_t *) 0x7049)
#define SPIFFTX		(*(volatile uint16_t *) 0x704A)
#define SPIFFRX		(*(volatile uint16_t *) 0x704B)
#define SPIFFCT		(*(volatile uint16_t *) 0x704C)
#define SPIPRI		(*(volatile uint16_t *) 0x704F)

//---------SPICCR REGISTER BITS---------------------
#define SPI_SW_RESET	(1<<7)
#define CLOCK_POLARITY	(1<<6)
#define SPILBK			(1<<4)
#define SPI_CHAR3		(1<<3)
#define SPI_CHAR2		(1<<2)
#define	SPI_CHAR1		(1<<1)
#define SPI_CHAR0		(1<<0)

//----------SPICTL REGISTER BITS-------------------
#define OVERRUN_INT_EN	(1<<4)
#define CLOCK_PHASE		(1<<3)
#define MASTER_SLAVE	(1<<2)
#define TALK			(1<<1)
#define SPI_INT_EN		(1<<0)

//---------SPIFFTX REGISTER BITS--------------------
#define SPIRST		(1<<15)
#define SPIFFENA	(1<<14)
#define TXFIFORST	(1<<13)
#define TXFFST4		(1<<12)
#define TXFFST3		(1<<11)
#define TXFFST2		(1<<10)			
#define TXFFST1		(1<<9)
#define TXFFST0		(1<<8)
#define TXFFINT		(1<<7)
#define TXFFINTCLR	(1<<6)
#define TXFFIEN		(1<<5)
#define TXFFIL4		(1<<4)
#define TXFFIL3		(1<<3)
#define TXFFIL2		(1<<2)
#define TXFFIL1		(1<<1)
#define	TXFFIL0		(1<<0)

//---------SPIFFRX REGISTER BITS---------------------
#define RXFFOVF		(1<<15)
#define RXFFOVF_CLR	(1<<14)
#define RXFIFORST	(1<<13)
#define	RXFFST4		(1<<12)
#define RXFFST3		(1<<11)
#define RXFFST2		(1<<10)
#define RXFFST1		(1<<9)
#define RXFFST0		(1<<8)
#define RXFFINT		(1<<7)
#define RXFFINT_CLR	(1<<6)
#define	RXFFINEN	(1<<5)
#define RXFFIL4		(1<<4)
#define RXFFIL3		(1<<3)
#define RXFFIL2		(1<<2)
#define RXFFIL1		(1<<1)
#define RXFFIL0		(1<<0)

//---------CC1101 BURST AND R/W BITS-------------------
#define BURST_BIT (1<<6)
#define READ_BIT  (1<<7)

