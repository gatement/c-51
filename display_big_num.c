#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

uchar code table[] = {	
0x3f, 0x06, 0x5b, 0x4f, 0x66, 
0x6d, 0x7d, 0x07, 0x7f, 0x6f, 
0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

uchar code position[] = {
0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf
};

void show(ulong);
void display(uchar, uchar);
void delay();
void delayms(uint);

sbit dula = P2^6;
sbit wela = P2^7;

void main()
{
	ulong num = 123456;

	while(1)
	{
		show(num);	
	}
}

void show(ulong num)
{
	uchar temp = 0;
 
	temp = num / 100000;
	display(temp, 1);

	temp = num % 100000 / 10000;
	display(temp, 2);

	temp = num % 10000 / 1000;
	display(temp, 3);

	temp = num % 1000 / 100;
	display(temp, 4);

	temp = num % 100 / 10;
	display(temp, 5);

	temp = num % 10;
	display(temp,6);
}

void display(uchar num, uchar pos)
{
	if(num != 0)
	{
		P0 = table[num];
		dula = 1;
		dula = 0;
		P0 = position[pos - 1];
		wela = 1;
		wela = 0;
	}

	delay();
}

void delay()
{
	delayms(3);
}

void delayms(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}
