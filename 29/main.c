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
	inittimer();
	while(1)
	{
		delay(100);
		frq++;
	}
}
void timer() interrupt 1 
{
	TH0=0xfe;
	TL0=frq;
	spk=!spk;
}