#ifndef LIGACAOSIMPLES_H
#define LIGACAOSIMPLES_H

#include<iostream>

using namespace std;

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

    int getDateDia(){return datahora.getDia();};
    int getDateHora(){return datahora.getHora();};
    double getNum(){return numTelefone;};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};

    void setNum(double num){numTelefone = num;};

};


#endif // LIGACAOSIMPLES_H
