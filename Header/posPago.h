#ifndef POSPAGO_H

#define POSPAGO_H

#include "Data.h"
#include "Exeption.h"
#include "Plano.h"


 class posPago: public Plano {

    private:
        string nome;
        double preco;
        double pacoteDeDados;//mb
        double veloInternet;//mb/s
        Data vencimento;
        static double reduz;

     public:

     //construtores

     posPago(string n,double p,double pd, double vel, Data &v): nome(n),preco(p),pacoteDeDados(pd),veloInternet(vel),vencimento(v) {}
     posPago(const posPago &b):nome(b.nome),preco(b.preco),pacoteDeDados(b.pacoteDeDados),veloInternet(b.veloInternet),vencimento(b.vencimento) {}

     //getters
      string getNome(){return nome;}
      double getVelocidade() {return veloInternet;}
      int getDiaVencimento () {return vencimento.getDia();}
      int getMesVencimento() {return vencimento.getMes();}


      //funções de funcionalidade

       bool isPrepago () {return false;}
       double getFran() {return pacoteDeDados;}
       double custoDeChamada() {return preco;}
       bool foraDaValidade(Data& now );
       void quitarInternet (double valor,Data& now);
       void pagar(double cash) ;

      ~posPago(){}


 };

 double posPago::reduz=0.5;


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


#endif // POSPAGO_H

