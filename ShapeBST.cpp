/*
a) Creare N oggetti Shape, con N e tipo di Shape (rettangolo, circonferenza, triangolo) scelti dall’utente.
b) Inserire gli oggetti Shape creati in tre BST a seconda del tipo, un BST per i rettangoli, uno per le circonferenze ed uno per i triangoli.
c) Permettere all’utente di inserire un valore di area, ed eliminare dai BST le figure geometriche che hanno un’area inferiore a quella data in input dall’utente.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Shape 												
{
public:
    int val;								// valore del Nodo
    Shape* left;							// figlio sinistro
    Shape* right;							// figlio destro
    Shape* parent;							// padre
    Shape* root;							// dichiaro la radice
	int cont=0;								// contatore dei nodi dell'albero
	double area;							// variabile per il calcolo dell'area
    Shape (Shape* r) : root(r){}			// costruttore che assegnerà a root il valore NULL passato dai costruttori delle sottoclassi
    
    virtual double getArea()=0;				// funzione che permetterà di ottenere il valore dell'area (non calcolare)
 			
};

class Rettangolo : public Shape				// rettangolo è una sottoclasse pubblica di Shape					
{
	
private:	
	void cancella(Shape* z)					
	{		
		while(z->left != NULL)				// finché il nodo z avrà dei figli sinistri
		{
			cancella(z->left);				// richiama la funzione cancella con input il figlio sinistro del nodo su cui si sta facendo il controllo
		}
		while(z->right != NULL)				// finché il nodo z avrà dei figli destri
		{
			cancella(z->right);				// richiama la funzione cancella con input il figlio destri del nodo su cui si sta facendo il controllo
		}

		if(z->parent->right==z)				// se il nodo controllato è figlio destro di suo padre
			z->parent->right=NULL;			// suo padre punterà a NULL e non più a suo figlio
		else								// se il nodo controllato è figlio sinistro di suo padre
			z->parent->left=NULL;			// suo padre punterà a NULL e non più a suo figlio
			
		delete z;							// elimina il nodo controllato
	}
	
public:
    Rettangolo(): Shape(NULL) {};			// di base non c'è alcuna radice, quindi l'albero è vuoto
    
    double calcarea(double base, double altezza)	// calcolo del valore dell'area
    {
    	area=base*altezza;
		return area;
	}
    
    double getArea()
	{
		return area;						// funzione che permette di vedere il valore dell'area dei singoli oggetti
	}
		
    void insert(int valore)					// inserimento del nodo il cui valore è "valore"
    {	
    	Shape* nuovo = new Rettangolo;		// creo un nuovo nodo di tipo rettangolo
	    Shape* x = root;					// la radice è x
		Shape* y = NULL;					// il figlio è y è vuoto
	
	    nuovo->val = valore;				// assegno il valore "valore" al nodo "nuovo"
	    nuovo->left = nuovo->right = NULL;	// dichiaro che il nodo "nuovo" non ha figli
	
	    while(x!=NULL)						// finché è presente una radice
		{
	        y=x;							// il figlio è uguale al padre
	        if(valore< x->val)				// se il nuovo valore è minore del valore del padre
	            x = x->left;				// la nuova radice sarà il figlio sinistro del padre  
	        else
	            x = x->right;				// la nuova radice sarà il figlio destro del padre  
	    }
	
	    nuovo->parent = y;					// il figlio diventa il nuovo padre
	    if(y==NULL)							// se il figlio è vuoto
	        root = nuovo;					// il nuovo elemento diventa radice
	    else if(valore<y->val)				// se il nuovo elemento è più piccolo del figlio
	        y->left = nuovo;				// il nuovo elemento sarà figlio sinistro del figlio
	    else
	        y->right = nuovo;				// il nuovo elemento sarà figlio destro del figlio
	
	    cont++;								// incrementa il contatore dei nodi 
	}
 
    int altezza(Shape* p)const				// funzione per trovare l'altezza dell'albero (servirà più avanti)
    {
    	if (p==NULL) 						// se l'albero è vuoto
			return 0;				 		// restiusci 0

	    int lh = altezza(p->left);			// richiama la funzione altezza passando il ramo sinistro 
	    int rh = altezza(p->right);			// richiama la funzione altezza passando il ramo destro
		
	    if(lh>rh)   						// se il ramo sinistro è più lungo del ramo destro
			return (lh+1);					// restituisci l'altezza del sinistro +1 
	    else        						// se il ramo sinistro è più lungo del ramo destro
			return (rh+1);					// restituisci l'altezza del destro +1 
	}
	
	bool cancella(double x)				// funzione che trova l'elemento dal quale deve partire l'eliminazione. x è il valore sotto il quale bisogna cancellare
    {
    	Shape* iter = root;						// dichiaro un nodo e lo pongo uguale alla radice (come se fosse un indice i=root)
	    while((iter!=NULL) && (x<iter->val))	// finché esiste una radice e il valore della radice è minore dall'elemento che vogliamo cancellare
		{
	        if(x>= iter->val)					// se l'elemento da cancellare è maggiore uguale del valore della radice
	            iter = iter->right;				// controlliamo il figlio sinistro della radice
	        else								// se l'elemento da cancellare è minore del valore della radice
	            iter = iter->left;				// controlliamo il figlio destro della racice
	    }
	    if(iter == NULL)						// se non è presente la radice, quindi se l'albero è vuoto
	        return false;						// esci dalla funzione

	    cancella(iter);							// chiama la funzione cancella dichiarata privata passandogli il nodo dal quale deve partire la cancellazione
	    return true; 							// una volta eseguita la funzione cancella(iter) esci dalla funzione
	}
	
    friend ostream& operator<<(ostream& out, const Rettangolo& t);	// overloading dell'operatore << per effetture la stampa dell'albero 
};


class Cerchio : public Shape					
{
private:
	void cancella(Shape* z)
	    {		
			while(z->left != NULL)
			{
				cancella(z->left);
			}
			while(z->right != NULL)
			{
				cancella(z->right);
			}

			if(z->parent->right==z)
				z->parent->right=NULL;
			else	
				z->parent->left=NULL;
	
			delete z;
		}

public:
    Cerchio(): Shape(NULL){};			
    
    double calcarea(double raggio, double raggio2)
    {
    	area=raggio*raggio*3.14;
		return area;
	}
    
    double getArea()
	{
		return area;
	}
    void insert(int valore)						
    {	
    	Shape* nuovo = new Cerchio;				
	    Shape* x = root;						
		Shape* y = NULL;						
	
	    nuovo->val = valore;					
	    nuovo->left = nuovo->right = NULL;		
	
	    while(x!=NULL)							
		{
	        y=x;								
	        if(valore< x->val)					
	            x = x->left;					
	        else
	            x = x->right;					 
	    }
	
	    nuovo->parent = y;						
	    if(y==NULL)								
	        root = nuovo;					
	    else if(valore<y->val)				
	        y->left = nuovo;				
	    else
	        y->right = nuovo;				
	
	    cont++;								
	}
 
    int altezza(Shape* p)const
    {
    	if (p==NULL) return 0;		

	    int lh = altezza(p->left);
	    int rh = altezza(p->right);
	
	    if(lh>rh)   
			return (lh+1);
	    else        
			return (rh+1);
	}
	
	bool cancella(double x)
    {
    	Shape* iter = root;							
	    while((iter!=NULL) && (x<iter->val))		
		{
	        if(x>= iter->val)					
	            iter = iter->right;				
	        else
	            iter = iter->left;					
	    }
	    if(iter == NULL)						
	        return false;

	    cancella(iter);
	    return true; 	
	}
	
    friend ostream& operator<<(ostream& out, const Cerchio& t);
    
};

class Triangolo : public Shape					
{
	private:
    void cancella(Shape* z)
	    {		
			while(z->left != NULL)
			{
				cancella(z->left);
			}
			while(z->right != NULL)
			{
				cancella(z->right);
			}

			if(z->parent->right==z)
				z->parent->right=NULL;
			else	
				z->parent->left=NULL;
	
			delete z;
		}
	
public:
    Triangolo(): Shape(NULL){};					// di base non c'è alcuna radice, quindi l'albero è vuoto
   double calcarea(double base, double altezza)
    {
    	area=(base*altezza)/2;
		return area;
	}
    
    double getArea()
	{
		return area;
	}
    void insert(int valore)						// inserisco l'elemento
    {	
    	Shape* nuovo = new Triangolo;			// creo un nuovo Shape
	    Shape* x = root;						// la radice è x
		Shape* y = NULL;						// il figlio è y
	
	    nuovo->val = valore;					// inserisco il valore nel Shape nuovo
	    nuovo->left = nuovo->right = NULL;		// il nuovo Shape ha figli NULL
	
	    while(x!=NULL)							// finché è presente una radice
		{
	        y=x;								// il figlio è uguale al padre
	        if(valore< x->val)					// se il nuovo valore è minore del valore del padre
	            x = x->left;					// la nuova radice sarà il figlio sinistro del padre  
	        else
	            x = x->right;					// la nuova radice sarà il figlio destro del padre  
	    }
	
	    nuovo->parent = y;						// il figlio diventa il nuovo padre
	    if(y==NULL)								// se il figlio è vuoto
	        root = nuovo;						// il nuovo elemento diventa radice
	    else if(valore<y->val)					// se il nuovo elemento è più piccolo del figlio
	        y->left = nuovo;					// il nuovo elemento sarà figlio sinistro del figlio
	    else
	        y->right = nuovo;					// il nuovo elemento sarà figlio destro del figlio
	
	    cont++;								// cont++
	}
 
    int altezza(Shape* p)const
    {
    	if (p==NULL) return 0;		

	    int lh = altezza(p->left);
	    int rh = altezza(p->right);
	
	    if(lh>rh)   
			return (lh+1);
	    else        
			return (rh+1);
	}
	
	bool cancella(double x)
    {
    	Shape* iter = root;							// i=radice
	    while((iter!=NULL) && (x<iter->val))		// finché esiste una radice e il valore della radice è diverso dall'elemento che vogliamo cancellare
		{
	        if(x>= iter->val)						// se l'elemento da cancellare è minore del valore della radice
	            iter = iter->right;					// controlliamo il figlio sinistro della radice
	        else
	            iter = iter->left;					// controlliamo il figlio destro della racice
	    }
	    if(iter == NULL)							// se non è presente la radice, quindi se l'albero è vuoro
	        return false;

	    cancella(iter);
	    return true; 	
	}
	
    friend ostream& operator<<(ostream& out, const Triangolo& t);
    
};


void stampa(Shape* p, int altezza)			// prende in input un nodo e un intero che indica l'altezza
{ 
    if(p == NULL)							// se p punta ad una posizione vuota
	{
        if (altezza==0) 					// se siamo al livello 0 quindi quello della foglia finale
			cout << "_\t";					// stampa _
        return;								// esce dalla funzione stampa
    }

    if(altezza == 0)						// se siamo al livello 0
       cout << p->val << "\t";				// stampa il valore del nodo presente in quel livello (essendo solo uno non serve fare altro)
    else if(altezza>0)						// se siamo ad un livello superiore
	{					
        stampa(p->left,altezza-1);			// richiama la funzione passando il figlio sinistro e decrementanod il livello di uno
        stampa(p->right,altezza-1);			// richiama la funzione passando il figlio destro e decrementanod il livello di uno
    }
}

ostream& operator<<(ostream&out, const Rettangolo& t)
{
    int h = t.altezza(t.root);				// richiamo la funzione altezza in modo da sapere il limite per il for successivo
    cout << "Albero Rettangolo" <<endl;
    for(int i=0;i<h;i++)
	{
        stampa(t.root, i);					// richiama la funzione stampa passando di volta in volta il nodo e il livello al quale questo si trova
        cout << endl;
    }
    return out;					
}

ostream& operator<<(ostream&out, const Cerchio& t)
{
   int h = t.altezza(t.root);
    cout << "Albero Cerchio"<<endl;
    for(int i=0;i<h;i++)
	{
        stampa(t.root, i);
        cout << endl;
    }
    return out;
}

ostream& operator<<(ostream&out, const Triangolo& t){
    int h = t.altezza(t.root);
    cout << "Albero Triangolo"<< endl;
    for(int i=0;i<h;i++){
        stampa(t.root, i);
        cout << endl;
    }
    return out;
}

int main()
{
	int n;				
	cout<<"Numero di oggetti da creare: ";
	cin>>n;
	
	cout<<endl<<"Scrivi 'r' per Rettangolo, 'c' per Cerchio e 't' per Triangolo "<<endl;
	
	string m;
	double dim1;
	double dim2;
	
	Rettangolo rett;
    Cerchio cerc;
    Triangolo tri;
	
	Shape*vett[n];
	for (int i =0; i<n; i++) 
	{
		cout<<endl<<"Tipo dell'oggetto "<< i << " : ";
		cin>>m;	
		
		if (m=="r")
		{
			cout<<"\t Valore della base: ";
			cin>>dim1;
			cout<<"\t Valore dell'altezza: ";
			cin>>dim2;
			vett[i]= new Rettangolo();
			rett.insert(rett.calcarea(dim1,dim2));		// chiamo la funzione insert passandogli il ritorno della chiamata calcarea
		}
			
		else if (m=="c")
		{
			cout<<"\t Valore del raggio: ";
			cin>>dim1;
			vett[i]= new Cerchio();
			cerc.insert(cerc.calcarea(dim1,0));
		}
		else if (m=="t")
		{
			cout<<"\t  Valore della base: ";
			cin>>dim1;
			cout<<"\t Valore dell'altezza: ";
			cin>>dim2;
			vett[i]= new Triangolo();
			tri.insert(tri.calcarea(dim1,dim2));	
		}	
		else
		{
			cout<<"Errore!"<<endl;
			return 0;
		}	
	}

    cout << rett << endl;
    cout << cerc << endl;
    cout << tri << endl;
    
    double y;
	cout<<"Inserisci un valore di area: ";
	cin>>y;

	rett.cancella(y);
	cerc.cancella(y);
	tri.cancella(y);
	cout << rett << endl;
    cout << cerc << endl;
    cout << tri << endl;

    return 0;
}
