#include"../Header/Celular.h"


 //construtores/destrutores
      Celular::Celular(Plano& p, double c, double f): plano(p),creditos(c), franquia(c) {

          srand( (unsigned)time(NULL) );
         for(int i=0 ; i <numeroDeAlgarismos ; i++)
                  numero.push_back(rand()%10);


        unsigned semente=unsigned  (rand());
         srand( semente);
         int sorte=rand() %100;
        if(sorte%2==0)
           std::random_shuffle ( numero.begin(),numero.end() );
         if(sorte%3==0)
           std::random_shuffle ( numero.begin(),numero.end() );
         if(sorte%5==0)
           std::random_shuffle ( numero.begin(),numero.end() );




      }
      Celular::Celular(Celular &c) :  plano(c.plano),creditos(c.creditos), franquia(c.franquia) {

        for(int i=0; i<numero;i++)
             numero[i]= c.numero[i];




      }
      ~Celular();


