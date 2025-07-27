#include<reg51.h>
#include<stdio.h>
sbit LED0=P0^0;
sbit LED1=P0^1;
sbit LED2=P0^2;
sbit LED3=P0^3;
sbit LED4=P0^4;
sbit LED5=P0^5;
sbit LED6=P0^6;
sbit LED7=P0^7;
sbit sw0 = P2^0;
sbit sw1 = P2^1;

void main()
{
	   if((sw0==1)&&(sw1==0)){
	     	LED0=LED2=LED4=LED6=1;
			  LED1=LED3=LED5=LED7=0;
	    }
     else if((sw0==0)&&((sw1==1))){
			  LED0=LED2=LED4=LED6=0;
			  LED1=LED3=LED5=LED7=1;
		 }
		 else if((sw0==1)&&((sw1==1))){
			  LED0=LED1=LED2=LED3=LED4=LED5=LED6=LED7=1;
		 }
	   else {
			  LED0=LED1=LED2=LED3=LED4=LED5=LED6=LED7=0;
		} 
}