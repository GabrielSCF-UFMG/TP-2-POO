#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<vector>

#include "Celular.h"
#include "Erro.h"

using namespace std;

class Cliente{

private:
    string CPF;
    string nome;
    string endereco;
    vector <Celular> celulares; //VETOR DE CELULARES DO CLIENTE
    int static proxNumCelular;

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
    vector <Celular> getCelular(){return celulares;} //Retorna todos os celulares do cliente(vector)

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndereco(string e){endereco = e;}

    void getNewCellPhone(double number,Plano &p){
		bool popCell;
        for (int i = 0; i< celulares.size();i++){
        	cout<<"\n"<<celulares[i].getNumero()<<endl;
            if (celulares[i].getNumero() == number){
                cout<<"Esse numero ja existe"<<endl;
                popCell = true;
				//celulares.pop_back();
                break;
            }
        }
        	celulares.push_back(Celular(number,p));
			if(popCell == true){
				celulares.pop_back();
			}
			proxNumCelular = celulares.size() + 1;//=celulares.size()
        }

     virtual void interface(){

        
		cout<<"--------------Informacoes do cliente-------------- "<<endl;
		cout<<"\nCPF do cliente:"<<CPF <<endl;
        cout<<"Nome do cliente:"<<nome <<endl;
        cout<<"Endereco do cliente:"<<endereco <<endl;
        if(celulares.size() == 0){
        	cout<<"Esse cliente não tem um celular!"<<endl;
		}else{
		cout<<"Numero de celulares do cliente:"<<celulares.size()<<endl;
        cout<<"Ligacoes do cliente:";
        for(int i = 0;i < celulares.size();i++){
        	celulares[i].interfaceCelulares(i);
		}
		}

     }
	
	 int getNumCelulares(){return proxNumCelular;};
	
};
 int Cliente::proxNumCelular = 0;
 
 #endif


