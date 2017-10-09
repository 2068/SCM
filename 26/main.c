#include"reg52.h"
sbit key=P1^0;
sbit led=P1^1;
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
void main()
{
	key=1;
	while(1)
	{
		if(!key)
		{
			delayms(10);
			if(!key)
			{
				while(!key);
					led=~led;
			}
		}
	}
}
