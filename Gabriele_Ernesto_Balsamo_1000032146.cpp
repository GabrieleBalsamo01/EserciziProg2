/*
Si implementi una classe BST, attraverso l'utilizzo dei template, contenente elementi di tipo generico H. La classe dovrà implementare la 
procedura di inserimento di un nuovo elemento, una visita che permette di visualizzare il contenuto del BST, ed una procedura int 
distanzaChiavi(H k, H h) che, prese in input due chiavi k e h, sia in grado di calcolare la distanza tra i nodi che contengono k e h 
rispettivamente. L'input è suddiviso in 6 task, uno per ogni riga. Ogni riga del file di input è formata da 3+N elementi. Il primo elemento è 
una stringa che identifica il tipo di dato che dovrà essere contenuto all'interno dell'albero. Il secondo elemento è un valore intero N, 
il quale rappresenta il numero delle operazioni di inserimento che dovranno essere effettuate nella struttura dati. Seguono N stringhe che 
rappresentano, nell'ordine dato, le operazioni da svolgere all'interno dell'albero. Nell specifico un inserimento di un valore "v" viene 
identificato dall stringa "ins:" seguita dal valore "v". Gli ultimi due elementi della sequenza sono i valori k ed h, i quali rappresentano 
le chiavi contenute nei nodi per i quali si vuole calcolare la distanza. Il metodo main deve leggere il contenuto del file input.txt, 
istanziare un BST per ciascun task, visualizzarne il contenuto ed eseguire l’operazione
Esempio:
Input: int 6 ins:10 ins:5 ins:15 ins:13 ins:22 ins:7 7 15
Output: 3
*/

#include <iostream>
#include <fstream>
#include <string>
#define N 50
using namespace std;

template <typename H>
class A
{
	
public:
	string tipo;
	int volte;
	H numero[N];
	H k;
	H h;
	
	A(){}
	A(string a, int e, H* b, H c, H d) : tipo(a), k(c), h(d), volte(e) {}
	

	H geth()
	{
		return h;
	}	
	
	H getk()
	{
		return k;
	}	

template <typename K>	
friend ostream& operator<<(ostream& out, const A<K>& u);	
};

template <typename K>
ostream& operator<<(ostream& out, const A<K>& u)
{
	out << u.tipo<< " "<< u.volte<< " "<< u.h<< " "<< u.k<<endl;	
	return out;
}

template <typename H>
string ins(istream& input, A<H> &user)
{
	string a="";
	while(input.good() && a!="int" && a!="char")
	{
		getline(input, a, ' ');
		if(a=="int"||a=="char")
			user.tipo=a;	
		else
			getline(input, a, '\n');

	}
	return a;
	
}

template <typename H>
void stampaUtenti(A<H> users[], int n)
{
	for(int i=0;i<n;i++)
		cout << users[i];
		
}

template <typename H>
A<H> insint(istream& input, A<H> &user)
{
	string num[N];
	string p;
	string q;
	string bin;
	string rip;
	getline(input, rip, ' ');
	user.volte=stoi(rip.c_str());
	if(user.tipo=="int")
	{
		for(int i=0; i<user.volte; i++)
		{
			getline(input, bin, ':');
			getline(input, num[i], ' ');
		}	
		
		for(int i=0; i<user.volte; i++)
		{		
			user.numero[i] = stoi(num[i].c_str());	
		}
			
		getline(input, p, ' ');
		getline(input, q, '\n');	
		user.h = stoi(p.c_str());	
		user.k = stoi(q.c_str());

		return user;	
	}
}

template <typename H>
A<H> inschar(istream& input, A<H> &user)
{	
	string p;
	string q;
	string bin;
	string rip;
	getline(input, rip, ' ');
	user.volte=stoi(rip.c_str());	
	string num[user.volte];	
	if(user.tipo=="char")
	{		
		for(int i=0; i<user.volte; i++)
		{	
			getline(input, bin, ':');
			getline(input, num[i], ' ');	
		}	
		
		for(int i=0; i<user.volte; i++)
		{
			user.numero[i] = num[i][0];			
		}
						
		getline(input, p, ' ');
		getline(input, q, '\n');
		user.h=p[0];
		user.k=q[0];	
		
		return user;	
	}
	
}

template <typename H>
int leggiint(A<H> utenti[])
{
	int num = 0;
	ifstream ifs("input.txt");
	while(ifs.good())
	{
		A<H> u;
		string x=ins(ifs,u);
		if(x=="int")
		{
			insint(ifs,u);			
			utenti[num++] = u;				
		}			
	}
	return num;
}

template <typename H>
int leggicarattere(A<H> utenti[])
{
	int num = 0;
	ifstream ifs("input.txt");
	while(ifs.good())
	{
		A<H> u;
		string x=ins(ifs,u);
		if(x=="char")
		{
			inschar(ifs,u);
			utenti[num++] = u;
		}
					
	}
	return num;
}

template <typename H>
class Nodo
{
	public:
		H val;
		Nodo* left;
		Nodo* right;
		Nodo* parent;
		Nodo(H x) : val(x) {}
				
};

template <typename H>
class Albero
{
	Nodo<H>* radice;
	
	public:
		Albero<H>()
		{
			radice=NULL;
		}
		
		void inserimento(H x)
		{	
			Nodo<H>* nuovo= new Nodo<H>(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			Nodo<H>* i=radice;
			if(radice==NULL)
			{
				radice=nuovo;
				nuovo->parent=NULL;
				return;
			}
			
			while(i)
			{
				if(nuovo->val < i->val)
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
		
		int altezza(Nodo<H>* p)const
	    {
	    	if (p==NULL) return 0;		
	
		    int a = altezza(p->left);
		    int b = altezza(p->right);
		
		    if(a>b)   
				return (a+1);
		    else        
				return (b+1);
		}
		
		Nodo<H>* getradice()
		{
			return radice;
		}
		
		void inorder(Nodo<H>* i)
		{
			if(i)
			{
				inorder(i->left);
				cout<< i->val<<" ";
				inorder(i->right);
			}
		}
	
	int distanzaChiavi(Nodo<H>* n, H m)
	{
		Nodo<H>* i= n;
			int cont=0;
			while(i)
			{
				if(i->val==m)
				{
					return cont;
				}
				if(i->val < m)
				{
					i=i->right;
				}
				else
					i=i->left;
				cont++;	
			}
			return cont;
	}
	
	Nodo<H>* trovanodo(H x)
		{
			Nodo<H>* i= radice;
			int cont=0;
			while(i)
			{
				if(i->val==x)
				{
					return i;
				}
				if(i->val < x)
				{
					i=i->right;
				}
				else
					i=i->left;
				cont++;	
			}
			return NULL;
		}
	int controllo(Nodo<H>*x,Nodo<H>*y, int cont)
	{
		if(x->parent==y->parent)
		{
			return cont;
		}
		else
		{
			cont=cont+2;
			controllo(x->parent,y->parent,cont);
		}
	}
template <typename T>		
friend ostream& operator << (ostream& out, const Albero<T>& x);	
};

template <typename T>
ostream& operator<<(ostream&out, const Albero<T>& x)
{
    int h = x.altezza(x.radice);
    for(int i=0;i<h;i++)
	{
        stampa(x.radice, i);
        cout << endl;
    }
    return out;
}

template <typename H>
void stampa(Nodo<H>* p, int l)
{ 
    if(p == NULL)						
	{
        if (l==0) 					
			cout << "_\t";
        return;
    }

    if(l == 0)						
       cout << p->val << "\t";			
    else if(l>0)				
	{					
        stampa(p->left,l-1);	
        stampa(p->right,l-1);
    }

}


int main()
{	
	int n;
	A<int>x[3];
	n = leggiint(x);
	
	int m;
	A<char>y[3];
	m=leggicarattere(y);
	Albero<int> T[3];
	
	
	for(int i=0; i<3; i++)
	{
		cout<<"Albero di interi "<<i<<endl;
		for(int j=0; j<x[i].volte;j++)
		{
			T[i].inserimento(x[i].numero[j]);
		}
		cout<<T[i]<<endl;
		
		int p=x[i].geth();
		int r=x[i].getk();
		int t=T[i].altezza(T[i].trovanodo(p));
		int u=T[i].altezza(T[i].trovanodo(r));
		if(t>u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<T[i].distanzaChiavi(T[i].trovanodo(p), r)<<endl<<endl;	
		}
		if(t<u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<T[i].distanzaChiavi(T[i].trovanodo(r), p)<<endl<<endl;
		}
		if(t==u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<T[i].controllo(T[i].trovanodo(p),T[i].trovanodo(r),2);
		}
	}

	Albero<char> C[3];
	
	for(int i=0; i<3; i++)
	{
		cout<<"Albero di char "<<i<<endl;
		for(int j=0; j<y[i].volte;j++)
		{
			C[i].inserimento(y[i].numero[j]);
		}
		cout<<C[i]<<endl;
		
		char p=y[i].geth();
		char r=y[i].getk();
		int t=C[i].altezza(C[i].trovanodo(p));
		int u=C[i].altezza(C[i].trovanodo(r));
		
		if(t>u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<C[i].distanzaChiavi(C[i].trovanodo(p), r)<<endl<<endl;	
		}
		if(t<u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<C[i].distanzaChiavi(C[i].trovanodo(r), p)<<endl<<endl;
		}
		if(t==u)
		{
			cout<<"Distanza tra "<<p<<" e "<< r<< " = "<<C[i].controllo(C[i].trovanodo(p),C[i].trovanodo(r),2)<<endl<<endl;
		}
	}	
				
}

