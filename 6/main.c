#include"reg52.h"
sbit led0=P1^0;
sbit led1=P1^1;
sbit led2=P1^2;
sbit led3=P1^3;
sbit led4=P1^4;
sbit led5=P1^5;
sbit led6=P1^6;
sbit led7=P1^7;
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
			led0=0;
			led2=1;
			led4=0;
			delay(5000);
			led0=1;
			led2=0;
			led4=1;
			delay(5000);
		}
		for(i=0;i<10;i++)
		{
			led0=0;
			led2=1;
			led4=0;
			delay(60000);
			led0=1;
			led2=0;
			led4=1;
			delay(60000);
		}
	}
}