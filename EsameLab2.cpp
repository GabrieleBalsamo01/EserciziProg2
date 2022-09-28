/*
Si legga il file e si inseriscano gli elementi in una lista semplicemente linkata, modellando gli elementi con una oppurtuna classe, che 
ridefinisca anche l'operatore <<. Si rimuovano gli elementi della lista e si inseriscano in un BST, che dovrà implementare le funzionalità di:
- Inserimento di un nuovo nodo
- Visualizzazione degli elementi
*/

#include <iostream>
#include <fstream>
#include <string>
#define N 2000
using namespace std;

class Utente
{
	int anno;
	string nome;
	double voto;


public:
	Utente(){}
	Utente(int x, string y, double z): anno(x), nome(y), voto(z) {}
	
	bool operator>(const Utente& u) const
	{ 
		return voto>u.getVoto();
	}
	
	bool operator==(const Utente& u) const
	{ 
		return voto==u.getVoto();
	}
	
	bool operator!=(const Utente& u) const
	{ 
		return voto!=u.getVoto();
	}

	int getAnno() const
	{
		return anno;
	}
	
	string getNome() const
	{
		return nome;
	}
	
	double getVoto() const
	{
		return voto;
	}
	
friend ostream& operator<<(ostream& out, const Utente& u);
friend istream& operator>>(istream& input, Utente &user);
	
};


ostream& operator<<(ostream& out, const Utente& u)
{
	out << "[Voto: "<<u.voto << ", Nome: " << u.nome << ", Anno: " << u.anno<<"] " ;	
	return out;
}


istream& operator>>(istream& input, Utente &user)
{
	string anno_st, voto_st;
	getline(input, user.nome, ';');
	getline(input, anno_st, ';');	
	getline(input, voto_st, '\n');
	user.anno = stoi(anno_st.c_str());
	user.voto = stod(voto_st.c_str());
	return input;
}

void stampaUtenti(Utente users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}


int leggi(Utente utenti[])
{
	int num = 0;
	ifstream ifs("film.txt");
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
			return val.getVoto();
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

	void cancellazione()
	{
		Nodo* appoggio=testa->succ;
		delete testa;
		testa=appoggio;
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
				a= x.getVoto();
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
	
		    int a = altezza(p->left);
		    int b = altezza(p->right);
		
		    if(a>b)   
				return (a+1);
		    else        
				return (b+1);
		}
		
		Nodo* getradice()
		{
			return radice;
		}
		
		void inorder(Nodo* i)
		{
			if(i)
			{
				inorder(i->left);
				cout<< i->val<<" ";
				inorder(i->right);
			}
		}	
friend ostream& operator << (ostream& out, const Albero& x);	
};

void stampa(Nodo* p, int l)
{ 
    if(p == NULL)						// se p punta ad una posizione vuota
	{
        if (l==0) 					// se siamo al livello 0 quindi quello della foglia finale
			cout << "_\t";
        return;
    }

    if(l == 0)						// se siamo al livello 0
       cout << p->val << "\t";			// stampa il valore del nodo presente in quel livello (essendo solo uno, non serve fare altro)
    else if(l>0)					// se siamo ad un livello superiore
	{					
        stampa(p->left,l-1);		// richiama la funzione passando il figlio sinistro e decrementa il livello di uno
        stampa(p->right,l-1);	// richiama la funzione passando il figlio destro e decrementa il livello di uno
    }

}

ostream& operator<<(ostream&out, const Albero& x)
{
    int h = x.altezza(x.radice);
    for(int i=0;i<h;i++)
	{
        stampa(x.radice, i);
        cout << endl;
    }
    return out;
}

int main()
{
/*	int n;
	Utente x[N];
	n = leggi(x);								// con n ci prendiamo la dimensione esatta della Utente
	insertionSort(x,n);
	Lista lista;
	lista.inserimento(x,n);
	cout<<"Lista: "<<endl;
	cout<<lista<<endl;
	*/
	int m;
	Utente y[N];
	m=leggi(y);
	Albero tree;
	for(int i=0; i<m; i++)
	{
		tree.inserimento(y[i],m);
	//	lista.cancellazione();
	}
	//cout<<"Lista dopo la cancellazione: "<<lista<<endl;
	cout<<"Albero: "<<endl;
	cout<<tree<<endl;
/*	
	cout<<endl<<"Visita inOrder: ";
	tree.inorder(tree.getradice());
	*/
	return 0;
}
