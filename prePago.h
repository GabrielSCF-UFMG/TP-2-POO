#ifndef PREPAGO_H

#define PREPAGO_H

#include "Data.h"
#include "Plano.h"
#include"Exception.h"


class prePago: public Plano {

    private:
         string nome;
         double precoMin;
         double franquia;
         double precoMb;
         int tempoValidade;
         Data validade;//Dia
    public:
        //construtores
         prePago(string nome,Data val, double pMb, double pm,unsigned int t);
         prePago(const prePago &p) ;
         ~prePago() ;


        //getters

         int getVal();
         int getTempoVal();
         int getValMes() ;
         double getFran() ;
         string getNome() ;
       //setters
        void setFran(double const &c);


       //funções de funcionalidade

         bool foraDaValidade(Data& now );
         bool isPrepago() ;
         double custoDeChamada () ;
         double custoDeInternet () ;







};

//construtores/destrutor
 prePago::prePago(string nome,Data val, double pMb, double pm,unsigned int t):nome(nome),
 validade(val),precoMb(pMb),precoMin(pm),tempoValidade(t) {validade.setDia(t); franquia=0;}

 prePago:: prePago(const prePago &p) : nome(p.nome),validade(p.validade),precoMin(p.precoMin),
 tempoValidade(p.tempoValidade) {validade.setDia(tempoValidade); franquia=0;}

 prePago::~prePago() {}


 //getters

 int prePago:: getVal(){
     return validade.getDia();
 }

 int prePago::getValMes() {
    return validade.getMes();
 }

 double prePago::getFran() {
     return franquia;
 }


 string prePago::getNome() {
     return nome;
}

int prePago:: getTempoVal(){
   return tempoValidade;
}




//setters

 void prePago::setFran(double const &c) {
   franquia=c;
 }



 //funções de funcionalidade


 bool prePago::foraDaValidade(Data& now ) {

      if(now.getAno()>validade.getAno())
           return true;
      else if (now.getAno()<validade.getAno())
           return false;
      else {
          if(now.getMes()>validade.getMes())
              return true;
          else if (now.getMes()<validade.getMes())
             return false;
          else {
            if(now.getDia()>validade.getDia())
                return true;
            else
                return false;
           }
      }

 }


 bool prePago::isPrepago() {
     return true;
}

 double prePago::custoDeChamada () {
     return precoMin ;
}

 double prePago::custoDeInternet () {
     return precoMb;
}







#endif // PREPAGO_H
