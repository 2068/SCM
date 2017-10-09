#include"reg52.h"
sbit key1=P1^0;
sbit key2=P1^1;
sbit wei=P0^0;
sbit duan=P0^1;
unsigned char code duanma[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code weima[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char temp[8];
void delayus(unsigned char t)
{
	while(t--);
}
void delayms(unsigned char t)
{
	while(t--)
	{
		delayus(245);
		delayus(245);
	}
}
void display(unsigned char first,unsigned char num)
{
	unsigned char i;
	for(i=0;i<num;i++)
	{
		P2=0;
		duan=1;
		duan=0;
		P2=weima[i+first];
		wei=1;
		wei=0;
		P2=temp[i];
		duan=1;
		duan=0;
		delayms(2);
	}
}
void main()
{
	unsigned char num=0;
	key1=1;
	key2=1;
	while(1)
	{
		if(!key1)
		{
			delayms(10);
			if(!key1)
			{
				while(!key1);
				if(num<9)
					num++;
			}
		}
		if(!key2)
		{
			delayms(10);
			if(!key2)
			{
				while(!key2);
				if(num>0)
					num--;
			}
		}
		temp[0]=duanma[num%10];
		display(0,1);
	}
}
