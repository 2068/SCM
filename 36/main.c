#include"reg52.h"
#include"intrins.h"
typedef unsigned char u8;
typedef unsigned char u16;
sbit a=P2^2;
sbit b=P2^3;
sbit c=P2^4;
void main()
{
	while(1)
	{
		a=1;
		b=0;
		c=1;
		P0=0x06;
	}
}