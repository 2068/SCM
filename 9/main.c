#include"reg52.h"
#include"intrins.h"
sbit CH1=P2^2;
sbit CH2=P2^3;
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
		P0=0xfe;
		CH2=1;
		CH2=0;
		P0=0x4f;
		CH1=1;
		CH1=0;
	
}