#include<reg51.h>
sbit d0=P2^7;
sbit d1=P2^6;
sbit d2=P2^5;
sbit d3=P2^4;
int i,j;
void delay()
{
for(i=0;i<1000;i++);
}

void main()
{
for(j=0;j<=520;j++){

	d0=0;d1=1;d2=1;d3=1;
	delay();

	d0=1;d1=0;d2=1;d3=1;
	delay();

	d0=1;d1=1;d2=0;d3=1;
	delay();

	d0=1;d1=1;d2=1;d3=0;
	delay();
}
do{} 
while(1);
}