#include"reg52.h"
#include"intrins.h"
sbit SRCLK=P3^6;
sbit RCLK1=P3^5;
sbit SER=P3^4;
void delay(unsigned int i)
{
	while(--i);
}
void Hc595SendByte(unsigned char dat)
{
	char i;
	for(i=0;i<8;i++)
	{
		SER=dat>>7;
		dat<<=1;
		SRCLK=0;
		_nop_();
		SRCLK=1;
	}
	RCLK1=1;
	_nop_();
	RCLK1=0;
}
void main()
{
	unsigned char num=0x01;
	while(1)
	{
		Hc595SendByte(num);
		num=_crol_(num,1);
		delay(50000);
	}
}