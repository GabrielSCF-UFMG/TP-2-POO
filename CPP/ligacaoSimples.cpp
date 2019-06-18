#include"../Header/LigacaoSimples.h"


//construtores & destrutor
	ligacaoSimples::ligacaoSimples(double precoMin, Data dia, double dur, double num){
        this->custo = dur * precoMin;
		this->dia=dia;
        this->duracao = dur;
		this->NumTelefone = num;
	}

	ligacaoSimples::ligacaoSimples(ligacaoSimples& l){
		this->dia = l.dia;
        this->custo = l.custo;
        this->duracao = l.duracao;
		this->NumTelefone = l.NumTelefone;


	}
	ligacaoSimples::~ligacaoSimples(){}



//getters
	Data ligacaoSimples::getDia(){
        return dia;
    }

	double ligacaoSimples::getCusto(){
		return custo;
    }

    double ligacaoSimples:: getDuracao(){
        return duracao;
    }

	// double ligacaoSimples:: getDuracaoSeg(){

	// 	return duracaoSEG;
	// }
	// double ligacaoSimples:: getDuracaoMin(){

	// 	return duracaoMIN;

	// }
