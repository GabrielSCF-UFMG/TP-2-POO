#include"Celular.h"



class Cliente {


    private:
        string nome;
        string CPF;
        vector<Celular*> aparelhos;
    public:
        Cliente(string n,string c);
        Cliente(Cliente&c);
        ~Cliente();
        void addCelular(Celular* cel);
        Celular* usarTelefone(unsigned posi);






};



    Cliente::Cliente(string n,string c): nome(n),CPF(c) {}
    Cliente::Cliente(Cliente&c):nome(c.nome),CPF(c.CPF){}
    Cliente:: ~Cliente () {
       aparelhos.clear();

    }

     void Cliente::addCelular(Celular* cel){
       aparelhos.push_back(cel);

     }


   Celular* Cliente:: usarTelefone(unsigned posi){

      if(posi>aparelhos.size())
           throw(Exception("Aparelho nao encontrado"));

      else
        return aparelhos[posi];



   }
