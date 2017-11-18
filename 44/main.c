#include"reg52.h"
sbit led=P2^0;
void Timer0Init()
{
	TMOD|=0x01;
	TH0=0xfc;
	TL0=0x18;
	ET0=1;
	EA=1;
	TR0=1;
}
void main()
{
	Timer0Init();
	while(1);
}
void Timer0()interrupt 1
{
	static int i;
	TH0=0xfc;
	TL0=0x18;
	i++;
	if(i==1000)
	{
		i=0;
		led=~led;
	}
}