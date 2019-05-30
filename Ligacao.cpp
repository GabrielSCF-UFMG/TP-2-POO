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

    void interface(){

        cout<<"Download:"<<Download<<endl;
        cout<<"Upload:"<<Upload<<endl;
        cout<<endl;
    }

};

class LigacaoSimples{

private:

    Date datahora;
    double duracao;
    double custo;
    double numTelefone;

public:
    LigacaoSimples(Date &dataLig,double dur,Plano &p,double num){
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        numTelefone = num;
    };

    int getDate(){return datahora.getDia();};
    double getNum(){return numTelefone;};
    double getDuracao(){return duracao;};
    double getCusto(){return custo;};

    void setNum(double num){numTelefone = num;};

    void interface(){

       cout<<"\nData:"<<getDate()<<endl;
       cout<<"Duracao:"<<duracao<<endl;
       cout<<"Custo:"<<custo<<endl;
       cout<<"Numero Telefone:"<<numTelefone<<endl;
       cout<<endl;

    }

};

class Ligacao{

private:
    Date datahora;
    double duracao;
    double custo;
    vector <Ligacao> lig;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;
    Plano plano;

public:
    Ligacao(Date &dataLig,double dur,Plano &p){
        plano = p;
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
    }
    Ligacao(Date &dataLig,double dur,Plano &p,double num){
        plano = p;
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligSim.push_back(LigacaoSimples(dataLig,dur,p,num));
    }
    Ligacao(Date &dataLig,double dur,Plano &p,double down,double up){
        plano = p;
        duracao = dur;
        custo = p.getVM() * dur;
        datahora = dataLig;
        ligDados.push_back(LigacaoDados(down,up));
    }
    Ligacao(const Ligacao &c){
        plano = c.plano;
        duracao = c.duracao;
        custo = c.custo;
        datahora = c.datahora;
    }

    void newLigacaoSimples(Date &dataLigacao, double dur, Plano &p, double num, vector <Ligacao> ligacoes){
        Ligacao nova(dataLigacao,dur,p,num);
        ligacoes.push_back(nova);
    }

    void newLigacaoSimples(Date &dataLigacao, double dur, Plano &p, double num){
        Ligacao nova(dataLigacao,dur,p,num);
        this->lig.push_back(nova);
    }

    void newLigacaoDados(Date &dataLigacao,double dur,Plano &p,double down,double up,vector <Ligacao> ligacoes){
        Ligacao nova(dataLigacao,dur,p,down,up);
        ligacoes.push_back(nova);
    }

    void newLigacaoDados(Date &dataLigacao,double dur,Plano &p,double down,double up){
        Ligacao nova(dataLigacao,dur,p,down,up);
        this->lig.push_back(nova);
    }


    //Gets
    int getDate(){return datahora.getDia();};
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

    void interfaceLigacoes(){

        cout<<"\nLigacoes simples:"<<endl;
        for(int i = 0;i<ligSim.size();i++){
            cout<<i<<":"<<endl;
            ligSim[i].interface();
        }
        cout<<"\nLigacao dados:"<<endl;
        for(int i = 0;i<ligSim.size();i++){
            cout<<i<<":"<<endl;
            ligDados[i].interface();
        }

    }

};
