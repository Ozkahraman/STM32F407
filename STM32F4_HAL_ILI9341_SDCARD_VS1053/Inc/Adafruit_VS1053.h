#ifndef ADAFRUIT_VS1053_H
#define ADAFRUIT_VS1053_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef volatile uint32 RwReg;
typedef uint32_t PortMask;
typedef volatile RwReg PortReg;

/* SCI COMMAND */
#define VS1053_SCI_READ 0x03
#define VS1053_SCI_WRITE 0x02

/* VS1053 REGISTER ADDRESS */
#define VS1053_REG_MODE  0x00
#define VS1053_REG_STATUS 0x01
#define VS1053_REG_BASS 0x02
#define VS1053_REG_CLOCKF 0x03
#define VS1053_REG_DECODETIME 0x04
#define VS1053_REG_AUDATA 0x05
#define VS1053_REG_WRAM 0x06
#define VS1053_REG_WRAMADDR 0x07
#define VS1053_REG_HDAT0 0x08
#define VS1053_REG_HDAT1 0x09
#define VS1053_REG_VOLUME 0x0B

/* VS1053 CONFIGURATION */
#define VS1053_GPIO_DDR 0xC017
#define VS1053_GPIO_IDATA 0xC018
#define VS1053_GPIO_ODATA 0xC019
#define VS1053_INT_ENABLE  0xC01A
#define VS1053_MODE_SM_DIFF 0x0001
#define VS1053_MODE_SM_LAYER12 0x0002
#define VS1053_MODE_SM_RESET 0x0004
#define VS1053_MODE_SM_CANCEL 0x0008
#define VS1053_MODE_SM_EARSPKLO 0x0010
#define VS1053_MODE_SM_TESTS 0x0020
#define VS1053_MODE_SM_STREAM 0x0040
#define VS1053_MODE_SM_SDINEW 0x0800
#define VS1053_MODE_SM_ADPCM 0x1000
#define VS1053_MODE_SM_LINE1 0x4000
#define VS1053_MODE_SM_CLKRANGE 0x8000
#define VS1053_SCI_AIADDR 0x0A
#define VS1053_SCI_AICTRL0 0x0C
#define VS1053_SCI_AICTRL1 0x0D
#define VS1053_SCI_AICTRL2 0x0E
#define VS1053_SCI_AICTRL3 0x0F

/* VS1053 BUFFER LEN */
#define VS1053_DATABUFFERLEN 32

/* PIN Configuration */
extern SPI_HandleTypeDef 	hspi3;
#define HSPI_MP3		 	&hspi3
#define	MP3_RST_PORT		GPIOD
#define MP3_RST_PIN			GPIO_PIN_1
#define	MP3_CS_PORT			GPIOD
#define MP3_CS_PIN			GPIO_PIN_2
#define	MP3_DC_PORT			GPIOD
#define MP3_DC_PIN			GPIO_PIN_3
#define MP3_DREQ_PIN		GPIO_PIN_0

/* VARIABLES */
extern uint8_t mp3buffer[VS1053_DATABUFFERLEN];
extern volatile bool DREQFlag;
extern volatile bool PlayingMusic;

/* FUNCTIONS */
void VS1053_Init(void);
void VS1053_Reset(void);
void VS1053_SoftReset(void);
void VS1053_SetVolume(uint8_t left, uint8_t right);
bool VS1053_PlayingFile(const char *trackname);
void VS1053_StopPlaying(void);
void VS1053_PausePlaying(boolean pause);
bool VS1053_IsPaused(void);
bool VS1053_IsStopped(void);

#endif // ADAFRUIT_VS1053_H