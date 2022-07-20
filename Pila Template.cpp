#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
	public:
		T val;
		Nodo<T>* succ;		
		Nodo<T>(T x): val(x) {}
};

template <typename T>
class Pila
{
	Nodo<T>* testa;
	
	public:
		Pila()
		{
			testa=NULL;
		}
		
	void push(int x)
	{
		Nodo<T>* nuovo=new Nodo<T>(x);
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
		Nodo<T>* i= testa;
		if(testa==NULL)
			return;
		else
		{
			testa=i->succ;
			delete i;
			return;
		}	
	}
	
	template <typename U>
	friend ostream& operator << (ostream& out, const Pila<U>& x);
	
};

template <typename U>
ostream& operator << (ostream& out, const Pila<U>& x)
{
	Nodo<U>* i=x.testa;
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
	Pila<char> a;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	cout<<a<<endl;
	a.pop();
	a.pop();
	cout<<a<<endl;
	
	a.push('e');
	a.push('f');
	a.pop();
	cout<<a<<endl;	
	
	return 0;
}
