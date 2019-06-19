#ifndef PLANO_H
#define PLANO_H


#include<iostream>

#include "Date.h"
#include "PrePago.h"
#include "PosPago.h"
#include "Exception.h"

using namespace std;

class Plano{

private:
    string nome;
    double valorMinuto;
    double velocidade;
    double franquia;
    double velocAlem;
    double credito;
    bool tipo;
    Date validade;
   // vector <PrePago> pre;
   // vector <PosPago> pos;

public:
    Plano(string planName ="Plano",double valMin = 0,double vel = 0,double fran = 0,double velAlem = 0,bool preOrPos = false,Date val = (0,0,0,0))
       {
        nome = planName;
        valorMinuto = valMin;
        velocidade= vel;
        franquia= fran*10*10*10; //Em megabytes
        velocAlem = velAlem;
        tipo = preOrPos;
        validade = val;
        if(tipo == true){
            nome += " PrePago";
            cout<<"Quantos creditos (em centavos) serao incluidos no plano "<<nome<<"?";
            cin>>credito;
            //PrePago p(credito,val);
            //pre.push_back(p);
        }else{
            nome += " PosPago";
            //PosPago a(val);
            //pos.push_back(a);
        }
        }

    virtual string getNome(){return nome;}
    double getVM(){return valorMinuto;}//centavos
    double getVel(){return velocidade;}//Mbps
    double getFran(){return franquia;}//Mbs
    double getVelAlem(){return velocAlem;}//Kbps
    double getCred(){return credito;}//centavos
    bool getTipo(){return tipo;}
   // PrePago &getPre(){return pre[pre.size()];}
   // PosPago &getPos(){return pos[pos.size()];}
    Date &getValidade(){return validade;}

    bool testaValidade(Date &d){

        if( (validade.getDia() >= d.getDia())&&(validade.getMes() == d.getMes())){
            return false;//Fora da validade
        }else{
            return true;
        }

    }

    void setPlano(string pN,double vMin,double vel,double fran,double vAlem){
        nome = pN;
        valorMinuto = vMin;
        velocidade = vel;
        franquia = fran;
        velocAlem = vAlem;
    }

    int getVencimentoDia(){return validade.getDia();}

    void setVencimento(const Date &d){
        validade = d;
    }

    void setCredito(double cred){ //Acrescenta + cred
        if(tipo == true ){
        credito += cred;
        validade.setAddMes(3);
        }else{
        franquia += cred;
        validade.setAddMes(3);
        }
    }

    void setDecreCreditos(double gasto){
        credito -= gasto;
        if(credito < 0){
            throw Exception("Creditos insuficientes para realizar a ligacao simples");
        }
    }

    void setDecreFran(double gasto){//Gasto em megabytes
        franquia -= gasto;
        if(franquia < 0){
            throw Exception("Creditos insuficientes para realizar a ligacao dados");
        }
    }

    double restanteCreditos(double gasto){return credito-gasto;}

    ~Plano(){
        nome = "--";
        valorMinuto = 0;
        velocidade = 0;
        franquia = 0;
        velocAlem = 0;
        credito = 0;
        tipo = false;
        validade.~Date();
        // for(int i = 0;i< pre.size();i++){
        //     pre[i].~PrePago();
        // }
        // for(int i = 0;i< pos.size();i++){
        //    pos[i].~PosPago();
        // }
    }

};

#endif
