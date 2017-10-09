#include"reg52.h"
sbit spk=P0^0;
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	while(1)
	{
		delay(1000);
		spk=!spk;
	}
}