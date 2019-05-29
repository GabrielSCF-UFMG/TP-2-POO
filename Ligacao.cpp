#include<iostream>
#include<vector>

using namespace std;

class LigacaoDados{

private:
    bool Download;
    bool Upload;
public:
    LigacaoDados(bool dadosD,bool dadosU):Download(dadosD),Upload(dadosU){}

    bool getDownload(){ return Download;}
    bool getUpload(){ return Upload;}


};

class LigacaoSimples{

private:
    double NumTelefone;
public:
    LigacaoSimples(double num):NumTelefone(num){};

    double getNum(){return NumTelefone;};

    void setNum(double num){NumTelefone = num;};

};

class Ligacao: public LigacaoDados,LigacaoSimples,Plano{

private:
    Date datahora;
    double duracao;
    double custo;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;

public:
    Ligacao(int dia,int hr,double dur,Plano p){
        duracao = dur;
        cost = p.valorMinuto * dur;
        Date d(hr,dia,0,0);
        datahora = d;
    }

    void newLigacao(int dia,double hora,double dura,Celular &cellLigando,Celular &cellRecebendo
                     ,bool simples,bool download,bool upload){//Duracao em minutos
    cellLigando.ligaçoes.push_back(Ligacao(dia,hora,dura,cellLigando.plano));

    if simples {
        ligSim = push_back(LigacaoSimples(cellRecebendo.numero))
        //cout<<"Numero do destinatario da ligaçao "<<ligaçoes.size()<< "eh:" <<cellRecebendo.numero;
    }else{
        ligDados = push_back(LigacaoDados(download,upload))
    }
    }


};
