#include<iostream>
#include<vector>

#include "Plano.cpp"

using namespace std;

class LigacaoDados{

private:
    double Download;
    double Upload;

public:
    LigacaoDados(double dadosD,double dadosU):Download(dadosD),Upload(dadosU){}

    double getDownload(){ return Download;}
    double getUpload(){ return Upload;}


};

class LigacaoSimples{

private:

    double NumTelefone;

public:
    LigacaoSimples(double num = 0.0):NumTelefone(num){};

    double getNum(){return NumTelefone;};

    void setNum(double num){NumTelefone = num;};

};

class Ligacao:public Plano{

private:
    Date datahora;
    double duracao;
    double custo;
    vector <Ligacao> lig;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;

public:
    Ligacao(Date &dataLig,double dur,Plano &p){
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
    }
    Ligacao(Date dataLig,double dur,Plano &p,double num){
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligSim.push_back(LigacaoSimples(num));
    }
    Ligacao(Date dataLig,double dur,Plano &p,double down,double up){
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligDados.push_back(LigacaoDados(down,up));
    }

    void newLigacaoSimples(Date &dataLigacao, double dur, Plano &p, double num){
        Ligacao nova(dataLigacao,dur,p,num);
        lig.push_back(nova);
    }

    //Gets
    Date getDate(){return datahora;};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};
    Ligacao getLig(int i){return lig[i];};
    LigacaoSimples getLigsimples(int i){return ligSim[i];};
    LigacaoDados getDados(int i){return ligDados[i];};
    //Sets
    void setDate(Date &d){datahora = d;};
    void setDuracao(double dur){duracao = dur;};
    void setCusto(double c){custo = c;};
    void setLig(int i,Ligacao &l){lig[i] = l;};
    void setLigsimples(int i, LigacaoSimples &ls){ligSim[i] = ls;};
    void setDados(int i, LigacaoDados ld){ligDados[i] = ld;};



};
