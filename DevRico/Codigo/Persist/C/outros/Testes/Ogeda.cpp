#include <iostream.h>
#include <iomanip.h>


class A 
{ public:
		virtual void M1() { cout << "A::M1" << endl;}
	protected:
		int p;
};

class B :public A
{ public:
		virtual void M1() { cout << "B::M1" << endl;}
		virtual void exibeP() { cout << "B::p=" << p << endl; }
};
	
class C :public B
{ public:
		void M1() { cout << "C::M1" << endl;}
		void exibeP() { cout << "C::p=" << p << endl; }
};

class SuperClasse 
{
	public:
	virtual ~SuperClasse() { cout<<"~SuperClasse"<<endl;};
	SuperClasse() { cout<<"SuperClasse"<<endl;};
};
class  SubClasse :public SuperClasse
{
	public:
	~SubClasse() { cout<<"~SubClasse"<<endl;};
	SubClasse() { cout<<"SubClasse"<<endl;};
};



void main() 
{
	cout << "Teste da heran‡a do protegido" << endl;
	A oA;
	B oB;
	C oC;
	oB.exibeP();
	oC.exibeP();
	cout << "m‚todo virtual POLIMORFISMO em ref" << endl;
	A& rA = oA;
	oA.M1();
	rA = oB;
	oB.M1();
	rA = oC;
	oC.M1();
	cout << "m‚todo virtual POLIMORFISMO em ref c/ cast p/ A" << endl;
	rA = (A&) oA;
	oA.M1();
	rA = (A&) oB;
	oB.M1();
	rA = (A&) oC;
	oC.M1();
	cout << "m‚todo virtual POLIMORFISMO c/ ptr cast A" << endl;
	A* pA;
	pA = &oA;
	pA->M1();
	pA = &oB;
	pA->M1();
	pA = &oC;
	pA->M1();
	cout << "==============================================" << endl;
	SuperClasse *pObj;
	pObj = new SubClasse();
	cout << "---" << endl;
	delete pObj;
}