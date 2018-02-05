#include"reg52.h"
#define uchar unsigned char
#define uint unsigned int
sbit rs=P2^4;
sbit lcden=P2^6;
sbit lcdrw=P2^5;
uchar code shen[]= {"LCD1602--CLOCK"};
uchar code word[]= {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a};
uchar dispbuf[8]= {0,0,10,0,0,10,0,0};
uchar num=0,s=0,m=0,h=0,flag=1;
void delay(uint x)
{
    uint a,b;
    for(a=x; a>0; a--)
        for(b=10; b>0; b--);
}
void write_com(uchar com)
{
    P0=com;
    rs=0;
    lcden=0;
    delay(10);
    lcden=1;
    delay(10);
    lcden=0;
}
void write_date(uchar date)
{
    P0=date;
    rs=1;
    lcden=0;
    delay(10);
    lcden=1;
    delay(10);
    lcden=0;
}
void Lcd_init()
{
    lcdrw=0;
    write_com(0x01);
    delay(20);
    write_com(0x38);
    delay(20);
    write_com(0x0c);
    delay(20);
    write_com(0x06);
    delay(20);
}
void time0_init()
{
    TMOD=0X01;
    TH0=(65536-25000)/256;
    TL0=(65536-25000)%256;
    EA=1;
    ET0=1;
    EX0=1;
    IT0=1;
    PX0=1;
    TR0=1;
}
void timer0() interrupt 1
{
    flag=0;
    TH0=(65536-25000)/256;
    TL0=(65536-25000)%256;
    num++;
    if(num==40)
    {
        flag=1;
        s++;
        num=0;
        if(s==60)
        {
            m++;
            s=0;
            if(m==60)
            {
                h++;
                m=0;
                if(h==24)
                    h=0;
            }
        }
    }
}
void time1() interrupt 0
{
    TR0=~TR0;
}
void main()
{
    uchar a;
    Lcd_init();
    write_com(0x80);
    delay(20);
    for(a=0; a<15; a++)
    {
        write_date(shen[a]);
        delay(20);
    }
    time0_init();
    while(1)
    {
        if(flag==1)
        {
            dispbuf[0]=h/10;
            dispbuf[1]=h%10;
            dispbuf[3]=m/10;
            dispbuf[4]=m%10;
            dispbuf[6]=s/10;
            dispbuf[7]=s%10;
            write_com(0xc0+4);
            delay(20);
            for(a=0; a<8; a++)
            {
                write_date(word[dispbuf[a]]);
                delay(20);
            }
        }
    }
}
