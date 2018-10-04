#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
using namespace std;

string upperCase(string s) {
	for(int x=0;x<s.size();x++) 
		s[x]-=' ';
	return s;
}

string change(string s) {
	for(int x=0;x<s.size();x++) {
		if(s[x]>'m')
			s[x]-=13;
		else
			s[x]+=13;
	}
	return s;
}

string reverse(string s) {
	for(int x=0;x<s.size()/2;x++) 
		swap(s[x],s[s.size()-1-x]);
	return s;
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
	
	int n,q,i=0,m=0,k=0;
	char c;
	string s;
	cin>>n>>q>>s;
	while(q--) {
		cin>>c;
		i+=c=='I';
		m+=c=='M';
		k+=c=='C';
	}
	if(k%2)
		s=change(s);
	if(i%2)
		s=reverse(s);
	if(m%2) 
		s=upperCase(s);
	cout<<s<<endl;
	return 0;	
}

char A[]={'I','M','C'};

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> disWords('a','z'),disCommands(0,2);
	int x,y;
	ofstream input;
	string fileName;
	//Primer grupo
	//10 casos donde n=q
	for(x=100;x<=1000;x+=100) {
		int n=x,q=x;
		stringstream ss;
		ss<<x/100;
		fileName="grupo1."+ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<q<<endl;
		for(y=0;y<n;y++) 
			input<<(char)disWords(gen);
		input<<endl;
		for(y=0;y<q;y++) 
			input<<A[disCommands(gen)]<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	uniform_int_distribution<> disGroup1(1,1000);
	//5 casos donde n y q son aleatorios
	for(x=1;x<=5;x++) {
		int n=disGroup1(gen),q=disGroup1(gen);
		stringstream ss;
		ss<<10+x;
		fileName="grupo1."+ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<q<<endl;
		for(y=0;y<n;y++) 
			input<<(char)disWords(gen);
		input<<endl;
		for(y=0;y<q;y++)
			input<<A[disCommands(gen)]<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}	
	//Segundo grupo
	//30 casos n=q
	for(x=4300;x<=100000;x+=3300) {
		int n=x,q=x;
		stringstream ss;
		ss<<x/3300;
		fileName="grupo2."+ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<q<<endl;
		for(y=0;y<n;y++) 
			input<<(char)disWords(gen);
		input<<endl;
		for(y=0;y<q;y++)
			input<<A[disCommands(gen)]<<endl;
		input.close();		
		solve(fileName+".in",fileName+".out");
	}
	//5 casos donde n y q son aleatorios
	uniform_int_distribution<> disGroup2(1,100000);
	for(x=1;x<=5;x++) {
		int n=disGroup2(gen),q=disGroup2(gen);
		stringstream ss;
		ss<<30+x;
		fileName="grupo2."+ss.str();
		input.open(fileName+".in");
		input<<n<<" "<<q<<endl;
		for(y=0;y<n;y++) 
			input<<(char)disWords(gen);
		input<<endl;
		for(y=0;y<q;y++)
			input<<A[disCommands(gen)]<<endl;
		input.close();		
		solve(fileName+".in",fileName+".out");
	}	
	return 0;
}
