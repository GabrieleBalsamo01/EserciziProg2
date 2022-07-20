#include <iostream>

using namespace std;

class Nodo
{
	public:
		int val;
		Nodo* succ;		
		Nodo(int x): val(x) {}
};

class Pila
{
	Nodo* testa;
	
	public:
		Pila()
		{
			testa=NULL;
		}
		
	void push(int x)
	{
		Nodo* nuovo=new Nodo(x);
		nuovo->succ=NULL;
		if(testa==NULL)
		{
			testa=nuovo;
			return;	
		}	
		else
		{
			nuovo->succ=testa;
			testa=nuovo;
			return;	
		}
		
	}
	
	void pop()
	{
		Nodo* i= testa;
		if(testa==NULL)
			return;
		else
		{
			testa=i->succ;
			delete i;
			return;
		}	
	}
	
	friend ostream& operator << (ostream& out, const Pila& x);
	
};

ostream& operator << (ostream& out, const Pila& x)
{
	Nodo* i=x.testa;
	while(i)
	{
		out<<i->val<<endl;
		i=i->succ;
	}
	out<<endl;
	return out;
}

int main()
{
	Pila a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	cout<<a<<endl;
	a.pop();
	a.pop();
	a.pop();
	cout<<a<<endl;
	
	a.push(2);
	a.push(8);
	a.push(9);
	a.pop();
	cout<<a<<endl;	
	
	return 0;
}
