#include <avr/io.h>

int main(void)
{
unsigned char input_data_rot_switch;
DDRA = 0x00;
DDRB = 0xFF;

while(1)
{
input_data_rot_switch = PINA & 0x0F;	
int decodedVal;

switch(input_data_rot_switch){
	case(0): decodedVal = 0x80;break;
	case(1): decodedVal = 0x40;break; 
	case(2): decodedVal = 0x20;break;
	case(3): decodedVal = 0x10;break;
	case(4): decodedVal = 0x08;break;
	case(5): decodedVal = 0x04;break;
	case(6): decodedVal = 0x02;break;
	case(7): decodedVal = 0x01;break;
	default: decodedVal = 0x00;break;
}
PORTB = decodedVal;
}

}