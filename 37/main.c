#include"reg52.h"
#include"intrins.h"
typedef unsigned char u8;
typedef unsigned char u16;
u8 code duanma[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	            0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 i;
void delay(u16 i)
{
	while(i--);
}
void keydown()
{ 
	char a=0;
	P1=0x0f;
	if(P1!=0x0f)
	{
		delay(1000);
		if(P1!=0x0f)
		{
			switch(P1)
			{
				case 0x07:i=0;break;
				case 0x0b:i=1;break;
				case 0x0d:i=2;break;
				case 0x0e:i=3;break;
			}
			P1=0xf0;
			{
				switch(P1)
			{
				case 0x70:i=i;break;
				case 0xb0:i=i+4;break;
				case 0xd0:i=i+8;break;
				case 0xe0:i=i+12;break;
			}
			while(a<50&&P1!=0xf0)
			{
				delay(1000);
				a++;
			}
		}
	}
 }
}
void main()
{
	while(1)
	{
		keydown();
		P0=~duanma[i];
	}
}