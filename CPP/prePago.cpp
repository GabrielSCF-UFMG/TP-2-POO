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

  double prePago::getVelocidade(){
    return veloInternet;
  }

  double prePago::getPrecoMin () {
     return precoMin ;
}



//setters
 void prePago:: setCredito(double c, Data&deposito) {
     credito+=c;
     validade=deposito;
     validade.setDia(30);
 }
 void prePago::setFranquia(double quantia) {
     franquia+=quantia;
     double valor = quantia * precoMb;
     debitarCredito(valor);
}



 //funções de funcionalidade

 void prePago:: debitarCredito (double valor) {

     if(credito<valor)
        throw(Erro("Saldo Insuficiente!"));

     else
     credito-=valor;
 }


void prePago::debitarInternet (double valor,Data& now){

         if(this->foraDaValidade(now)) {
             throw(Exception("Creditos expirados"));

         } else {

             if(valor<franquia)
                 franquia-=valor;
             else {
                franquia=0;
                veloInternet = veloInternet*reduz;
                throw(Exception("Pacote de dados todos consumidos, internet com velocidade reduzida"));
             }

         }


    }


     bool prePago::foraDaValidade(Data& now ) {

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



    double prePago::custoDeInternet () {
        return precoMb;
}

    void prePago::contabilizar(double valor){
        this->debitarCredito(valor);
 }


