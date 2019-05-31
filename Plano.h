#ifndef PLANO_H
#define PLANO_H


#include<iostream>

#include "Date.h"
#include "PrePago.h"
#include "PosPago.h"

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

#endif
