#include<iostream>

using namespace std;

class Cliente: public Celular{

private:
    string CPF;
    string nome;
    string endere�o;
    vector <Celular> celulares;
    bool hasCell;

public:
    Cliente(string C = "123.456.789-99",string n = "Cleiton",string e = "Rua",bool h = false):CPF(C),nome(n),endere�o(e),hasCell(h){}
    //Construtor de copia
    Cliente(const Cliente &c): CPF(c.CPF),nome(c.nome),endere�o(c.endere�o),hasCell(c.hasCell){}

    string getCPF(){return CPF;}
    string getNome(){return nome;}
    string getEndere�o(){return endere�o;}
    vector <Celular> getCelular(){return *celulares;}

    void setCPF(string C){CPF = C;}
    void setNome(string n){nome = n;}
    void setEndere�o(string e){endere�o = e;}

    void getNewCellPhone(double number,string planName,double valMin,double vel,
                         double fran,double velAlem){
        celulares.push_back(Celular(number,this->CPF,this->nome
        ,this->endere�o,planName,valMin,vel,fran,velAlem));

        for (i = 0; i< celulares.size();i++){
            if celulares[i].numero = number{
                cout<<"Esse numero ja existe"<<endl
                celulares.pop_back;
                break;
            }
        }

        }


};

class Celular: public Cliente,Plano{

private:
    double numero; //Come�a em 0 e incrementa 1 a cada novo numero
    Cliente cliente;
    Plano plano;
    vector <Liga�ao> liga�oes;
    double static proxNumCelular;

public:

    Celular(double num,string C,string n,string e,
            string planName,double valMin,double vel,double fran,double velAlem):
    numero(n),cliente=Cliente(C,n,e,)
    ,plano = Plano(planName,valMin,vel,fran,velAlem),proxNumCelular++{};
    //Construtor de copia
    Celular(const Celular &cel):numero(cel.numero),
    cliente=cel.cliente,plano=cel.plano,liga�oes = cel.lega�oes{};

    double getNumero(){return numero;}

    virtual void Ligar = 0;

};

class Plano:public Celular{

private:
    string nome;
    double ValorMinuto;
    double velocidade;
    double Franquia;
    double VelocAlem;
public:
    Plano(string planName,double valMin,double vel,double fran,double velAlem):
        nome(planName),ValorMinuto(valMin),velocidade(vel),
        Franquia(fran),VelocAlem(velAlem){}

};

class PrePado:public Plano{

private:
    double credito;
    Date validade;
public:

    PrePado(double cr,int valDia):credito(cr),validade = Date(valDia){}

    void val(){return validade.dia;}

    double restanteCreditos(){
        double auxGastos = 0.0;

        for (i = 0;i < liga�oe.size();i++){
            auxGastos += Celular.liga�oes[i].cost;
        }
        double auxCredito = credito;

        return auxCredito-auxGastos;
    }

    bool foraDaValidade(Date now){//Vencido?
        if now.dia <= validade.dia {
            return false;
        }else
            return true;
    }

};

class PosPago:public Plano{
private:
    Date vencimento;
public:
    PrePado(int venDia):vencimento = Date(venDia){}

    void getVencimento(){return vencimento.dia;}
    bool vencido(Date now){
        if now.dia <= validade.dia {
            return false;
        }else
            return true;
    }
};

class Ligacao:public Celular{

private:
    Date datahora;
    double duracao;
    double custo;
    vector <LigacaoSimples> ligSim;
    vector <LigacaoDados> ligDados;

public:
    Ligacao(int dia,double hr,double dur,double cost):dataHora = Date(dia,hr),duracao(dur),custo(cost){}

    void newLiga�ao(int dia,double hora,double dura,Celular &cellLigando,Celular &cellRecebendo
                     ,bool simples,bool download,bool upload){//Duracao em minutos
        double cost = cell.Plano.ValorMinuto * dura;
    cellLigando.liga�oes.push_back(Ligacao(dia,hora,dura,cost));

    if simples {
        ligSim = push_back(LigacaoSimples(cellRecebendo.numero))
        //cout<<"Numero do destinatario da liga�ao "<<liga�oes.size()<< "eh:" <<cellRecebendo.numero;
    }else{
        ligDados = push_back(LigacaoDados(download,upload))
    }
    }

};

class LigacaoDados: public Ligacao{

private:
    bool Download;
    bool Upload;
public:
    LigacaoDados(bool dadosD,bool dadosU):Download(dadosD),Upload(dadosU){}

    bool getDownload(){ return Download;}
    bool getUpload(){ return Upload;}


};
