#include"reg52.h"
sbit led=P1^1;
sbit key=P1^0;
void main()
{
	unsigned int i;
	while(1)
	{
		if(key==0)
		{
			for(i=0;i<5000;i++);
			if(!key)
			{
				while(!key);
			  led=!led;
			}
		}			
	}
}