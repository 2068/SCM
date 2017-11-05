#include"reg52.h"
sbit moto=P0^0;
void delay(unsigned int i)
{
	while(--i);
}
void main()
{
	char i;
	moto=0;
  for(i=0;i<100;i++)
	{
		moto=1;
		delay(50000);
	}
	moto=0;
	while(1)
	{
		
	}
}