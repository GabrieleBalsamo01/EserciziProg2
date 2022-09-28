#include <iostream>

using namespace std;

class Nodo
{
	public:
		int val;
		Nodo* succ;
		Nodo* prec;
};

class Lista
{
	Nodo* testa;
	
	public:
		Lista() 
		{
			testa=NULL;
		}
		
	void inserimento(int x)
	{
		Nodo* nuovo = new Nodo;
		nuovo->val=x;
		nuovo->succ=NULL;
		nuovo->prec=NULL;
		if(testa==NULL)
		{
			testa=nuovo;
			return;
		}
		Nodo* i=testa;
		while(i->succ)
		{
			i=i->succ;
		}
		i->succ=nuovo;	
		nuovo->prec=i;		
	}
	
	void insordinato(int x)
	{
		Nodo* nuovo = new Nodo;
		nuovo->val=x;
		if(testa==NULL)
		{
			testa=nuovo;
			nuovo->succ=NULL;
			nuovo->prec=NULL;
			return;
		}
		if(nuovo->val < testa->val)
		{
			nuovo->prec=NULL;
			nuovo->succ=testa;
			testa=nuovo;
			return;
		}
		Nodo* i=testa;
		while(i->succ!=NULL && nuovo->val > i->succ->val)
		{
			i=i->succ;
		}
		nuovo->prec=i;
		nuovo->succ=i->succ;
		i->succ->prec=nuovo;	
		i->succ=nuovo;	
		return;
	}

	void cancellazione(int x)
	{
		Nodo* i=testa;
		Nodo* appoggio= new Nodo;
		appoggio=NULL;
		if(i->val==x)
		{
			i.succ->prec=NULL;
			testa=i->succ;
			delete i;
			return;
		}
		while(i->succ!=NULL)
		{
			
			if(i->succ->val==x)
			{
				if(i->succ->succ==NULL)
				{
					delete i->succ;	
					i->succ=NULL;
					return;
				}
					
				appoggio=i->succ->succ;
				delete i->succ;
				appoggio->prec=i;
				i->succ=appoggio;
				return;		
			}		
			i=i->succ;
		}
		cout<< x << " non e' presente in lista"<<endl;
		return;
	}	
		
	friend ostream& operator<<(ostream& out, const Lista& ls);
};

ostream& operator<<(ostream& out, const Lista& ls)
{
    Nodo* i = ls.testa;						
    while(i!=NULL)							
	{
        out << i->val << " --> ";			
        i = i->succ;						
    }
    cout << "NULL" << endl;						
    return out;		
}


int main()
{
	Lista ciao;
	ciao.inserimento(5);
	ciao.inserimento(4);
	ciao.inserimento(9);
	ciao.inserimento(6);
	
	cout<<ciao<<endl;
	
	Lista due;
	due.insordinato(8);
	due.insordinato(3);
	due.insordinato(1);
	due.insordinato(4);
	due.insordinato(9);
	
	cout<<due<<endl;
	
	due.cancellazione(9);
	due.cancellazione(1);
	due.cancellazione(19);
	
	cout<<due<<endl;
	return 0;
}
