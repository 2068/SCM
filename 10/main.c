#include"reg52.h"
void delay(unsigned int i)
{
	while(i--);
}
void main()
{
  char i,j;
	while(1)
	{
		P1=j=0xfe;
		delay(50000);
		for(i=0;i<7;i++){
			j=j<<1;
			j=j|0x01;
			P1=j;
	   delay(50000);
		}
		P1=j=0x7f;
		delay(50000);
		for(i=0;i<7;i++){
			j=j>>1;
			j=j|0x80;
			P1=j;
	   delay(50000);
		}
	}
}