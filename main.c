#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[] = {	
0x3f, 0x06, 0x5b, 0x4f, 0x66, 
0x6d, 0x7d, 0x07, 0x7f, 0x6f, 
0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

void delay(uint);

sbit dula = P2^6;
sbit wela = P2^7;

uchar temp;
uchar num;

void main()
{	
	P0 = 0;
	dula=1;
	dula=0;

	P0 = 0xfe;
	wela = 1;
	wela = 0;

	P3=0xfe;
	num = 0;

	while(1)
	{
		temp = P3;
		temp = temp & 0xf0;
		if(temp != 0xf0)
		{
			delay(5);
			temp = P3;
			temp = temp & 0xf0;
			if(temp != 0xf0)
			{
				switch (temp)
				{
					case 0xe0:
						num = 1;
						break;
					case 0xd0:
						num = 2;
						break;
					case 0xb0:
						num = 3;
						break;
					case 0x70:
						num = 4;
						break;
				}

				P0 = table[num];
				dula = 1;
				dula = 0;
			}
		}
	}
}

//unit: millisecond
void delay(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}
