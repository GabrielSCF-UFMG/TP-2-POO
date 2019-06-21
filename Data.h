#ifndef DATA_H

#define DATA_H

#include <ctime>

#include<cmath>
#include<iostream>




using namespace std;





class Data{



private:

    int hora;

    int segundos;

    int dia;

    int minutos;

    int mes;

    int ano;

public:

    Data();
    Data(int dia, int mes, int ano, int hora=0, int segundos=0,int minutos=0) ;
    Data(const Data&b);
    ~Data();
    const int difMinutos(const Data& d);//calcula intervalo de minutos entre duas Datas
    const int difSegundos(const Data& d);//calcula intervalo de segundos entre duas Datas
    void atualizar();
    void setDia (int d);
    int getDia() {return (dia);}
     int getMes() {return (mes);}
    int getAno() {return (ano);}






};

Data::Data(int dia, int mes, int ano, int hora, int segundos,int minutos) :
     dia(dia), hora(hora),mes(mes),ano(ano),minutos(minutos),segundos(segundos) {}

    Data::Data(const Data&b):dia(b.dia), hora(b.hora),mes(b.mes),ano(b.ano),
    minutos(b.minutos),segundos(b.segundos) {}

Data:: Data () {

      time_t timer;
      struct tm *horarioLocal;

      time(&timer); // Obtem informações de data e hora
      horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

       dia= horarioLocal->tm_mday;
       mes = horarioLocal->tm_mon + 1;
       ano = horarioLocal->tm_year + 1900;

        hora = horarioLocal->tm_hour;
        minutos  = horarioLocal->tm_min;
        segundos  = horarioLocal->tm_sec;

}


Data::~Data() {}


const int Data::difMinutos(const Data&d) {
    int dif= abs(minutos-d.minutos);
   return (dif);



 }


 const int Data::difSegundos(const Data&d) {
    int dif= abs(segundos-d.segundos);
   return (dif);



 }


 void Data::atualizar() {

      time_t timer;
      struct tm *horarioLocal;

      time(&timer); // Obtem informações de data e hora
      horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

       dia= horarioLocal->tm_mday;
       mes = horarioLocal->tm_mon + 1;
       ano = horarioLocal->tm_year + 1900;

        hora = horarioLocal->tm_hour;
        minutos  = horarioLocal->tm_min;
        segundos  = horarioLocal->tm_sec;



 }

 void Data::setDia(int d) {

   int aux;

   dia+=d;

   if(dia>30) {
     aux= dia/30;
     if(dia%30!=0)
        dia=dia%30;
     else
        dia=1;
     mes+=aux;


   }

   if(mes>12) {
     aux=mes/12;
     mes=mes%12;

     ano+=aux;


   }


 }










#endif

