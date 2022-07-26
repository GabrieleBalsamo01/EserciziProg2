/*
Definire una classe albero che restituisca una istanza della classe albero che rappresenta il simmetrico dell'oggetto albero. Per simmetrico intendiamo un albero 
in cui ogni nodo ha sottoalberi sinistro e destro invertiti
*/

#include <iostream>

using namespace std;

class Nodo
{
	public:
		int val;
		Nodo* right;
		Nodo* left;
		Nodo* parent;
		Nodo(int x) : val(x) {}		
};

class Albero
{
	public:
		Nodo* radice;
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
		
		Albero simmetrico(Nodo* x,Nodo* i, Albero copia)
		{
			Nodo*appoggio;
			if(i)
			{
				simmetrico(x->left,i->left,copia);
				appoggio=x->left;
				x->left=i->right;
				simmetrico(x->right,i->right,copia);
				x->right=appoggio;
			}
			return copia;
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


int main()
{
	Albero a;
									a.inserimento(10); 	
						a.inserimento(9); 					a.inserimento(15);
				a.inserimento(4); 			a.inserimento(11); 				a.inserimento(17);
		a.inserimento(3); 															a.inserimento(18);
a.inserimento(2); 				
	 	 	 	 	
	cout<<a<<endl;

	cout<<endl<<"Visita inOrder: ";
	a.inorder(a.getradice());
	cout<<endl;
	Albero copia=a;
cout<<a.simmetrico(copia.getradice(),a.getradice(),copia);
	
}
