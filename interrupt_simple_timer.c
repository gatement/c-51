#include <reg52.h>
#include <math.h>

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

void show(float, uchar);
void display(uchar, uchar, uchar);
void delay();
void delayms(uint);
void init_timer0();

sbit dula = P2^6;
sbit wela = P2^7;

sbit beep = P2^3;

uint num;
uint done;
uint i;

void main()
{
	done = 0;
	num = 220;

	TMOD = 0x01;
	init_timer0();
	EA = 1;
	ET0 = 1;
	TR0 = 1;

	while(1)
	{
		i = num / 20;

		show(i, 0);

		if(i == 0 && done == 0)
		{
			done = 1;
			beep = 0;
			delayms(1000);
			beep = 1;
		}
	}
}

void timer0() interrupt 1
{
	init_timer0();
	num --;
	if( num  == 0)
	{
		TR0 = 0;
	}
}

void init_timer0()
{
	TH0 = 19456 / 256;
	TL0 = 19456 % 256;	
}

void show(float fnum, uchar decimal_count)
{
	uchar temp = 0;
	ulong num = fnum * pow(10, decimal_count);

	temp = num / 100000;
	display(temp, 1, decimal_count);

	temp = num % 100000 / 10000;
	display(temp, 2, decimal_count);

	temp = num % 10000 / 1000;
	display(temp, 3, decimal_count);

	temp = num % 1000 / 100;
	display(temp, 4, decimal_count);

	temp = num % 100 / 10;
	display(temp, 5, decimal_count);

	temp = num % 10;
	display(temp, 6, decimal_count);
}

void display(uchar num, uchar pos, uchar decimal_count)
{
	if(num != 0 || pos == 6)
	{
		uchar val = table[num];

		if(decimal_count != 0 && pos == 6 - decimal_count)
		{
			val |= 0x80;
		}

		P0 = val;
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
	delayms(1);
}

void delayms(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 113; y > 0; y--);
}
