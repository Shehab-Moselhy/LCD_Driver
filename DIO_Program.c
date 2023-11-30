/*
 * DIO_Program.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Shehab Eldin Saber
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/DIO_Interface.h"
#include "../include/MCAL/DIO_Private.h"
#include "../include/MCAL/DIO_Cfg.h"

void MDIO_voidInit()
{
	DDRA_REG = CONC_BIT(PORTA_PIN7_DIRECTION , PORTA_PIN6_DIRECTION , PORTA_PIN5_DIRECTION,
						 PORTA_PIN4_DIRECTION , PORTA_PIN3_DIRECTION , PORTA_PIN2_DIRECTION,
						 PORTA_PIN1_DIRECTION , PORTA_PIN0_DIRECTION);

	DDRB_REG = CONC_BIT(PORTB_PIN7_DIRECTION , PORTB_PIN6_DIRECTION , PORTB_PIN5_DIRECTION,
						 PORTB_PIN4_DIRECTION , PORTB_PIN3_DIRECTION , PORTB_PIN2_DIRECTION,
						 PORTB_PIN1_DIRECTION , PORTB_PIN0_DIRECTION);

	DDRC_REG = CONC_BIT(PORTC_PIN7_DIRECTION , PORTC_PIN6_DIRECTION , PORTC_PIN5_DIRECTION,
						 PORTC_PIN4_DIRECTION , PORTC_PIN3_DIRECTION , PORTC_PIN2_DIRECTION,
						 PORTC_PIN1_DIRECTION , PORTC_PIN0_DIRECTION);

	DDRD_REG = CONC_BIT(PORTD_PIN7_DIRECTION , PORTD_PIN6_DIRECTION , PORTD_PIN5_DIRECTION,
						 PORTD_PIN4_DIRECTION , PORTD_PIN3_DIRECTION , PORTD_PIN2_DIRECTION,
						 PORTD_PIN1_DIRECTION , PORTD_PIN0_DIRECTION);


	PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE , PORTA_PIN6_VALUE , PORTA_PIN5_VALUE,
						 PORTA_PIN4_VALUE , PORTA_PIN3_VALUE , PORTA_PIN2_VALUE,
						 PORTA_PIN1_VALUE , PORTA_PIN0_VALUE);

	PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE , PORTB_PIN6_VALUE , PORTB_PIN5_VALUE,
						 PORTB_PIN4_VALUE , PORTB_PIN3_VALUE , PORTB_PIN2_VALUE,
						 PORTB_PIN1_VALUE , PORTB_PIN0_VALUE);

	PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE , PORTC_PIN6_VALUE , PORTC_PIN5_VALUE,
						 PORTC_PIN4_VALUE , PORTC_PIN3_VALUE , PORTC_PIN2_VALUE,
						 PORTC_PIN1_VALUE , PORTC_PIN0_VALUE);

	PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE , PORTD_PIN6_VALUE , PORTD_PIN5_VALUE,
						 PORTD_PIN4_VALUE , PORTD_PIN3_VALUE , PORTD_PIN2_VALUE,
						 PORTD_PIN1_VALUE , PORTD_PIN0_VALUE);

}


void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPort ,DIO_PINS A_DIOPin ,PIN_DIRECTION A_PinDirection)
{
	if((A_DIOPort <= PORTD) && (A_DIOPin <= PIN7) && (A_PinDirection <= DIO_OUTPUT ))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRA_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(DDRA_REG, A_DIOPin); break;
					}
					break;
		case PORTB :
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRB_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(DDRB_REG, A_DIOPin); break;
					}
					break;
		case PORTC :
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRC_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(DDRC_REG, A_DIOPin); break;
					}
					break;
		case PORTD :
					switch(A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRD_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(DDRD_REG, A_DIOPin); break;
					}
					break;
			default :break;
		}
	}
}
void MDIO_voidSetPinStatus(DIO_PORTS A_DIOPort ,DIO_PINS A_DIOPin ,PIN_STATUS A_PinStatus)
{
	if((A_DIOPort <= PORTD) && (A_DIOPin <= PIN7) && (A_PinStatus <= DIO_OUTPUT ))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					switch(A_PinStatus)
					{
					case DIO_OUTPUT: SET_BIT(PORTA_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(PORTA_REG, A_DIOPin); break;
					}
					break;
		case PORTB :
					switch(A_PinStatus)
					{
					case DIO_OUTPUT: SET_BIT(PORTB_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(PORTB_REG, A_DIOPin); break;
					}
					break;
		case PORTC :
					switch(A_PinStatus)
					{
					case DIO_OUTPUT: SET_BIT(PORTC_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(PORTC_REG, A_DIOPin); break;
					}
					break;
		case PORTD :
					switch(A_PinStatus)
					{
					case DIO_OUTPUT: SET_BIT(PORTD_REG, A_DIOPin); break;
					case DIO_INPUT : CLR_BIT(PORTD_REG, A_DIOPin); break;
					}
					break;
			default :break;
		}
	}
}
void MDIO_voidTogglePin(DIO_PORTS A_DIOPort ,DIO_PINS A_DIOPin )
{
	if((A_DIOPort <= PORTD) && (A_DIOPin <= PIN7))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					TOG_BIT(PORTA_REG,A_DIOPin);
					break;
		case PORTB :
					TOG_BIT(PORTB_REG,A_DIOPin);
					break;
		case PORTC :
					TOG_BIT(PORTC_REG,A_DIOPin);
					break;
		case PORTD :
					TOG_BIT(PORTD_REG,A_DIOPin);
					break;
			default :break;
		}
	}
}
PIN_STATUS MDIO_PinStatusGetPinValue(DIO_PORTS A_DIOPort ,DIO_PINS A_DIOPin )
{
	PIN_STATUS A_PinStatus;
	if((A_DIOPort <= PORTD) && (A_DIOPin <= PIN7))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					A_PinStatus = GET_BIT(PORTA_REG,A_DIOPin);
					break;
		case PORTB :
					A_PinStatus = GET_BIT(PORTB_REG,A_DIOPin);
					break;
		case PORTC :
					A_PinStatus = GET_BIT(PORTC_REG,A_DIOPin);
					break;
		case PORTD :
					A_PinStatus = GET_BIT(PORTD_REG,A_DIOPin);
					break;
			default :break;
		}
	}
	return A_PinStatus;

}
void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPort ,u8 A_u8PortDirection)
{
	if((A_DIOPort <= PORTD))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					DDRA_REG = A_u8PortDirection;
					break;
		case PORTB :
					DDRB_REG = A_u8PortDirection;
					break;
		case PORTC :
					DDRC_REG = A_u8PortDirection;
					break;
		case PORTD :
					DDRD_REG = A_u8PortDirection;
					break;
			default :break;
		}
	}
}
void MDIO_voidSetPortStatus(DIO_PORTS A_DIOPort ,u8 A_u8PortStatus)
{
	if((A_DIOPort <= PORTD))
	{
		switch (A_DIOPort)
		{
		case PORTA :
					PORTA_REG = A_u8PortStatus;
					break;
		case PORTB :
					PORTB_REG = A_u8PortStatus;
					break;
		case PORTC :
					PORTC_REG = A_u8PortStatus;
					break;
		case PORTD :
					PORTD_REG = A_u8PortStatus;
					break;
			default :break;
		}
	}
}










