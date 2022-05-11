#include <avr/io.h>

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0xFE;

	return 0;
}
