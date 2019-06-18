#ifndef POSPAGO_H

#define POSPAGO_H

#include "Data.h"
#include "Exception.h"
#include "Erro.h"
#include "Plano.h"


class posPago: public Plano {

private:
    string nome;
    double precoMin;
    double veloInternet;//mb/s
    double franquia;//mb
    double reduz=0.5;

    double precoPacote;
    Data vencimento;

public:

    //construtores/destrutores
    posPago(string n,double pm,double pp,double pd, double vel, Data &v);
    posPago(const posPago &b);
    ~posPago();

    //getters
    string getNome();
    double getFran() ;
    double getVelocidade() ;
    int getDiaVencimento () ;
    int getMesVencimento() ;
    double getPrecoMin() ;
    double getPrecoPacote() ;


    //funções de funcionalidade
    bool isPrepago () ;
    bool foraDaValidade(Data& now );
    void debitarInternet (double valor,Data& now);
    void pagar(double cash,double fatura) ;
    void contabilizar(double valor){};

};




#endif // POSPAGO_H

