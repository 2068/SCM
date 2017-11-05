#include"reg52.h"
#include"intrins.h"
sbit IN_PL=P1^6;
sbit IN_Data=P1^7;
sbit SCK=P3^6;
char Read()
{
	char i,indata;
	IN_PL=0;
	_nop_();
	IN_PL=1;
	_nop_();
	indata=0;
	for(i=0;i<8;i++)
	{
		indata=indata<<1;
		SCK=0;
		_nop_();
		indata|=IN_Data;
		SCK=1;
	}
	return indata;
}
void main()
{
	unsigned char i;
  P0=0;
	while(1)
	{
		i=Read();
		if(i!=0xff)
		{
			P0=~i;	
		}
	}
}

