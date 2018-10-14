#include<sstream>
#include<random>
#include<fstream>
#include<iostream>

using namespace std;

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
	long long n;
	cin>>n;
	cout<<n*n<<endl;
	return 0;	
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis2(45e3,1e9),dis1(2,45e3);
	//int n=dis(gen);
	ofstream input;
	string fileName;
	//6 casos n <=10^6
	for(int i=1;i<=5;i++) {
		fileName="grupo1.";
		fileName.push_back('0'+i);
		input.open(fileName+".in");
		input<<dis1(gen)<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	fileName="grupo1.6";
	input.open(fileName+".in");
	input<<45000<<endl;
	input.close();
	solve(fileName+".in",fileName+".out");
	//14 casos n<=3x10^7
	for(int i=1;i<=13;i++) {
		stringstream ss;
		ss<<i;
		fileName="grupo2."+ss.str();
		input.open(fileName+".in");
		input<<dis2(gen)<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}
	fileName="grupo2.14";
	input.open(fileName+".in");
	input<<1000000000<<endl;
	input.close();
	solve(fileName+".in",fileName+".out");
	return 0;
}
