#include<reg51.h>
sbit d0=P2^7;
sbit d1=P2^6;
sbit d2=P2^5;
sbit d3=P2^4;
int i,j;
void delay(int ms);
void angle(int deg,int mode);

void main()
{
angle(180,0);
delay(3000);
angle(90,1);
delay(3000);
angle(45,1);
	
do{}
while(1);
}

void delay(int ms) {
int i, j;
for (i = 0; i < ms; i++)
for (j = 0; j < 128; j++);
}

void angle(int deg, int mode){
int val = deg/0.69;
if (mode == 0){
	for(j=0;j<=val;j++){
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
if (mode == 1){
	for(j=0;j<=val;j++){
	d0=0;d1=1;d2=1;d3=1;
	delay(5);
	d0=1;d1=0;d2=1;d3=1;
	delay(5);
	d0=1;d1=1;d2=0;d3=1;
	delay(5);
	d0=1;d1=1;d2=1;d3=0;
	delay(5);
  }
 }
}
	