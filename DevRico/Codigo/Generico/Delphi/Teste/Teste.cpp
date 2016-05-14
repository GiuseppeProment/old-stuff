#include <iostream.h>
#include <iomanip.h>

// objetivo:
// 	Uma classe que possa criar objetos de tipos variados

class Persistente 
{
	public:
		Persistente() {cout << "Persistente()" << endl;};
		~Persistente() {cout << "~Persistente()" << endl;};
		virtual char* Identifica() {return "Persistente";};
};

class Pessoa :public Persistente
{
	public:
		Pessoa() { cout << "Pessoa()" << endl; };
		~Pessoa() { cout << "~Pessoa()" << endl; };
		char* Identifica() { return "Pessoa";};
		static Persistente* novoObjeto() { return new Pessoa(); };
		static void deletaObjeto(Persistente* obj) { cout <<"metodo destrutor"<<endl;delete (Pessoa*) obj; return;};
};



class Colecao
{
  public:
    Colecao(Persistente* (*paramMetodoCriador) (void),void (*paramMetodoDestrutor) (Persistente*) ) 
		{ pMetodoCriador = paramMetodoCriador;
		  pMetodoDestrutor = paramMetodoDestrutor;};
    ~Colecao() { if (objPersistente!=NULL) pMetodoDestrutor(objPersistente);  };
		Persistente *objPersistente;	
		Persistente* Crie() {
			objPersistente = pMetodoCriador();
			return objPersistente;
		}
    Persistente* (*pMetodoCriador) (void);
    void (*pMetodoDestrutor) ( Persistente* );
};


void main()
{
	cout << "*** Inicio ***" << endl;
	Colecao ColecaoPessoa(&Pessoa::novoObjeto,&Pessoa::deletaObjeto);
	Pessoa *objPessoa;
	objPessoa = (Pessoa*) ColecaoPessoa.Crie();
	cout << ((Persistente*)objPessoa)->Identifica() << endl;
	cout << objPessoa->Identifica() << endl;
	cout << "*** teste    ***" << endl;
	Persistente* objPtr = new Pessoa();
	cout << "identifica=" << objPtr->Identifica() << endl;
	delete (Pessoa*)objPtr;
	cout << "*** Fim    ***" << endl;
}