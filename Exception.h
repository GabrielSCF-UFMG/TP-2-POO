#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<iostream>


class Exception{

    private:

	string tipo_erro;

	public:

		Exception(const string &te):tipo_erro(te){};

		void mensagem_erro(){

			cout<<"Excecao: "<<tipo_erro<<endl;

		}

};



#endif // EXCEPTION_H
