/*
Esercizio 1: Rappresentazione di Grafi usando liste di adiacenza
*/

#include <iostream>
using namespace std;

template <class T> 
struct Nodo 
{
	T valore;						// valore del nodo
	Nodo<T>* succ;					// nodo successivo
};

template <class T> 
class Lista
{
		
	Nodo<T>* testa;

public:
	
	Lista() 	
	{
		testa=NULL;					// inizialmente poni la testa uguale a null
	}
	~Lista()
	{
		Nodo<T>* iter=this->testa;		// i=testa

		while(iter!=NULL)				// finch� i � una testa/un nodo
		{
			Nodo<T>* temp= iter->succ;	// appoggia il figlio della testa in temp
			delete iter;				// elimina la testa
			iter=temp;					// rendi il figlio della testa appena cancellata la nuova testa
		}
	}
	void print() 
	{
		Nodo<T>* iter=this->testa;		// i=testa

		while (iter!=NULL) 				// finch� i � una testa/un nodo
		{
			cout << " " << iter->valore << "\t";		// stampane il valore
			iter=iter->succ;			// passa al nodo successivo
		}
	}
	
	void insert(T val)
	{
		Nodo<T>* nuovo= new Nodo<T>;	// crea un nuovo nodo 

		nuovo->valore=val;				// il cui valore � val
		nuovo->succ=this->testa;		// il cui successivo � l'attuale testa
		this->testa=nuovo;				// rendi il nuovo nodo la nuova testa
	}
	Nodo<T>* getTesta() 
	{
		return testa;
	}
	Nodo<T>* search(T indice)
	{
			Nodo<T>* p;								// dichiara un nodo
		for (p=this->testa; p!=NULL; p=p->succ)		// esegui il for dal nodo testa passando al figlio di volta in volta finch� ce ne saranno
			if (p->valore==indice)					// se il valore del nodo � quello che si sta cercando
				return p;							// restituisce il nodo
		return NULL;					
	}

	friend ostream& operator<<(ostream& out, const Lista& ls)
	{
	    Nodo<T>* iter=ls.testa;
	
		while (iter!=NULL) 
		{
			out << " " << iter->valore << "\t";
			iter=iter->succ;
		}
			return out;
	}

};


template <class H> 
class LGraph 
{
	private:
		int len;				//len numero massimo di nodi
		int n;					//n numero di nodi effettivo
		int m;  				//m numero di archi effettivo
		H **K;					// lista di puntatori ad elementi di tipo H
		Lista<int> **Adj; 		// lista di puntatori ad elementi di tipo Lista<int>

		int findIndex(H x) 			// Trova l'indice associato al nodo
		{
			for(int i=0; i<n; i++)		
				if(*K[i] == x) 		// se la lista di puntatori con indice i sta puntato ad un elemento di indice x
					return i;		// restituisci la posizione del puntatore all'elemento di indice x
			return -1;
		}

	public:
		LGraph(int len) 						// costruttore che riceve il numero di nodi
		{
			this->len = len;					// len=numero di nodi del grafo
			n = m = 0;							// poni il numero effettivo di nodi ed archi a 0
			K = new H*[len];					// crei un array di puntatori di tipo H di lunghezza len
			for(int i=0; i<len; i++)		
                K[i] = NULL;					// fai puntare tutti i puntatori a null
			Adj = new Lista<int>*[len];			// crea una lista di puntatori ad elementi di tipo Lista<int> lunga len
			for(int i=0; i<len; i++)
				Adj[i] = new Lista<int>();		// inizializzo ogni lista di adiacenza coma un Lista<int>
		}

		LGraph<H>* addNode(H k) 				// Aggiunge un nodo al grafo (se non gi� presente)
		{
			if(n==len) 							// se il numero di nodi � uguale alla lunghezza del grafo dichiarata in fase di creazione dell'oggetto
				return this;					// restituisce il grafo cos� com'�, il grafo � pieno e non pu� essere aggiunto un nodo (?)
			if(findIndex(k)>=0) 				// se l'elemento � gia presente
				return this;					// restituisce il grafo cos� com'�
			K[n] = new H(k);					// ad indice n aggiungi un oggetto di tipo H con valore k
			n++;								// incrementa il numero di nodi effettivi del grafo
			return this;
		}

		LGraph<H>* addEdge(H x, H y) 			// Aggiunge un arco al grafo (se non gi� presente)
		{
			int i = findIndex(x);				// poni i uguale all'indice del nodo x
			int j = findIndex(y);				// poni i uguale all'indice del nodo y
			if(i<0 || j<0) 						// se uno dei due nodi � ad indice minore di 0 (quindi non esiste)
				return this;					// restiuisci il grafo com'� perch� non si pu� fare nulla
			if(!Adj[i]->search(j)) 				// se in posizione i della lista Adj, non � presente un nodo con valore j
			{
				Adj[i]->insert(j);				// aggiungi in posizione i della lista Adj un nodo il cui valore sar� l'indice j
				m++;							// incrementa il numero effettivo di archi del grafo
			}
			return this;
		}

		void print() 
		{
			for(int i=0; i<n; i++) 
				cout << "(" << i << ", " << *K[i] << ")" << " : " << *Adj[i]<< endl;	// stampa da 0 a n indicando i nodi e dopo a quali nodi sono legati con archi
		}
};



int main() 
{
	LGraph<char> *Gr = new LGraph<char>(9);

	Gr->addNode('A')->addNode('B')->addNode('C')->addNode('D')->addNode('E')->addNode('F')->addNode('G')->addNode('H')->addNode('I');

	Gr->addEdge('A','I')->addEdge('A','B');
	Gr->addEdge('B','I');
	Gr->addEdge('C','E');
	Gr->addEdge('D','F')->addEdge('D','G')->addEdge('D','H');
	Gr->addEdge('E','D')->addEdge('E','A');
	Gr->addEdge('F','G')->addEdge('F','D');
	Gr->addEdge('G','F');
	Gr->addEdge('I','C');

	Gr->print();
}
