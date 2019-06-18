#include"../Header/LigacaoDados.h"

 //construtores & destrutor
    ligacaoDados::ligacaoDados(double dc, Data dia,double dur, TipoDados tipo){
        this->dadosConsumidos = dc;
        this->dia=dia;
        this->tipo = tipo;
        this->custo = 0;
    }

    ligacaoDados::ligacaoDados(const ligacaoDados &b){
        this->dadosConsumidos = b.dadosConsumidos;
        this->dia=b.dia;
        this->tipo = b.tipo;
        this->custo = 0;
    }

    ligacaoDados::~ligacaoDados(){}

//getters
    Data ligacaoDados::getDia() {
        return dia;
    }

    double ligacaoDados::getCusto() {
		return custo;
    }

    double ligacaoDados::getDadosCon() {
        return dadosConsumidos;
	}


//set

    // void ligacaoDados::setCusto(double &c){
    //     custo=c;
    // }

