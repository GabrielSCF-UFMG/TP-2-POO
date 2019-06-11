#include"../Header/prePago.h"

 //construtores/destrutor
 prePago::prePago(string nome, double cr,Data val, double pMb, double pm,unsigned int t):nome(nome),credito(cr),
 validade(val),precoMb(pMb),precoMin(pm),tempoValidade(t) {validade.setDia(t); franquia=0;}

 prePago:: prePago(const prePago &p) : credito(p.credito),validade(p.validade) {}

 prePago::~prePago() {}


 //getters

 int prePago:: getVal(){
     return validade.getDia();
 }

 int prePago::getValMes() {
    return validade.getMes();
 }

 double prePago::getFran() {
     return franquia;
 }
 double prePago::getCredito() {
     return credito;
}
 string prePago::getNome() {
     return nome;
}


//setters
 void prePago:: setCredito(double c, Data&deposito) {
     credito+=c; validade.setDia(deposito.getDia()+30);
 }
 void prePago::setFranquia(double quantia) {
     franquia+=quantia;
}



 //funções de funcionalidade
 void prePago:: quitarCredito (double valor) {

     if(credito<valor)
        throw(Erro("Saldo Insuficiente!"));

     else
     credito-=valor;
 }

 bool prePago::foraDaValidade(Data now ) {

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


 bool prePago::isPrepago() {
     return true;
}

 double prePago::custoDeChamada () {
     return precoMin ;
}

 double prePago::custoDeInternet () {
     return precoMb;
}


