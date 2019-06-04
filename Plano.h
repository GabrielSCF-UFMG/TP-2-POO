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
    double credito;
    bool tipo; //true = prePago;
    Date validade;
    vector <PrePago> pre;
    vector <PosPago> pos;
    //PrePago pre;
    //PosPago pos;

public:
    Plano(string planName ="Plano",double valMin = 0,double vel = 0,double fran = 0,double velAlem = 0,bool preOrPos = false,Date val = (0,0,0,0))
       {
        nome = planName;
        valorMinuto = valMin;
        velocidade= vel;
        franquia= fran;
        velocAlem = velAlem;
        tipo = preOrPos;
        validade = val;
        if(tipo == true){
            nome += "PrePago";
            cout<<"Quantos creditos serao incluidos no plano "<<nome<<"?"<<endl;
            cin>>credito;
            PrePago p(credito,val);
            pre.push_back(p);
            //pre = p;
        }else{
            nome += "PosPago";
            PosPago a(val);
            pos.push_back(a);
            //pos  = a;
        }
        }

    string getName(){return nome;}
    double getVM(){return valorMinuto;}
    double getVel(){return velocidade;}
    double getFran(){return franquia;}
    double getVelAlem(){return velocAlem;}
    double getCred(){return credito;}
    bool getTipo(){return tipo;}
    PrePago &getPre(){return pre[pre.size()];}
    PosPago &getPos(){return pos[pos.size()];}

    void setPlano(string pN,double vMin,double vel,double fran,double vAlem){
        nome = pN;
        valorMinuto = vMin;
        velocidade = vel;
        franquia = fran;
        velocAlem = vAlem;
    }

    void setVencimento(const Date &d){
        validade = d;
    }


    void creditosRestantes(){}


};

#endif
