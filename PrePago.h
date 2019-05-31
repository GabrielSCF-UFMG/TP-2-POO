#ifndef PREPAGO_H
#define PREPAGO_H

#include<iostream>

#include "Date.h"

using namespace std;

class PrePado{

private:
    double credito;
    Date validade;//Dia

public:

    PrePado(double cr,Date val){
        credito = cr;
        validade = val;
    }

    int getVal(){return validade.getDia();}

    double restanteCreditos(double gasto){return credito-gasto;}


    //Vencido?
    bool foraDaValidade(Date now){now.getDia() <= validade.getDia() ? true : false;}

};


#endif // PREPAGO_H
