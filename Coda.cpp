#include <iostream>

using namespace std;

class Nodo
{

	public:
		int val;
		Nodo* succ;
		Nodo(int x) : val(x) {}
	
};

class Coda
{
	Nodo* testa;
	
	public:
		Coda()
		{
			testa=NULL;
		}
		
		void enqueue(int x)
		{
			Nodo* nuovo= new Nodo(x);
			nuovo->succ=NULL;
			Nodo*i=testa;
			if(testa==NULL)
			{
				testa=nuovo;
				return;
			}
			while(i)
			{
				if(i->succ==NULL)
				{
					i->succ=nuovo;
					nuovo->succ=NULL;
					return;
				}
				i=i->succ;
			}	
		}
		
		void dequeue()
		{
			Nodo*i=testa;
			if(testa==NULL)
				return;
				
			if(i->succ==NULL)			// nel caso in cui ci fosse un solo elemento
			{
				testa=NULL;
				delete i;
				return;	
			}	
			else
			{
				testa=i->succ;
				delete i;
				return;
			}
		}
		
		bool isEmpty()
		{
			if(testa==NULL)
				return true;
		}
		
friend ostream& operator << (ostream& out, const Coda& x);		
		
};

ostream& operator << (ostream& out, const Coda& x)
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
	Coda a;
	a.enqueue(1);
	a.enqueue(2);
	a.enqueue(3);
	a.enqueue(4);
	a.enqueue(5);
	a.enqueue(6);
	cout<<a<<endl;
	a.dequeue();
	a.dequeue();
	a.dequeue();
	cout<<a<<endl;


	a.enqueue(2);
	a.enqueue(8);
	a.enqueue(9);
	a.dequeue();
	cout<<a<<endl;	

	
	return 0;
}
