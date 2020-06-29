#include<reg51.h> 
#define led P0
sbit sw1=P2^0;
sbit sw2=P2^1;
sbit sw3=P2^2;
sbit sw4=P2^3;
unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay (int);
void display (int);
void sdelay (char);
char count=0;
int speed=0;
void delay (int d)
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}
void sdelay (char d)
{
	for(;d>0;d--);
}

void display (int n)
{
	led=ch[n/1000];
	sw1=1;
	sdelay(30);
	sw1=0;
	led=ch[(n/100)%10];
	sw2=1;
	sdelay(30);
	sw2=0;
	led=ch[(n/10)%10];
	sw3=1;
	sdelay(30);
	sw3=0;
	led=ch[n%10];
	sw4=1;
	sdelay(30);
	sw4=0;
}


void main()
{
	unsigned long int i=0;
	TMOD=0x05;
	TR0=1;
	P0=0xff;
	while(1)
	{
	  for(i=586;i>0;i--)
	  {
		count=(TH0*256)+TL0;
		sdelay(1);
		display(speed);
	  }
		speed=count*60;
	 count=0;
	 TH0=TL0=0;
	}
}