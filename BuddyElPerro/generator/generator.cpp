#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
using namespace std;

int solve(string input,string output) {
	
	/** Inicia la redirección de cin y cout. **/
	ifstream in(input);
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out(output);
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	/** Termina la redirección de cin y cout **/
	
	/** Solución del problema. **/
	int n;
	cin>>n;
	if(n%6==0)
		cout<<"Buddy tiene hambre\n";
	else if(n%2==0 && n%3)
		cout<<"Buddy tiene frio\n";
	else if(n%2 && n%3==0)
		cout<<"Buddy quiere jugar\n";
	else
		cout<<"Buddy detecto un intruso\n";
	return 0;
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(INT_MIN,INT_MAX);
	ofstream input;
	for(int x=1;x<=100;x++) {
		stringstream ss;
		ss<<x;
		string filename=ss.str();
		input.open(filename+".in");
		input<<dis(gen)<<endl;
		input.close();
		solve(filename+".in",filename+".out");
	}
	return 0;
}
