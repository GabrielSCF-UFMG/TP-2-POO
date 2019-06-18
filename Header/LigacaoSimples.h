#ifndef LIGACAOSIMPLES_H
#define LIGACAOSIMPLES_H

#include"Ligacao.h"

class ligacaoSimples: public Ligacao {

    private:
        double duracao;
        double NumTelefone;
    public:

        //construtores & destrutor
        ligacaoSimples(double precoMin, Data dia, double dur, double num);
        ligacaoSimples(ligacaoSimples& l);
        ~ligacaoSimples();

        //getters
        Data getDia();
        double getCusto();
        double getDuracao();
        //double getDuracaoMin( );

        //setters
        void setDuracao(double &dur);
        //void setDuracaoMin(double &m);









};



#endif // LIGACAOSIMPLES_H
