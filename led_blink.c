#include <reg52.h>
#define uint unsigned int

void delay(uint);

void main()
{
	while(1)
	{		
		P1 = 0xfe;
		delay(1000);
		P1 = 0xff;
		delay(1000);
	}
}

//unit: millisecond
void delay(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}

