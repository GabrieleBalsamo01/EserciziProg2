/*
Si implementi una semplice classe BST, attraverso l'utilizzo dei template, con elementi di tipo generico T. La classe dovrà implementare le seguenti funzionalità:
- Inserimento di un nuovo elemento
- Visualizzare gli elementi del BST

Inoltre tale class BST dovrà essere in grado di gestire le chiavi duplicate. In particolare, le chiavi duplicate dovranno essere inserite nei sottoalberi destro 
o sinistro della chiave duplicata già presente nel BST in modo alternato

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
				
		Nodo<T>* duplicato(T x)
		{
			Nodo<T>* i=radice;
			while(i)
			{
				if(i->val==x)
					return i;
				if(i->val>x)
					i=i->left;
				else
					i=i->right;		
			}
		}
		
		Nodo<T>* posizione(Nodo<T>* x, Nodo<T>* nuovo)
		{
			int c=0;
			while(x)
			{
				if(x->right==NULL)
				{			
					x->right=nuovo;
					nuovo->parent=x;
					return nuovo;
				}
				else if(x->right!=NULL && x->right->val > nuovo->val)
				{
						x->right->parent=nuovo;
						nuovo->right=x->right;
						nuovo->parent=x;
						x->right=nuovo;						
						return nuovo;
				}
					
				else
				{
					if(x->left==NULL) 
					{
						x->left=nuovo;
						nuovo->parent=x;
						return nuovo;
					}
						
					if(x->left->val!=nuovo->val)
					{
						x->left->parent=nuovo;
						nuovo->left=x->left;
						nuovo->parent=x;
						x->left=nuovo;						
						return nuovo;
					}		
				}
	
				if(c%2==0)	
					x=x->right;
				else
					x=x->parent->left;
				c++;
			}
				
		}
			
		void inserimento(T x)
		{
			Nodo<T>* nuovo= new Nodo<T>(x);
			nuovo->right=NULL;
			nuovo->left=NULL;
			
			Nodo<T>* dup=duplicato(x);
			if(dup)
			{		
				Nodo<T>* pos= posizione(dup,nuovo);
				return;				
			}

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
		
		int altezza(Nodo<T>* p)const
	    {
	    	if (p==NULL) return 0;		
	
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
	Albero<int> a;
/*									a.inserimento(10); 	
						a.inserimento(9); 					a.inserimento(15);
				a.inserimento(4); 	 				a.inserimento(15);			a.inserimento(15);
		a.inserimento(3); 					a.inserimento(11);
a.inserimento(2); 				
	*/ 	 	 	 	
/	
a.inserimento(10); a.inserimento(4);a.inserimento(8); a.inserimento(10);a.inserimento(11);a.inserimento(2);a.inserimento(11);a.inserimento(6);
a.inserimento(15);a.inserimento(19);a.inserimento(13);a.inserimento(21);a.inserimento(1);a.inserimento(2);a.inserimento(10);a.inserimento(13);
a.inserimento(11);a.inserimento(16);a.inserimento(18);a.inserimento(20);a.inserimento(21);a.inserimento(10); a.inserimento(7); a.inserimento(32);	 	 	 	

	 	 	
cout<<a<<endl;

	cout<<endl<<"Visita inOrder: ";
	a.inorder(a.getradice());
}
