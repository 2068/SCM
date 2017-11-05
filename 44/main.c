#include"reg52.h"
sbit led=P2^0;
sbit k3=P3^3;
void delay(unsigned int i)
{
	while(--i);
}
void Int0()
{
	IT1=1;
	EX1=1;
	EA=1;
}
void main()
{
  Int0();
	while(1);
}
void Int01() interrupt 2
{
	delay(1000);
	if(k3==0)
	{
		led=~led;
	}
}