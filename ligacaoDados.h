#ifndef LIGACAODADOS_H
#define LIGACAODADOS_H

#include "Ligacao.h"

class ligacaoDados: public Ligacao {

  private:
     double dadosConsumidos;
  public:

      //construtores & destrutor
      ligacaoDados(double dc, Data dia);
      ligacaoDados(ligacaoDados& b);
      ~ligacaoDados();
      //getters
      Data getDia();
      double getCusto();
      double getDadosCon( );
      //set
      void setCusto(double const &c);
      bool isSimples();









};



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

       void ligacaoDados::setCusto(double const &c){

          custo=c;


       }

bool ligacaoDados:: isSimples() {
  return false;




}


#endif // LIGACAODADOS_H


