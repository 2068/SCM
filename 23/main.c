#include"reg52.h"
sbit led=P1^0;
void inittimer()
{
	TMOD|=0x01;
	TH0=0x00;
	TL0=0x00;
	EA=1;
	ET0=1;
	TR0=1;
}
void main()
{
	inittimer();
	while(1);
}
void timer() interrupt 1 using 1
{
	TH0=0x00;
	TL0=0x00;
	led=~led;
}