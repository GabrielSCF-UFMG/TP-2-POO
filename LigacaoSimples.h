#ifndef LIGACAOSIMPLES_H
#define LIGACAOSIMPLES_H

#include<iostream>

#include "Date.h"

using namespace std;

class Date;

class LigacaoSimples{

private:

    Date datahora;
    double duracao;
    double custo;
    double numTelefone;

public:
    LigacaoSimples(Date &dataLig,double dur,Plano &p,double num){
        duracao = dur;
        custo = (p.getVM() * dur)*pow(10,-2);
        datahora = dataLig;
        numTelefone = num;
    };

    Date &getDate(){return datahora;};
    int getDia(){return datahora.getDia();};
    int getHora(){return datahora.getHora();};
    int getMes(){return datahora.getMes();};
    int getAno(){return datahora.getAno();};
    double getNum(){return numTelefone;};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};

    void setNum(double num){numTelefone = num;};

    ~LigacaoSimples(){

        datahora.~Date();
        duracao = 0;
        custo = 0;
        numTelefone = 0;

    }

};


#endif // LIGACAOSIMPLES_H
