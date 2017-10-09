#include"reg52.h"
#include"intrins.h"
unsigned char segout[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char code tab[]={0x00,0x6c,0x92,0x82,0x44,0x28,0x10,0x00};
sbit latch=P1^0;
sbit srclk=P1^1;
sbit ser=P1^2;
sbit latch2=P2^2;
sbit srclk2=P2^1;
sbit ser2=P2^0;
void sendbyte(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		srclk=0;
		ser=dat&0x80;
		dat<<=1;
		srclk=1;
	}
}
void send2byte(unsigned char dat1,unsigned char dat2)
{
	sendbyte(dat1);
	sendbyte(dat2);
}
void out595()
{
	latch=1;
	_nop_();
	latch=0;
}
void sendseg(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		srclk2=0;
		ser2=dat&0x80;
		dat<<=1;
		srclk2=1;
	}
	latch2=1;
	_nop_();
	latch2=0;
}
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	unsigned char i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			sendseg(segout[i]);
			send2byte(~tab[i],0xff);
			out595();
			delay(100);
			send2byte(0xff,0xff);
			out595();
		}
	}
}