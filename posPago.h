#ifndef POSPAGO_H

#define POSPAGO_H

#include "Data.h"
#include "Exception.h"

#include "Plano.h"


 class posPago: public Plano {

    private:
        string nome;
        double preco;
        double pacoteDeDados;//mb
        Data vencimento;


     public:

     //construtores/destrutores

     posPago(string n,double p,double pd, Data &v);
     posPago(const posPago &b);
     ~posPago();
     //getters
      string getNome();
      double getVelocidade() ;
      int getVal() ;
      int getValMes() ;



      //funções de funcionalidade

       bool isPrepago () ;
       double getFran() ;
       double custoDeChamada() ;
       bool foraDaValidade(Data& now );
       void setVal(const Data& dataPag);




 };
//construtores/destrutores


    posPago::posPago(string n,double p,double pd, Data &v): nome(n),preco(p),pacoteDeDados(pd),
vencimento(v) {}

    posPago::posPago(const posPago &b):nome(b.nome),preco(b.preco),
    pacoteDeDados(b.pacoteDeDados),vencimento(b.vencimento) {}

    posPago::  ~posPago(){}


 //getters
    string posPago::getNome(){
        return nome;
    }



    int posPago::getVal() {
        return vencimento.getDia();
    }

    int posPago::getValMes() {
        return vencimento.getMes();
    }



 //funções de funcionalidade

   bool posPago::isPrepago () {
       return false;
    }


   double posPago::getFran() {
    return pacoteDeDados;
    }


   double posPago::custoDeChamada() {
    return preco;
    }


   bool posPago:: foraDaValidade(Data& now) {
        if(now.getAno()>vencimento.getAno())
           return true;
        else if (now.getAno()<vencimento.getAno())
           return false;
        else {
          if(now.getMes()>vencimento.getMes())
              return true;
        else if (now.getMes()<vencimento.getMes())
             return false;
        else {
            if(now.getDia()>vencimento.getDia())
                return true;
            else
                return false;
            }
          }

   }





 void posPago::setVal(const Data& dataPag) {


            vencimento=dataPag;
            vencimento.setDia(30);


  }





#endif

