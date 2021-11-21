/*
 * GccApplication1.c
 *
 * Created: 16/09/2019 11:55:06
 * Author : tulio
 */ 

#define F_CPU 16000000UL //defini��o da frequ�ncia de clock para uso da biblioteca delay

#include <avr/io.h>	     //biblioteca para acesso aos registradores do uC
#include "util/delay.h"	    //biblioteca para fun��es de delay

int main(void)			 //fun��o principal
{
	DDRB = 0b00100000;	 //configura pino PB5 como sa�da e demais como entradas
	
	while(1)			 //loop principal
	{
		PORTB^=(1<<PB5); //inverte estado do pino PB5
		_delay_ms(1000); //aguarda 1 seg
	}
}
