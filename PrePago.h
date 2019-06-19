#ifndef PREPAGO_H
#define PREPAGO_H

#include<iostream>

#include "Date.h"

class Date;

using namespace std;

class Date;

class PrePago{

private:
    double credito;
    Date validade;//Dia

public:

    PrePago(double cr,Date val){
        credito = cr;
        validade = val;
    }
    PrePago(const PrePago &p){
        credito = p.credito;
        validade = p.validade;
    }

    int getVal(){return validade.getDia();}
    void setCredito(double c){credito += c;}

    double restanteCreditos(double gasto){return credito-gasto;}


    //Vencido?
    bool foraDaValidade(Date now){now.getDia() <= validade.getDia() ? true : false;}

    ~PrePago(){

        credito = 0;
        validade.~Date();

    }

};


#endif // PREPAGO_H
