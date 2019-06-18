#ifndef PLANO_H
#define PLANO_H

#include <string>

#include "Data.h"


class Plano {
    public:
        //getters
        virtual string getNome()=0;
        virtual double getFran()=0;
        virtual double getPrecoMin()= 0;
        virtual double getVelocidade()=0;
        virtual double getPrecoPacote()=0;

        //outras funcoes
        virtual void contabilizar(double valor)=0;
        virtual void debitarInternet(double valor,Data& now)=0;
        virtual bool foraDaValidade(Data& now)=0;
        virtual bool isPrepago ()=0;
//        Plano(string n, double pMin, double vel, double f): nome(n), precoMin(pMin), veloInternet(vel), franquia(f){};
//        virtual ~Plano(){};

};



#endif
