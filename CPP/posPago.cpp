#include"../Header/posPago.h"


//construtores/destrutores

    posPago::posPago(string n, double pm, double pp, double f, double vel, Data &v): nome(n),precoMin(pm), precoPacote(pp),franquia(f),
        veloInternet(vel),vencimento(v) {}

    posPago::posPago(const posPago &b):nome(b.nome),precoMin(b.precoMin),precoPacote(b.precoPacote),
        franquia(b.franquia),veloInternet(b.veloInternet),vencimento(b.vencimento) {}

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
    return franquia;
    }


   double posPago::getPrecoMin() {
    return precoMin;
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


    void posPago::debitarInternet (double valor,Data& now){

         if(this->foraDaValidade(now)) {
             throw(Exception("Pendencia de pagamento"));

         } else {

             if(valor<franquia)
                 franquia-=valor;
             else {
                franquia=0;
                veloInternet=veloInternet*reduz;
                throw(Exception("Pacote de dados todos consumidos, internet com velocidade reduzida"));
             }

         }


    }


  void posPago::pagar( double cash, double fatura) {

        if(cash < fatura)
            throw(Erro("Valor insuficiente!"));
        else {
            vencimento.setDia(30);

        }
}


double posPago::getPrecoPacote(){
    return precoPacote;
}
