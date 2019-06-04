#ifndef PREPAGO_H
#define PREPAGO_H

#include<iostream>

#include "Date.h"

using namespace std;

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

};


#endif // PREPAGO_H
