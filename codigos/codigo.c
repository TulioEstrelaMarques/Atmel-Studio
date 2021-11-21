#include <avr/io.h>
#include <util/delay.h>


void sleep(uint8_t millesec){
	while(millesec){
		_delay_ms(1);
		millesec--;
	}
}

main(){
	DDRC |=1<<PC2;
	while(1){
		PORTC &= -(1<<PC2);
		sleep(1000);

		PORTC |= -(1<<PC2);
		sleep(1000);

	}
}

