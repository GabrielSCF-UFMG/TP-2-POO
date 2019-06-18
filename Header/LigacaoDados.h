#ifndef LIGACAODADOS_H
#define LIGACAODADOS_H

#include "Ligacao.h"

enum TipoDados{down,up};

class ligacaoDados: public Ligacao {

    private:
        double dadosConsumidos;
        TipoDados tipo;

    public:
        //construtores & destrutor
        ligacaoDados(double dc, Data dia,double dur, TipoDados tipo);
        ligacaoDados(const ligacaoDados &b);
        ~ligacaoDados();

        //getters
        Data getDia();
        double getCusto();
        double getDadosCon();

        //set

        //void setCusto(double &c);









};

#endif // LIGACAODADOS_H

