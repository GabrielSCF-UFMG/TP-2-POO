#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cliente.h"
#include "Erro.h"

using namespace std;


class Interface{

private:

    vector <Cliente>cliente;
    vector <Plano*> plano;
    vector <Celular> celular;
    vector <Data> dataLig;
    static int num;

public:

    Interface(){};

    vector <Plano*>   &getPlano  (){return plano  ;};
    vector <Cliente> &getCliente(){return cliente;};
    vector <Celular> &getCelular(){return celular;};

    bool verificaDadosNovoCliente(string CPF,string nome);
    bool verificaPlano(string pName);
    bool verificaCelular(double num);
    bool verificaDataLig(int i,Data &d);
    bool testaValidade(int i,Data &d);
    bool testaFranquia(int i);


    int retornaCelular(double num);

    void addCreditos();
    void regLigacao();
    void cadastrarCliente();
    void cadastrarPlano();
    void cadastrarCelular();
    void novaLigacao();

    void listarPlanos();
    void listarClientes();
    void listarCelulares();
    void listarLigacoesSimples(int i,ligacaoSimples &ls);
    void listarLigacoesDados(int i,ligacaoDados &ld);
    void listarValorDaConta();
    void listarCreditosData();

    void interfacePlano(Plano &p);
    void interfaceCelular(Celular &c);
    void interfaceCliente(Cliente &c);
    void interfaceLigacao(Ligacao &l);
    void interfaceLigSimples(ligacaoSimples &ls);
    void interfaceLigDados(ligacaoDados &ld);

    void dadosPacoteInternet();
    void extratoSimples();
    void extratoDados();

    void informarVenciCred();
    void informarFranquia();

    ~Interface(){

        for(int i = 0;i < cliente.size();i++){
            cliente[i].~Cliente();
        }
        for(int i = 0;i < plano.size();i++){
            plano[i]->~Plano();
        }
        for(int i = 0;i < celular.size();i++){
            celular[i].~Celular();
        }
    }

};
int Interface::num = 0;


#endif // INTERFACE_H
