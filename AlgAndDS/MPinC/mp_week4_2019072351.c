#include <avr/io.h>

#define FND_C0 0x01
#define FND_C1 0x02
#define FND_C2 0x03

const char Font[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
	0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C,
	0x39, 0x5E, 0x79, 0x71, 0x00};

void delay(unsigned long x)
{
	while(x--);
}

int main(void)
{
unsigned char digit0, digit1, digit2;
DDRB = 0xFF;
DDRG = 0xFF;

PORTB = 0x00;
PORTG = 0xFF;

int count = 0;
while(1)
{
digit2 = count/100;
digit1 = (count%100)/10;
digit0 = ((count%100)%10);

PORTG |= 0x07;
PORTG &= ~FND_C2;
PORTB = Font[digit2];
delay(100);

PORTG |= 0x07;
PORTG &= ~FND_C1;
PORTB = Font[digit1];
delay(100);

PORTG |= 0x07;
PORTG &= ~FND_C0;
PORTB = Font[digit0];
delay(100);

count++;
delay(10000);
if(count>999)break;

}
return 0;
}


