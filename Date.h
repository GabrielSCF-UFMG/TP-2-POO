#ifndef DATE_H
#define DATE_H

#include<iostream>
//#include "Exception.h"

using namespace std;


class Date{

private:
    int hora;
    int dia;
    int mes;
    int ano;
public:
    Date(int h = 0,int d = 0,int m = 0,int a = 0):hora(h),dia(d),mes(m),ano(a){
        if(ano > 2019){
           ano -= 1;//throw Exception("O ano da data nao pode ser alem de 2019!");
        }

    };
    Date(const Date &d){dia = d.dia;mes = d.mes;ano = d.ano;};

    void normaliza(){

    if (hora > 24){
        int auxH = hora;
        int auxD = auxH/24;
        hora = auxH%24;
        setAddDia(auxD);
    }

    if (dia > 30){
        int auxD = dia;
        int auxM = auxD/30;
        dia = auxD%30;
        setAddMes(auxM);
    }

    if(mes > 12){
        int auxM = mes;
        int auxA = auxM/12;
        mes = auxM%12;
        setAddAno(auxA);
    }

    }

    virtual int getHora(){return hora;};
    virtual int getDia(){return dia;};
    virtual int getMes(){return mes;};
    virtual int getAno(){return ano;};

    void setAddDia(int d){dia += d; normaliza();};
    void setAddMes(int m){mes += m; normaliza();};
    void setAddAno(int a){ano += a; normaliza();};

    bool operator<(Date &d){

        if((dia < d.dia)&&(mes < d.mes)){
            return true;
        }else if(mes < d.mes){
            return true;
        }else{
            return false;
        }
    }

    bool operator==(Date &d){

        if((dia = d.dia)&&(mes = d.mes)&&(ano = d.ano)){
            return true;
        }else{
            return false;
        }

    }

    ~Date(){

        hora = 0;
        dia = 0;
        mes = 0;
        ano = 0;

    }
};


#endif
