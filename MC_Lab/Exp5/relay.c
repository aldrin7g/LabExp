#include<reg51.h>

sbit pin=P2^0;

void delay(int ms);

void main()
{ 
	 while(1)
	 {
		 pin=1;
		 delay(1000);
		 pin=0;
		 delay(1000);
   }
}

void delay(int ms){
	int i,j;
	for(i=0; i< ms; i++){
    for(j=0; j<128; j++);
	}
}