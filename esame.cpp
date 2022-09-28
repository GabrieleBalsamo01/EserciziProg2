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
	Albero<int> T[3];
	
	
	for(int i=0; i<3; i++)
	{
		cout<<"Albero di interi "<<i<<endl;
		for(int j=0; j<x[i].volte;j++)
		{
			T[i].inserimento(x[i].numero[j]);
		}
		cout<<T[i]<<endl;
	}
				
}

