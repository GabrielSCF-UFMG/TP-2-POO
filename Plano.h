#ifndef PLANO_H
#define PLANO_H


#include<iostream>

#include "Date.h"

using namespace std;

class Plano{

private:
    string nome;
    double valorMinuto;
    double velocidade;
    double franquia;
    double velocAlem;

public:
    Plano(string planName ="Plano",double valMin = 1,double vel = 1,double fran = 1,double velAlem = 1):
        nome(planName),valorMinuto(valMin),velocidade(vel),
        franquia(fran),velocAlem(velAlem){}


    double getVM(){return valorMinuto;};

    void setPlano(string pN,double vMin,double vel,double fran,double vAlem){
        nome = pN;
        valorMinuto = vMin;
        velocidade = vel;
        franquia = fran;
        velocAlem = vAlem;
    }

    void interfacePlano(){

        cout<<"Nome do plano: "<<nome<<endl;
        cout<<"Valor do minuto: RS 0,"<<valorMinuto<<"!"<<endl;
        cout<<"Velocidade da internet: "<<velocidade<<" Mbps!"<<endl;
        cout<<"Franquia: "<<franquia<<"Gb!" <<endl;
        cout<<"Velocidade alem da Franquia: "<<velocAlem<<"Kbps!"<<endl;
        cout<<endl;

    }


};

class PrePado:public Plano,Date{

private:
    double credito;
    Date validade;//Dia
    Plano plano;

public:

    PrePado(double cr,Date val,Plano p){
        credito = cr;
        validade = val;
        plano = p;
    }

    int getVal(){return validade.getDia();}

    double restanteCreditos(double gasto){return credito-gasto;}


    //Vencido?
    bool foraDaValidade(Date now){now.getDia() <= validade.getDia() ? true : false;}

};

class PosPago:public Plano,Date{
private:
    Date vencimento;
public:
    PosPado(Date v){
        vencimento = v;
    }

    int getVencimento(){return vencimento.getDia();}

    bool vencido(Date now){now.getDia() <= vencimento.getDia() ? true : false;}
};


#endif
