#include"reg52.h"
sbit wei=P0^0;
sbit duan=P0^1;
unsigned char code weima[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char code duanma[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	int i=0,j,num;
	while(1)
	{
		P1=weima[i];
		wei=1;
		wei=0;
		P1=duanma[num+i];
		duan=1;
		duan=0;
		delay(200);
		i++;
		j++;
		if(i==8)
			i=0;
		if(j==500)
		{
			j=0;
			num++;
			if(num==9)
				num=0;
		}
	}
}