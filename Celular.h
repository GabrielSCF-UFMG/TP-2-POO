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
     double getDados();
     Plano* getPlano();
     void registroChamadas ();
     void registroDados ();
     void transferirDados (Data& d,double Bits);
     void renovarPagamento(Data &d,double pay=0);// serve para os dois tipos de planos
     void comprarDados(Data &d,double c);




};

 Celular::Celular(Plano *x,double c,double d):p(x),creditos(c),dados(d) {

   srand (unsigned(rand()));

     for(int a=0; a<numDigitos; a++) {
        numero.push_back(rand()%9);


         }



     std::random_shuffle ( numero.begin(), numero.end() );

     if(p->isPrepago()==false)
           dados+=p->getFran();//celular pos pago pode ser iniciado com pacote de dados iniciais, mas vai receber aquilo que está contido no plano também



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

double Celular::getDados() {
    if(p->isPrepago()==true)
         return dados;
     else
    return dynamic_cast<posPago*> (p)->getFran();
}


void Celular::ligar(Data& d,double duraM,double duraS)  {

     if(p->foraDaValidade(d))
         throw(Exception("Pendencia de pagamento, coloque creditos ou renove seu plano") );


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


void Celular::transferirDados (Data& d,double Bits) {

      double dadosConsumidos,custo;
      if(p->foraDaValidade(d))
         throw(Exception("Pendencia de pagamento, coloque creditos ou renove seu plano") );

     if(p->isPrepago()==true) { //condição de pre pago

         if(dados==0)
             throw (Exception("Seu pacote de dados chegou ao fim"));



         if(Bits>=dados){
             dadosConsumidos=dados;
             dados=0;

         } else {
          dadosConsumidos=Bits;
          dados-=Bits;

        }


    }  else {  //condição de pos pago
       dadosConsumidos=Bits;
       if(dadosConsumidos>dados)
         throw(Exception("pacote de dados chegou ao fim") );
       else if (dadosConsumidos==dados)
             dados=0;
        else
          dados-=dadosConsumidos;




    }



     Ligacao *l=new ligacaoDados(dadosConsumidos,d);
         registro.push_back(l);





}


void Celular::registroDados (){

 for (int k=0;k<registro.size();k++) {

     if(registro[k]->isSimples()==false) {
        cout<<"Data do uso: "<<registro[k]->getDia().getDia() <<"/"<<registro[k]->getDia().getMes();
        cout<<"/"<<registro[k]->getDia().getAno()<<endl;

        cout<<"Dados consumidos: "<<dynamic_cast<ligacaoDados*>(registro[k])->getDadosCon( )<<" Mbs"<<endl;

        cout<<endl;
     }

 }


}


void Celular::renovarPagamento(Data &d,double pay) {


  if(p->isPrepago()) {
    creditos=pay;
      p->setVal(d);

  } else {

     dynamic_cast<posPago*>(p)->setVal(d);


  }


}

void Celular::comprarDados(Data &d,double c) {
   if(p->foraDaValidade(d))
       throw(Exception("Pendencia de pagamento, coloque creditos ou renove seu plano") );
   if(p->isPrepago()) {
       double preco=dynamic_cast<prePago*>(p)->custoDeInternet ();
       preco*=c;

       if(preco>creditos)
           throw(Exception("Voce nao possui creditos para realizar esta operacao") );
       else {
          dados+=c;
          creditos-=preco;

       }
    }
    else
       throw(Exception("Essa operacao nao e permitida para seu plano"));

}

Plano* Celular::getPlano() {
    return p;

}




#endif // CELULAR_H
