#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
using namespace std;

int A[65536],B[65536];

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
	int n,i=0,j=0;
	cin>>n;
	for(int x=1;x*x<=n;x++) {
		if(n%x==0) {
			A[i++]=x;
			if(n/x!=x)
				B[j++]=n/x;	
		}
	}
	for(int x=0;x<i;x++)
		cout<<A[x]<<" ";
	for(int x=j-1;x>=0;x--)
		cout<<B[x]<<" ";
	cout<<endl;
	return 0;
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	//Primer grupo:
	uniform_int_distribution<> dis1(1,20000000);
	//Caso especial 0:
	ofstream input0;
	input0.open("grupo1.1.in");
	input0<<0<<endl;
	input0.close();
	solve("grupo1.1.in","grupo1.1.out");
	//Caso especial raíz cuadrada.
	ofstream input36;
	input36.open("grupo1.2.in");
	input36<<36<<endl;
	input36.close();
	solve("grupo1.2.in","grupo1.2.out");
	for(int i=2;i<5;i++) {
		stringstream ss;
		ss<<i+1;
		string fileName="grupo1."+ss.str();
		ofstream input;
		input.open(fileName+".in");
		input<<(dis1(gen))<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	//Segundo grupo:
	uniform_int_distribution<> dis2(20000001,40000000);
	for(int i=0;i<4;i++) {
		stringstream ss;
		ss<<i+1;
		string fileName="grupo2."+ss.str();
		ofstream input;
		input.open(fileName+".in");
		input<<(dis2(gen))<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}	
	//Mayor numero
	ofstream input2max;
	input2max.open("grupo2.5.in");
	input2max<<40000000<<endl;
	input2max.close();
	solve("grupo2.5.in","grupo2.5.out");
	//Tercer grupo:
	uniform_int_distribution<> dis3(40000001,80000000);
	for(int i=0;i<9;i++) {
		stringstream ss;
		ss<<i+1;
		string fileName="grupo3."+ss.str();
		ofstream input;
		input.open(fileName+".in");
		input<<(dis3(gen))<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}	
	//Mayor numero
	ofstream input3max;
	input3max.open("grupo3.10.in");
	input3max<<80000000<<endl;
	input3max.close();
	solve("grupo3.10.in","grupo3.10.out");
	return 0;
}
