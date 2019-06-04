#ifndef CELULAR_H
#define CELULAR_H


#include<iostream>
#include<vector>
#include "Ligacao.h"
#include "Cliente.h"

using namespace std;

class Celular{

private:
    double numero; //Começa em 0 e incrementa 1 a cada novo numero
    Plano plano;
    vector <Ligacao> ligacoes;
    int static proxNum;

public:

    Celular(Plano &p){
        numero = proxNum;
        plano = p;
        proxNum += proxNum/10;
    };

    Celular(const Celular &c){
        setNumero(c.numero);
        plano = c.plano;
        ligacoes = c.ligacoes;
        proxNum -= proxNum/10;
    }

    double getNumero(){return numero;}

    Plano &getPlano(){return plano;}

    vector <Ligacao> &getLigacoes(){return ligacoes;}

    void setNumero(double num){
        numero = num;
    }

    void setPlanoCelular(string pN,double vMin,double vel,double fran,double vAlem){
        plano.setPlano(pN,vMin,vel,fran,vAlem);
    }

                            //d = Dia e hora
    virtual void newLigacaoSimples(Date &d,double dur,Celular &cDest){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao
        cout<<"\nDiscando no celular..."<<endl;
        ligacoes[ligacoes.size()].newLigacaoSimples(d,dur,cDest.plano,cDest.numero);
        //ligacoes.newLigacaoSimples(d,dur,cDest.plano,cDest.numero);
    }

    virtual void newLigacaoDados(Date &d,double dur,double down,double up){//Plano do proprio celular
        ligacoes[ligacoes.size()].newLigacaoDados(d,dur,this->plano,down,up);
        //ligacoes.newLigacaoDados(d,dur,this->plano,down,up);
    }

    void IncluirLigacao(const Ligacao &l){
        ligacoes.push_back(l);
    }

    void acrecentarCreditos(double nCreditos){
        if(plano.getTipo() == true){
            this->plano.getPre().setCredito(nCreditos);//Acrescenta 'nCreditos' ao celular;
        }
        double gasto = 0;
        for (int i = 0;i <ligacoes.size();i++){
            gasto += ligacoes[i].gastosLig();
        }
            cout<<"Creditos disponiveis:"<<plano.getPre().restanteCreditos(gasto)<<endl;
    }


};
//vector <double> Celular::numerosCelular;
int Celular::proxNum = 100001;

#endif

