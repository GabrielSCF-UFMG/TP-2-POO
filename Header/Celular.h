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
    double creditos;
    double franquia;

public:
     //construtores/destrutores
    Celular(Plano& p, double c, double f);
    Celular(Celular &c);
    ~Celular();

    //getters
    vector<int> getNum();
    vector<Ligacao*> getHistorico();

    //demais funcoes

    void chamada(double duracao);



};

int Celular::numeroDeAlgarismos=8;

#endif

