#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[] = {
0x3f, 0x06, 0x5b, 0x4f, 0x66, 
0x6d, 0x7d, 0x07, 0x7f, 0x6f, 
0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

sbit d0 = P1^0;
sbit dula=P2^6;
sbit wela=P2^7;
sbit s1=P3^4;

uchar num;
void delay(uint z);

void main()
{
	P0 = 0xfe;
	wela = 1;
	wela = 0;

	s1 = 1;
	num = 0;

	while(1)
	{
		if(s1==0)
		{
			delay(8);
			if(s1 == 0)
			{
				d0 = 0;
				num++;
				if(num == 10)
					num = 0;
			}
		
			while(!s1);
			delay(8);
			while(!s1);
		}
		else
		{
			d0 = 1;
		}


		P0 = table[num];
		dula = 1;
		dula = 0;
	}
}

//unit: millisecond
void delay(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}
