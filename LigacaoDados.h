#ifndef LIGACAODADOS_H
#define LIGACAODADOS_H

#include<iostream>

using namespace std;

class LigacaoDados{

private:

    double Download; //Vel do plano
    double Upload; //Vel do plano/10
    double velocidade;

public:
    LigacaoDados(double dadosD,double dadosU,double vel):Download(dadosD),Upload(dadosU),velocidade(vel){}

    double getDownload(){ return Download;}
    double getUpload(){ return Upload;}
    double getVelDownload(){return velocidade;}
    double getVelUpload(){return velocidade/10;}

};


#endif // LIGACAODADOS_H
