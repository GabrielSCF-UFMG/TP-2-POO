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
      void setDuracaoSeg(double &s);
      void setDuracaoMin(double &m);









};



#endif // LIGACAOSIMPLES_H
