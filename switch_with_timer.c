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
sbit d0 = P1^0;
sbit s1=P3^4;
sbit s2=P3^5;
sbit s3=P3^6;
sbit s4=P3^7;

char num;
long count;
bit is_counting;

void main()
{
	is_counting = 0;

	TMOD = 0x01;
	init_timer0();
	EA = 1;
	ET0 = 1;
	//TR0 = 1;
	
	s1 = 1;
	num = 0;
	count = 20;

	while(1)
	{
		if(s1==0)
		{
			delayms(8);
			if(s1 == 0)
			{
				d0 = 0;
				num++;
				if(num == 60)
					num = 0;
			}
		
			while(!s1);
			delayms(8);
			while(!s1);
		}
		else
		{
			d0 = 1;
		}

		if(s2==0)
		{
			delayms(8);
			if(s2 == 0)
			{
				d0 = 0;
				num--;
				if(num == -1)
					num = 59;
			}
		
			while(!s2);
			delayms(8);
			while(!s2);
		}
		else
		{
			d0 = 1;
		}

		if(s3==0)
		{
			delayms(8);
			if(s3 == 0)
			{
				d0 = 0;
				num = 0;
			}
		
			while(!s3);
			delayms(8);
			while(!s3);
		}
		else
		{
			d0 = 1;
		}

		if(s4==0)
		{
			delayms(8);
			if(s4 == 0)
			{
				d0 = 0;
				if(is_counting == 0)
				{
					TR0 = 1;
					is_counting = 1;
					count = 20;
				}
				else
				{
					TR0 = 0;
					is_counting = 0;
				}
			}
		
			while(!s4);
			delayms(8);
			while(!s4);
		}
		else
		{
			d0 = 1;
		}

		if(count <= 0)
		{
			count = 20;
			num++;
			if(num == 60)
				num = 0;
		}


		show(num, 0);
	}
}

void timer0() interrupt 1
{
	init_timer0();
	count --;
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
