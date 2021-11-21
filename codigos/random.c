#define FSOC  8000000
#define F_CPU 8000000
#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	unsigned int END = 0x0F;
	unsigned int LED_CLICK = 0;
	unsigned int COUNT = 0;
	unsigned char AUX;
	unsigned char VAL = 0x00;
	int AUX2;
	int k, j;

	while(1){
		PORTB 	= 0x00;
		AUX 	= PINB;
		AUX		= AUX & 0x02;

		srand(time(NULL));
		if(AUX == 0x02){
			PORTB = 0x01;
			PORTB = 0x04;
			LED_CLICK = 1;
		}

		if(LED_CLICK == 0){
			if(END >= 0x0F && END <= 0xFF){			
				VAL = rand();
				eeprom_write_byte((uint8_t *)END, VAL);
				PORTB = 0x01;
				_delay_ms(1000);
				COUNT++;
			}
		}

		for(k = 16; k < 255 && LED_CLICK == 1 ; k++){
			for(j = 15; j < 255 - 1 && LED_CLICK == 1; j++){
				if(eeprom_read_byte((uint8_t *)j) > eeprom_read_byte((uint8_t *)j + 1)){
					AUX2 = eeprom_read_byte((uint8_t *)j);
					eeprom_write_byte((uint8_t *)j, eeprom_read_byte((uint8_t *)j + 1));
					eeprom_write_byte((uint8_t *)j + 1, AUX2);
				}
			}
		}

		
		END = (END >= 0x0F && END <= 0x0F) ? END + 1 : 0x0F;
		eeprom_write_byte(0x00, COUNT);
	}		

	return 1;
}