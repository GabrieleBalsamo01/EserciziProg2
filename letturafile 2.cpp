/*
Letture da fare:
1- Lettura semplice con stampa uguale del file
2- Lettura con utilizzo di array
3- Lettura di testo con numeri traformandoli in interi
4- Lettura di testo con numeri traformandoli in double
5- Lettura di testo con sia interi che double
6- Lettura con elementi di righe che hanno determinate funzioni 

ciao sono gabriele 1 5 3 ciao 6 9 aaaa 8 7

ciao sono 2.5 3.8 7.5 gabriele 5.9 7.8 44.2 ciao


1 5 6 3 4.2 9 3.7 4 3.9 7.5
6 7 9.5 7.4 8 7 3.1 0 12 5.8
0.5 8 14 3.2 8 9.5 7.1 4 2 3

a: 4 8 6 pippo paperino 7
b: 7 9 3 topolino topolina 3
c: 1 3 8 pluto paperina 1
*/

// lettura file
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#define N 1000
using namespace std;

/*
// Lettura semplice con stampa uguale del file
int main()
{
	ifstream File("letturafile.txt");
	char c;
	string x;
	while(!File.eof())
	{
		File.get(c);
		if(File.eof())
		{
			cout<<x<<endl;
		}
		x+=c;
		if(c==' '||c=='\n')
		{
			cout<<x;	
			x="";	
		}
	
			
	}
	File.close();
}

// Lettura con utilizzo di array di stringhe
int main()
{
	string x[N];
	ifstream File("letturafile.txt");
	char c;
	int i=0;
	while(!File.eof())
	{
		
		File.get(c);
		if(File.eof())
		{
			cout<<"i "<<i<<": "<<x[i];
		}
		x[i]+=c;
		if(c==' '||c=='\n')
		{		
			cout<<"i "<<i<<": "<<x[i];		
			i++;
		}
		
	}
	File.close();
}



//Lettura di testo con numeri traformandoli in interi
class A
{
	string lettera;
	int numero[3];
	string nome1;
	string nome2;
	int x;

public:
	A(){}
	A(string a, int* b, string c, string d, int e) : lettera(a), nome1(c), nome2(d), x(e) 
	{
		for(int i=0; i<3; i++)
		{
			numero[i]=b[i];
		}
	}
	
friend ostream& operator<<(ostream& out, const A& u);	
friend istream& operator>>(istream& input, A &user);
	
};

ostream& operator<<(ostream& out, const A& u)
{
	out << u.lettera << " "<< u.nome1 << " "<< u.nome2 << " "<< u.x << " ";
	{
		for(int i=0; i<3; i++)
			out<<u.numero[i]<< " ";	
	}
	out<<endl;	
	return out;
}

istream& operator>>(istream& input, A &user)
{
	string num[3];
	string y;
	getline(input, user.lettera, ' ');
	for(int i=0; i<3; i++)
		getline(input, num[i], ' ');
	getline(input, user.nome1, ' ');
	getline(input, user.nome2, ' ');	
	for(int i=0; i<3; i++)
		user.numero[i] = stoi(num[i].c_str());
	getline(input, y, '\n');	
	user.x = stoi(y.c_str());	
	return input;
}

void stampaUtenti(A users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}

int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("letturafile.txt");
	while(ifs.good())
	{
		A u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

int main()
{
	
	int n;
	A x[N];
	n = leggi(x);
	stampaUtenti(x,n);								// con n ci prendiamo la dimensione esatta della A
}



// Lettura di testo con numeri trasformandoli in double
class A
{
	string lettera;
	double numero[3];
	string nome1;
	string nome2;
	double x;

public:
	A(){}
	A(string a, double* b, string c, string d, int e) : lettera(a), nome1(c), nome2(d), x(e) 
	{
		for(int i=0; i<3; i++)
		{
			numero[i]=b[i];
		}
	}
	
friend ostream& operator<<(ostream& out, const A& u);	
friend istream& operator>>(istream& input, A &user);
	
};

ostream& operator<<(ostream& out, const A& u)
{
	out << u.lettera << " "<< u.nome1 << " "<< u.nome2 << " "<< u.x << " ";
	{
		for(int i=0; i<3; i++)
			out<<u.numero[i]<< " ";	
	}
	out<<endl;	
	return out;
}

istream& operator>>(istream& input, A &user)
{
	string num[3];
	string y;
	getline(input, user.lettera, ' ');
	for(int i=0; i<3; i++)
		getline(input, num[i], ' ');
	getline(input, user.nome1, ' ');
	getline(input, user.nome2, ' ');	
	for(int i=0; i<3; i++)
		user.numero[i] = stod(num[i].c_str());
	getline(input, y, '\n');	
	user.x = stod(y.c_str());	
	return input;
}

void stampaUtenti(A users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}

int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("letturafile.txt");
	while(ifs.good())
	{
		A u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

int main()
{	
	int n;
	A x[N];
	n = leggi(x);
	stampaUtenti(x,n);								// con n ci prendiamo la dimensione esatta della A
}



// Lettura di testo con numeri trasformandoli in double e int
class A
{
	string lettera;
	int numero[3];
	string nome1;
	string nome2;
	double x;

public:
	A(){}
	A(string a, int* b, string c, string d, double e) : lettera(a), nome1(c), nome2(d), x(e) 
	{
		for(int i=0; i<3; i++)
		{
			numero[i]=b[i];
		}
	}
	
friend ostream& operator<<(ostream& out, const A& u);	
friend istream& operator>>(istream& input, A &user);
	
};

ostream& operator<<(ostream& out, const A& u)
{
	out << u.lettera << " "<< u.nome1 << " "<< u.nome2 << " "<< u.x << " ";
	{
		for(int i=0; i<3; i++)
			out<<u.numero[i]<< " ";	
	}
	out<<endl;	
	return out;
}

istream& operator>>(istream& input, A &user)
{
	string num[3];
	string y;
	getline(input, user.lettera, ' ');
	for(int i=0; i<3; i++)
		getline(input, num[i], ' ');
	getline(input, user.nome1, ' ');
	getline(input, user.nome2, ' ');	
	for(int i=0; i<3; i++)
		user.numero[i] = stoi(num[i].c_str());
	getline(input, y, '\n');	
	user.x = stod(y.c_str());	
	return input;
}

void stampaUtenti(A users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}

int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("letturafile.txt");
	while(ifs.good())
	{
		A u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

int main()
{	
	int n;
	A x[N];
	n = leggi(x);
	stampaUtenti(x,n);								// con n ci prendiamo la dimensione esatta della A
}



// Lettura di testo con numeri trasformandoli in double e int
class A
{
	string lettera;
	int numero[3];
	string nome1;
	string nome2;
	double x;

public:
	A(){}
	A(string a, int* b, string c, string d, double e) : lettera(a), nome1(c), nome2(d), x(e) 
	{
		for(int i=0; i<3; i++)
		{
			numero[i]=b[i];
		}
	}
	
friend ostream& operator<<(ostream& out, const A& u);	
friend istream& operator>>(istream& input, A &user);
	
};

ostream& operator<<(ostream& out, const A& u)
{
	for(int i=u.x; i<u.numero[0]; i++)
	{
		out<<u.nome1<<" ";
	}
	for(int i=u.x; i<u.numero[1]; i++)
	{
		out<<u.nome2<<" ";
	}
	for(int i=u.x; i<u.numero[2]; i++)
	{
		out<<u.nome1<<u.nome2<<" ";
	}
	out<<endl;
	return out;
}

istream& operator>>(istream& input, A &user)
{
	string num[3];
	string y;
	getline(input, user.lettera, ' ');
	for(int i=0; i<3; i++)
		getline(input, num[i], ' ');
	getline(input, user.nome1, ' ');
	getline(input, user.nome2, ' ');	
	for(int i=0; i<3; i++)
		user.numero[i] = stoi(num[i].c_str());
	getline(input, y, '\n');	
	user.x = stod(y.c_str());	
	return input;
}

void stampaUtenti(A users[], int n)
{
		for(int i=0;i<n;i++)
			cout << users[i];
}

int leggi(A utenti[])
{
	int num = 0;
	ifstream ifs("letturafile.txt");
	while(ifs.good())
	{
		A u;
		ifs >> u;
		utenti[num++] = u;
	}
	return num;
}

int main()
{	
	int n;
	A x[N];
	n = leggi(x);
	stampaUtenti(x,n);								// con n ci prendiamo la dimensione esatta della A
}

*/
template <typename T>
class A
{
	
public:
	string tipo;
	int volte;
	T numero[];
	T x;
	T y;
	
	A(){}
	A(string a, int e, T* b, T c, T d) : tipo(a), x(c), y(d), volte(e) 
	{
		for(int i=0; i<e; i++)
		{
			numero[i]=b[i];
		}
	}

template <typename K>	
friend ostream& operator<<(ostream& out, const A<K>& u);	
};
template <typename K>
ostream& operator<<(ostream& out, const A<K>& u)
{
	out << u.tipo<< " "<< u.volte<< " "<< u.x<< " "<< u.y<<endl;	
	return out;
}

template <typename K>
string ins(istream& input, A<K> &user)
{
	string a="";
	while(input.good() && a!="int" && a!="char")
	{
		getline(input, a, ' ');
		if(a=="int"||a=="char")
			user.tipo=a;	
		else
			getline(input, a, '\n');

	}
	return a;
	
}

template <typename T>
void stampaUtenti(A<T> users[], int n)
{
	for(int i=0;i<n;i++)
		cout << users[i];
		
}

template <typename K>
A<K> insint(istream& input, A<K> &user)
{
	string num[10];
	string p;
	string q;
	string bin;
	string rip;
	getline(input, rip, ' ');
	user.volte=stoi(rip.c_str());
	if(user.tipo=="int")
	{
		for(int i=0; i<user.volte; i++)
		{
			getline(input, bin, ':');
			getline(input, num[i], ' ');
		}	
		
		for(int i=0; i<user.volte; i++)
			user.numero[i] = stoi(num[i].c_str());	
			
		getline(input, p, ' ');
		getline(input, q, '\n');	
		user.x = stoi(p.c_str());	
		user.y = stoi(q.c_str());

		return user;	
	}
}

template <typename K>
A<K> inschar(istream& input, A<K> &user)
{	
	string p;
	string q;
	string bin;
	string rip;
	getline(input, rip, ' ');
	user.volte=stoi(rip.c_str());	
	string num[user.volte];	
	if(user.tipo=="char")
	{		
		for(int i=0; i<user.volte; i++)
		{	
			getline(input, bin, ':');
			getline(input, num[i], ' ');	
		}	
		
		for(int i=0; i<user.volte; i++)
			user.numero[i] = num[i][0];	
			
		getline(input, p, ' ');
		getline(input, q, '\n');
		user.x=p[0];
		user.y=q[0];	
		
		return user;	
	}
	
}

template <typename K>
int leggiint(A<K> utenti[])
{
	int num = 0;
	ifstream ifs("leggi.txt");
	while(ifs.good())
	{
		A<K> u;
		string x=ins(ifs,u);
		if(x=="int")
		{
			insint(ifs,u);
			utenti[num++] = u;
		}			
	}
	return num;
}

template <typename K>
int leggicarattere(A<K> utenti[])
{
	int num = 0;
	ifstream ifs("leggi.txt");
	while(ifs.good())
	{
		A<K> u;
		string x=ins(ifs,u);
		if(x=="char")
		{
			inschar(ifs,u);
			utenti[num++] = u;
		}
					
	}
	return num;
}


int main()
{	
	int n;
	A<int>x[3];
	n = leggiint(x);
	stampaUtenti(x,n);	
	
	int m;
	A<char>y[3];
	m=leggicarattere(y);
	stampaUtenti(y,m);						
}

/*
int 10 ins:80 ins:172 ins:13 ins:138 ins:223 ins:245 ins:144 ins:152 ins:151 ins:270 151 138
int 10 ins:54 ins:285 ins:218 ins:95 ins:166 ins:272 ins:118 ins:124 ins:141 ins:84 54 218
int 10 ins:282 ins:208 ins:239 ins:120 ins:37 ins:258 ins:298 ins:141 ins:14 ins:26 14 282
char 15 ins:m ins:h ins:s ins:e ins:j ins:p ins:w ins:f ins:l ins:i ins:u ins:q ins:z ins:n ins:r l n
char 9 ins:o ins:q ins:f ins:l ins:p ins:t ins:c ins:s ins:m c p
char 13 ins:n ins:e ins:t ins:h ins:x ins:o ins:c ins:d ins:r ins:w ins:g ins:i ins:z g r
*/
