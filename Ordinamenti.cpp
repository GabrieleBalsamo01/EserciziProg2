#include<iostream>
using namespace std;

void stampa(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<" "<<a[i]<<" ";
	cout<<endl;
}
/*

// Insertion Sort
void InsertionSort(int a[], int n)		// passiamo l'array a e la dimensione n
{
	int j;								// dichiariamo l'indice che utilizzeremo per l'elemento di confronto
	int valore;							// dichiariamo la variabile di appoggio dei valori dell'array a
	for(int i=1;i<n;i++)
	{
		valore=a[i];					// usiamo valore come appoggio per l'elemento di posizioe i
		j=i-1;							// poniamo l'inidice j ad i-1 in modo da poter effettuare il confronto tra i e il precedente
		while(j>=0 && a[j]>valore)		
		{	
			a[j+1]=a[j];				// l'elemento in posizione j+1, ovvero i, assume il valore dell'elemento precedente
			j--;		
		}
		a[j+1]=valore;					// l'elemento di posizione j+1 (considerando i j-- possibili) assume il valore di "valore" ovvero 
										
	}
}

int main()
{
	int a[5];
	int n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,n);
	InsertionSort(a, n);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,n);
	return 0;
}

// Selection Sort

#include<iostream>
using namespace std;
void selezione(int a[], int n)				// passiamo l'array a e la dimensione n
{
	int indice;								// dichiarimo la variabile d'appoggio per l'indice dell'elemento principale da scambiare
	int aux;								// dichiaromo la variabile d'appoggio per l'elemento di indice i
	for(int i=0;i<n-1;i++)
	{
		indice=i;							// pongo indice uguale ad i
		for(int j=i+1;j<n;j++)
			if (a[indice]>a[j])				// se l'elemento precedente è maggiore di quello successivo
				indice=j;					// pongo indice a j, cioè all'elemento successivo
			aux=a[i];						// passo momentaneamente il valore di indice i ad aux
			a[i]=a[indice];					// pongo l'elemento in posizione i uguale al suo successivo
			a[indice]=aux;					// pongo l'elemento successivo uguale ad aux, ovvero il valore originario del precedente
		
	}
}

int main()
{
	int a[5];
	int n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,n);
	selezione(a,n);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,n);
	return 1;
}


// Bubble Sort

#include<iostream>
using namespace std;

void Bubblesort(int a[], int n)				// passo l'array a e la dimensione n
{
	int aux;
	bool flag=true;							// dichiaro la variabile flag che indicherà 
	while (flag)
	{
		flag=false;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
				flag=true;
			}
		}
			
	}
		
}


int main()
{
	int a[5];
	int n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,5);
	Bubblesort(a, 5);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,5);
	return 1;
}


// Quick Sort

void QuickSort (int v[], int s, int d)		// prende in input array, indice iniziale e indice finale
{
	int i=s;								// copio indice iniziale
	int j=d;								// copio indice finale
	int tmp;								// variabile di appoggio per l'elemento di posizione i
	int pivot = v[(s+d)/2];					// dichiaro pivot
	while (i<=j)
	{
		while (v[i]<pivot)					// finchè l'elemento di posizione i è minore del pivot
			i++;							// passa all'elemento successivo
		while (v[j]>pivot)					// finchè l'elemento di posizione j è minore del pivot
			j--;							// passa all'elemento precedente
			
		if(i<=j)							// se l'indice sinistro è minore di quello destro
		{
			tmp=v[i];						// copia in tmp il valore di posizione i
			v[i]=v[j];						// metti il valore di posizione j in posizione i
			v[j]=tmp;						// metti l'elemento salvato in tmp, cioè l'elemento di posizione i originario, in posizione j
			i++;							// passa all'elemento successivo da sinistra
			j--;							// passa all'elemento precedente da destra
		}
	}
	
	if (s<j)								// se partendo da destra non si è ancora arrivati a indice 0
		QuickSort(v,s,j);
	if (i<d)								// se partendo da sinistra non si è ancora arrivati a indice n-1
		QuickSort(v,i,d);	
}

int main()
{
	int a[5];
	int n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,5);
	QuickSort(a,0,n-1);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,5);
	return 0;
}

*/
// Merge Sort

#include<iostream>
using namespace std;
void merge(int a[], int left, int center, int right, int n)	// input l'array, indice iniziale, indice finale, indice centrale e la dimensione
{
	int i=left;							// pone i uguale all'indice sinistro
	int j=center+1;						// pone j uguale all'indice centrale +1
	int k=i;							// pone k uguale ad i. k è l'indice del nuovo array che conterrà gli elementi ordinati
	int b[n];
	while((i<=center)&& (j<=right))		// fichè l'indice iniziale non arriva al centro e quello centrale non arriva alla fine
	{
		if(a[i]<=a[j])					// se l'elemento a sinistra è <= di quello a destra
		{			
			b[k]=a[i];					// insierici in posizione k l'elemento in posizione i
			i++;						// controlla l'elemento sinistro successivo
		}
		else 
		{
			b[k]=a[j];					// insierici in posizione k l'elemento in posizione j
			j++;						// controlla l'elemento destro successivo
		}
		k++;							// incrementa l'indice dell'array di copia
	}
	while(i<=center)					// finchè l'indice sinistro non arriva al centro
	{
		b[k]=a[i];						// insierici in posizione k l'elemento di posizione i
		i++;							// controlla l'elemento sinistro successivo
		k++;							// incrementa l'indice dell'array di copia
	}	
	while(j<=right)						// finchè l'indice destro non arriva alla fine
	{
		b[k]=a[j];						// insierici in posizione k l'elemento di posizione j
		j++;							// controlla l'elemento destro successivo
		k++;							// incrementa l'indice dell'array di copia
	}
	for(k=left;k<=right;k++)			
		a[k]=b[k];						// ricopia nell'array originale a tutti gli elementi ordinati presenti nell'array copia b
	
}

void mergesort(int a[], int left, int right, int n)
{
	if(left<right)						// se l'indice sinistro è minore di quello destro
	{
		int center=(left+right)/2;		// poni l'indice centrale
		mergesort(a,left,center,n);		// chiama il mergesort per il sottoarray che va da 0 al centro
		mergesort(a,center+1,right,n);	// chiama il mergesort per il sottoarray che va dal centro+1 alla fine
		merge(a,left,center,right,n);	// chiama il merge per riordinare tutti i singoli sottoarray
	}
}

int main()
{
	int a[5];
	int n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,5);
	mergesort(a,0,n-1,n);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,5);
	return 0;
}

/*

//ORDINAMENTO PER SCAMBIO
#include <iostream>
using namespace std;
void scambia(int &a, int &b){
	int aux=a;
	a=b;
	b=aux;
}
void OrdScambio(int a[], int n){
	for (int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if (a[i]>a[j]) 
				scambia(a[i],a[j]);
}

int main(){
	int a[5];
	int n;
	n=5;
	cout<<"Inserisci i valori del vettore: "<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cout<<"Vettore inserito: "<<endl;
	stampa(a,5);
	OrdScambio(a, 5);
	cout<<"Vettore ordinato: "<<endl;
	stampa(a,5);
	return 1;
}
	
*/
