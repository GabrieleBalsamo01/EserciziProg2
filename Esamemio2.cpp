/* Creare un albero in base all'anno di nascita ma stampando nome e cognome */


#include <iostream>
#include <fstream>
#include <string>
#define N 2000
using namespace std;

class A
{
	int anno;
	string nome;
	string cognome;


public:
	A(){}
	A(string y, string z, int x): anno(x), nome(y), cognome(z) {}
	
	bool operator>(const A& u) const
	{ 
		return anno>u.getAnno();
	}
	
	bool operator==(const A& u) const
	{ 
		return anno==u.getAnno();
	}
	
	bool operator!=(const A& u) const
	{ 
		return anno!=u.getAnno();
	}
	
	int getAnno() const
	{
		return anno;
	}
	
	string getNome() const
	{
		return nome;
	}
	
	string getCognome() const
	{
		return cognome;
	}
	
friend ostream& operator<<(ostream& out, const A& u);
friend istream& operator>>(istream& input, A &user);
	
};


ostream& operator<<(ostream& out, const A& u)
{
	out << "["<<u.nome << " " << u.cognome <<"] " ;	
	return out;
}


istream& operator>>(istream& input, A &user)
{
	string anno_st;
	getline(input, user.nome, ' ');
	getline(input, user.cognome, ' ');	
	getline(input, anno_st, '\n');
	user.anno = stoi(anno_st.c_str());
	return input;
}

void stampaUtenti(A users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}


int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("anno.txt");
	while(ifs.good())
	{
		A u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

class Nodo
{
	public:
		A val;
		Nodo* succ;
		Nodo* left;
		Nodo* right;
		Nodo* parent;
		Nodo(A x) : val(x) {}
		
		int getP()
		{
			return val.getAnno();
		}
};

class Albero
{
	Nodo* radice;
	
	public:
		Albero()
		{
			radice=NULL;
		}
		
		void inserimento(A x, int n)
		{	
			Nodo* nuovo= new Nodo(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			Nodo* i=radice;
			int a;
			int b;
			if(radice==NULL)
			{
				radice=nuovo;
				nuovo->parent=NULL;
				return;
			}
			
			while(i)
			{
				a= x.getAnno();
				b=i->getP();
				if(a > b)
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
	int n;
	A x[N];
	n = leggi(x);							
	
	Albero tree;
	for(int i=0; i<n; i++)
	{
		tree.inserimento(x[i],n);
	}
	cout<<"Albero: "<<endl;
	cout<<tree<<endl;
	
	cout<<endl<<"Visita inOrder: ";
	tree.inorder(tree.getradice());
	
	return 0;
}
