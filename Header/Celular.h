#ifndef CELULAR_H
#define CELULAR_H


#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
#include "Ligacao.h"
#include"LigacaoSimples.h"
#include"LigacaoDados.h"
#include"Plano.h"
#include"prePago.h"
#include"posPago.h"


using namespace std;

class Celular{

private:
    vector<int> numero; //Começa em 0 e incrementa 1 a cada novo numero
    Plano* plano;
    vector <Ligacao*> ligacoes;
    static int numeroDeAlgarismos;

public:
     //construtores/destrutores
    Celular(Plano& p);
    Celular(Celular &c);
    ~Celular();

    //getters
    vector<int> getNum();
    vector<Ligacao*> getHistorico();

    //demais funcoes
    void newLigacaoS(Data &d,double dur, double num);
    void newLigacaoD(Data &d,double dur, TipoDados tipo);
    void chamada(double duracao);
    double fatura();



};

int Celular::numeroDeAlgarismos=8;

#endif

