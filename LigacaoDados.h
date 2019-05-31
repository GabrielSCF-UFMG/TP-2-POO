#ifndef LIGACAODADOS_H
#define LIGACAODADOS_H

#include<iostream>

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


#endif // LIGACAODADOS_H
