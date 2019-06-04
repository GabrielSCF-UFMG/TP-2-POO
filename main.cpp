#include<iostream>

#include "Cliente.h"
#include "Interface.h"


int main(){

    Date d1(0,15,1);
    Date d2(0,15,2);

	//Plano p1("HELLOW 150 MB 30 Gb", 50, 150, 30, 200, true,d1);
	//Plano p2("HELLOW 200 MB 50 Gb", 50, 200, 50, 200, false,d2);
    Plano p1;

    Interface plano1(p1);

    plano1.interfacePlano();






	return 0;


}

