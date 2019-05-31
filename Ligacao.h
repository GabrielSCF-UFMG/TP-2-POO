#ifndef LIGACAO_H
#define LIGACAO_H


#include<iostream>
#include<vector>
#include<cmath>

#include "Plano.h"

using namespace std;

class LigacaoDados{

private:
    double Download;
    double Upload;

public:
    LigacaoDados(double dadosD,double dadosU):Download(dadosD),Upload(dadosU){}

    double getDownload(){ return Download;}
    double getUpload(){ return Upload;}

    void interface(){

        cout<<"Download:"<<Download<<endl;
        cout<<"Upload:"<<Upload<<endl;
        cout<<endl;
    }

};

class LigacaoSimples{

private:

    Date datahora;
    double duracao;
    double custo;
    double numTelefone;

public:
    LigacaoSimples(Date &dataLig,double dur,Plano p,double num){
        duracao = dur;
        custo = (p.getVM() * dur)*pow(10,-2);
        datahora = dataLig;
        numTelefone = num;
    };

    int getDateDia(){return datahora.getDia();};
    int getDateHora(){return datahora.getHora();};
    double getNum(){return numTelefone;};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};

    void setNum(double num){numTelefone = num;};

    void interface(){

       cout<<"\nData(dia,hora): "<<getDateDia()<<","<<getDateHora()<<endl;
       cout<<"Duracao: "<<duracao<<endl;
       cout<<"Custo: "<<custo<<" reais!"<<endl;
       cout<<"Numero Telefone: "<<numTelefone<<endl;
       cout<<endl;

    }

};

class Ligacao{

private:
    Date datahora; //Dia e hora
    double duracao;
    double custo;
    //vector <Ligacao> ligacoes;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;
    Plano plano;

public:
    Ligacao(Date &dataLig,double dur,Plano &p){
        plano = p;
        duracao = dur;
        custo = (p.getVM() * dur)*pow(10,-2);
        datahora = dataLig;
    }
    /*
    Ligacao(Date &dataLig,double dur,Plano &p,double num){
        plano = p;
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligSim.push_back(LigacaoSimples(dataLig,dur,p,num));
    }
    Ligacao(Date &dataLig,double dur,Plano &p,double down,double up){
        plano = p;
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligDados.push_back(LigacaoDados(down,up));
    }*/
    Ligacao(const Ligacao &c){
        plano = c.plano;
        duracao = c.duracao;
        custo = c.custo;
        datahora = c.datahora;
        ligSim = c.ligSim;
        ligDados = c.ligDados;
    }

    void newLigacaoSimples(Date &dataLigacao, double dur, Plano p, double num){
        cout<<"Realizando a ligacao..."<<endl;
        //Ligacao nova(dataLigacao,dur,p,num);
        //ligacoes[ligacoes.size()].ligSim.push_back(LigacaoSimples(dataLigacao,dur,p,num));
        ligSim.push_back(LigacaoSimples(dataLigacao,dur,p,num));
    }

    void newLigacaoDados(Date &dataLigacao,double dur,Plano p,double down,double up){
        //Ligacao nova(dataLigacao,dur,p,down,up);
        //ligacoes.push_back(nova);
        ligDados.push_back(LigacaoDados(down,up));
    }


    //Gets
    int getDate(){return datahora.getDia();};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};
    //Ligacao getLig(int i){return ligacoes[i];};
    LigacaoSimples getLigsimples(int i){return ligSim[i];};
    LigacaoDados getDados(int i){return ligDados[i];};

    //Sets
    void setDate(Date &d){datahora = d;};
    void setDuracao(double dur){duracao = dur;};
    void setCusto(double c){custo = c;};
    //void setLig(int i,Ligacao &l){ligacoes[i] = l;};
    void setLigsimples(int i, LigacaoSimples &ls){ligSim[i] = ls;};
    void setDados(int i, LigacaoDados ld){ligDados[i] = ld;};

    void interfaceLigacoes(){

        cout<<"\nLigacoes simples:"<<endl;
        for(int i = 0;i<ligSim.size();i++){
            cout<<i<<":"<<endl;
            ligSim[i].interface();
        }
        cout<<"\nLigacao dados:"<<endl;
        for(int i = 0;i<ligSim.size();i++){
            cout<<i<<":"<<endl;
            ligDados[i].interface();
        }

    }

};

#endif
