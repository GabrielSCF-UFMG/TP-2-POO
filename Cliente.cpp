#include<iostream>
#include<vector>


using namespace std;

class Cliente: public Celulares{

private:
    string CPF;
    string nome;
    string enderešo;
    vector <Celular> celulares;
    bool hasCell;

public:
    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua",bool h = false):CPF(C),nome(n),enderešo(e),hasCell(h){}
    //Construtor de copia
    Cliente(const Cliente &c): CPF(c.CPF),nome(c.nome),enderešo(c.enderešo),hasCell(c.hasCell){}

    string getCPF(){return CPF;}
    string getNome(){return nome;}
    string getEnderešo(){return enderešo;}
    vector <Celular> getCelular(){return *celulares;}

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEnderešo(string e){enderešo = e;}

    void getNewCellPhone(double number,string planName,double valMin,double vel,
                         double fran,double velAlem){
        celulares.push_back(Celular(number,this->CPF,this->nome
        ,this->enderešo,planName,valMin,vel,fran,velAlem));

        for (i = 0; i< celulares.size();i++){
            if celulares[i].numero = number{
                cout<<"Esse numero ja existe"<<endl
                celulares.pop_back;
                break;
            }
        }

        }


};
