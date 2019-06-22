#ifndef CELULAR_H
#define CELULAR_H

#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

#include "Ligacao.h"
#include "Cliente.h"



using namespace std;

class Celular{

private:
    int numero;
    Plano plano;
    vector <Ligacao> ligacoes;
    static int prox;
    double creditos;
    double franquia;

public:

    Celular(Plano &p){

    this->plano = p;

    creditos = plano.getCred();
    franquia = plano.getFran();

    numero = prox;

    prox = aleatorioNum();


    };

    int aleatorioNum() {

        srand((unsigned)time(0)); //para gerar números aleatórios reais.
        int maior;
        maior = 999999999;
        int menor;
        menor = 980000001;
        int aleatorio = rand()%(maior-menor+1) + menor;

        return  aleatorio;

    }

    Celular(const Celular &c){

        numero = c.numero;
        plano = c.plano;
        ligacoes = c.ligacoes;

    }

    double getFranquia() const;

    int getNumero(){

        return numero;

    }

    double getCreditos(){
        return creditos;
    }

    Plano &getPlano(){return plano;}

    vector <Ligacao> &getLigacoes(){return ligacoes;}

    void setNumero(int newNum){

        numero = newNum;
    }

    void setPlanoCelular(Plano &newP){
        plano = newP;
    }

                            //d = Dia e hora
    void newLigacaoSimples(Date &dataLigacao,double dur,double num){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao

        Ligacao l(dataLigacao,dur,this->plano);
        ligacoes.push_back(l);


        LigacaoSimples ls(dataLigacao,dur,this->plano,num);
        ligacoes[ligacoes.size()-1].newLigacaoSimples(ls);
    }

    void newLigacaoDadosDownload(Date &dataLigacao,double dur,double down){

        Ligacao l(dataLigacao,dur,this->plano);
        ligacoes.push_back(l);

        LigacaoDados ldd(down,this->plano.getVel(),dataLigacao);
        ligacoes[ligacoes.size()-1].newLigacaoDadosDownload(ldd);
    }

    void newLigacaoDadosUpload(Date &dataLigacao,double dur,double up){

        Ligacao l(dataLigacao,dur,this->plano);
        ligacoes.push_back(l);

        LigacaoDados ldu(up,this->plano.getVel(),dataLigacao);
        ligacoes[ligacoes.size()-1].newLigacaoDadosUpload(ldu);
    }

    void IncluirLigacao(const Ligacao &l){
        ligacoes.push_back(l);
    }

    void acrecentarCreditos(double nCreditos){

        creditos += nCreditos;

    }

    void setCreditos(double cred){ //Acrescenta + cred
        if(plano.getTipo() == true ){
        creditos += cred;
        plano.addMesVencimento(3);
        }else{
        franquia += cred;
        plano.addMesVencimento(3);
        }
    }

    double restanteCreditos(double gasto){return creditos-gasto;}

    ~Celular(){

        plano.~Plano();
        for(unsigned int i = 0;i< ligacoes.size();i++){
            ligacoes[i].~Ligacao();
        }

    }

};
int Celular::prox = 980000000;



#endif

