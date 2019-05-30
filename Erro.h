#include<iostream>
#include<string>

using namespace std;

class Erro{
	
	private:
		
	string  tipo_erro;
		
	public:
		
		Erro(const string &te):tipo_erro(te){};
		
		void mensagem_erro(){
			
			cout<<"Erro:"<<tipo_erro<<endl;
			
		}
			
};
