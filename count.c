#include <REGX51.H>

	 sbit rs=P3^2;
	 sbit rw=P3^3;
	 sbit en=P3^4;												   
	
 	 sfr datas=0xA0;

	 void lcdinit(void);
	 void lcdcmd(unsigned char );	 
	 void delay(unsigned int del);		
	 void lcddata(unsigned char ldat);	
		 void del1();
 		void sms1();
		void sendd();

void INITLCD()
{
 lcdinit();
}


void COMMAND(unsigned char val)
	{
	 lcdcmd(val);
	}
void DISPLAY(unsigned char val)
	{
	 lcddata(val);
	}

	 void lcdinit(void)
	 {
	 lcdcmd(0x38);
	 lcdcmd(0x38);
	 lcdcmd(0x38);
	 lcdcmd(0x06);
	 lcdcmd(0x0e);
	 lcdcmd(0x01);
	 lcdcmd(0x0C);
	 lcdcmd(0x80);
	 }

	void lcdcmd(unsigned char lcmd)
	{
	 datas=lcmd;
	 rs=0;
	 rw=0;
	 en=1;
 	 delay(100);
	 en=0;
	}
	

	void delay(unsigned int del)
	{
	while(del--);
 	}

	void lcddata(unsigned char ldat) 
	{
	 datas=ldat;
	 rs=1;
	 rw=0;
	 en=1;
   	 delay(100);
	 en=0;
 	}

char flags=0;
char flagt=0;
char kval=0;
char flagr=0;
int recharge=0;
char flagtick=0;

unsigned char keypad();
 
void disp(unsigned char dat)
	{
	  
	  DISPLAY(dat);
	}


void cls()
	{
	 	  COMMAND(0x01);
		  COMMAND(0x02); 
	 	  COMMAND(0x80);
	}

void putchar(unsigned char val[16],char len)
	{
	 char i;
	 for(i=0;i<len;i++)
	 	{
		 disp(val[i]);
		}
	}

 void txs(unsigned char val)
	{
	    int i;
		TI=0;
		SBUF=val;
		for(i=0;i<600;i++);
		//while(TI==0);
	}


unsigned int val,value,ct,fg,i=0,j;
int ps;
int hb,hbt,hbtt;

void main()
	{
	unsigned int flg=0,flg1=0;
	SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
		INITLCD();
				lcdcmd(0x80);
				putchar("Speed=                 ",16);
		lcdcmd(0x88);	
	lcddata((val/100)+0x30);
	lcddata(((val%100)/10)+0x30);
	lcddata((val%10)+0x30);	
 lcddata(' ');

 lcddata('r');
 lcddata('p');
 lcddata('m');
				
		
	while(1)
	 	{
			
			
			if(P1_1==1)
			{
				if(ps==0)
				{
				ps=1;
				hb++;
				}
			}
			else
			{
				ps=0;
			}
			
			hbt++;
							lcdcmd(0xC8);	

 lcddata(' ');
 lcddata(' ');
 lcddata(' ');
										lcdcmd(0xC8);	

 lcddata(' ');
 lcddata(' ');
 lcddata(' ');
			if(hbt>600)
			{
				val=hb*3;
				hbt=0;
				hb=0;
					lcdcmd(0x88);	
	lcddata((val/100)+0x30);
	lcddata(((val%100)/10)+0x30);
	lcddata((val%10)+0x30);	
 lcddata(' ');

 lcddata('r');
 lcddata('p');
 lcddata('m');
				
				if(val>150)
						P1_0=0;
				else
					P1_0=1;
			}
			
		}		
	}
	
	//ABCDEFGHIJKLMNOPQRSTUVWXYZ