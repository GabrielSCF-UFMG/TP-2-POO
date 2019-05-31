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
    //static vector <double> numerosCelular;
    int static numDeCelulares;

public:

    Celular(double n,Plano &p){
        numero = n;
        plano = p;
        numDeCelulares++;
    };
    Celular(const Celular &c){
        setNumero(c.numero);
        plano = c.plano;
        ligacoes = c.ligacoes;
        numDeCelulares--;
    }

    double getNumero(){return numero;}

    double getPlano(){plano.interfacePlano();}

    void setNumero(double num){
        numero = num;
    }

    void setPlanoCelular(string pN,double vMin,double vel,double fran,double vAlem){
        plano.setPlano(pN,vMin,vel,fran,vAlem);
    }
                            //d = Dia e hora
    virtual void newLigacaoSimples(Date &d,double dur,Celular cDest){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao
        cout<<"\nDiscando no celular..."<<endl;
        ligacoes[ligacoes.size()].newLigacaoSimples(d,dur,cDest.plano,cDest.numero);
    }

    virtual void newLigacaoDados(Date &d,double dur,double down,double up){//Plano do proprio celular
        ligacoes[ligacoes.size()].newLigacaoDados(d,dur,this->plano,down,up);
    }

    void interfaceCelulares(){
        cout<<"\nNumero do celular:"<<numero<<endl;
        plano.interfacePlano();
        if(ligacoes.size() == 0){
            cout<<"---O celular nao tem nenhum ligacao---"<<endl;
        }else{
        for(int i = 0;i< ligacoes.size();i++){
        cout<<"-----Interface da Ligacao "<<i<<"-----"<<endl;
        ligacoes[i].interfaceLigacoes();
        }
        cout<<endl;
        }
    }


};
//vector <double> Celular::numerosCelular;
int Celular::numDeCelulares = 0;

#endif

