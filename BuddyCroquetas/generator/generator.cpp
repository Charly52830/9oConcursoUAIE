#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
using namespace std;

typedef long long ll;

ll M[1010][1010];

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
	int n,m,q,x,y,a,b;
	cin>>n>>m>>q;
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) 
			cin>>M[x][y];
	}
	
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			if(y-1>=0)
				M[x][y]+=M[x][y-1];
			if(x-1>=0)
				M[x][y]+=M[x-1][y];
			if(y-1>=0 && x-1>=0)
				M[x][y]-=M[x-1][y-1];
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>a>>b>>x>>y;
		a--;
		b--;
		x--;
		y--;
		ll s=M[x][y];
		if(a-1>=0)
			s-=M[a-1][y];
		if(b-1>=0)
			s-=M[x][b-1];
		if(a-1>=0 && b-1>=0)
			s+=M[a-1][b-1];
		cout<<"Pregunta #"<<i<<": "<<s<<endl;
	}
	return 0;	
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis1(1,100),dis2(101,1000);
	string fileName;
	ofstream input;
	int x,y,a,b,c,d,n,m,q;
	//6 casos.
	for(int i=1;i<=4;i++) {
		n=dis1(gen),m=dis1(gen),q=dis1(gen);
		stringstream ss;
		ss<<i;
		fileName=ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<m<<" "<<q<<endl;
		for(x=0;x<n;x++) {
			for(y=0;y<m;y++) 
				input<<dis1(gen)<<" ";
			input<<endl;
		}
		uniform_int_distribution<> disN(1,n),disM(1,m);
		while(q--) {
			a=disN(gen),c=disN(gen);
			if(c<a)
				swap(a,c);
			b=disM(gen),d=disM(gen);
			if(d<b)
				swap(b,d);
			input<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	//Casos especiales.
	{
		n=100,m=100,q=100;
		fileName="5";
		input.open(fileName+".in");
		input<<n<<" "<<m<<" "<<q<<endl;
		for(x=0;x<n;x++) {
			for(y=0;y<m;y++) 
				input<<dis1(gen)<<" ";
			input<<endl;
		}
		uniform_int_distribution<> disN(1,n),disM(1,m);
		while(q--) {
			a=disN(gen),c=disN(gen);
			if(c<a)
				swap(a,c);
			b=disM(gen),d=disM(gen);
			if(d<b)
				swap(b,d);
			input<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	{
		n=1,m=1,q=2;
		fileName="6";
		input.open(fileName+".in");
		input<<n<<" "<<m<<" "<<q<<endl;
		for(x=0;x<n;x++) {
			for(y=0;y<m;y++) 
				input<<dis1(gen)<<" ";
			input<<endl;
		}
		uniform_int_distribution<> disN(1,n),disM(1,m);
		while(q--) {
			a=disN(gen),c=disN(gen);
			if(c<a)
				swap(a,c);
			b=disM(gen),d=disM(gen);
			if(d<b)
				swap(b,d);
			input<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	//Resto de los casos
	for(int i=7;i<=19;i++) {
		n=dis2(gen),m=dis2(gen),q=dis2(gen);
		stringstream ss;
		ss<<i;
		fileName=ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<m<<" "<<q<<endl;
		for(x=0;x<n;x++) {
			for(y=0;y<m;y++) 
				input<<dis2(gen)<<" ";
			input<<endl;
		}
		uniform_int_distribution<> disN(1,n),disM(1,m);
		while(q--) {
			a=disN(gen),c=disN(gen);
			if(c<a)
				swap(a,c);
			b=disM(gen),d=disM(gen);
			if(d<b)
				swap(b,d);
			input<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	//Caso especial MAX.
	{
		n=1000,m=1000,q=1000;
		fileName="20";
		input.open(fileName+".in");
		input<<n<<" "<<m<<" "<<q<<endl;
		for(x=0;x<n;x++) {
			for(y=0;y<m;y++) 
				input<<dis2(gen)<<" ";
			input<<endl;
		}
		uniform_int_distribution<> disN(1,n),disM(1,m);
		while(q--) {
			a=disN(gen),c=disN(gen);
			if(c<a)
				swap(a,c);
			b=disM(gen),d=disM(gen);
			if(d<b)
				swap(b,d);
			input<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	return 0;
}
