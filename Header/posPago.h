#ifndef POSPAGO_H

#define POSPAGO_H

#include "Data.h"
#include "Exception.h"
#include"Erro.h"
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

     //construtores/destrutores

     posPago(string n,double p,double pd, double vel, Data &v);
     posPago(const posPago &b);
     ~posPago();
     //getters
      string getNome();
      double getVelocidade() ;
      int getDiaVencimento () ;
      int getMesVencimento() ;


      //funções de funcionalidade

       bool isPrepago () ;
       double getFran() ;
       double custoDeChamada() ;
       bool foraDaValidade(Data& now );
       void quitarInternet (double valor,Data& now);
       void pagar(double cash) ;




 };

 double posPago::reduz=0.5;







#endif // POSPAGO_H

