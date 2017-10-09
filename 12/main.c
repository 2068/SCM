#include"reg52.h"
sbit LAT1=P2^0;
sbit LAT2=P2^1;
unsigned char code sumaguan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71
};
unsigned char code wei[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char temp[8];
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
  unsigned char i;
	unsigned int j;
	while(1)
	{
		j++;
		for(i=0;i<8;i++)
		{
		temp[0]=sumaguan[j/10000];
		temp[1]=sumaguan[j/1000%10];
		temp[2]=sumaguan[j/100%10];	
		temp[3]=sumaguan[j/10%10]|0x80;
		temp[4]=sumaguan[j%10];
	  P0=wei[i];
		LAT1=1;
		LAT1=0;
		P0=temp[i];
		LAT2=1;
		LAT2=0;
		delay(200);
		}
	}
}