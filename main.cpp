#include<iostream>

#include "Cliente.h"


int main(){


	//Construtor do Cliente:
	//(CPF, NOME, ENDERECO, TEM CELULAR?);

	//Construtor do Plano:
	//NOME DO PLAN, VALOR MINUTO (0,valor), VELOCIDADE(Mbps), FRANQUIA (Gb), VELALEM(Kbps)


	Plano p1("HELLOW 150 MB 30 Gb", 50, 150, 30, 200);
	Plano p2("HELLOW 200 MB 50 Gb", 50, 200, 50, 200);


	Cliente jao("000.000.000-99", "Jao da Silva","Rua Um",false);

	jao.interface();

	try{
	jao.getNewCellPhone(123456,p1);
	}catch(Erro &e){
        e.mensagem_erro();
	}
	jao.interface();

    //Cliente pedro("000.000.001-99","Pedro da Silva","Rua 2",false);

    //pedro.getNewCellPhone(654321,p2);

    Date d;//int (Hora = 0,dia = 0,mes = 0,ano = 0)

    Ligacao l1(d,10,p1);

    l1.newLigacaoSimples(d,10,p1,123456);
    l1.newLigacaoDados(d,10,p1,10,20);

    l1.newLigacaoSimples(d,20,p1,124521);
    l1.newLigacaoDados(d,20,p2,120,200);

    cout<<"Interface ligacoes:"<<endl;
    l1.interfaceLigacoes();

    cout<<"Criando celulares"<<endl;
    Celular c1(152123,p1);
    Celular c2(123654,p2);

    //c1.newLigacaoSimples(d,20,c2);
    //c1.newLigacaoDados(d,10,100,200);

    cout<<"Tentativa de incluir ligacao"<<endl;
    c1.IncluirLigacao(l1);

    cout<<"Interface celulares:"<<endl;
    c1.interfaceCelulares();

    //cout<<"Processo de ligacao..."<<endl;

    //jao.solicitarLigacaoS(0,d,10.0,pedro.getCelular(0)); //Celular usando, data ligacao, duracao minutos, celular a ligar

    //jao.interface();

	return 0;


}

