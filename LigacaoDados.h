#ifndef LIGACAODADOS_H
#define LIGACAODADOS_H

#include<iostream>

#include "Date.h"

using namespace std;

class LigacaoDados{

private:

    Date datahora;
    double Download;
    int Upload;
    double velocidade;

public:
    LigacaoDados(double dadosD,double vel,Date &d):Download(dadosD),velocidade(vel),datahora(d){}
    LigacaoDados(int dadosU,double vel,Date &d):Upload(dadosU),velocidade(vel),datahora(d){}


    Date &getDate(){return datahora;};
    int getDia(){return datahora.getDia();};
    int getHora(){return datahora.getHora();};
    int getMes(){return datahora.getMes();};
    int getAno(){return datahora.getAno();};
    double getDownload(){ return Download;}
    double getUpload(){ return Upload;}
    double getVelDownload(){return velocidade;}
    double getVelUpload(){return velocidade/10;}

    ~LigacaoDados(){

        datahora.~Date();
        Download = 0;
        Upload = 0;
        velocidade = 0;

    }

};


#endif // LIGACAODADOS_H
