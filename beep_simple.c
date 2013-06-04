#include <reg52.h>

sbit beep = P2^3;

void main()
{
	beep = 0;
	while(1);
}
