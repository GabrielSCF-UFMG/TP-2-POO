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
	
	
	jao.getNewCellPhone(1,p1);
	
	jao.interface();
	
	
	
	
	
	return 0;
	
	
}

