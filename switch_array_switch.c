#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[] = {	
0x3f, 0x06, 0x5b, 0x4f, 0x66, 
0x6d, 0x7d, 0x07, 0x7f, 0x6f, 
0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

void delay(uint);
void display(uchar);
uchar keyscan();

sbit dula = P2^6;
sbit wela = P2^7;

uchar temp;
uchar num;

void main()
{
	num = 0;

	P0 = 0;
	dula=1;
	dula=0;

	P0 = 0xfe;
	wela = 1;
	wela = 0;

	while(1)
	{
		display(keyscan());	
	}
}

uchar keyscan()
{
	// commit it out because the board s6-s9 don't work
	/*P3 = 0xfe;
	if(P3 != 0xfe)
	{
		delay(5);
		if(P3 != 0xfe)
		{
			switch (P3)
			{
				case 0xee:
					num = 0;
					break;
				case 0xde:
					num = 1;
					break;
				case 0xbe:
					num = 2;
					break;
				case 0x7e:
					num = 3;
					break;
			}			
		}
	}*/

	P3 = 0xfd;
	if(P3 != 0xfd)
	{
		delay(5);
		if(P3 != 0xfd)
		{
			switch (P3)
			{
				case 0xed:
					num = 4;
					break;
				case 0xdd:
					num = 5;
					break;
				case 0xbd:
					num = 6;
					break;
				case 0x7d:
					num = 7;
					break;
			}			
		}
	}

	P3 = 0xfb;
	if(P3 != 0xfb)
	{
		delay(5);
		if(P3 != 0xfb)
		{
			switch (P3)
			{
				case 0xeb:
					num = 8;
					break;
				case 0xdb:
					num = 9;
					break;
				case 0xbb:
					num = 10;
					break;
				case 0x7b:
					num = 11;
					break;
			}			
		}
	}

	P3 = 0xf7;
	if(P3 != 0xf7)
	{
		delay(5);
		if(P3 != 0xf7)
		{
			switch (P3)
			{
				case 0xe7:
					num = 12;
					break;
				case 0xd7:
					num = 13;
					break;
				case 0xb7:
					num = 14;
					break;
				case 0x77:
					num = 15;
					break;
			}			
		}
	}
	
	return num;
}

void display(uchar num)
{
	P0 = table[num];
	dula = 1;
	dula = 0;
}

//unit: millisecond
void delay(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}
