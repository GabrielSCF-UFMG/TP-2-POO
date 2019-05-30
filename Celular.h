#ifndef CELULAR_H
#define CELULAR_H


#include<iostream>
#include<vector>
#include "Ligacao.h"

using namespace std;

class Celular{

private:
    double numero; //Começa em 0 e incrementa 1 a cada novo numero
    Plano plano;
    vector <Ligacao> ligacoes;

public:

    Celular(double n,Plano &p){
        numero = n;
        plano = p;
        
    };
    Celular(const Celular &c){
        numero = c.numero;
        plano = c.plano;
        ligacoes = c.ligacoes;
    }

    double getNumero(){return numero;}

    double getPlano(){plano.interfacePlano();}

    void setNumero(double num){numero = num;}
    void setPlanoCelular(string pN,double vMin,double vel,double fran,double vAlem){
        plano.setPlano(pN,vMin,vel,fran,vAlem);
    }

    void newLigacaoCelularSimples(Date &d,double dur,Plano &p,double num,int i){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao
        ligacoes[i].newLigacaoSimples(d,dur,p,num);
    }

    void newLigacaoCelularDados(Date &d,double dur,Plano &p,double down,double up,int i){
        ligacoes[i].newLigacaoDados(d,dur,p,down,up);
    }

    void interfaceCelulares(int i){

        cout<<"Numero:"<<numero<<endl;
        cout<<"Plano:"<<endl;plano.interfacePlano();
        cout<<"Lista de ligacoes:"<<endl;ligacoes[i].interfaceLigacoes();
        cout<<endl;
    }


};


#endif

