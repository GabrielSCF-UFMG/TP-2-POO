#ifndef POSPAGO_H
#define POSPAGO_H

#include<iostream>

#include "Date.h"

using namespace std;

class PosPago{

private:
    Date vencimento;
public:
    PosPago(Date v){
        vencimento = v;
    }
    PosPago(const PosPago &p){
        vencimento = p.vencimento;
    }

    int getVencimento(){return vencimento.getDia();}

    bool vencido(Date now){now.getDia() <= vencimento.getDia() ? true : false;}

    ~PosPago(){

    vencimento.~Date();

    }

};

#endif // POSPAGO_H
