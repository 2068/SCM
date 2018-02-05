#include "reg52.h"
void delay(unsigned int i)
{
	while(i--);
}
unsigned char code smgduan[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
	                   0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char KeyValue;
void KeyDown()
{
	char a=0;
	P0=0x0f;
	if(P0!=0x0f)
	{
		delay(1000);
		if(P0!=0x0f)
		{
			switch(P0)
			{
				case 0x07:KeyValue=0;break;
				case 0x0b:KeyValue=1;break;
				case 0x0d:KeyValue=2;break;
				case 0x0e:KeyValue=3;break;
			}
			P0=0xf0;
			switch(P0)
			{
				case 0x70:KeyValue=KeyValue+0;break;
				case 0xb0:KeyValue=KeyValue+4;break;
				case 0xd0:KeyValue=KeyValue+8;break;
				case 0xe0:KeyValue=KeyValue+12;break;
			}
			while(a<10&&P0!=0xf0)
			{
				delay(1000);
				a++;
			}
		}
	}
}
void Init()
{
	SCON=0X50;
	TMOD=0X20;
	PCON=0X80;
	TH1=0Xfd;
	TL1=0Xfd;
	EA=1;
	ES=1;
	TR1=1;
}

void main()
{
	Init();
	while(1)
    {
        KeyDown();
        P1=smgduan[KeyValue];
        SBUF=KeyValue;
	    while(!TI);
	    TI=0;
    }
}
void Usart() interrupt 4
{
	unsigned char temp;
	temp=SBUF;
	RI = 0;
	switch(temp)
        {
            case 0:P1=smgduan[temp];break;
            case 1:P1=smgduan[temp];break;
            case 2:P1=smgduan[temp];break;
            case 3:P1=smgduan[temp];break;
            case 4:P1=smgduan[temp];break;
            case 5:P1=smgduan[temp];break;
            case 6:P1=smgduan[temp];break;
            case 7:P1=smgduan[temp];break;
            case 8:P1=smgduan[temp];break;
            case 9:P1=smgduan[temp];break;
            case 10:P1=smgduan[temp];break;
            case 11:P1=smgduan[temp];break;
            case 12:P1=smgduan[temp];break;
            case 13:P1=smgduan[temp];break;
            case 14:P1=smgduan[temp];break;
            case 15:P1=smgduan[temp];break;
        }
}