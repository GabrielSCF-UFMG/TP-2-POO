#ifndef CELULAR_H
#define CELULAR_H
#include"prePago.h"
#include"posPago.h"
#include"ligacaoDados.h"
#include"ligacaoSimples.h"
#include<vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>



class Celular {

 private:
  vector<int> numero;
  vector<Ligacao*> registro;
  Plano*p;
  double creditos;
  double dados;

 public:

    Celular(Plano *x,double c=0,double d=0);
    Celular(Celular &c);
    ~Celular();

     void printNumero();




};

 Celular::Celular(Plano *x,double c,double d):p(x),creditos(c),dados(d) {

   srand (unsigned(rand()));

     for(int a=0; a<8; a++) {
        numero.push_back(rand()%9);


         }



     std::random_shuffle ( numero.begin(), numero.end() );



 }
 Celular::Celular(Celular &c):p(c.p),creditos(c.creditos),dados(c.dados),numero(c.numero) {}

Celular::~Celular() {registro.clear();}

void Celular::printNumero() {

  for(int i=0;i<numero.size();i++)
       std::cout<<numero[i];




}


#endif // CELULAR_H
