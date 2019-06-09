#ifndef PREPAGO_H

#define PREPAGO_H

#include "Data.h"
#include "Plano.h"
#include"Erro.h"


class prePago: public Plano {

    private:
         string nome;
         double credito;
         double precoMin;
         double franquia;
         double precoMb;
         int tempoValidade;
         Data validade;//Dia
    public:
        //construtores
         prePago(string nome, double cr,Data val, double pMb, double pm,unsigned int t):nome(nome),credito(cr),validade(val),precoMb(pMb),precoMin(pm),tempoValidade(t) {validade.setDia(t); franquia=0;}
         prePago(const prePago &p) : credito(p.credito),validade(p.validade) {}

        //getters

         int getVal(){return validade.getDia();}
         int getValMes() {return validade.getMes();}
         double getFran() { return franquia; }
         double getCredito() { return credito; }
         string getNome() {return nome;}

       //setters
         void setCredito(double c, Data&deposito) { credito+=c; validade.setDia(deposito.getDia()+30);}
         void setFranquia(double quantia) {franquia+=quantia;}
       //funções de funcionalidade
         void quitarCredito (double valor); //grande demais pra ser inline
         bool foraDaValidade(Data now );//grande demais pra ser inline
         bool isPrepago() {return true;}
         double custoDeChamada () {return precoMin ;}
         double custoDeInternet () {return precoMb;}

         ~prePago() {}






};

 void  prePago::quitarCredito (double valor) {

     if(credito<valor)
        throw(Erro("Saldo Insuficiente!"));

     else
     credito-=valor;}

 bool prePago:: foraDaValidade(Data now) {

  if(now.getAno()>validade.getAno())
       return true;
  else if (now.getAno()<validade.getAno())
       return false;
   else {
      if(now.getMes()>validade.getMes())
          return true;
      else if (now.getMes()<validade.getMes())
         return false;
      else {
        if(now.getDia()>validade.getDia())
            return true;
        else
            return false;
      }
  }







 }


#endif // PREPAGO_H
