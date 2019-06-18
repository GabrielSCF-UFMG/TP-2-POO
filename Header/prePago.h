#ifndef PREPAGO_H

#define PREPAGO_H

#include "Data.h"
#include "Plano.h"
#include "Erro.h"
#include "Exception.h"


class prePago: public Plano {

    private:
        string nome;
        double precoMin;
        double veloInternet;//mb/s
        double franquia;//mb
        double reduz=0.5;

        double credito;
        double precoMb;
        int tempoValidade;
        Data validade;//Dia

    public:
        //construtores
        prePago(string nome, double cr,Data val, double pMb, double pm,unsigned int t);
        prePago(const prePago &p) ;
        ~prePago() ;

        //getters
        int getVal();
        int getValMes() ;
        double getFran() ;
        double getCredito() ;
        string getNome() ;
        double getVelocidade() ;
        double getPrecoMin() ;
        double getPrecoPacote(){int x=0; return x;};


        //setters
        void setCredito(double c, Data&deposito) ;
        void setFranquia(double quantia) ;

        //funções de funcionalidade
        void contabilizar(double valor); //migué
        void debitarCredito (double valor);
        void debitarInternet (double valor,Data& now);
        bool foraDaValidade(Data& now );
        bool isPrepago() ;
        double custoDeInternet () ;

};


#endif // PREPAGO_H
