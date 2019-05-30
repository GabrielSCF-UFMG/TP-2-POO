#ifndef DATE_H
#define DATE_H

#include<iostream>

using namespace std;


class Date{

private:
    int hora;
    int dia;
    int mes;
    int ano;
public:
    Date(int h = 0,int d = 0,int m = 0,int a = 0):hora(h),dia(d),mes(m),ano(a){};
    Date(const Date &d){dia = d.dia;mes = d.mes;ano = d.ano;};

    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAno(){return ano;};

    void setDia(int d){dia = d;};
    void setMes(int m){mes = m;};
    void setAno(int a){ano = a;};

    void interface(){

        cout<<"\n-----DATA-----"<<endl;

        cout<<"DIA:"<<dia<<endl;
        cout<<"MES:"<<mes<<endl;
        cout<<"ANO:"<<ano<<endl;

    }
};


#endif
