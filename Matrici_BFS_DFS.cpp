#include <iostream>

using namespace std;

class Nodo
{
	public:
		int val;
		Nodo* succ;
		Nodo(int x) : val(x) {	}
		
};

class Grafro
{
	Nodo* radice;
	public:
		Grafo()
		{
			radice=NULL;
		}
		
	void NuovoNodo(int x)
	{
		Nodo* nuovo=new Nodo(x);	
		nuovo->succ=NULL;	
	}	
	
	void NuovoArco(Nodo* x, Nodo* y)
	{
		x->succ=y;
	}
	
	Nodo* NuovoArco(int x, int y)
	{
		
		//if()
	}
	
};

int main()
{
	return 0;
}
