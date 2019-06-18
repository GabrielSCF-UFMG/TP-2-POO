#include"../Header/Celular.h"


//construtores/destrutores
    Celular::Celular(Plano& p){
        plano=&p;
        srand( (unsigned)time(NULL) );
        for(int i=0 ; i <numeroDeAlgarismos ; i++)
			numero.push_back(rand()%10);


        unsigned semente=unsigned  (rand());
        srand( semente);
        int sorte=rand() %100;
        if(sorte%2==0)
            std::random_shuffle ( numero.begin(),numero.end() );
        if(sorte%3==0)
            std::random_shuffle ( numero.begin(),numero.end() );
        if(sorte%5==0)
            std::random_shuffle ( numero.begin(),numero.end() );
    }

    Celular::Celular(Celular &c) :  plano(c.plano){
        for(int i=0; i<numero.size();i++)
        numero[i]= c.numero[i];
    }

    Celular:: ~Celular(){

        for(int k=0;k<ligacoes.size();k++)
            delete ligacoes[k];
    }


//getters
    vector<int> Celular::getNum(){
        return numero;

    }

    vector<Ligacao*> Celular::getHistorico(){
        return ligacoes;

    }

    void Celular::chamada(double duracao) {

        Data now= Data();
        if(plano->foraDaValidade(now ))
            throw(Exception("Fora da validade!"));

        if(plano->isPrepago()) {

            double custo=plano->getPrecoMin();
        }
    }


    void Celular::newLigacaoD(Data &d,double dur, TipoDados tipo){
        double dc = plano->getVelocidade() * dur * 60; //dados consumidos, dur em minutos vezes 60 p/ segundos
        plano->debitarInternet(dc,d);
        ligacaoDados* l = new ligacaoDados(dc, d, dur, tipo);
        ligacoes.push_back(l);
    }

    void Celular::newLigacaoS(Data &d,double dur, double num){
        double precoMin = plano->getPrecoMin();
        double valor = dur * precoMin;
        if(plano->isPrepago()){
            plano->contabilizar(valor);
        }
        ligacaoSimples* l = new ligacaoSimples(precoMin,d,dur,num);
        ligacoes.push_back(l);
    }

    double Celular::fatura(){
        if(!plano->isPrepago()){
            double valor = 0;
            for(int i=0; i<ligacoes.size(); i++){
                valor += ligacoes[i]->getCusto();
            }
            valor += plano->getPrecoPacote();
            return valor;
        }else{
            throw(Exception("Plano pre pago"));
        }
    }
