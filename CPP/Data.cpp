#include "../Header/Data.h"


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
     dia=dia%30;
     mes+=aux;


   }

   if(mes>12) {
     aux=mes/12;
     mes=mes%12;

     ano+=aux;


   }


 }




