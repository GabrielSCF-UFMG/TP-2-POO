#ifndef LIGACAOSIMPLES_H

#define LIGACAOSIMPLES_H

#include"Ligacao.h"

class ligacaoSimples: public Ligacao {

  private:
     double duracaoMIN, duracaoSEG;
  public:

      //construtores & destrutor
      ligacaoSimples(double c, Data dia,double dm=0,double ds=0);
      ligacaoSimples(ligacaoSimples& l);
      ~ligacaoSimples();
      //getters
      Data getDia();
      double getCusto();
      double getDuracaoSeg( );
      double getDuracaoMin( );
      //set
      void setDuracaoSeg(double const &s);
      void setDuracaoMin(double const &m);









};
 ligacaoSimples::ligacaoSimples(double c, Data dia,double dm,double ds): duracaoMIN(dm), duracaoSEG(ds) {
      this->dia=dia;
      this->custo=c;


      }
      ligacaoSimples::ligacaoSimples(ligacaoSimples& l): duracaoMIN(l.duracaoMIN), duracaoSEG(l.duracaoSEG) {
      this->dia=l.dia;
      this->custo=l.custo;


      }
      ligacaoSimples::~ligacaoSimples(){}



      //getters
      Data ligacaoSimples::getDia() {

        return dia;


      }

      double ligacaoSimples::getCusto() {
         return custo;

      }





      double ligacaoSimples:: getDuracaoSeg( ){

        return duracaoSEG;
      }
      double ligacaoSimples:: getDuracaoMin( ) {

       return duracaoMIN;

      }
      void ligacaoSimples:: setDuracaoSeg(double const &s) {
           this->duracaoSEG=s;
           }
      void ligacaoSimples::setDuracaoMin(double const &m) {

          this->duracaoMIN=m;

      }




#endif // LIGACAOSIMPLES_H


