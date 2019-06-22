#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<vector>
#include<string>

#include "Celular.h"
#include "Exception.h"

class Celular;

using namespace std;

class Cliente{

private:

    string CPF;
    string nome;
    string endereco;
    vector <Celular> celulares; //VETOR DE CELULARES DO CLIENTE

public:

    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua"):CPF(C),nome(n),endereco(e){};

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
        celulares.push_back(c);
        }

     ~Cliente(){

        CPF = "--";
        nome = "--";
        endereco = "--";
        for(unsigned int i = 0;i< celulares.size();i++){
            celulares[i].~Celular();
        }
     }
};


 #endif


