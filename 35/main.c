#include"reg52.h"
#include"intrins.h"
typedef unsigned char u8;
typedef unsigned char u16;
sbit a=P2^2;
sbit b=P2^3;
sbit c=P2^4;
u8 code duanma[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(u16 i)
{
	while(--i);
}
void display()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case 0:a=0;b=0;c=0;break;
			case 1:a=1;b=0;c=0;break;
			case 2:a=0;b=1;c=0;break;
			case 3:a=1;b=1;c=0;break;
			case 4:a=0;b=0;c=1;break;
			case 5:a=1;b=0;c=1;break;
			case 6:a=0;b=1;c=1;break;
			case 7:a=1;b=1;c=1;break;
		}
		P0=duanma[i];
		delay(100);
		P0=0;
	}
}
void main()
{
	while(1)
	{
		display();
	}
}