#include "Interface.h"
#include "Exception.h"

bool Interface::verificaDadosNovoCliente(string CPF,string nome){
    for (int i = 0;i < cliente.size();i++){
        if(cliente[i].getCPF() == CPF){
            throw Exception("O CPF solicitado ja existe!");
            return false;
        }
        if(cliente[i].getNome() == nome){
            throw Exception("Existe um cliente cadastrada nesse nome!");
            return false;
        }
    }
        return true;

}

bool Interface::verificaPlano(string pName){
    for (int i = 0;i < plano.size();i++){
        if(plano[i].getName() == pName){
            throw Exception("Esse nome ja pertence a outro plano!");
            return false;
        }
    }
        return true;
}

void Interface::cadastrarCliente(){

    string CPF;string nome;string endereco;
    cout<<"\nDigite o CPF do novo cliente:";
    cin>>CPF;
    cout<<"Digite o nome do novo cliente:";
    cin>>nome;
    cout<<"Digite o endereco do novo cliente:";
    cin>>endereco;
    if(verificaDadosNovoCliente(CPF,nome) == true){
        cliente.push_back(Cliente(CPF,nome,endereco));
    }

}

void Interface::cadastrarPlano(){

    string pName;double vMin;double vel;double fran;double vAlem;bool preOrPos;
    cout<<"Digite o nome do plano:";
    cin>>pName;
    cout<<"Esse plano sera do tipo cartao (Pre-pago,TRUE) ou assinatura (Pos-Pago,FALSE):";
    cin>>preOrPos;

    if(preOrPos == true){
        cout<<"Digite o valor do minuto da ligacao em centavos:";
        cin>>vMin;cout<<" centavos."<<endl;
    }else{
        cout<<"Digite a velocidade da internet em Mbps:";
        cin>>vel;
        cout<<"Digite a quantia da franquia em Gbs:";
        cin>>fran;
        cout<<"Digite a velocidade alem da franquia em Kbps:";
        cin>>vAlem;
        }
    int dia,mes;
    cout<<"Digite a data de vencimento do plano:";
    cout<<"\nDia:";cin>>dia;
    cout<<"Mes:";cin>>mes;
    Date d(0,dia,mes,0);

    plano.push_back(Plano(pName,vMin,vel,fran,vAlem,preOrPos,d));
    if(verificaPlano(plano[plano.size()-1].getName()) == false){
        plano.pop_back();
    }

}

void Interface::interfacePlano(Plano &p){

    cout<<"\nNome do plano: "<<p.getName()<<endl;
    cout<<"Valor do minuto: RS 0,"<<p.getVM()<<"!"<<endl;
    cout<<"Velocidade da internet: "<<p.getVel()<<" Mbps!"<<endl;
    cout<<"Franquia: "<<p.getFran()<<"Gb!" <<endl;
    cout<<"Velocidade alem da Franquia: "<<p.getVelAlem()<<"Kbps!"<<endl;
    cout<<endl;

}

void Interface::interfaceCliente(Cliente &c){

    cout<<"\nCPF do cliente:"<<c.getCPF() <<endl;
    cout<<"Nome do cliente:"<<c.getNome() <<endl;
    cout<<"Endereco do cliente:"<<c.getEndereco() <<endl;
    if(c.getCelulares().size() == 0){
        cout<<"Esse cliente nao tem um celular!"<<endl;
    }else{
        cout<<"Numero de celulares do cliente:"<<c.getCelulares().size()<<endl;
    }

}

void Interface::interfaceCelular(Celular &c){

    cout<<"\nNumero do celular:"<<c.getNumero()<<endl;
    interfacePlano(c.getPlano());
    if(c.getLigacoes().size() == 0){
        cout<<"---O celular nao tem nenhum ligacao---"<<endl;
    }else{
        cout<<"O celular tem "<<c.getLigacoes().size()<<"ligacoes"<<endl;
    }

}

void Interface::listarPlanos(){
    for (int i = 0;i < plano.size();i++){
        cout<<"Plano numero "<<i<<":"<<endl;
        interfacePlano(plano[i]);
    }
}

void Interface::listarCliente(){
    for (int i = 0;i < cliente.size();i++){
        cout<<"Cliente numero "<<i<<":"<<endl;
        interfaceCliente(cliente[i]);
    }

}

void Interface::cadastrarCelular(){
    int nPlano,nCliente;

    cout<<"Escolha o plano do celular pelo seu numero:";
    listarPlanos();
    cout<<"\nNumero do plano:";cin>>nPlano;

    if(plano[nPlano].getTipo() == false){
        int dia,mes;
        cout<<"Digite a data de vencimento do plano do celular:";
        cout<<"Digite a data de vencimento do plano:";
        cout<<"\nDia:";cin>>dia;
        cout<<"Mes:";cin>>mes;
        Date val(0,dia,mes,0);
        plano[nPlano].setVencimento(val);
    }

    cout<<"Escolha o cliente a quem o celular sera pertencido pelo seu numero:";
    listarCliente();
    cout<<"Numero do cliente:";cin>>nCliente;

    celular.push_back(Celular(plano[nPlano]));//Cria o novo celular com o plano escolhido
    cliente[nCliente].getNewCellPhone(celular[celular.size()-1]);//Atribui ao cliente escolhido o novo celular

}

void Interface::interfaceLigacao(Ligacao &l){

    cout<<"\nLigacoes simples:"<<endl;
        for(int i = 0;i<l.getLigsimples().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigSimples(l.getLigsimples()[i]);
        }
        cout<<"\nLigacao dados:"<<endl;
        for(int i = 0;i<l.getLigDados().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigDados(l.getLigDados()[i]);
        }
        if(l.getPlano().getTipo() == true){//PrePago
            cout<<"Restante dos creditos: "<<l.getPlano().getPre().restanteCreditos(l.gastosLig());
        }
    };

void Interface::interfaceLigSimples(LigacaoSimples &ls){

    cout<<"\nData(dia,hora): "<<ls.getDateDia()<<","<<ls.getDateHora()<<endl;
    cout<<"Duracao: "<<ls.getDuracao()<<endl;
    cout<<"Custo: "<<ls.getCusto()<<" reais!"<<endl;
    cout<<"Numero Telefone: "<<ls.getNum()<<endl;
    cout<<endl;

}

void Interface::interfaceLigDados(LigacaoDados &ld){

    double velD = ld.getVelDownload();
    double velU = ld.getVelUpload();
    double taxaD = ld.getDownload()/velD;
    double taxaU = ld.getUpload()/velU;

    cout<<"Tamanho do dado de Download:"<<ld.getDownload()<<"Mb"<<endl;
    cout<<"Tamanho do dado de Upload:"<<ld.getUpload()<<"Kb"<<endl;
    cout<<"Velocidade de Download:"<<ld.getVelDownload()<<"Mbps"<<endl;
    cout<<"Velocidade de Upload:"<<ld.getVelUpload()<<"Mbps"<<endl;
    cout<<"Download realizado em:"<<taxaD<<" segundos!"<<endl;
    cout<<"Upload realizadao em:"<<taxaU<<" segundos!"<<endl;
    cout<<endl;
}

void Interface::addCreditos(){



}
