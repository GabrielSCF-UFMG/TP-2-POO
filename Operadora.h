#ifndef OPERADORA_H
#define OPERADORA_H

class Cliente;
class Plano;
class Celular;
class Date;

class Operadora{

private:

    vector <Cliente>cliente;
    vector <Plano> plano;
    vector <Celular> celular;

public:

    Operadora(){};

    vector <Cliente> &getCliente(){return cliente;};
    vector <Plano>   &getPlano  (){return plano  ;};
    vector <Celular> &getCelular(){return celular;};

    void setPlano(vector <Plano> &p){plano = p;}
    void setCliente(vector <Cliente> &c){cliente = c;}
    void setCelular(vector <Celular> &cell){celular = cell;}

    ~Operadora(){

        for(unsigned int i = 0;i < cliente.size();i++){
            cliente[i].~Cliente();
        }
        for(unsigned int i = 0;i < plano.size();i++){
            plano[i].~Plano();
        }
        for(unsigned int i = 0;i < celular.size();i++){
            celular[i].~Celular();
        }


    }

};


#endif // OPERADORA_H
