#ifndef LIGACAO_H

#define LIGACAO_H

#include"Data.h"

class Ligacao {


    protected:
        Data dia;
        double custo;

    public:
      virtual Data getDia()=0;
      virtual double getCusto()=0;
      virtual ~Ligacao(){}
      virtual bool isSimples()=0;




};





#endif // LIGACAO_H




