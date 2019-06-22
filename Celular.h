#ifndef CELULAR_H
#define CELULAR_H
#include"prePago.h"
#include"posPago.h"
#include"ligacaoDados.h"
#include"ligacaoSimples.h"
#include<vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>



class Celular {

 private:
  vector<int> numero;
  vector<Ligacao*> registro;
  Plano*p;
  double creditos;
  double dados;
  const int numDigitos=8;

 public:

    Celular(Plano *x,double c=0,double d=0);
    Celular(Celular &c);
    ~Celular();

     void printNumero();
     void ligar(Data& d,double duraM,double duraS=0);
     double getCreditos ();
     void registroChamadas ();




};

 Celular::Celular(Plano *x,double c,double d):p(x),creditos(c),dados(d) {

   srand (unsigned(rand()));

     for(int a=0; a<numDigitos; a++) {
        numero.push_back(rand()%9);


         }



     std::random_shuffle ( numero.begin(), numero.end() );



 }

Celular::Celular(Celular &c):p(c.p),creditos(c.creditos),dados(c.dados),numero(c.numero) {}

Celular::~Celular() {registro.clear();}

void Celular::printNumero() {

  for(int i=0;i<numero.size();i++)
       std::cout<<numero[i];




}

double Celular::getCreditos() {
    return creditos;
}


void Celular::ligar(Data& d,double duraM,double duraS)  {

     double custo, tempoChamada;
     double Ttotal=duraM+duraS/60;

     if(p->isPrepago()==true) { //condição de pre pago

         if(creditos==0)
             throw (Exception("Voce nao possui creditos para realizar a ligacao"));


         double maximoT= creditos/p->custoDeChamada();


         if(maximoT<=Ttotal){
             tempoChamada=maximoT;
             custo=creditos;
             creditos=0;

         } else {
          custo= Ttotal*(p->custoDeChamada() );

          tempoChamada=Ttotal;

          creditos-=custo;

        }


    }  else {  //condição de pos pago
      custo=p->custoDeChamada();
      tempoChamada=Ttotal;

    }



     Ligacao *l=new ligacaoSimples(custo,d,tempoChamada);
         registro.push_back(l);




}


void Celular:: registroChamadas () { //so printa ligaçao simples

 for (int k=0;k<registro.size();k++) {

     if(registro[k]->isSimples()) {
        cout<<"Data da ligacao: "<<registro[k]->getDia().getDia() <<"/"<<registro[k]->getDia().getMes();
        cout<<"/"<<registro[k]->getDia().getAno()<<endl;

        cout<<"Duracao: "<<dynamic_cast<ligacaoSimples*>(registro[k])->getDuracaoMin( )<<" minutos"<<endl;
        if(p->isPrepago())
            cout<<"Preco da chamada:"<<registro[k]->getCusto()<<" reais"<<endl;
        cout<<endl;
     }

 }









}


#endif // CELULAR_H
