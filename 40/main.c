#include"reg52.h"
#include"intrins.h"
unsigned char duanma[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
                        0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
char i;
void delay(unsigned int i)
{
	while(--i);
}
void keydown()
{
	char t=0;
	P1=0xf0;
	if(P1!=0x0f)
	{
		delay(1000);
		if(P1!=0xf0)
		{
			switch(P1)
			{
				case 0x70:i=0;break;
				case 0xb0:i=1;break;
				case 0xd0:i=2;break;
				case 0xe0:i=3;break;
			}	
			P1=0x0f;
			switch(P1)
			{
				case 0x0e:i=i;break;
				case 0x0d:i=i+4;break;
				case 0x0b:i=i+8;break;
				case 0x07:i=i+12;break;
			}	
      while(t<50&&P1!=0x0f)
			{
				delay(1000);
				t++;
			}				
		}	
	}
}
void main()
{
	while(1)
	{
		keydown();
		P0=duanma[i];
	}
}