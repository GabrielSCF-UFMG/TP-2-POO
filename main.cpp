#include<iostream>

#include "Cliente.h"

#include "Interface.h"
#include "Exception.h"

bool Interface::verificaDadosNovoCliente(string CPF,string nome){
    for (auto & i : cliente){
        if(i.getCPF() == CPF){
            throw Exception("O CPF solicitado ja existe!");

        }
        if (!(i.getNome() == nome))continue;
        throw Exception("Existe um cliente cadastrada nesse nome!");

    }
        return true;

}

bool Interface::verificaPlano(string pName){
    for (auto & i : plano){
        if (!(i.getNome() == pName))continue;
        throw Exception("Esse nome ja pertence a outro plano!");

    }
        return true;
}

bool Interface::verificaIndexPlano(int i){

    unsigned int j = i;
    if (!(j >= plano.size()) && !(j < 0)) {
        return true;
    } else {
        return false;

    }

}

bool Interface::verificaIndexCliente(int i){

    unsigned int j = i;
    if (j >= cliente.size() || j < 0) {
        return false;

    } else {
        return true;
    }

}

bool Interface::verificaCelular(double num){
    for (auto & i : celular){
        if(i.getNumero() == num){
            return true;

        }
    }
        throw Exception("Esse numero de celular nao existe!");

}



int Interface::retornaCelular(int num){
    for (unsigned int i = 0;i < celular.size();i++){
        if(celular[i].getNumero() == num){
            return i;
            break;
        }
    }
        throw Exception("Esse numero de celular nao existe!");
}

void Interface::cadastrarCliente(){
    cout<<"\n\t--CADASTRANDO NOVO CLIENTE--"<<endl;
    string CPF;string nome;string endereco;
    cout<<"Digite o CPF do novo cliente:";
    cin>>CPF;
    cout<<"Digite o nome do novo cliente:";
    cin>>nome;
    cout<<"Digite o endereco do novo cliente:";
    cin>>endereco;
    if(verificaDadosNovoCliente(CPF,nome)){
        cliente.push_back(Cliente(CPF,nome,endereco));
        cout<<"\t--CLIENTE CADASTRADO COM SUCESSO!--"<<endl;
    }else{
        throw("\t--CLIENTE NAO PODE SER CADASTRADO!--");
    }

}

void Interface::cadastrarPlano(){
    cout<<"\n\t--CADASTRANDO NOVO PLANO--"<<endl;
    string pName = "Plano1";double vMin = 0.0;double vel = 0.0;double fran = 0.0;double vAlem = 0.0;int tipo = 0, cred = 0;bool preOrPos = true;
    cout<<"Digite o nome do plano:";
    cin>>pName;
    cout<<"Esse plano sera do tipo cartao (Pre-pago,1) ou assinatura (Pos-Pago,0):";
    cin>>tipo;

    preOrPos = tipo == 1;

    if (!preOrPos) {
        cout << "Digite a velocidade da internet em Mbps:";
        cin >> vel;
        cout << "Digite a quantia da franquia em Gbs:";
        cin >> fran;
        cout << "Digite a velocidade alem da franquia em Kbps:";
        cin >> vAlem;
    } else {
        cout << "Digite o valor do minuto da ligacao em centavos:";
        cin >> vMin;
        cout << "Digite a quantidade de creditos inicais do plano:";
        cin >> cred;

    }

    int dia,mes;
    cout<<"Digite a data de vencimento do plano:";
    cout<<"\nDia:";cin>>dia;
    cout<<"Mes:";cin>>mes;
    Date d(0,dia,mes,2019);

    if(verificaPlano(pName)){
        plano.push_back(Plano(cred,pName,vMin,vel,fran,vAlem,preOrPos,d));
        cout<<"\t--PLANO CADASTRADO COM SUCESSO!--"<<endl;
    }else{
        throw("\t--PLANO NAO PODE SER CADASTRADO!--");
    }

}

void Interface::cadastrarCelular(){
    int nPlano,nCliente;

    cout<<"\n\t--CADASTRANDO NOVO CELULAR--\n";
    cout<<"Escolha o plano do celular pelo seu numero:"<<endl;
    listarPlanos();
    cout<<"\nNumero do plano escolhido:";cin>>nPlano;

    if(verificaIndexPlano(nPlano)){

    cout<<"Escolha o cliente que recebera o celular pelo seu numero:"<<endl;
    listarClientes();
    cout<<"\nNumero do cliente escolhido:";cin>>nCliente;
        if(verificaIndexCliente(nCliente)){
            Celular novoCelular(plano[nPlano]);

            celular.push_back(novoCelular);//Cria o novo celular com o plano escolhido
            cout<<"Celular criado com sucesso!\n";
            cliente[nCliente].getNewCellPhone(novoCelular);//Atribui ao cliente escolhido o novo celular

            cout<<"\nCliente "<<cliente[nCliente].getNome()<<" acaba de ganhar um novo celular de numero :" <<novoCelular.getNumero()<<endl;

        }
    }
}

void Interface::interfacePlano(Plano &p){

    if(p.getTipo()){
    cout<<"\nNome do plano: "<<p.getNome()<<endl;
    cout<<"Valor do minuto: "<<p.getVM()<<" centavos!"<<endl;
    cout<<"Creditos iniciais:  "<<p.getCred()<<" centavos!"<<endl;
    }
    else if(!p.getTipo()){
    cout<<"Velocidade da internet: "<<p.getVel()<<" Mbps!"<<endl;
    cout<<"Franquia: "<<p.getFran()<<"Mb!" <<endl;
    cout<<"Velocidade alem da Franquia: "<<p.getVelAlem()<<"Kbps!"<<endl;
    }

}

void Interface::interfaceCliente(Cliente &c){

    cout<<"CPF do cliente:"<<c.getCPF() <<endl;
    cout<<"Nome do cliente:"<<c.getNome() <<endl;
    cout<<"Endereco do cliente:"<<c.getEndereco() <<endl;
    if(c.getCelulares().size() == 0){
        cout<<"Esse cliente nao tem um celular!"<<endl;
    }else{
        cout<<"Numero de celulares do cliente:"<<c.getCelulares().size()<<endl;
        for(unsigned int i = 0;i < c.getCelulares().size();i++){
            cout<<"Celular "<<i<<":\n";
            interfaceCelular(c.getCelulares()[i]);
        }
    }

}

void Interface::interfaceCelular(Celular &c){

    cout<<"Numero do celular:"<<c.getNumero()<<endl;
    interfacePlano(c.getPlano());
    if(numeroLigacoes(c) == 0){
        cout<<"Esse celular nao realizou nenhuma ligacao"<<endl;
    }else{
        cout<<"O celular tem "<<numeroLigacoes(c)<<" ligacoes"<<endl;
        for(int i = 0;i < numeroLigacoes(c);i++){
            interfaceLigacao(c.getLigacoes()[i]);
        }
    }

}

int Interface::numeroLigacoes(Celular &c){
    int n = 0;
    for(unsigned int i = 0;i < c.getLigacoes().size();i++){
        n += c.getLigacoes()[i].getNumLigacoes();
    }
    return n;
}

void Interface::listarPlanos(){

    cout<<"\n\t--LISTANDO PLANOS--";
    for (unsigned int i = 0;i < plano.size();i++){
        cout<<"\nPlano numero "<<i<<":"<<endl;
        interfacePlano(plano[i]);
    }
}

void Interface::listarClientes(){

    cout<<"\n\t--LISTANDO CLIENTES--";
    for (unsigned int i = 0;i < cliente.size();i++){
        cout<<"\nCliente numero "<<i<<":"<<endl;
        interfaceCliente(cliente[i]);
    }

}

void Interface::listarCelulares(){

    cout<<"\n\t--LISTANDO CELULARES--\n";
    for (unsigned int i = 0;i < celular.size();i++){
        cout<<"\nCelular numero "<<i<<":"<<endl;
        interfaceCelular(celular[i]);
    }

}

void Interface::listarNumeroCelulares(){

    cout<<"\n\t--LISTANDO OS NUMEROS DOS CELULARES E SEUS RESPECTIVOS DONOS--"<<endl;
    for(unsigned int i = 0;i < cliente.size();i++){
        for(unsigned int j = 0;j < cliente[i].getCelulares().size();j++){
            cout<<"\nNumero de celular: "<<cliente[i].getCelulares()[j].getNumero()<<endl;
            cout<<"Nome do cliente: "<<cliente[i].getNome()<<endl;
        }
    }

}

void Interface::interfaceLigacao(Ligacao &l){

    if(l.getPlano().getTipo() == true){
    cout<<"\nLigacoes simples:"<<endl;
        for(unsigned int i = 0;i<l.getLigsimples().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigSimples(l.getLigsimples()[i]);
        }
        cout<<"Restante dos creditos: "<<l.getPlano().getCred();
    }else{
    cout<<"\nLigacao dados:"<<endl;
        for(unsigned int i = 0;i<l.getLigDados().size();i++){
            cout<<i<<":"<<endl;
            interfaceLigDados(l.getLigDados()[i]);
        }
        cout<<"Restante da franquia:"<<l.getPlano().getFran();
    }

    };

void Interface::interfaceLigSimples(LigacaoSimples &ls){

    cout<<"\nDia da ligacao: "<<ls.getDia()<<endl;
    cout<<"Duracao: "<<ls.getDuracao()<<endl;
    cout<<"Custo: "<<ls.getCusto()<<" reais!"<<endl;
    cout<<"Numero do celular ligado: "<<ls.getNum()<<endl;
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

    int numCell;

    cout<<"Digite o numero do celular que sera adicionado os creditos:";
    cin>>numCell;
    if (verificaCelular(numCell) ){
        double cred;
        cout<<"Digite quantos creditos serao acrescentados:";
        cin>>cred;
        int i = retornaCelular(numCell);
        celular[i].getPlano().setCredito(cred);
    }else{
        double fran;
        cout<<"Digite quantos creditos na franquia serao acrescentados:";
        cin>>fran;
        int i = retornaCelular(numCell);
        celular[i].getPlano().setFranquia(fran);
    }

}

bool Interface::verificaDataLig(int i,Date &d){



    for(unsigned int j = 0;j < dataLig.size();j++){
        if(d < dataLig[j]){
            throw Exception("Nao se pode registrar ligacoes com datas passadas!");
            return false;
            break;
        }
    }
        return true;

}

int Interface::clienteNum(int num){

    for(unsigned int i = 0;i < cliente.size();i++){
        for(unsigned int j = 0;j< cliente[i].getCelulares().size();j++){
            if(cliente[i].getCelulares()[j].getNumero() == num){
                return i;
            }
        }
    }

    return 0;
}

void Interface::regLigacao(){//Registro de ligacoes na ordem cronologica do tempo. Todas as ligacoe sao feitas em 2019

    int numLigando,numRecebendo;
    cout<<"\n\t--REGISTRANDO NOVA LIGACAO--\n";
    listarNumeroCelulares();
    bool simples;
    cout<<"Digite o numero do celular ligando:";
    cin>>numLigando;
    if(verificaCelular(numLigando)){
        int i = retornaCelular(numLigando);
        cout<<"A ligacao eh simples(1) ou de dados(0)?";
        cin>>simples;

        int hora,dia,mes;
        cout<<"Digite a data da ligacao:"<<endl;
        cout<<"Hora:";cin>>hora;
        cout<<"Dia:";cin>>dia;
        cout<<"Mes:";cin>>mes;
        Date d(hora,dia,mes,2019);
        dataLig.push_back(d);

        if(simples == true){
        if(verificaCelular(numLigando)){
            cout<<"Digite o numero do celular a ligar:";
            cin>>numRecebendo;
            if (verificaCelular(numRecebendo)) {
                int j = retornaCelular(numRecebendo);
                if (verificaDataLig(i, d)) {
                    double dura1;
                    cout << "Digite a duracao da ligacao:";
                    cin >> dura1;
                    if (testaValidade(i, d)) {
                        interfaceCelular(celular[i]);
                        double credIni = celular[i].getPlano().getCred();
                        cout << "Creditos do celular antes da ligacao: " << credIni << endl;
                        double gasto = celular[i].getPlano().getVM() * dura1;
                        cout << "Creditos do celular apos a ligacao: " << credIni - gasto << endl;

                        celular[i].getPlano().setCredito(gasto*(-1));
                        celular[i].newLigacaoSimples(d, dura1, numRecebendo);
                        int cLig = clienteNum(numLigando);
                        int cRec = clienteNum(numRecebendo);
                        cout << "" << cliente[cLig].getNome() << " ligou para " << cliente[cRec].getNome()
                             << " com sucesso!";
                    } else {
                        cout << "Nao foi possivel realizar a ligacao simples!" << endl;
                    }
                }
            }
        }
        }
        else{
                    if(verificaDataLig(i,d) == true){
                        double dura;
                        cout<<"Digite a duracao em minutos para se fazer o download ou upload:";
                        cin>>dura;

                    bool tipo;
                    cout<<"Foi usado o recurso de download(1) ou upload(0)?";
                    cin>>tipo;
                    if(tipo == true){//Ligacao download
                        if(testaValidade(i,d) == true){
                            double down  = celular[i].getPlano().getVel() * dura * 60;

                            double credIni = celular[i].getPlano().getFran();
                            cout << "Franquia do celular antes da ligacao: " << credIni << endl;
                            cout << "Franquia do celular apos a ligacao: " << credIni - down << endl;


                            celular[i].getPlano().setCredito(down*(-1));
                            celular[i].newLigacaoDadosDownload(d,dura,down);

                            cout<<"Download concluido com sucesso!"<<endl;
                        }else{
                            cout<<"Nao foi possivel realizar o download!"<<endl;
                        }
                        }else{
                            if(testaValidade(i,d) == true){
                                double up = celular[i].getPlano().getVel()/10 * dura * 60;

                                double credIni = celular[i].getPlano().getFran();
                                cout << "Franquia do celular antes da ligacao: " << credIni << endl;
                                cout << "Franquia do celular apos a ligacao: " << credIni - up << endl;

                                celular[i].getPlano().setCredito(up*(-1));
                                celular[i].newLigacaoDadosUpload(d,dura,up);

                                cout<<"Upload concluido com sucesso!"<<endl;
                            }else{
                                cout<<"Nao foi possivel realizar o upload!"<<endl;
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

    int numCell;
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

    int numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    cout<<"\n\t--LIGACOES DO CELULAR--\n";
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        if(celular[i].getPlano().getTipo() == true){
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = 0;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    listarLigacoesSimples(i,celular[i].getLigacoes()[j].getLigsimples()[k]);
                }
            }
            cout<<"Creditos restantes:"<<celular[i].getPlano().getCred();
        }else{
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = 0;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
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

    int numCell;
    cout<<"Digite o numero do celular a verificar a conta:";
    cin>>numCell;
    if(verificaCelular(numCell) ==  true){
        int i = retornaCelular(numCell);
        if(celular[i].getPlano().getTipo() == true){
            int i = retornaCelular(numCell);
            cout<<"Creditos do celular:"<<celular[i].getPlano().getCred()<<endl;
            cout<<"Data de validade do celular:"<<endl;
            interfaceDate(celular[i].getPlano().getValidade());
        }else{
            int i = retornaCelular(numCell);
            cout<<"Franquia do celular:"<<celular[i].getPlano().getFran()<<endl;
            cout<<"Data de validade do celular:"<<endl;
            interfaceDate(celular[i].getPlano().getValidade());
        }
    }

}

void Interface::extratoSimples(){

    int numCell;
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
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = 0;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    if(celular[i].getLigacoes()[j].getLigsimples()[k].getDate() == d){
                        aux = k;
                        break;
                    }
                }
            }
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = aux;k < celular[i].getLigacoes()[j].getLigsimples().size();k++){
                    listarLigacoesSimples(i,celular[i].getLigacoes()[j].getLigsimples()[k]);
                }
            }
        }

    }

}

void Interface::extratoDados(){

    int numCell;
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
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = 0;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
                    if(celular[i].getLigacoes()[j].getLigDados()[k].getDate() == d){
                        aux = k;
                        break;
                    }
                }
            }
            for(unsigned int j=0;j<celular[i].getLigacoes().size();j++){
                for(unsigned int k = aux;k < celular[i].getLigacoes()[j].getLigDados().size();k++){
                    listarLigacoesDados(i,celular[i].getLigacoes()[j].getLigDados()[k]);
                }
            }
        }

    }

}

void Interface::informarVenciCred(){
    int dia,mes;
    cout<<"Digite a data de hoje:"<<endl;
    cout<<"Dia:";cin>>dia;
    cout<<"Mes:";cin>>mes;
    Date d(0,dia,mes,2019);
    for(unsigned int i = 0;i < cliente.size();i++){
        for(unsigned int j = 0;j < cliente[i].getCelulares().size();j++){
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
    for(unsigned int i = 0;i < cliente.size();i++){
        for(unsigned int j = 0;j < cliente[i].getCelulares().size();j++){
            if(cliente[i].getCelulares()[j].getPlano().getTipo() == false){
                if(cliente[i].getCelulares()[j].getPlano().getFran() == 0){
                    cout<<"O celular de numero" <<cliente[i].getCelulares()[j].getNumero()<<" pertencente ao cliente "<<cliente[i].getNome();
                    cout<<" esta com a franquia zerada!"<<endl;
                }
            }
        }
    }

}


int main(){

    Interface i;

    try {
        i.cadastrarPlano();

        i.cadastrarCliente();

        i.cadastrarCelular();

        i.regLigacao();

    }catch (Exception &e){
        e.mensagem_erro();
    }
	return 0;

}

