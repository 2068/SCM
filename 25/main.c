#include"reg52.h"
sbit key=P1^0;
sbit led=P1^1;
void main()
{
	ley=1;
	while(1)
	{
		if(!key)
			led=0;
		else
			led=1;
	}
}
