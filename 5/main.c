#include"reg52.h"
sbit led=P1^0;
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	unsigned char i;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			led=0;
			delay(5000);
			led=1;
			delay(5000);
		}
		for(i=0;i<10;i++)
		{
			led=0;
			delay(60000);
			led=1;
			delay(60000);
		}
	}
}