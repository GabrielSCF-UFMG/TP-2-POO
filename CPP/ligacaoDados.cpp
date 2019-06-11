#include"../Header/LigacaoDados.h"

 //construtores & destrutor
      ligacaoDados::ligacaoDados(double dc, Data dia):  dadosConsumidos(dc) {this->dia=dia;}

      ligacaoDados::ligacaoDados(ligacaoDados& b):dadosConsumidos(b.dadosConsumidos){this->dia=b.dia;}

      ligacaoDados::~ligacaoDados(){}

