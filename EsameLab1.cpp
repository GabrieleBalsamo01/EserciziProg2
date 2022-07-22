/*
Si implementi una semplice classe BST, attraverso l'utilizzo dei template, con elementi di tipo generico T. La classe dovrà implementare le seguenti funzionalità:
- Inserimento di un nuovo elemento
- Visualizzare gli elementi del BST
- Un metodo 'distaza successore' che prende in input un valore X e restituisce il numero di archi che separano il nodo contenente X dal nodo contenente il suo 
  successore. Se la chiave non ha successorre il metodo restituisce il valore 0

Nel metodo main, instanziare un BST di interi e uno di char, successivamente inserire dei valori e testare il corretto funzionamento delle funzionalità implementate  
*/

#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
	public:
		T val;
		Nodo<T>* right;
		Nodo<T>* left;
		Nodo<T>* parent;
		Nodo<T>(T x) : val(x) {}		
};

template <typename T>
class Albero
{
	public:
		Nodo<T>* radice;
		Albero<T>() 
		{
			radice=NULL;
		}
		
		void inserimento(T x)
		{
			Nodo<T>* nuovo= new Nodo<T>(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			Nodo<T>* i=radice;
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
		
		int distanzaSuccessore(Nodo<T>* n, Nodo<T>* m)
		{
			int a=arco(n->val);
			int b=arco(m->val);
			if(a>b)
			 return a-b;
			else
				return b-a; 
		}
		
		Nodo<T>* trovanodo(T x)
		{
			Nodo<T>* i= radice;
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
		
		int arco(T x)
		{
			Nodo<T>* i= radice;
			int cont=0;
			while(i)
			{
				if(i->val==x)
				{
					return cont;
				}
				if(i->val < x)
				{
					i=i->right;
				}
				else
					i=i->left;
				cont++;	
			}
			return cont;
		}
	
		
		Nodo<T>* getradice()
		{
			return radice;
		}
		
		void inorder(Nodo<T>* i)
		{
			if(i)
			{
				inorder(i->left);
				cout<< i->val<<" ";
				inorder(i->right);
			}
		}
		
		void preorder(Nodo<T>* i)
		{
			if(i)
			{
				cout<< i->val<<" ";
				inorder(i->left);	
				inorder(i->right);
			}
		}
		
		void postorder(Nodo<T>* i)
		{
			if(i)
			{
				inorder(i->left);
				inorder(i->right);
				cout<< i->val<<" ";
			}
		}
		
		int altezza(Nodo<T>* p)const
	    {
	    	if (p==NULL) 
				return 0;		
		    int lh = altezza(p->left);
		    int rh = altezza(p->right);
		
		    if(lh>rh)   
				return (lh+1);
		    else        
				return (rh+1);
		}
		
template <typename U>		
friend ostream& operator << (ostream& out, const Albero<U>& x);		

};
template <typename T>
void stampaLivello(Nodo<T>* p, int level)
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
template <typename U>
ostream& operator<<(ostream&out, const Albero<U>& x)
{
    int h = x.altezza(x.radice);
    for(int i=0;i<h;i++)
	{
        stampaLivello(x.radice, i);
        cout << endl;
    }
    return out;
}


int main()
{
	
// ALBERO DI TIPO INT
	
	Albero<int> a;
													a.inserimento(10); 	
							a.inserimento(9); 									a.inserimento(15);
					a.inserimento(8); 								a.inserimento(11);	 		a.inserimento(20);
		a.inserimento(4);																				a.inserimento(24); 				
	a.inserimento(2); 																		a.inserimento(22); 
a.inserimento(1);																		a.inserimento(21); 
	cout<<a<<endl;
	
	cout<<endl<<"Visita inOrder: ";
	a.inorder(a.getradice());
	
	cout<<endl<<"Visita preOrder: ";
	a.preorder(a.getradice());
	
	cout<<endl<<"Visita postOrder: ";
	a.postorder(a.getradice());
	

	int x;
	cout<<endl<<"Insierisci un valore: ";
	cin>> x;
	Nodo<int>*n=a.trovanodo(x);
	Nodo<int>*m=a.trovanodo(x+1);
	if(n!=NULL && m!=NULL)
	{
		cout<<endl<<"Distanza tra "<<x <<" e "<< x+1 <<" = "<< a.distanzaSuccessore(n,m);
	}		
	else
	{
		if(n==NULL&&m==NULL)
			cout<<x <<" e il suo successore "<< x+1 << " non esistono!"<<endl;
		else if(n==NULL&&m!=NULL)
			cout<<x <<"non esiste!"<<endl;
		else if(n!=NULL&&m==NULL)
			cout<< x+1 << " non esiste!"<<endl;
	}	
	
// ALBERO DI TIPO CHAR 	
	
	
	Albero<char> b;
									b.inserimento('r'); 	
						b.inserimento('p'); 					b.inserimento('t');
				b.inserimento('h'); 			b.inserimento('s'); 				b.inserimento('v');
		b.inserimento('c'); 																	b.inserimento('z');
b.inserimento('a'); 				
	 	 	 	 	
	cout<<endl<<b<<endl;

	cout<<endl<<"Visita inOrder: ";
	b.inorder(b.getradice());
	
	cout<<endl<<"Visita preOrder: ";
	b.preorder(b.getradice());
	
	cout<<endl<<"Visita postOrder: ";
	b.postorder(b.getradice());
	
	
	char y;
	cout<<endl<<"Insierisci un valore: ";
	cin>> y;
	char z=y+1;
	Nodo<char>*p=b.trovanodo(y);
	Nodo<char>*q=b.trovanodo(z);
	if(p!=NULL && q!=NULL)
	{
		cout<<endl<<"Distanza tra "<<y <<" e "<< z <<" = "<< b.distanzaSuccessore(p,q);
	}		
	else
	{
		if(p==NULL&&q==NULL)
			cout<<y <<" e il suo successore "<< z << " non esistono!"<<endl;
		else if(p==NULL&&q!=NULL)
			cout<<y <<"non esiste!"<<endl;
		else if(p!=NULL&&q==NULL)
			cout<< z << " non esiste!"<<endl;
	}	
}
