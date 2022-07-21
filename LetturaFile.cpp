#include <iostream>
#include <fstream>
#include <string>
#define N 2000
using namespace std;

class Utente
{
	int id;
	string cognome;
	string nome;
	double pop;

public:
	Utente(){}
	Utente(int x, string y, string z, double w): id(x), cognome(y), nome(z), pop(w) {}
	
	bool operator>(const Utente& u) const
	{ 
		return pop>u.getPopularity();
	}
	
	bool operator==(const Utente& u) const
	{ 
		return pop==u.getPopularity();
	}
	
	bool operator!=(const Utente& u) const
	{ 
		return pop!=u.getPopularity();
	}

	int getId() const
	{
		return id;
	}
	
	string getCognome() const
	{
		return cognome;
	}
	
	string getNome() const
	{
		return nome;
	}
	
	double getPopularity() const
	{
		return pop;
	}
	
friend ostream& operator<<(ostream& out, const Utente& u);
friend istream& operator>>(istream& input, Utente &user);
	
};


ostream& operator<<(ostream& out, const Utente& u)
{
	out << "[Popolarita':"<<u.pop << ", Id: " << u.id << ", Cognome: " << u.cognome<<"] " ;	
	return out;
}


istream& operator>>(istream& input, Utente &user)
{
	string id, pop;
	getline(input, id, ';');
	getline(input, user.cognome, ';');
	getline(input, user.nome, ';');
	getline(input, pop, '\n');
	user.id = stoi(id.c_str());
	user.pop = stod(pop.c_str());
	return input;
}

// per stampare tutta la Utente
void stampaUtenti(Utente users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}

//per stampare solo parte di una Utente (in totale 10)
/*void stampaUtenti(Utente users[], int n, int maxval=10)
{
	cout << "Contenuto array:" << endl;
	
	if(n>maxval)
	{
		for(int i=0;i<maxval/2;i++)
			cout << users[i];
		cout << "... " << endl;
		for(int i = n-maxval/2;i<n;i++)
			cout << users[i];
			}
	else
		for(int i=0;i<n;i++)
			cout << users[i];
}*/

int leggi(Utente utenti[])
{
	int num = 0;
	ifstream ifs("utenti - Copia.txt");
	while(ifs.good())
	{
		Utente u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

void insertionSort(Utente arr[], int n)
{
	int j;
	Utente appoggio;
	for(int i=0;i<n;i++)
	{
		appoggio = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>appoggio)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = appoggio;
	}
}


class Nodo
{
	public:
		Utente val;
		Nodo* succ;
		Nodo* left;
		Nodo* right;
		Nodo* parent;
		Nodo(Utente x) : val(x) {}
		
		double getP()
		{
			return val.getPopularity();
		}
};

class Lista
{
	Nodo* testa;
	public:
		Lista()
		{
			testa=NULL;
		}
	
	void inserimento(Utente arr[],int n)
	{
		Nodo* uno=new Nodo(arr[0]);
		Nodo* due=new Nodo(arr[1]);
		if(testa==NULL)
		{
			testa=uno;
			testa->succ=NULL;
		}
		if(testa->succ==NULL)
		{	
			testa->succ=due;
		}
		
		Nodo* x=due;
		for(int i=2; i<n; i++)
		{			
			Nodo* nuovo=new Nodo(arr[i]);
			if(nuovo!=NULL)
			{
				x->succ=nuovo;
				nuovo->succ = NULL;
				x = nuovo;
			}		
		}
	}
	
friend ostream& operator<<(ostream& out, const Lista& ls);
};

class Albero
{
	Nodo* radice;
	
	public:
		Albero()
		{
			radice=NULL;
		}
		
		void inserimento(Utente x, int n)
		{	
			Nodo* nuovo= new Nodo(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			Nodo* i=radice;
			double a;
			double b;
			if(radice==NULL)
			{
				radice=nuovo;
				nuovo->parent=NULL;
				return;
			}
			
			while(i)
			{
				a= x.getPopularity();
				b=i->getP();
				if(a < b)
				{
					if(i->left==NULL)
					{
						i->left=nuovo;
						nuovo->parent=i;
						return;
					}
					i=i->left;		
				}
				else
				{
					if(i->right==NULL)
					{
						i->right=nuovo;
						nuovo->parent=i;
						return;
					}
					i=i->right;	
				}
			}
			
		}
		
		int altezza(Nodo* p)const
	    {
	    	if (p==NULL) return 0;		
	
		    int lh = altezza(p->left);
		    int rh = altezza(p->right);
		
		    if(lh>rh)   
				return (lh+1);
		    else        
				return (rh+1);
		}	
friend ostream& operator << (ostream& out, const Albero& x);	
};

void stampaLivello(Nodo* p, int level)
{ 
    if(p == NULL)						// se p punta ad una posizione vuota
	{
        if (level==0) 					// se siamo al livello 0 quindi quello della foglia finale
			cout << "_\t";
        return;
    }

    if(level == 0)						// se siamo al livello 0
       cout << p->val << "\t";			// stampa il valore del nodo presente in quel livello (essendo solo uno, non serve fare altro)
    else if(level>0)					// se siamo ad un livello superiore
	{					
        stampaLivello(p->left,level-1);		// richiama la funzione passando il figlio sinistro e decrementa il livello di uno
        stampaLivello(p->right,level-1);	// richiama la funzione passando il figlio destro e decrementa il livello di uno
    }

}

ostream& operator<<(ostream&out, const Albero& x)
{
    int h = x.altezza(x.radice);
    for(int i=0;i<h;i++)
	{
        stampaLivello(x.radice, i);
        cout << endl;
    }
    return out;
}

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
	int n;
	Utente x[N];
	n = leggi(x);								// con n ci prendiamo la dimensione esatta della Utente
	insertionSort(x,n);
	cout<<"Array utenti ordinato: "<<endl;
	stampaUtenti(x,n);
	cout<<endl<<endl;
	Lista lista;
	lista.inserimento(x,n);
	cout<<"Lista: "<<endl;
	cout<< lista<<endl<<endl;
	
	int m;
	Utente y[N];
	m=leggi(y);
	Albero tree;
	cout<<"Albero: "<<endl;
	for(int i=0; i<n; i++)
	{
		tree.inserimento(y[i],n);
	}
	
	cout<<tree<<endl;
	return 0;
}
