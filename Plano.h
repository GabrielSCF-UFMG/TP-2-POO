#ifndef PLANO_H

#define PLANO_H

#include <string>



#include "Data.h"

 class Plano {

 public:

 virtual string getNome()=0;

 virtual bool isPrepago ()=0;


 virtual double getFran()=0;

 virtual double custoDeChamada()= 0;

 virtual ~Plano(){}






 };






#endif
