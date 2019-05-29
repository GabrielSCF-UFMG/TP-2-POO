#include<iostream>
#include "Date.cpp"

using namespace std;

class PosPago:public Date{
private:
    Date vencimento;
public:
    PrePado(int venDia):{
        Date d(0,venDia,0,0);
        vencimento = d;
    }

    void getVencimento(){return vencimento.dia;}
    bool vencido(Date now){
        if now.dia <= validade.dia {
            return false;
        }else
            return true;
    }
};
