#include"reg52.h"
sbit led=P1^0;
void inittimer()
{
	TMOD|=0x10;
	TH1=0x00;
	TL1=0x00;
	EA=1;
	ET1=1;
	TR1=1;
}
void main()
{
	inittimer();
	while(1);
}
void timer() interrupt 3 using 1
{
	TH1=0x00;
	TL1=0x00;
	led=~led;
}