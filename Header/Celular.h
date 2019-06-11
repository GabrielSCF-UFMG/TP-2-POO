#ifndef CELULAR_H
#define CELULAR_H


#include<iostream>
#include<vector>
#include "Ligacao.h"
//#include "Cliente.h"

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
        proxNum += proxNum + 2;
    };

    Celular(const Celular &c){
        setNumero(c.numero);
        plano = c.plano;
        ligacoes = c.ligacoes;
        proxNum = c.proxNum;
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
    void newLigacaoSimples(Date &d,double dur,double num){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao
        cout<<"\nDiscando no celular..."<<endl;
        ligacoes[ligacoes.size()].newLigacaoSimples(d,dur,plano,num);
        //ligacoes.newLigacaoSimples(d,dur,cDest.plano,cDest.numero);
    }

    void newLigacaoDadosDownload(Date &dataLigacao,double dur,double down){
        cout<<"Realizando a ligacao de download..."<<endl;
        ligacoes[ligacoes.size()].newLigacaoDadosDownload(dataLigacao,dur,plano,down);
    }

    void newLigacaoDadosUpload(Date &dataLigacao,double dur,double up){
         cout<<"Realizando a ligacao de upload..."<<endl;
        ligacoes[ligacoes.size()].newLigacaoDadosUpload(dataLigacao,dur,plano,up);
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

    ~Celular(){
        numero = 0;
        plano.~Plano();
        for(int i = 0;i< ligacoes.size();i++){
            ligacoes[i].~Ligacao();
        }
        proxNum = 10;
    }

};
//vector <double> Celular::numerosCelular;
int Celular::proxNum = 10;
#endif

