/**************************************************************
 *  Project          : Enclustra Vivado reference design
 *  File description : Hello World
 *  File name        : main.c
 *  Author           : Christoph Glattfelder
 **************************************************************
 *  Copyright (c) 2015 by Enclustra GmbH, Switzerland
 *  All rights reserved.
 **************************************************************
 *  Notes:
 *
 **************************************************************
 *  File history:
 *
 *  Version | Date     | Author             | Remarks
 *  -----------------------------------------------------------
 *  1.0	    | 29.06.15 | Ch. Glattfelder    | Created
 *  1.1     | 16.07.15 | D. Ungureanu       | Cleaned-up code
 *          |          |                    |
 *  ------------------------------------------------------------
 *
 **************************************************************/


#include <stdio.h>
#include "StandardIncludes.h"
#include "UtilityFunctions.h"

#if SYSTEM == XILINX_MICROBLAZE
	#define SLEEP_VALUE 100000
	#define SYSTEM_INIT
#elif SYSTEM == XILINX_ARM_SOC
	#define SLEEP_VALUE 10000
	#define SYSTEM_INIT
#elif SYSTEM == ALTERA_NIOS
	#define SLEEP_VALUE 10000000
	#define SYSTEM_INIT
#elif SYSTEM == ALTERA_ARM_SOC
	#include "AlteraInitSystem.h"
	#define SLEEP_VALUE 100000000
	#define SYSTEM_INIT AlteraInitSystem()
#elif SYSTEM == UBOOT
	#define SLEEP_VALUE 10000000
	#define SYSTEM_INIT
#endif


int32_t spi_issue_cmd(uint8_t *data, uint8_t loop, uint32_t csn)
{
	int i;
	while ((Xil_In32(XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x64) & 0x1) != 0x1)
			Xil_In32(XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x6c);

		Xil_Out32((XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x70), csn);
		Xil_Out32((XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x60), 0x086 );
		for (i = 0; i < loop; i++) {
			Xil_Out32((XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x68), *(data + i));

			while ((Xil_In32(XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x64) & 0x1) == 0x1)
				{ 		};
			*(data + i) = Xil_In32(XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x6c) & 0xff;
		}
		Xil_Out32((XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x70), 0xff);
		Xil_Out32((XPAR_AXI_QUAD_SPI_1_BASEADDR + 0x60),
			  0x186 );

		return 0;

}

/***************************************************************************//**
* @brief ad9250_spi_read
*******************************************************************************/
int32_t spi_read(uint16_t reg_addr, uint32_t csn)
{
	uint8_t buf[8];
	int32_t ret;

	buf[3] = 0x0;
	buf[0] = 0x80 | (reg_addr >> 8);
	buf[1] = reg_addr & 0xFF;
	buf[2] = 0x00;
	buf[4] = 0x0;
	buf[5] = 0x0;
	buf[6] = 0x0;
	buf[7] = 0x0;

	ret = spi_issue_cmd(buf, 3, csn);
	printf ("ADDR=0x%x, VAL=0x%x\n", reg_addr, buf[3]);

	return buf[3];
}

/***************************************************************************//**
* @brief ad9250_spi_write
*******************************************************************************/
int32_t spi_write(
						 uint16_t reg_addr,
						 uint8_t reg_data, uint32_t csn)
{
	uint8_t buf[4];
	int32_t ret;

	buf[3] = 0;
	buf[0] = reg_addr >> 8;
	buf[1] = reg_addr & 0xFF;
	buf[2] = reg_data;

	ret = spi_issue_cmd(buf, 3, csn);

	return ret;
}


int main()
{
	
	int i;

	SYSTEM_INIT;

    uint32_t csn = ~(1 << (0));
	spi_write(0x00, 0x30, csn);Sleep(SLEEP_VALUE); // reset clock tree
	    spi_write(0x00, 0x10, csn);Sleep(SLEEP_VALUE); // pull it out of reset

	    //set output for CH0-3 to 600mA
		spi_write(0x3C, 0x0C, csn);Sleep(SLEEP_VALUE);
		spi_write(0x3D, 0x0C, csn);Sleep(SLEEP_VALUE);
		spi_write(0x3E, 0x0C, csn);Sleep(SLEEP_VALUE);
		spi_write(0x3F, 0x0C, csn);Sleep(SLEEP_VALUE);

		//enable channel 5 and 7
		spi_write(0x40, 0x03, csn);Sleep(SLEEP_VALUE);
		spi_write(0x41, 0x02, csn);Sleep(SLEEP_VALUE);
		spi_write(0x42, 0x02, csn);Sleep(SLEEP_VALUE);
		spi_write(0x43, 0x03, csn);Sleep(SLEEP_VALUE);
		//set high/low cycles and phase offset
		spi_write(0x48, 0x21, csn);Sleep(SLEEP_VALUE);// low[7:4] high[3:0]
		spi_write(0x49, 0x00, csn);Sleep(SLEEP_VALUE);// phase[3:0 bypass[7]]
		spi_write(0x4A, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x4B, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x4C, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x4D, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x4E, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x4F, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x50, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x51, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x52, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x53, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x54, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x55, 0x00, csn);Sleep(SLEEP_VALUE);
		spi_write(0x56, 0x21, csn);Sleep(SLEEP_VALUE);
		spi_write(0x57, 0x00, csn);Sleep(SLEEP_VALUE);
		// global params
		spi_write(0x04, 0x05, csn);Sleep(SLEEP_VALUE); // A counter [5:0]
		spi_write(0x05, 0x00, csn);Sleep(SLEEP_VALUE); // B counter[4:0 - > 12:8]
		spi_write(0x06, 0x0F, csn);Sleep(SLEEP_VALUE); // B counter [7:0]
		//spi_write(0x07, 0xFF, csn);Sleep(SLEEP_VALUE); // loss of ref settings
		spi_write(0x08, 0x4F, csn);Sleep(SLEEP_VALUE); // CP mode[1:0]; MUX[5:2]; PFD[6]
		spi_write(0x09, 0x70, csn);Sleep(SLEEP_VALUE); //[counter resets{Rn N All}[2:0]] CP curren[6:4]
		spi_write(0x0A, (0x2 << 2), csn);Sleep(SLEEP_VALUE); //prescaller[4:2] Powerdown [1:0]
		spi_write(0x0B, 0x00, csn);Sleep(SLEEP_VALUE); // R divider[13:8 -> 5:0]
		spi_write(0x0C, 0x10, csn);Sleep(SLEEP_VALUE); // R divider[7:0]
		spi_write(0x45, 0x02, csn);Sleep(SLEEP_VALUE); // clock power down
		spi_write(0x5A, 0x01, csn);Sleep(SLEEP_VALUE); // update registers

    EN_PRINTF("\n\r\n\r\n\r\n\r");

	EN_PRINTF("== Enclustra Hello World Example ==\r\n\r\n");
	
    for (i=0; i<20; i++){
    	EN_PRINTF("Hello World %d\n\r", i);
		Sleep(SLEEP_VALUE);
    }

    EN_PRINTF("\n\rGoodbye...\n\r");

	while (1);
    return 0;
}
