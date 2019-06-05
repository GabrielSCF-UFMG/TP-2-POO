#ifndef OPERADORA_H
#define OPERADORA_H

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

        delete [] cliente;
        delete [] plano;
        delete [] celular;

    }

};


#endif // OPERADORA_H
