#include"../Header/LigacaoDados.h"

 //construtores & destrutor
      ligacaoDados::ligacaoDados(double dc, Data dia):  dadosConsumidos(dc) {this->dia=dia;}

      ligacaoDados::ligacaoDados(ligacaoDados& b):dadosConsumidos(b.dadosConsumidos){this->dia=b.dia;}

      ligacaoDados::~ligacaoDados(){}

       //getters
     Data ligacaoDados::getDia() {

        return dia;


      }

      double ligacaoDados::getCusto() {
         return custo;

      }

      double ligacaoDados::getDadosCon() {
        return dadosConsumidos;
      }


      //set

       void ligacaoDados::setCusto(double &c){

          custo=c;


       }

