#include <iostream>

#include"Celular.h"



using namespace std;


int main()
{
    Data A (20,05,2020);
  Plano*p=new prePago("Oi",A,0.5,0.08,30);
  Celular cel(p,30);
  Celular C(p,50);
  cel.printNumero();
  cout<<endl;
  C.printNumero();


    return 0;
}
