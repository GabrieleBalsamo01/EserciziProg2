/*
Dato un file contenente un elenco di utenti nel seguente formato
ID;COGNOME;NOME;POPOLARITA
ID;COGNOME;NOME;POPOLARITA
…
ID;COGNOME;NOME;POPOLARITA
Dove COGNOME e NOME sono stringhe e POPOLARITA è un double, implementare almeno due algoritmi di ordinamento tra quelli visti a lezione. Inoltre, sfruttando le 
librerie standard, valutarne la complessità temporale stimando il tempo di esecuzione.
*/

#include <iostream>
#include <fstream>			// per lettura file di testo
#include <string>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <chrono>

#define dim 2000

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::duration;

using namespace std;

class Lista
{
	
public:	
	int id;
	string nome;
	string cognome;
	double popo;
	
	Lista(int a, string b, string c, double d) : id(a), nome(c), cognome(b), popo(d){}
	Lista(){}				// da inserire per la creazione di un oggetto di tipo lista nel main
	
	bool operator>(const Lista& u) const
	{ 
		return popo>u.getpopolarita();
	}
	
	bool operator==(const Lista& u) const
	{ 
		return popo==u.getpopolarita();
	}
	
	bool operator!=(const Lista& u) const
	{ 
		return popo!=u.getpopolarita();
	}
	
	int getid() const
	{
		return id;
	}
	
	string getnome() const
	{
		return nome;
	}
	
	string getcognome() const
	{
		return cognome;
	}
	
	double getpopolarita() const
	{
		return popo;
	}
	
	friend ostream& operator<<(ostream& out, const Lista& u);
	
};


ostream& operator<<(ostream& out, const Lista& u)
{
	out << u.popo << "\t-\t" << u.id << "\t" << u.cognome << endl;	
	return out;
}

void dividi(string x, string arr[4])
{
	char delimitatore=';';
	stringstream ss(x);
	int i=0;
	while(getline(ss,arr[i],delimitatore))
	{
		i++;
		if(i==4)
			break;
	}	
}

int lettura(Lista elenco[])
{
	char c;
	string x;
	string arr[4];
	ifstream fin("utenti.txt");		// leggi il file utenti che si trova nella stessa cartella del programma
	int i= 0;

		while(fin.get(c))				// finché leggi qualcosa sul file
		{
			x+=c;
			if(c=='\n')
			{
				dividi(x,arr);
				x="";
				Lista u = Lista(stoi(arr[0]), arr[1], arr[2], stod(arr[3]));
				elenco[i] = u;
				i++;
			}
		}
	
		fin.close();				// finisci la lettura. la funzione verrà eseguita dopo essere usciti dal while, quindi quando il file sarà stato letto tutto
	return i;
}

void insertion(Lista arr[], int n)
{
	Lista tmp;
	int j;
	for(int i=1; i<n; i++)
	{
		j=i-1;
		tmp=arr[i];
		while(j>=0 && arr[j]>tmp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=tmp;
	}
}

void bubble(Lista arr[], int n)
{
	Lista tmp;
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=1; i<n-1; i++)
		{
			if(arr[i]>arr[i+1])
			{
				tmp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
				flag=true;
			}		
		}
	}
	
}

void stampa(Lista users[], int n, int maxval=10)
{
	if(n>maxval)
	{
		for(int i=0;i<maxval/2;i++)
			cout << users[i];
		cout << "... " << endl;
		for(int i = n-maxval/2;i<n;i++)
			cout << users[i];
		
	}
	else
		for(int i=0;i<n;i++)
			cout << users[i];
}

int main()
{	
	Lista elenco[dim];
	int n=lettura(elenco);
	cout<<"Insertion Sort: "<<endl;
	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
	duration<double, milli> ms_double;
	t1 = high_resolution_clock::now();
	insertion(elenco,n);
	t2 = high_resolution_clock::now();
	ms_double = t2 - t1;
	cout << "Tempo in ms:\t" << ms_double.count() << " ms" << endl;
	stampa(elenco,n);
	cout<<endl<<"Bubble Sort: "<<endl;
	bubble(elenco,n);
	stampa(elenco,n);	
	
	return 0;
	
	
}
