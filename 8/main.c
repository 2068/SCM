#include"reg52.h"
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	unsigned char i;
	delay(50000);
	P1=0x7f;
	for(i=0;i<8;i++)
	{
		delay(50000);
		P1>>=1;
	}
	while(1)
	{
		
	}
}