#include<iostream>

#include "Cliente.h"
#include "Operadora.h"
#include "InterfaceMetodos.cpp"


int main(){

    Cliente CLI;
    Plano PLAN1("PLANO1",10,0,0,0);
    Plano PLAN2("PLANO2",10,0,0,0);

    Celular CELL1(PLAN1);
    Celular CELL2(PLAN2);


    CELL1.acrecentarCreditos(100);
    CELL2.acrecentarCreditos(200);

    Date d(10,12,5,2019);

    //CELL1.newLigacaoSimples(d,10,CELL2.getNumero());

    Ligacao l(d,10,PLAN1);
    l.newLigacaoSimples(d,10,PLAN1,CELL2.getNumero());

    CELL1.IncluirLigacao(l);

    cout<<"Ligacao:\n";
    cout<<"ANO:"<<CELL1.getLigacoes()[0].getLigsimples()[0].getAno()<<endl;
    cout<<"DIA:"<<CELL1.getLigacoes()[0].getLigsimples()[0].getDia()<<endl;
    cout<<"CUSTO:"<<CELL1.getLigacoes()[0].getLigsimples()[0].getCusto()<<endl;
    cout<<"DURACAO:"<<CELL1.getLigacoes()[0].getLigsimples()[0].getDuracao()<<endl;
    cout<<"NUMERO:"<<CELL1.getLigacoes()[0].getLigsimples()[0].getNum()<<endl;

	return 0;

}

