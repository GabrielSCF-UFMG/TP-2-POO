#ifndef DATA_H
#define DATA_H

#include <ctime>
#include<cmath>
#include<iostream>

using namespace std;

class Data{
    private:
        int segundos;
        int minutos;
        int hora;
        int dia;
        int mes;
        int ano;

    public:

        Data();
        Data(int dia, int mes, int ano, int hora=0, int segundos=0,int minutos=0) : dia(dia),mes(mes),ano(ano), hora(hora),segundos(segundos),minutos(minutos){}
        Data(const Data&b):dia(b.dia), hora(b.hora),mes(b.mes),ano(b.ano),minutos(b.minutos),segundos(b.segundos) {}
        ~Data();
        const int difMinutos(const Data& d);//calcula intervalo de minutos entre duas Datas
        const int difSegundos(const Data& d);//calcula intervalo de segundos entre duas Datas
        void atualizar();
        void setDia (int d);
        int getDia() {return (dia);}
        int getMes() {return (mes);}
        int getAno() {return (ano);}


};


#endif
