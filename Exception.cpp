#include<iostream>
#include<string>

#include "main.cpp"



class Exception{
	
	private:
		
		string tipo_erro;
		
	public:
		
		Exception(string te):tipo_erro(te){};
		
		void mensagem_erro(){
			
			cout<<"Erro:"<<tipo_erro<<endl;
			
		}
			
};
