#include"reg52.h"
sbit duan=P2^0;
sbit wei=P2^1;
unsigned char code duanma[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code weima[]= {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char temp[8];
int h,m,s,n;
void delay(unsigned int i)
{
    while(--i);
}
void display()
{
    int i;
    for(i=0; i<8; i++)
    {
        P0=0;
        duan=1;
        duan=0;
        P0=weima[i];
        wei=1;
        wei=0;
        P0=temp[i];
        duan=1;
        duan=0;
        delay(200);
    }
}
void timer0()
{
    TMOD=0x01;
	  TH0=(65536-25000)/256;
    TL0=(65536-25000)%256;
    EA=1;
    ET0=1;
    TR0=1;
}
void timer() interrupt 1
{
    TH0=(65536-25000)/256;
    TL0=(65536-25000)%256;
    display();
    n++;
    if(n==40)
    {
        n=0;
        s++;
        if(s==60)
        {
            s=0;
            m++;
            if(m==60)
            {
                m=0;
                h++;
                if(h==24)
                    h=0;
            }
        }
        temp[0]=duanma[h/10];
        temp[1]=duanma[h%10];
        temp[2]=0x40;
        temp[3]=duanma[m/10];
        temp[4]=duanma[m%10];
        temp[5]=0x40;
        temp[6]=duanma[s/10];
        temp[7]=duanma[s%10];
    }
}
void main()
{
    timer0();
    while(1);
}
