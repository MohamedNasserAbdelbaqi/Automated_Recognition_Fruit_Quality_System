/*
 * WATCH_DOG.c
 *
 * Created: 2/23/2022 10:25:27 PM
 * Author: Mohamed Nasser
 */ 
#include <avr/io.h>
#include "WATCH_DOG.h"

error_state_t WATCH_DOG_Sleep(float32_t sleeping_time)
{
	error_state_t error_state = ERROR_OK;
	/* set the pre-scaler */
	if (sleeping_time <= 0)
	{
		error_state = WATCH_DOG_ERROR_UNDER_RANGE_TIME;
	}
	else if (sleeping_time > 2100)
	{
		error_state = WATCH_DOG_ERROR_OVER_RANGE_TIME;
	}
	else if (sleeping_time > 0 && sleeping_time <= 16.3)
	{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 16.3 && sleeping_time <= 32.5)
	{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 32.5 && sleeping_time <= 65)
	{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 65 && sleeping_time <= 130)
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 130 && sleeping_time <= 260)
	{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 260 && sleeping_time <= 520)
	{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 520 && sleeping_time <= 1000)
	{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if (sleeping_time > 1000 && sleeping_time <= 2100)
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	/* enable watch dog timer */
	SET_BIT(WDTCR,WDE);
	
	return error_state;
}

void WATCH_DOG_Disable(void)
{
	uint8_t global_int_status = INTERRUPT_ReadGlobalINTStatus();
	if (global_int_status == ON)
	{
		INTERRUPT_DisableGlobalINT();
	}
	/* disable watch dog timer */
	SET_BIT(WDTCR,WDE);
	SET_BIT(WDTCR,WDTOE);
	CLR_BIT(WDTCR,WDE);
	if (global_int_status == ON)
	{
		INTERRUPT_EnableGlobalINT();
	}
}