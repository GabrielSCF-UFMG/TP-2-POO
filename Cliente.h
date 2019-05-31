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
    vector <Celular> getCelulares(){return celulares;}//Retorna todos os celulares do cliente por vector
    Celular getCelular(int i){return celulares[i];} //Retorna um celular expecifico do cliente

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndereco(string e){endereco = e;}

    void getNewCellPhone(double number,Plano &p){
        cout<<"\nObtendo um celular..."<<endl;
        if(number > 999999){
            throw Erro("O numero do telefone deve ter no maximo 6 digitos!Numero invalido!");
        }

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
        }

     virtual void interface(){


		cout<<"\n--------------Informacoes do cliente-------------- "<<endl;
		cout<<"\nCPF do cliente:"<<CPF <<endl;
        cout<<"Nome do cliente:"<<nome <<endl;
        cout<<"Endereco do cliente:"<<endereco <<endl;
        if(celulares.size() == 0){
        	cout<<"Esse cliente nao tem um celular!"<<endl;
		}else{
		cout<<"Numero de celulares do cliente:"<<celulares.size()<<endl;
        cout<<"Ligacoes do cliente:"<<endl;
        for(int i = 0;i < celulares.size();i++){
        	cout<<"-----Interface Celular "<<i<<"------"<<endl;
        	celulares[i].interfaceCelulares();
		}
		}

     }

     void solicitarLigacaoS(int i, Date &d,double dur,Celular c){ //Celualr a ligar
        celulares[i].newLigacaoSimples(d,dur,c);
     }

     void solicitarLigacaoD(int i,Date &d,double dur,double down,double up){
        celulares[i].newLigacaoDados(d,dur,down,up);
     }

};


 #endif


