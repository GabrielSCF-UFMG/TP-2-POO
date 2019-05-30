#include<iostream>
#include<vector>
#include "Ligacao.cpp"

using namespace std;

class Celular{

private:
    double numero; //Começa em 0 e incrementa 1 a cada novo numero
    Plano plano;
    vector <Ligacao> ligacoes;
    int static proxNumCelular;

public:

    Celular(double n,Plano p){
        numero = n;
        plano = p;
        proxNumCelular++;
    };
    Celular(const Celular &c){
        numero = c.numero;
        plano = c.plano;
    }

    double getNumero(){return numero;}

    double getPlano(){plano.interfacePlano();}

    void setNumero(double num){numero = num;}
    void setPlanoCelular(string pN,double vMin,double vel,double fran,double vAlem){
        plano.setPlano(pN,vMin,vel,fran,vAlem);
    }

    void newLigacaoCelular(Date &d,double dur,Plano &p,double num){//Duracao em minutos
        newLigacaoSimples(d,dur,p,num,ligacoes);
    }

    void interfaceCelulares(){

        cout<<"Numero:"<<numero<<endl;
        cout<<"Plano:"<<plano.interfacePlano()<<endl;
        cout<<"Lista de ligacoes:"<<ligacoes.interfaceLigacoes()<<endl;
        cout<<"Proximo numero"<<proxNumCelular<<endl;
        cout<<endl;
    }

};
int Celular::proxNumCelular = 0

