#include<iostream>

#include "Date.cpp"


using namespace std;

class PrePado:public Date{

private:
    double credito;
    Date validade;
public:

    PrePado(double cr,int valDia):credito(cr){
        Date d(0,valDia,0,0,0);
        validade = d;
    }

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
