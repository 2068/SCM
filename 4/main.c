#include"reg52.h"
sbit led=P1^0;
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	led=0;
	delay(10000);
	led=1;
	delay(10000);
}