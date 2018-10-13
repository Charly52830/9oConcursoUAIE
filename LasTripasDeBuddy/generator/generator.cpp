#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

vector<int> v;
set<int> exSet;
bool M[1010][1010];

int randNum(int n) {
	return rand()%n;
}

pii cor(int k,int n) {
	return mp(k/n,k%n);
}

int num(int a,int b,int n) {
	return a*n+b;
}

int solve(string input,string output) {
	
	/** Inicia la redirección de cin y cout. **/
	ifstream in(input);
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out(output);
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	/** Termina la redirección **/
	
	/** Solucion aqui **/ 
	int n,m,x,y,a,b;
	bool bul=1;
	cin>>n;
	for(x=0;x<n;x++) {
		for(y=0;y<n;y++) {
			cin>>a>>b;
			M[a-1][b-1]=bul;
			bul=!bul;
		}
	}
	bul=1;
	//Verificar primer diagonal
	for(x=1;x<n && bul;x++)
		bul=M[x][x]==M[x-1][x-1];
	if(bul) {
		if(M[0][0])
			cout<<"El ganador es Buddy!\n";
		else
			cout<<"El ganador es CJ!\n";
		return 0;
	}
	//Verificar segunda diagonal.
	bul=1;
	for(x=1;bul && x<n;x++)
		bul=M[n-1-x][x]==M[n-x][x-1];
	if(bul) {
		if(M[n-1][0])
			cout<<"El ganador es Buddy!\n";
		else
			cout<<"El ganador es CJ!\n";
		return 0;
	}
	//Verificar filas.
	for(x=0;x<n;x++) {
		bul=1;
		for(y=1;bul && y<n;y++)
			bul=M[x][y]==M[x][y-1];
		if(bul) {
			if(M[x][0])
				cout<<"El ganador es Buddy!\n";
			else
				cout<<"El ganador es CJ!\n";
			return 0;
		}
	}
	//Verificar columnas.
	for(x=0;x<n;x++) {
		bul=1;
		for(y=1;bul && y<n;y++) 
			bul=M[y][x]==M[y-1][x];
		if(bul) {
			if(M[0][x])
				cout<<"El ganador es Buddy!\n";
			else
				cout<<"El ganador es CJ!\n";
			return 0;
		}
	}
	//Default
	cout<<"Empate!\n";
	return 0;
}

int main() {
	srand(unsigned(time(0)));
	random_device rd;
	mt19937 gen(rd());
	int n=1,x,fila,col;
	pii p;
	ofstream input;
	string fileName;
	//Caso 1: probable empate.
	fileName="1";
	n+=10;
	for(x=0;x<n*n;x++)
		v.push_back(x);
	random_shuffle(v.begin(),v.end(),randNum);
	input.open(fileName+".in");
	input<<n<<endl;
	for(x=0;x<v.size();x++)	{
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 2: probable empate.
	memset(M,0,sizeof M);
	fileName="2";
	v.resize(0);
	n+=10;
	for(x=0;x<n*n;x++)
		v.push_back(x);
	random_shuffle(v.begin(),v.end(),randNum);
	input.open(fileName+".in");
	input<<n<<endl;
	for(x=0;x<v.size();x++)	{
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 3: Buddy gana por primer diagonal.
	memset(M,0,sizeof M);
	fileName="3";
	v.resize(0);
	n+=10;
	for(x=0;x<n;x++)
		exSet.insert(num(x,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 4: CJ gana por primer diagonal.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="4";
	v.resize(0);
	n+=10;
	for(x=0;x<n;x++)
		exSet.insert(num(x,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 5: Buddy gana por segunda diagonal.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="5";
	v.resize(0);
	n+=10;
	for(x=0;x<n;x++)
		exSet.insert(num(n-1-x,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 6: CJ gana por segunda diagonal.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="6";
	v.resize(0);
	n+=10;
	for(x=0;x<n;x++)
		exSet.insert(num(n-1-x,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 7: Buddy gana por fila.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="7";
	v.resize(0);
	n+=10;
	uniform_int_distribution<> dis7(0,n-1);
	fila=dis7(gen);
	for(x=0;x<n;x++)
		exSet.insert(num(fila,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 8: CJ gana por fila.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="8";
	v.resize(0);
	n+=10;
	uniform_int_distribution<> dis8(0,n-1);
	fila=dis8(gen);
	for(x=0;x<n;x++)
		exSet.insert(num(fila,x,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 9: Buddy gana por columna.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="9";
	v.resize(0);
	n+=10;
	uniform_int_distribution<> dis9(0,n-1);
	col=dis9(gen);
	for(x=0;x<n;x++)
		exSet.insert(num(x,col,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	//Caso 10: CJ gana por columna.
	memset(M,0,sizeof M);
	exSet.clear();
	fileName="10";
	v.resize(0);
	n+=10;
	uniform_int_distribution<> dis10(0,n-1);
	col=dis10(gen);
	for(x=0;x<n;x++)
		exSet.insert(num(x,col,n));
	for(x=0;x<n*n;x++) {
		if(!exSet.count(x))
			v.push_back(x);
	}
	input.open(fileName+".in");
	random_shuffle(v.begin(),v.end(),randNum);
	x=0;
	input<<n<<endl;
	for(set<int>::iterator it=exSet.begin();it!=exSet.end();it++) {
		p=cor(v[x++],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
		p=cor(*it,n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	for(;x<v.size();x++) {
		p=cor(v[x],n);
		input<<p.first+1<<" "<<p.second+1<<endl;
	}
	input.close();
	solve(fileName+".in",fileName+".out");
	return 0;
}
