#include <iostream>
#include <fstream>
#include <string>
#define N 50
using namespace std;

template <typename H>
class A
{
	
public:
	string mezzo;
	string marca;
	string nome[N];
	int numero;
	H prezzo[N];
	A(){}
	
	string getNome(int i) const
	{
		return nome[i];
	}
	H getPrezzo(int i) const
	{
		return prezzo[i];
	}
	
	
template <typename K>	
friend ostream& operator<<(ostream& out, const A<K>& u);	
};

template <typename K>
ostream& operator<<(ostream& out, const A<K>& u)
{
	for(int i=0; i<u.numero; i++)
		out<< "["<<u.getNome(i)<< " "<<u.getPrezzo(i)<<"]";
	out<<endl;
	return out;
}

template <typename H>
string ins(istream& input, A<H> &user)
{
	string a="";
	while(input.good() && a!="Auto" && a!="Moto")
	{
		getline(input, a, ':');
		if(a=="Auto"||a=="Moto")
			user.mezzo=a;	
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
A<H> insAuto(istream& input, A<H> &user)
{
	string prezzi[N];
	string bin;
	string n;
	getline(input, bin, ' ');
	getline(input, user.marca, ' ');
	getline(input, n, ' ');
	user.numero=stoi(n.c_str());
	getline(input, bin, ' ');
	for(int i=0; i<user.numero; i++)
	{
		getline(input, user.nome[i], ':');
		if(i==user.numero-1)
			getline(input, prezzi[i], '\n');	
		else
			getline(input, prezzi[i], ' ');
		user.prezzo[i]=stoi(prezzi[i].c_str());
	}
	
	return user;	
}

template <typename H>
A<H> insMoto(istream& input, A<H> &user)
{	
	string prezzi[N];
	string bin;
	string n;
	getline(input, bin, ' ');
	getline(input, user.marca, ' ');
	getline(input, n, ' ');
	user.numero=stoi(n.c_str());
	getline(input, bin, ' ');
	for(int i=0; i<user.numero; i++)
	{
		getline(input, user.nome[i], ':');
		if(i==user.numero-1)
			getline(input, prezzi[i], '\n');	
		else
			getline(input, prezzi[i], ' ');
		user.prezzo[i]=stod(prezzi[i].c_str());
	}
	
	return user;
}

template <typename H>
int leggiAuto(A<H> utenti[])
{
	int num = 0;
	ifstream ifs("esamemio3.txt");
	while(ifs.good())
	{
		A<H> u;
		string x=ins(ifs,u);
		if(x=="Auto")
		{
			insAuto(ifs,u);			
			utenti[num++] = u;				
		}			
	}
	return num;
}

template <typename H>
int leggiMoto(A<H> utenti[])
{
	int num = 0;
	ifstream ifs("esamemio3.txt");
	while(ifs.good())
	{
		A<H> u;
		string x=ins(ifs,u);
		if(x=="Moto")
		{
			insMoto(ifs,u);
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
	
template <typename T>		
friend ostream& operator << (ostream& out, const Albero<T>& x);	
};

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


int main()
{	
	int n;
	A<int>x[N];
	n = leggiAuto(x);
	
	int m;
	A<double>y[N];
	m=leggiMoto(y);
	Albero<int> T[N];
	Albero<double> D[N];
	
	for(int i=0; i<n; i++)
	{
		cout<<"Albero di Macchine "<<x[i].marca<<endl;
		for(int j=0; j<x[i].numero;j++)
		{
			T[i].inserimento(x[i].prezzo[j]);
		}
		
		cout<<T[i]<<endl;	
	}

	for(int i=0; i<m; i++)
	{
		cout<<"Albero di Moto "<<y[i].marca<<endl;
		for(int j=0; j<y[i].numero;j++)
		{
			D[i].inserimento(y[i].prezzo[j]);
		}
		cout<<D[i]<<endl;	
	}		
}

