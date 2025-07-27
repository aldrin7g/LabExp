#include<reg51.h>

sbit port = P0^1;

void delay1();
void delay2();

void main(){

	while(1){
		port = 0;
		delay1();
		port = 1;
		delay2();
		}
}

//20ms delay
void delay1(){
	TMOD = 0x01;
	TH0 = 0xB7;
	TL0 = 0xFF;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}

//40ms delay
void delay2(){
	TMOD = 0x01;
	TH0 = 0x6F;
	TL0 = 0xFE;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}