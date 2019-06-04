#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<vector>

#include "Celular.h"
#include "Erro.h"

//using namespace std;

class Cliente{

private:
    string CPF;
    string nome;
    string endereco;
    vector <Celular> celulares; //VETOR DE CELULARES DO CLIENTE
    //int static numDeCelulares;

public:
    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua",bool h = false):CPF(C),nome(n),endereco(e){};

    //Construtor de copia
    Cliente(const Cliente &c){
			CPF = c.CPF;
			nome = c.nome;
			endereco = c.endereco;
		}



    string getCPF(){return CPF;}
    string getNome(){return nome;}
    string getEndereco(){return endereco;}
    vector <Celular> &getCelulares(){return celulares;}//Retorna todos os celulares do cliente por vector
    Celular &getCelular(int i){return celulares[i];} //Retorna um celular expecifico do cliente

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndereco(string e){endereco = e;}

    void getNewCellPhone(Celular &c){
        cout<<"\nObtendo um celular..."<<endl;
        celulares.push_back(c);
        }

     void solicitarLigacaoS(int i, Date &d,double dur,Celular &c){ //Celualr a ligar
        celulares[i].newLigacaoSimples(d,dur,c);
     }

     void solicitarLigacaoD(int i,Date &d,double dur,double down,double up){
        celulares[i].newLigacaoDados(d,dur,down,up);
     }

};


 #endif


