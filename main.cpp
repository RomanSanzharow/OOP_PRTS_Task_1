#include <iostream>
#include "PNI_Trax.h"
using namespace std;

void test1();//прототип функции проверки
void test2();

int main(){
	test1();
	test2();
	system("pause");//Для продолжения нажмите любую клавишу...
	return 0;
}

void test1(){
	const int inplen1 = 12;//заранее изсестная длина массива посылки
	unsigned char inp1[inplen1] = {0x05,0x66,0xE6,0xF6,0x42,
							       0x18,0x3D,0xBA,0x29,0x44,
								   0x08,0x01};// посылка с датчика Big Endian
	//ID=5 data=123.45=0х42F6E666; ID=24 data=678.91=0x4429BA3D; ID=8 data=true
	Trax t1(inp1, inplen1);//конструктор-разборщик посылки
	t1.TraxShow();//метод печати компонент
}
void test2(){
	const int inplen2 = 32;
	unsigned char inp2[inplen2] = {0x4D,0x9A,0x99,0x99,0x3F,0x9A,0x99,0x19,0x40,0x66,0x66,0x66,0x40,0x9A,0x99,0x99,0x40,
								   0x1B,0x66,0x66,0xA6,0x40,
								   0x1C,0xCD,0xCC,0xCC,0x40,
								   0x1D,0x33,0x33,0xF3,0x40};// посылка с датчика Big Endian
	//IG=77 data=[1.2=3F99999A, 2.4=4019999A, 3.6=40666666, 4.8=4099999A]; ID=27 data=5.2=40A66666;
	//ID=28 data=40CCCCCD; ID=29 data=40F33333
	Trax t2(inp2, inplen2); 
	t2.TraxShow();
	
}
