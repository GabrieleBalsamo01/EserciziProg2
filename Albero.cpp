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
		
		void preorder(Nodo* i)
		{
			if(i)
			{
				cout<< i->val<<" ";
				inorder(i->left);	
				inorder(i->right);
			}
		}
		
		void postorder(Nodo* i)
		{
			if(i)
			{
				inorder(i->left);
				inorder(i->right);
				cout<< i->val<<" ";
			}
		}
		
		int altezza(Nodo* p)const
	    {
	    	if (p==NULL) 
				return 0;		
	
		    int a = altezza(p->left);
		    int b = altezza(p->right);
		
		    if(a>b)   
				return (a+1);
		    else        
				return (b+1);
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
	Albero a;
									a.inserimento(10); 	
						a.inserimento(9); 					a.inserimento(15);
				a.inserimento(4); 			a.inserimento(11); 				a.inserimento(17);
		a.inserimento(3); 															a.inserimento(18);
a.inserimento(2); 				
	 	 	 	 	
	cout<<a<<endl;
	
	a.cancellazione(10);			// due figli (radice)
	a.cancellazione(15);			// due figli (no radice)
	a.cancellazione(4);				// solo figlio sinistro
	a.cancellazione(2);				// nessun figlio
	a.cancellazione(17);			// solo figlio destro

	cout<<a<<endl;
	cout<<endl<<"Visita inOrder: ";
	a.inorder(a.getradice());
	
	cout<<endl<<"Visita preOrder: ";
	a.preorder(a.getradice());
	
	cout<<endl<<"Visita postOrder: ";
	a.postorder(a.getradice());
}
