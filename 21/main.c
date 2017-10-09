#include"reg52.h"
sbit wei=P0^0;
sbit duan=P0^1;
unsigned char code weima[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char code duanma[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char temp[8];
void delay(unsigned int i)
{
	while(i--);
}
void display(char first,char num)
{
	char i;
	for(i=0;i<num;i++)
	{
		P1=0;
		duan=1;
		duan=0;
		P1=weima[i+first];
		wei=1;
		wei=0;
		P1=temp[i];
		duan=1;
		duan=0;
		delay(100);
	}
}
void main()
{
	int j,num=9999;
	while(1)
	{
		j++;
		if(j==10)
		{
			j=0;
			if(num>0)
			  num--;
			else 
			  num=9999;	
		}
		temp[0]=duanma[num/1000];
		temp[1]=duanma[num/100%10];
		temp[2]=duanma[num/10%10]|0x80;
		temp[3]=duanma[num%10];
		display(2,4);
	}
}