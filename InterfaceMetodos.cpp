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
        if(plano[i].getNome() == pName){
            throw Exception("Esse nome ja pertence a outro plano!");
            return false;
            break;
        }
    }
        return true;
}

bool Interface::verificaCelular(double num){
    for (int i = 0;i < celular.size();i++){
        if(celular[i].getNumero() == num){
            return true;
            break;
        }
    }
        throw Exception("Esse numero de celular nao existe!");
        return false;
}

int Interface::retornaCelular(double num){
    for (int i = 0;i < celular.size();i++){
        if(celular[i].getNumero() == num){
            return i;
            break;
        }
    }
        throw Exception("Esse numero de celular nao existe!");
}

void Interface::cadastrarCliente(){
    cout<<"--CADASTRANDO CLIENTE--"<<endl;
    string CPF;string nome;string endereco;
    cout<<"Digite o CPF do novo cliente:";
    cin>>CPF;
    cout<<"Digite o nome do novo cliente:";
    cin>>nome;
    cout<<"Digite o endereco do novo cliente:";
    cin>>endereco;
    if(verificaDadosNovoCliente(CPF,nome)){
        cliente.push_back(Cliente(CPF,nome,endereco));
        cout<<"--Cliente cadastrado com sucesso!--"<<endl;
    }else{
        cout<<"--Cliente nao pode ser cadastrado!--"<<endl;
    }

}

void Interface::cadastrarPlano(){
    cout<<"--CADASTRANDO PLANO--"<<endl;
    string pName;double vMin;double vel;double fran;double vAlem;int tipo;bool preOrPos;
    cout<<"Digite o nome do plano:";
    cin>>pName;
    cout<<"Esse plano sera do tipo cartao (Pre-pago,1) ou assinatura (Pos-Pago,0):";
    cin>>tipo;

    if(tipo == 1){
        preOrPos = true;
    }else{
        preOrPos = false;
    }

    if(preOrPos){
        cout<<"Digite o valor do minuto da ligacao em centavos:";
        cin>>vMin;
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
    Date d(0,dia,mes,2019);

    if(verificaPlano(pName)){
        plano.push_back(Plano(pName,vMin,vel,fran,vAlem,preOrPos,d));
        cout<<"--Plano cadastrado com sucesso!--"<<endl;
    }else{
        cout<<"--Plano nao pode ser cadastrado!--"<<endl;
    }

}

void Interface::cadastrarCelular(){
    int nPlano,nCliente;

    cout<<"Escolha o plano do celular pelo seu numero:"<<endl;
    listarPlanos();
    cout<<"Numero do plano:";cin>>nPlano;

    if(!plano[nPlano].getTipo()){
        int dia,mes;
        cout<<"\nDigite a data de vencimento do plano assinatura:";
        cout<<"\nDia:";cin>>dia;
        cout<<"Mes:";cin>>mes;
        Date val(0,dia,mes,0);
        plano[nPlano].setVencimento(val);
    }

    cout<<"Escolha o cliente a quem o celular sera pertencido pelo seu numero:"<<endl;
    listarClientes();
    cout<<"Numero do cliente:";cin>>nCliente;

    celular.push_back(Celular(plano[nPlano]));//Cria o novo celular com o plano escolhido
    cout<<"Celular criado com sucesso!";

    //Celular c = celular[celular.size()-1];
    cliente[nCliente].getNewCellPhone(celular[celular.size()-1]);//Atribui ao cliente escolhido o novo celular
    //this->cliente[nCliente].celulares.push_back(c);
    cout<<"Cliente "<<cliente[nCliente].getNome()<<" acaba de ganhar um novo celular de numero "<<celular[celular.size()-1].getNumero()<<"!"<<endl;

}

void Interface::interfacePlano(Plano &p){

    if(p.getTipo()){
    cout<<"\nNome do plano: "<<p.getNome()<<endl;
    cout<<"Valor do minuto: RS 0,"<<p.getVM()<<"!"<<endl;
    cout<<"Creditos iniciais: RS "<<p.getCred() / 100<<",00!"<<endl;
    }
    else if(!p.getTipo()){
    cout<<"Velocidade da internet: "<<p.getVel()<<" Mbps!"<<endl;
    cout<<"Franquia: "<<p.getFran()<<"Mb!" <<endl;
    cout<<"Velocidade alem da Franquia: "<<p.getVelAlem()<<"Kbps!"<<endl;
    }
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

    cout<<"Numero do celular:"<<c.getNumero()<<endl;
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

void Interface::listarClientes(){
    for (int i = 0;i < cliente.size();i++){
        cout<<"Cliente numero "<<i<<":"<<endl;
        interfaceCliente(cliente[i]);
    }

}

void Interface::listarCelulares(){
    for (int i = 0;i < celular.size();i++){
        cout<<"Celular numero "<<i<<":"<<endl;
        interfaceCelular(celular[i]);
    }

}

void Interface::interfaceLigacao(Ligacao &l){

    if(l.getPlano().getTipo() == true){
    cout<<"\nLigacoes simples:"<<endl;
        for(int i = 0;i<l.getLigsimples().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigSimples(l.getLigsimples()[i]);
        }
        cout<<"Restante dos creditos: "<<l.getPlano().getCred();
    }else{
    cout<<"\nLigacao dados:"<<endl;
        for(int i = 0;i<l.getLigDados().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigDados(l.getLigDados()[i]);
        }
        cout<<"Restante da franquia:"<<l.getPlano().getFran();
    }

    };

void Interface::interfaceLigSimples(LigacaoSimples &ls){

    cout<<"\nData(dia/hora): "<<ls.getDia()<<"/"<<ls.getHora()<<endl;
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

    double numCell;

    cout<<"Digite o numero do celular que sera adicionado os creditos:";
    cin>>numCell;
    if (verificaCelular(numCell) == true){
        double cred;
        cout<<"Digite quantos creditos serao acrescentados:";
        cin>>cred;
        int i = retornaCelular(numCell);
        celular[i].getPlano().setAddCreditos(cred);
    }

}

bool Interface::verificaDataLig(int i,Date &d){

    for(int j = 0;j < dataLig.size();j++){
        if(d < dataLig[j]){
            throw Exception("Nao se pode registrar ligacoes com datas passadas!");
            return false;
            break;
        }
    }
        return true;

}

void Interface::regLigacao(){//Registro de ligacoes na ordem cronologica do tempo. Todas as ligacoe sao feitas em 2019

    double numLigando,numRecebendo;

    cout<<"Digite o numero do celular ligando:";
    cin>>numLigando;
    if(verificaCelular(numLigando) == true){
        int i = retornaCelular(numLigando);
        cout<<"Digite o numero do celular a ligar:";
        cin>>numRecebendo;
        if(verificaCelular(numRecebendo) == true){
            int j = retornaCelular(numRecebendo);
            int hora,dia,mes;
            cout<<"Digite a data da ligacao:"<<endl;
            cout<<"Hora:";cin>>hora;
            cout<<"Dia:";cin>>dia;
            cout<<"Mes:";cin>>mes;
            Date d(hora,dia,mes,2019);
            dataLig.push_back(d);
            if(verificaDataLig(i,d) == true){
                double dura;
                cout<<"Digite a duracao da ligacao:";
                cin>>dura;
                bool simples;
                cout<<"A ligacao eh simples(1) ou de dados(0)?";
                cin>>simples;
                if(simples == true){
                    if(testaValidade(i,d) == true){
                        int gasto = celular[i].getPlano().getVM() * dura;
                        celular[i].getPlano().setDecreCreditos(gasto);
                        celular[i].newLigacaoSimples(d,dura,numRecebendo);
                    }else{
                        cout<<"Nao foi possivel realizar a ligacao simples!"<<endl;
                    }
                }else{
                    bool tipo;
                    cout<<"Foi usado o recurso de download(1) ou upload(1)?";
                    cin>>tipo;
                    if(tipo == true){//Ligacao download
                        if(testaValidade(i,d) == true){
                            double down  = celular[i].getPlano().getVel() * dura * 60;
                            celular[i].getPlano().setDecreFran(down);
                            celular[i].newLigacaoDadosDownload(d,dura,down);
                        }else{
                            cout<<"Nao foi possivel realizar o download!"<<endl;
                        }
                    }else{
                        if(testaValidade(i,d) == true){
                            int up = celular[i].getPlano().getVel()/10 * dura * 60;
                            celular[i].getPlano().setDecreFran(up);
                            celular[i].newLigacaoDadosUpload(d,dura,up);
                        }else{
                            cout<<"Nao foi possivel realizar o upload!"<<endl;
                        }
                    }
                }
            }
        }
    }
}

bool Interface::testaValidade(int i,Date &d){

    if(celular[i].getPlano().testaValidade(d)  == false){
        throw Exception("Plano assinatura com data vencida!");
        return false;
    }else{
        return true;
    }
}

bool Interface::testaFranquia(int i){

    if(celular[i].getPlano().getFran() == 0){
        throw Exception("Esse celular nao tem nenhuma franquia!");
        return false;
    }else if(celular[i].getPlano().getTipo() == true){
        throw Exception("Esse celular nao eh do tipo assinatura!");
    }else{
        return true;
    }
}

void Interface::dadosPacoteInternet(){

    double numCell;
    cout<<"Digite o numero do celular com franquia:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        if(testaFranquia(i) == true){
            double fran = celular[i].getPlano().getFran()/(10*10*10);
            double velD = celular[i].getPlano().getVel();
            double velU = velD/10;
            double velA = celular[i].getPlano().getVelAlem();
            cout<<"--Dados de internet--"<<endl;
            cout<<"Franquia:"<<fran<<"Gbs"<<endl;
            cout<<"Velocidade de download:"<<velD<<"Mbs"<<endl;
            cout<<"Velocidade de upload:"<<velU<<"Mbs"<<endl;
            cout<<"Velocidade alem da franquia:"<<velA<<"Kbps"<<endl;
        }
    }
}

void Interface::listarLigacoesSimples(int i,LigacaoSimples &ls){

    if(celular[i].getPlano().testaValidade(ls.getDate()) == true){
        interfaceLigSimples(ls);
    }else{
        cout<<"Fim da lista de ligacoes simples ate a data de validade desse mes!"<<endl;
    }

}

void Interface::listarLigacoesDados(int i,LigacaoDados &ld){

    if(celular[i].getPlano().testaValidade(ld.getDate()) == true){
        interfaceLigDados(ld);
    }else{
        cout<<"Fim da lista de ligacoes simples ate a data de validade desse mes!"<<endl;
    }

}

void Interface::listarValorDaConta(){

    double numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        if(celular[i].getPlano().getTipo() == true){
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = 0;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    listarLigacoesSimples(i,celular[i].getLigacoes()[j].getLigsimples()[k]);
                }
            }
            cout<<"Creditos restantes:"<<celular[i].getPlano().getCred();
        }else{
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = 0;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
                    listarLigacoesDados(i,celular[i].getLigacoes()[j].getLigDados()[k]);
                }
            }
             cout<<"Franquia restante:"<<celular[i].getPlano().getFran();
        }
    }
}

void interfaceDate(Date &d){

        cout<<"Dia:"<<d.getDia()<<endl;
        cout<<"Mes:"<<d.getMes()<<endl;
        cout<<"Ano:"<<d.getAno()<<endl;

    }

void Interface::listarCreditosData(){

    double numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        if(celular[i].getPlano().getTipo() == true){
            int i = retornaCelular(numCell);
            cout<<"Creditos do celular:"<<celular[i].getPlano().getCred()<<endl;
            cout<<"Data de validade do celular:"<<endl;
            interfaceDate(celular[i].getPlano().getValidade());
        }
    }

}

void Interface::extratoSimples(){

    double numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        int hora,dia,mes;
        cout<<"Digite a data base para verificar o extrato simples:"<<endl;
        cout<<"Hora:";cin>>hora;
        cout<<"Dia:";cin>>dia;
        cout<<"Mes:";cin>>mes;
        Date d(hora,dia,mes,2019);
        if(celular[i].getPlano().getTipo() == true){
            int aux;
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = 0;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    if(celular[i].getLigacoes()[j].getLigsimples()[k].getDate() == d){
                        aux = k;
                        break;
                    }
                }
            }
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = aux;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    listarLigacoesSimples(i,celular[i].getLigacoes()[j].getLigsimples()[k]);
                }
            }
        }

    }

}

void Interface::extratoDados(){

    double numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        int hora,dia,mes;
        cout<<"Digite a data base da ligacao para verificar o extrato dados:"<<endl;;
        cout<<"Hora:";cin>>hora;
        cout<<"Dia:";cin>>dia;
        cout<<"Mes:";cin>>mes;
        Date d(hora,dia,mes,2019);
        if(celular[i].getPlano().getTipo() == false){
            int aux;
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = 0;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
                    if(celular[i].getLigacoes()[j].getLigDados()[k].getDate() == d){
                        aux = k;
                        break;
                    }
                }
            }
            for(int j=0;j<celular[i].getLigacoes().size();j++){
                for(int k = aux;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
                    listarLigacoesDados(i,celular[i].getLigacoes()[j].getLigDados()[k]);
                }
            }
        }

    }

}

void Interface::informarVenciCred(){
    int dia,mes;
    cout<<"Digite a data de hoje:";
    cout<<"Dia:";cin>>dia;
    cout<<"Mes:";cin>>mes;
    Date d(0,dia,mes,2019);
    for(int i = 0;i < cliente.size();i++){
        for(int j = 0;j < cliente[i].getCelulares().size();j++){
            if(cliente[i].getCelulares()[j].getPlano().getTipo() == false){
                if(cliente[i].getCelulares()[j].getPlano().testaValidade(d) == false){
                    cout<<"O celular de numero" <<cliente[i].getCelulares()[j].getNumero()<<" pertencente ao cliente "<<cliente[i].getNome();
                    cout<<" esta com a fatura vencida!"<<endl;
                }
            }else{
                if(cliente[i].getCelulares()[j].getPlano().getCred() == 0){
                    cout<<"O celular de numero" <<cliente[i].getCelulares()[j].getNumero()<<" pertencente ao clinete "<<cliente[i].getNome();
                    cout<<"esta sem credito!"<<endl;
                }
            }
        }
    }

}

void Interface::informarFranquia(){
    for(int i = 0;i < cliente.size();i++){
        for(int j = 0;j < cliente[i].getCelulares().size();j++){
            if(cliente[i].getCelulares()[j].getPlano().getTipo() == false){
                if(cliente[i].getCelulares()[j].getPlano().getFran() == 0){
                    cout<<"O celular de numero" <<cliente[i].getCelulares()[j].getNumero()<<" pertencente ao cliente "<<cliente[i].getNome();
                    cout<<" esta com a framquia zerada!"<<endl;
                }
            }
        }
    }

}
