#include<reg51.h>
sbit d0=P2^7;
sbit d1=P2^6;
sbit d2=P2^5;
sbit d3=P2^4;

void delay(int ms);
void angle(int deg);

void main()
{
angle(180);
	
do{}
while(1);
}

void delay(int ms) {
	int i,j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 128; j++);
}

void angle(int deg){
	int i;
	int val = deg/0.69;
	
		for(i=0;i<=val;i++){
			d0=1;d1=1;d2=1;d3=0;
			delay(5);
			d0=1;d1=1;d2=0;d3=1;
			delay(5);
			d0=1;d1=0;d2=1;d3=1;
			delay(5);
			d0=0;d1=1;d2=1;d3=1;
			delay(5);
		}
}