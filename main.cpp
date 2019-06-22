#include <iostream>

#include"Celular.h"



using namespace std;


int main(){
    Data A (21,06,2019);
  Plano*p=new prePago("Oi",A,0.5,1,10);
  Celular cel(p,20);

  try {

   cel.ligar(A,9,60);
   cel.ligar(A,1,30);
   cel.ligar(A,2,15);



  } catch(Exception &e) {

   e.mensagem_erro();
  }

   cel.registroChamadas();

    return 0;
}
