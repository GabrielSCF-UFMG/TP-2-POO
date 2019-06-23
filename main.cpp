#include <iostream>

#include"Cliente.h"



using namespace std;

class Interface{

private:

    vector <Plano>  pl;
    vector <Cliente*> cli;
    vector <Celular> cel;


public:

    void registrarPlano(){

        //Usário fornece os dados de um novo
        //plano e adiciona ao vector 'pl'

    }
    void registrarCliente(){

        //Usário fornece os dados de um novo
        //cliente e adiciona ao vector 'cli'

    }
    void registraCelular(){

        //Usário fornece os dados de um novo
        //celular e adiciona ao vector 'cel'

    }



    void listarPlanos(){

        //Lista todos os planos registrados
        //no vector 'pl'

    }
    void listarClientes(){

        //Lista todos os clientes registrados
        //no vector 'cli'

    }
    void listarCelulares(){

        //Lista todos os celulares registrados
        //no vector 'cel'

    }



    void fazerLigacao(){

        //Registra uma nova ligacao atraves de
        //dados fornecidos do usuario como:
        //-Qual o cliente
        //-Qual o celular ligando
        //-Qual o celular a receber a ligacao
        //-Qual a duracao

    }

    void mostrarExtrato(){

        //Lista todos os clientes,
        //seus respectivos celulares,
        //suas ligacoes e o preco.
        //No final mostra se os creditos
        //de cada celular.

    }


};


int main(){
    Data A (21,06,2019);
  Plano*p=new posPago("Tim",60,500,A);
  Plano *c=new prePago("OI",A,0.05,0.02,30);

  Celular* cel=new Celular(p,20,100);
  Celular* cel2=new Celular(c,0,0);

  Cliente cleber ("Cleber","1200125");
  cleber.addCelular(cel);
  cleber.addCelular(cel2);

   Celular* tel;

   tel=cleber.usarTelefone(0);

  try {

   tel->ligar(A,9,60);
   tel->ligar(A,1,30);
   tel->ligar(A,2,15);
   tel->transferirDados(A,100);
    tel->comprarDados(A,500);



  } catch(Exception &e) {

   e.mensagem_erro();
  }

   tel->registroChamadas();
   tel->registroDados();
   cout<<tel->getDados()<<endl<<tel->getCreditos()<<endl;

   Plano *a=tel->getPlano();

   cout<<"Nome do plano:"<<a->getNome()<<endl;
   if(a->isPrepago()) {
    cout<<"Preco do Min: "<<a->custoDeChamada()<<endl;
    cout<<"Preco do Mb: "<<dynamic_cast<prePago*> (a)->custoDeInternet () <<endl;

   }
   else {
    cout<<"Preço do plano: "<<a->custoDeChamada()<<endl;
    cout<<"Pacote de dados: "<<a->getFran()<<endl;
   }

    tel=cleber.usarTelefone(1);

  try {

   tel->ligar(A,9,60);
   tel->ligar(A,1,30);
   tel->ligar(A,2,15);
   tel->transferirDados(A,100);
    tel->comprarDados(A,500);




  } catch(Exception &e) {

   e.mensagem_erro();
  }


   tel->registroChamadas();
   tel->registroDados();
   cout<<tel->getDados()<<endl<<tel->getCreditos()<<endl;

   a=tel->getPlano();

   cout<<"Nome do plano:"<<a->getNome()<<endl;
   if(a->isPrepago()) {
    cout<<"Preco do Min: "<<a->custoDeChamada()<<endl;
    cout<<"Preco do Mb: "<<dynamic_cast<prePago*> (a)->custoDeInternet () <<endl;

   }
   else {
    cout<<"Preço do plano: "<<a->custoDeChamada()<<endl;
    cout<<"Pacote de dados: "<<a->getFran()<<endl;
   }

    return 0;
}
