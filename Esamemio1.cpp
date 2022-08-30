/* Classe BST con inserimento, cancellazione, visita.
Creare i BST sulla base della media dei voti del file.
Creare poi 2 BST differenti, uno per gli studenti con media sufficiente, l'altro per quelli con la media sufficiente 


Nome: Gabriele Voti: Italiano: 8 Matematica: 8 Inglese: 9
Nome: Giorgio Voti: Italiano: 6 Matematica: 7 Inglese: 5
Nome: Giovanna Voti: Italiano: 3 Matematica: 8 Inglese: 6
Nome: Pina Voti: Italiano: 9 Matematica: 10 Inglese: 8
Nome: Alessandro Voti: Italiano: 7 Matematica: 5 Inglese: 9
Nome: Arturo Voti: Italiano: 8 Matematica: 9 Inglese: 9
Nome: Federico Voti: Italiano: 10 Matematica: 10 Inglese: 10
Nome: Salvo Voti: Italiano: 6 Matematica: 6 Inglese: 6
Nome: Angela Voti: Italiano: 5 Matematica: 9 Inglese: 7
Nome: Tano Voti: Italiano: 4 Matematica: 6 Inglese: 5
Nome: Pippo Voti: Italiano: 5 Matematica: 5 Inglese: 5
Nome: Topolino Voti: Italiano: 9 Matematica: 8 Inglese: 6
Nome: Paperino Voti: Italiano: 2 Matematica: 4 Inglese: 3
Nome: Pluto Voti: Italiano: 2 Matematica: 5 Inglese: 1
Nome: Topolina Voti: Italiano: 3 Matematica: 9 Inglese: 9
Nome: Qui Voti: Italiano: 8 Matematica: 4 Inglese: 5
Nome: Quo Voti: Italiano: 3 Matematica: 6 Inglese: 6
Nome: Qua Voti: Italiano: 5 Matematica: 6 Inglese: 7

*/

#include <iostream>
#include <fstream>
#define N 50
using namespace std;


class A
{
	
public:
	string nome;
	int voti[N];
	A() {}
	A(string a, int* b) : nome(a){}

friend ostream& operator<<(ostream& out, const A& u);	
};

ostream& operator<<(ostream& out, const A& u)
{
	return out;
}


void stampaUtenti(A users[], int n)
{
	for(int i=0;i<n;i++)
		cout << users[i];
		
}

istream& operator>>(istream& input, A &user)
{
	string a[N];
	string bin;
	getline(input, bin, ' ');
	getline(input, user.nome, ' ');	
	getline(input, bin, ' ');			

	for(int i=0; i<2; i++)
	{
		getline(input, bin, ' ');			
		getline(input, a[i], ' ');		
		user.voti[i] = stoi(a[i].c_str());	
	}	
			
	getline(input, bin, ' ');			
	getline(input, a[2], '\n');		
	user.voti[2] = stoi(a[2].c_str());
	cout<<"Voti di "<<user.nome<<" : ";	
	for(int i=0; i<3; i++)
		cout<<user.voti[i]<<" ";
	cout<<endl;	
	return input;				
}

int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("file.txt");
	while(ifs.good())
	{
		A u;
		ifs>>u;		
		utenti[num++] = u;						
	}
	return num;
}

class Nodo
{
	public:
		int val;
		Nodo* left;
		Nodo* right;
		Nodo* parent;
		Nodo(int x) : val(x) {}
				
};

class Albero
{
	Nodo* radice;
	
	public:
		Albero()
		{
			radice=NULL;
		}
		
		void inserimento(int x)
		{	
			Nodo* nuovo= new Nodo(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			Nodo* i=radice;
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
		
		void cancellazione (int x)
		{
			Nodo* appoggio;
			Nodo* i=radice;
			if(radice==NULL)											// non ci sono nodi da cancellare
				return;	

			while(i)
			{
				if(i->val==x)
				{					
					if(i->left==NULL && i->right==NULL)					// il nodo non ha figli
					{
						
						if(i->parent->val >= i->val)								
						{
							i->parent->left=NULL;
						}
								
						if(i->parent->val < i->val)
						{

							i->parent->right=NULL;
						}
						
						delete i;
						return;
					}
					
					if(i->left==NULL && i->right!=NULL)					// se ha figlio destro ma non sinistro
					{
						if(i==radice)
						{
							radice=i->right;
							i->right->parent=NULL;	
							delete i;
							return;
						}

						i->parent->right=i->right;
						i->right->parent=i->parent;
						delete i;
						return;
					}
					else if(i->left!=NULL && i->right==NULL)			// se ha figlio sinistro ma non destro
					{
						if(i==radice)
						{
							radice=i->left;
							i->left->parent=NULL;
							delete i;
							return;	
						}
							i->parent->left=i->left;
							i->left->parent=i->parent;
						delete i;
						return;
					}	
					else												// se ha figlio destro e sinistro
					{
						appoggio=i->right;
						if(i==radice)
						{
							radice=i->right;
							i->right->parent=NULL;
						}
						else
						{
							appoggio->parent=i->right->parent;
							i->parent->right=appoggio;	
						}	
						while(appoggio)
						{
							if(appoggio->left==NULL)
							{
								appoggio->left=i->left;
								i->left->parent=appoggio;
								delete i;
								return;
							}
							appoggio=appoggio->left;		
						}
					}
				}	
				else
				{
					if(i->val < x)
						i=i->right;
					else
						i=i->left;	
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
	A x[18];
	n= leggi(x);	
	Albero suff;
	Albero insuff;

	for(int i=0; i<18; i++)
	{
		int media=0;
		for(int j=0; j<3; j++)
		{
			media+=x[i].voti[j];	
		}
		media=media/3;
		if(media>=6)
			suff.inserimento(media);	
				
		else
			insuff.inserimento(media);
		
	}
		cout<<"Medie sufficienti"<<endl<<suff<<endl;
		cout<<"Medie insufficienti"<<endl<<insuff<<endl;
		
}







