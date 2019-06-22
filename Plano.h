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

public:
    Plano(int cred = 0,string planName ="Plano",double valMin = 0,double vel = 0,double fran = 0,double velAlem = 0,bool preOrPos = false,Date val = (0,0,0,0))
       {
        credito = cred;
        nome = planName;
        valorMinuto = valMin;
        velocidade= vel;
        franquia= fran*10*10*10; //Em megabytes
        velocAlem = velAlem;
        tipo = preOrPos;
        validade = val;
        if(tipo == true){
            nome += " PrePago";
        }else{
            nome += " PosPago";
        }

        }

    //Gets
    virtual string getNome(){return nome;}
    double getVM(){return valorMinuto;}//centavos
    double getVel(){return velocidade;}//Mbps
    double getFran(){return franquia;}//Mbs
    double getVelAlem(){return velocAlem;}//Kbps
    double getCred(){return credito;}//centavos
    bool getTipo(){return tipo;}
    Date &getValidade(){return validade;}
    int getVencimentoDia(){return validade.getDia();}


    //Sets
    void setPlano(string pN,double vMin,double vel,double fran,double vAlem){
        nome = pN;
        valorMinuto = vMin;
        velocidade = vel;
        franquia = fran;
        velocAlem = vAlem;
    }

    void setTipo(bool tipo) {
        Plano::tipo = tipo;
    }

    void setNome(const string &nome) {
        Plano::nome = nome;
    }

    void setValorMinuto(double valorMinuto) {
        Plano::valorMinuto = valorMinuto;
    }

    void setVelocidade(double velocidade) {
        Plano::velocidade = velocidade;
    }

    void setFranquia(double franquia) {

        Plano::franquia = franquia;
    }

    void setVelocAlem(double velocAlem) {
        Plano::velocAlem = velocAlem;
    }

    void setCredito(double cred) {

        if(tipo == true) {

            credito += cred;
        }else{
            franquia += cred;
        }
        if(credito < 0){
            credito += cred;
            Exception("Creditos negativos!");
        }
        if(franquia < 0){
            franquia += cred;
            Exception("Creditos negativos!");
        }
    }

    void setValidade(const Date &validade) {
        Plano::validade = validade;
    }

    bool testaValidade(Date &d){

        if( (validade.getDia() >= d.getDia())&&(validade.getMes() == d.getMes())){
            return false;//Fora da validade
        }else{
            return true;
        }

    }

    void addMesVencimento(int mes){
        validade.setAddMes(mes);
    }

    ~Plano(){
        nome = "--";
        valorMinuto = 0;
        velocidade = 0;
        franquia = 0;
        velocAlem = 0;
        credito = 0;
        tipo = false;
        validade.~Date();

    }

};

#endif
