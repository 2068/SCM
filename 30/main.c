#include"reg52.h"
sbit spk=P0^0;
unsigned char frq;
void inittimer()
{
	TMOD|=0x01;
	EA=1;
	ET0=1;
	TR0=1;
}
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	unsigned char i;
	inittimer();
	while(1)
	{
		frq=0;
		for(i=0;i<60;i++)
		{
			delay(1000);
		}
		frq=100;
		for(i=0;i<60;i++)
		{
			delay(1000);
		}
	}
}
void timer() interrupt 1 
{
	TH0=0xfe;
	TL0=frq;
	spk=!spk;
}