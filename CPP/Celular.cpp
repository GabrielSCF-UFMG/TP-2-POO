#include"../Header/Celular.h"


 //construtores/destrutores
      Celular::Celular(Plano& p, double c, double f): creditos(c), franquia(c) {
          plano=&p;
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

        for(int i=0; i<numero.size();i++)
             numero[i]= c.numero[i];




      }
     Celular:: ~Celular(){

        for(int k=0;k<ligacoes.size();k++)
                delete ligacoes[k];

      }


      //getters
    vector<int> Celular::getNum(){
      return numero;

    }
    vector<Ligacao*> Celular::getHistorico(){
       return ligacoes;

    }

   void Celular::chamada(double duracao) {

       Data now= Data();
       if(plano->foraDaValidade(now ))
           throw(Exception("Fora da validade!"));

       if(plano->isPrepago()) {

             double custo=plano->custoDeChamada ();



       }



   }


