#include<reg51.h>

sbit port = P0^1;

void delay();

void main(){

	while(1){
		port = 0;
		delay();
		port = 1;
		delay();
		}
}

void delay(){
	TMOD = 0x01;
	TH0 = 0xB7;
	TL0 = 0xFF;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}