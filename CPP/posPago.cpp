#include"../Header/posPago.h"


//construtores/destrutores

    posPago::posPago(string n,double p,double pd, double vel, Data &v): nome(n),preco(p),pacoteDeDados(pd),
    veloInternet(vel),vencimento(v) {}

    posPago::posPago(const posPago &b):nome(b.nome),preco(b.preco),
    pacoteDeDados(b.pacoteDeDados),veloInternet(b.veloInternet),vencimento(b.vencimento) {}

    posPago::  ~posPago(){}


 //getters
    string posPago::getNome(){
        return nome;
    }

    double posPago::getVelocidade() {
        return veloInternet;
    }

    int posPago::getDiaVencimento () {
        return vencimento.getDia();
    }

    int posPago::getMesVencimento() {
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


    void posPago::quitarInternet (double valor,Data& now){

         if(this->foraDaValidade(now)) {
             throw(Exception("Pendencia de pagamento"));

         } else {

             if(valor<pacoteDeDados)
                 pacoteDeDados-=valor;
             else {
                pacoteDeDados=0;
                veloInternet=veloInternet*reduz;
                throw(Exception("Pacote de dados todos consumidos, internet com velocidade reduzida"));
             }

         }


    }


  void posPago::pagar( double cash) {

        if(cash<this->preco)
            throw(Erro("Valor insuficiente!"));
        else {
            vencimento.setDia(30);

        }




  }
