#include<iostream>
#include<vector>


using namespace std;

class Cliente: public Celulares{

private:
    string CPF;
    string nome;
    string endere�o;
    vector <Celular> celulares;
    bool hasCell;

public:
    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua",bool h = false):CPF(C),nome(n),endere�o(e),hasCell(h){}
    //Construtor de copia
    Cliente(const Cliente &c): CPF(c.CPF),nome(c.nome),endere�o(c.endere�o),hasCell(c.hasCell){}

    string getCPF(){return CPF;}
    string getNome(){return nome;}
    string getEndere�o(){return endere�o;}
    vector <Celular> getCelular(){return *celulares;}

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndere�o(string e){endere�o = e;}

    void getNewCellPhone(double number,string planName,double valMin,double vel,
                         double fran,double velAlem){
        celulares.push_back(Celular(number,this->CPF,this->nome
        ,this->endere�o,planName,valMin,vel,fran,velAlem));

        for (i = 0; i< celulares.size();i++){
            if celulares[i].numero = number{
                cout<<"Esse numero ja existe"<<endl
                celulares.pop_back;
                break;
            }
        }

        }


};
