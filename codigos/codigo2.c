#include<avr/io.h>
#include<util/delay.h>


void sleep(uint8_t millisec)
{
	while(millisec)
	{
	  _delay_ms(1);
	  millisec--;
	}
}


main()
{

	
	DDRB |= 1<<PB1;
	DDRB |= 1<<PB0;
	
	while(1)
	{
	
	DDRB = 0<<PB1;
	sleep(1000);

	DDRB = 0<<PB0;
	sleep(6000);

	DDRB |= 1<<PB1;
	sleep(3000);

	DDRB = 0<<PB1;
	sleep(1000);
	
	DDRB = 0<<PB0;
	sleep(5000);

	
	DDRB |= 1<<PB0;
	sleep(1000);

	DDRB |= 1<<PB1;
	sleep(3000);

	}

}
