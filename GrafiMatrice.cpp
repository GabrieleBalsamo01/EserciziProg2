/*
Esercizio 2: Rappresentazione di Grafi usando matrici di adiacenza
*/
#include <iostream>
using namespace std;

template <class H> 
class MGraph 
{
		int len;				//len numero massimo di nodi
		int n;					//n numero di nodi effettivo
		int m; 					//m numero di archi effettivo
		int **M; 				//Contiene gli indici corrispondenti ai vari nodi
		H **K; 					// Contiene i valori dei nodi

		int findIndex(H x) 
		{
			for(int i=0; i<n; i++)	
				if(*K[i] == x) 			// se in posizione i è presente l'elemento x
					return i;			// restituisci l'indice in cui è presente l'elemento x
			return -1;
		}

	public:
		MGraph(int len) 
		{
			this->len = len;			// poni la variabile len privata pari al dato dato in input
			n = m = 0;					// poni il numero di nodi ed archi a 0
			M = new int*[len];			// allocazione dinamica della matrice
			for(int i=0; i<len; i++) 
			{
				M[i] = new int[len];
				for(int j=0; j<len; j++)
					M[i][j] = 0;				// riempi la matrice con 0
			}
			
			K = new H*[len];			
			for(int i=0; i<len; i++) 
				K[i] = NULL;			
		}

		MGraph<H>* addNode(H k)			// funzione che restituisce un puntatore di tipo H
		{
			if(n==len) 					// se il numero di nodi è uguale alla lunghezza 
				return this;			// restituisci il 
			if(findIndex(k)>=0) 
				return this;
			K[n] = new H(k);
			n++;
			return this;
		}

		MGraph<H>* addEdge(H x, H y) 
		{
			int i = findIndex(x);
			int j = findIndex(y);
			if(i<0 || j<0) return this;
			if(!M[i][j]) 
			{
				M[i][j] = 1;
				m++;
			}
			return this;
		}

		void print() 
		{
			for(int i=0; i<n; i++) 
			{
				cout << "(" << i << ", " << *K[i] << ")" << " : ";
				for(int j=0; j<n; j++) 
				{
					if(M[i][j]) cout << *K[j] << " ";
				}
				cout << endl;
			}
		}
};


int main() 
{
	MGraph<char> *Gr = new MGraph<char>(9);

	Gr->addNode('A')->addNode('B')->addNode('C')->addNode('D');
	Gr->addNode('E')->addNode('F')->addNode('G')->addNode('H');
	Gr->addNode('I');

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
