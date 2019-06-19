#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cliente.h"
#include "Erro.h"

class Cliente;
class Plano;
class Celular;
class Date;

using namespace std;


class Interface{

private:

    vector <Cliente>cliente;
    vector <Plano> plano;
    vector <Celular> celular;
    vector <Date> dataLig;
    static int num;

public:

    Interface(){};

    vector <Plano>   &getPlano  (){return plano  ;};
    vector <Cliente> &getCliente(){return cliente;};
    vector <Celular> &getCelular(){return celular;};

    bool verificaDadosNovoCliente(string CPF,string nome);
    bool verificaPlano(string pName);
    bool verificaCelular(double num);
    bool verificaDataLig(int i,Date &d);
    bool verificaIndexPlano(int i);
    bool verificaIndexCliente(int i);
    bool testaValidade(int i,Date &d);
    bool testaFranquia(int i);

    int clienteNum(int num);
    int retornaCelular(double num);
    int numeroLigacoes(Celular &c);

    void addCreditos();
    void regLigacao();
    void cadastrarCliente();
    void cadastrarPlano();
    void cadastrarCelular();
    void novaLigacao();

    void listarPlanos();
    void listarClientes();
    void listarCelulares();
    void listarNumeroCelulares();
    void listarLigacoesSimples(int i,LigacaoSimples &ls);
    void listarLigacoesDados(int i,LigacaoDados &ld);
    void listarValorDaConta();
    void listarCreditosData();

    void interfacePlano(Plano &p);
    void interfaceCelular(Celular &c);
    void interfaceCliente(Cliente &c);
    void interfaceLigacao(Ligacao &l);
    void interfaceLigSimples(LigacaoSimples &ls);
    void interfaceLigDados(LigacaoDados &ld);

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
            plano[i].~Plano();
        }
        for(int i = 0;i < celular.size();i++){
            celular[i].~Celular();
        }
    }

};
int Interface::num = 0;


#endif // INTERFACE_H
