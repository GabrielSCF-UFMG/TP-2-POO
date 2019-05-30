#include<iostream>
#include<vector>
#include "Celular.cpp"

using namespace std;

class Cliente{

private:
    string CPF;
    string nome;
    string endereco;
    vector <Celular> celulares; //VETOR DE CELULARES DO CLIENTE
    bool hasCell;
    int static proxNumCelular;

public:
    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua",bool h = false):CPF(C),nome(n),endereco(e),hasCell(h){}
    //Construtor de copia
    Cliente(const Cliente &c): CPF(c.CPF),nome(c.nome),endereco(c.endereco),hasCell(c.hasCell){}

    string getCPF(){return CPF;}
    string getNome(){return nome;}
    string getEndereco(){return endereco;}
    vector <Celular> getCelular(){return celulares;}

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndereco(string e){endereco = e;}

    void getNewCellPhone(double number,Plano &p){
        hasCell = true;
		celulares.push_back(Celular(number,p));

        for (int i = 0; i< celulares.size();i++){
            if (celulares[i].getNumero() == number){
                cout<<"Esse numero ja existe"<<endl;
                celulares.pop_back();
                break;
            }
        }
			proxNumCelular = celulares.size() + 1;//=celulares.size()
        }

     virtual void interface(){

        cout<<"CPF do cliente:"<<CPF <<endl;
        cout<<"Nome do cliente:"<<nome <<endl;
        cout<<"Endereco do cliente:"<<endereco <<endl;
        if(hasCell = false){
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

