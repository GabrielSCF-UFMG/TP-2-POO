#ifndef LIGACAO_H
#define LIGACAO_H


#include<iostream>
#include<vector>
#include<cmath>

#include "Plano.h"
#include "LigacaoSimples.h"
#include "LigacaoDados.h"

using namespace std;

class Ligacao{

private:
    Date datahora; //Dia e hora
    double duracao;
    double custo;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;
    Plano plano;

public:

    Ligacao(Date &dataLig,double dur,Plano &p){
        plano = p;
        duracao = dur;
        custo = (p.getVM() * dur)*pow(10,-2);//Em reais
        datahora = dataLig;
    }

    Ligacao(const Ligacao &c){
        plano = c.plano;
        duracao = c.duracao;
        custo = c.custo;
        datahora = c.datahora;
        ligSim = c.ligSim;
        ligDados = c.ligDados;
    }

    virtual void newLigacaoSimples(Date &dataLigacao, double dur, Plano &p, double num){
        cout<<"Realizando a ligacao simples..."<<endl;
        ligSim.push_back(LigacaoSimples(dataLigacao,dur,p,num));
    }

    virtual void newLigacaoDadosDownload(Date &dataLigacao,double dur,Plano &p,double down){
        cout<<"Realizando a ligacao de download..."<<endl;
        ligDados.push_back(LigacaoDados(down,p.getVel(),dataLigacao));
    }

    virtual void newLigacaoDadosUpload(Date &dataLigacao,double dur,Plano &p,int up){
         cout<<"Realizando a ligacao de upload..."<<endl;
        ligDados.push_back(LigacaoDados(up,p.getVel(),dataLigacao));
    }

    double gastosLig(){
         double gasto;
         for(int i = 0;i<ligSim.size();i++){
            gasto += ligSim[i].getCusto();
        }
        return gasto;
    }

    //Gets
    int getDate(){return datahora.getDia();};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};
    int getNumLigacoes(){return ligDados.size()+ligSim.size();};
    Plano &getPlano(){return plano;};
    vector <LigacaoSimples> &getLigsimples(){return ligSim;};
    vector <LigacaoDados> &getLigDados(){return ligDados;};

    //Sets
    void setDate(Date &d){datahora = d;};
    void setDuracao(double dur){duracao = dur;};
    void setCusto(double c){custo = c;};
    //void setLig(int i,Ligacao &l){ligacoes[i] = l;};
    void setLigsimples(int i, LigacaoSimples &ls){ligSim[i] = ls;};
    void setDados(int i, LigacaoDados ld){ligDados[i] = ld;};

    ~Ligacao(){
    datahora.~Date(); //Dia e hora
    duracao = 0;
    custo = 0;
    for(int i = 0;i< ligSim.size();i++){
        ligSim[i].~LigacaoSimples();
    }
    for(int i = 0;i< ligDados.size();i++){
        ligDados[i].~LigacaoDados();
    }
    plano.~Plano();

    }

};

#endif
