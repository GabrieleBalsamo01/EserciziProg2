#include <iostream>

using namespace std;

template <typename T>
class Nodo
{

	public:
		T val;
		Nodo<T>* succ;
		Nodo<T>(T x) : val(x) {}
	
};

template <typename T>
class Coda
{
	Nodo<T>* testa;
	
	public:
		Coda()
		{
			testa=NULL;
		}
		
		void enqueue(int x)
		{
			Nodo<T>* nuovo= new Nodo<T>(x);
			nuovo->succ=NULL;
			Nodo<T>*i=testa;
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
			Nodo<T>*i=testa;
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

template <typename U>		
friend ostream& operator << (ostream& out, const Coda<U>& x);		
		
};

template <typename U>
ostream& operator << (ostream& out, const Coda<U>& x)
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
	Coda<int> a;
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
