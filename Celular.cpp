#include<iostream>
#include<vector>
#include "Ligacao.cpp"

using namespace std;

class Celular{

private:
    double numero; //Come�a em 0 e incrementa 1 a cada novo numero
    Plano plano;
    vector <Ligacao> ligacoes;
    int static proxNumCelular;

public:

    Celular(double n,Plano &p){
        numero = n;
        plano = p;
        proxNumCelular++;
    };
    Celular(const Celular &c){
        numero = c.numero;
        plano = c.plano;
        ligacoes = c.ligacoes;
    }

    double getNumero(){return numero;}

    double getPlano(){plano.interfacePlano();}

    void setNumero(double num){numero = num;}
    void setPlanoCelular(string pN,double vMin,double vel,double fran,double vAlem){
        plano.setPlano(pN,vMin,vel,fran,vAlem);
    }

    void newLigacaoCelularSimples(Date &d,double dur,Plano &p,double num,int i){//Duracao em minutos, i  indica qual celualr deseja fazer a ligacao
        ligacoes[i].newLigacaoSimples(d,dur,p,num);
    }

    void newLigacaoCelularDados(Data &d,double dur,Plano &p,double down,double up,int i){
        ligacoes[i].newLigacaoDados(d,dur,p,down,up);
    }

    void interfaceCelulares(int i){

        cout<<"Numero:"<<numero<<endl;
        cout<<"Plano:"<<endl;plano.interfacePlano();
        cout<<"Lista de ligacoes:"<<endl;ligacoes[i].interfaceLigacoes();
        cout<<"Proximo numero"<<proxNumCelular<<endl;
        cout<<endl;
    }

    int num(){return proxNumCelular;};

};
int Celular::proxNumCelular = 0;

