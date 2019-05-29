#include<iostream>

#include "Celular.cpp"
#include "PrePago.cpp"
#include "PosPago.cpp"

using namespace std;

class Plano{

private:
    string nome;
    double valorMinuto;
    double velocidade;
    double franquia;
    double velocAlem;
public:
    Plano(string planName,double valMin,double vel,double fran,double velAlem):
        nome(planName),valorMinuto(valMin),velocidade(vel),
        franquia(fran),velocAlem(velAlem){}

    void setPlano(string pN,double vMin,double vel,double fran,double vAlem){
        nome = pN;
        valorMinuto = vMin;
        velocidade = vel;
        franquia = fran;
        velocAlem = vAlem;
    }

    void interfacePlano(){

        cout<<"Nome do plano:"<<nome<<endl;
        cout<<"Valor do minuto:"<<valorMinuto<<endl;
        cout<<"Velocidade da internet:"<<velocidade<<endl;
        cout<<"Franquia:"<<franquia<<endl;
        cout<<"Velocidade além da Franquia:"<<velocAlem<<endl;
        cout<<endl;

    }


};

class PrePado:public Plano{

private:
    double credito;
    Date validade;
public:

    PrePado(double cr,int valDia):credito(cr),validade = Date(valDia){}

    void val(){return validade.dia;}

    double restanteCreditos(){
        double auxGastos = 0.0;

        for (i = 0;i < ligaçoe.size();i++){
            auxGastos += Celular.ligaçoes[i].cost;
        }
        double auxCredito = credito;

        return auxCredito-auxGastos;
    }

    bool foraDaValidade(Date now){//Vencido?
        if now.dia <= validade.dia {
            return false;
        }else
            return true;
    }

};

class PosPago:public Plano{
private:
    Date vencimento;
public:
    PrePado(int venDia):vencimento = Date(venDia){}

    void getVencimento(){return vencimento.dia;}
    bool vencido(Date now){
        if now.dia <= validade.dia {
            return false;
        }else
            return true;
    }
};
