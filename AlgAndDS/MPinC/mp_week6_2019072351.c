#include <avr/io.h>
#define KEY_CTRL PORTE
#define R0 0x10
#define FND_C0 0x01
#define FND_C1 0x02
#define FND_C2 0x03

const char Font[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
	0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C,
	0x39, 0x5E, 0x79, 0x71, 0x00};



void delay(unsigned long x){
	while(x--);
}

unsigned char key_scan(void)
{
	unsigned char scan = 0;
	unsigned char key_control = 0;
	unsigned char input_data = 0;
	unsigned char key = 0;
	
	key_control = R0;
	
	for(scan = 0; scan < 4; scan++)
	{
		KEY_CTRL &= 0x0F;
		KEY_CTRL |= key+control;
		delay(1);
		input_data = PINF & 0x07;
		
		if(   )
		
		
	}
	return key;
}

int main(void)
{
	unsigned char digit0, digit1; 
	unsigned char led = 0;
	unsigned char key = 0;
	DDRF = 0x00;
	DDRE = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRG = 0xFF;
	
	
	while(1)
	{
		key = key_scan();
		digit2 = key/10;
		digit1 = key%10;
		led = 0x01;
		
		if(key==0)
			led = 0x00;
			
		else if(key < 9)
			led = led <<(key-1);
			
		else if(key == 9)
			led = 0x81;
		
		else if(key == 10)
			led = 0x0F;
		
		else if(key == 11)
			led = 0xFF;
		
		else if(key == 12)
			led = 0xF0;
		
		PORTG |= 0x07;
		PORTG &= ~FND_C1;
		PORTB = Font[digit1];
		delay(100);
		
		PORTG |= 0x07;
		PORTG &= ~FND_C0;
		PORTB = Font[digit0];
		delay(100);

		PORTA = led;
	}
}
