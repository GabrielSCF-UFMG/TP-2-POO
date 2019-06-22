#include <iostream>

#include"Celular.h"



using namespace std;


int main(){
    Data A (21,06,2019);
  Plano*p=new posPago("Tim",60,500,A);

  Celular cel(p,20,100);

  try {

   cel.ligar(A,9,60);
   cel.ligar(A,1,30);
   cel.ligar(A,2,15);
   cel.transferirDados(A,100);
    cel.comprarDados(A,500);



  } catch(Exception &e) {

   e.mensagem_erro();
  }

   cel.registroChamadas();
   cel.registroDados();
   cout<<cel.getDados()<<endl<<cel.getCreditos();

   Plano *a=cel.getPlano();

   cout<<"Nome do plano:"<<a->getNome()<<endl;
   if(a->isPrepago()) {
    cout<<"Preco do Min: "<<a->custoDeChamada()<<endl;
    cout<<"Preco do Mb: "<<dynamic_cast<prePago*> (a)->custoDeInternet () <<endl;

   }
   else {
    cout<<"Preço do plano: "<<a->custoDeChamada()<<endl;
    cout<<"Pacote de dados: "<<a->getFran()<<endl;
   }

    return 0;
}
