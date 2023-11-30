/*
 * main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Shehab Eldin Saber
 */
#include "util/delay.h"

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO_Interface.h"
#include "../include/HAL/LCD_Interface.h"
#define F_CPU 8000000UL


int main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HLCD_voidGoToPos(0,5);
	HLCD_SendString("ALLAH");
	_delay_ms(1000);
	HLCD_voidClearDisplay();
	HLCD_voidGoToPos(1,5);
	HLCD_SendString("amr");
	_delay_ms(1000);
	HLCD_voidClearDisplay();
	HLCD_voidGoToPos(0,5);
	HLCD_voidDisplayNumber(-10);



	while(1)
	{

	}
}
