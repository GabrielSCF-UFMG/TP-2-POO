#include"../Header/LigacaoSimples.h"


 //construtores & destrutor
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
