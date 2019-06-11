#ifndef PREPAGO_H

#define PREPAGO_H

#include "Data.h"
#include "Plano.h"
#include"Erro.h"


class prePago: public Plano {

    private:
         string nome;
         double credito;
         double precoMin;
         double franquia;
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
       //setters
         void setCredito(double c, Data&deposito) ;
         void setFranquia(double quantia) ;
       //funções de funcionalidade
         void quitarCredito (double valor);
         bool foraDaValidade(Data now );
         bool isPrepago() ;
         double custoDeChamada () ;
         double custoDeInternet () ;







};





#endif // PREPAGO_H
