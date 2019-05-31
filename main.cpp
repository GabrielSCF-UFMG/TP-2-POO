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

    Cliente pedro("000.000.001-99","Pedro da Silva","Rua 2",false);

    pedro.getNewCellPhone(654321,p2);

    Date d(12,5);//int (Hora = 0,dia = 0,mes = 0,ano = 0)

    cout<<"Processo de ligacao..."<<endl;

    jao.solicitarLigacaoS(0,d,10.0,pedro.getCelular(0)); //Celular usando, data ligacao, duracao minutos, celular a ligar

    //jao.interface();

	return 0;


}

