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
      Data getDia();
      double getCusto();









};

#endif // LIGACAODADOS_H

