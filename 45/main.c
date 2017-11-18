#include"reg52.h"
typedef unsigned int u16;
typedef unsigned char u8;
void UsartInit()
{
	TMOD=0x20;
	TH1=0xf3;
	TL1=0xf3;
	PCON=0x80;
	TR1=1;
	SCON=0x50;
	ES=1;
	EA=1;
}
void main()
{
	UsartInit();
	while(1);
}
void Usart()interrupt 4
{
	u8 receiveData;
	receiveData=SBUF;
	RI=0;
	SBUF=receiveData;
	while(!TI);
	TI=0;
}