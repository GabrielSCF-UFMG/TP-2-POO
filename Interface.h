#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cliente.h"
#include "Erro.h"

using namespace std;


class Interface{

private:

    vector <Cliente>cliente;
    vector <Plano> plano;
    vector <Celular> celular;
    vector <Ligacao> ligacao;

public:

    vector <Plano>   &getPlano  (){return plano  ;};
    vector <Cliente> &getCliente(){return cliente;};
    vector <Celular> &getCelular(){return celular;};
    vector <Ligacao> &getLigacao(){return ligacao;};

    bool verificaDadosNovoCliente(string CPF,string nome);
    bool verificaPlano(string pName);
    void cadastrarCliente();
    void cadastrarPlano();
    void cadastrarCelular();
    void novaLigacao();

    void listarPlanos();
    void listarCliente();


    void interfacePlano(Plano &p);
    void interfaceCelular(Celular &c);
    void interfaceCliente(Cliente &c);
    void interfaceLigacao(Ligacao &l);
    void interfaceLigSimples(LigacaoSimples &ls);
    void interfaceLigDados(LigacaoDados &ld);






};


#endif // INTERFACE_H
