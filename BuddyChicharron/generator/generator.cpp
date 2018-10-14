#include<string.h>
#include<math.h>
#include<stdio.h>
#include<sstream>
#include<random>
#include<fstream>
#include<iostream>
#define mp make_pair
using namespace std;

typedef pair<double,double> pdd;

pdd chicharronera(int a,int b,int c) {
	double k=sqrt(b*b-4*a*c);
	return mp((-b+k)/(2*a),(-b-k)/(2*a));
}

int solve(string input,string output) {
	
	/** Solucion aqui **/ 
	int a,b,c;
	char nombreEntrada[input.size()+1],nombreSalida[output.size()+1];
	strcpy(nombreEntrada,input.c_str());
	strcpy(nombreSalida,output.c_str());
	FILE *entrada,*salida;
	entrada=fopen(nombreEntrada,"r"),salida=fopen(nombreSalida,"w");
	fscanf(entrada,"(x+%d)(x+%d)=%d",&a,&b,&c);
	pdd p=chicharronera(1,a+b,a*b-c);
	fprintf(salida,"x1= %.5lf x2= %.5lf\n",p.first,p.second);
	fclose(entrada);
	fclose(salida);
	return 0;	
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1,100);
	for(int i=1;i<=20;i++) {
		stringstream ss;
		ss<<i;
		string fileName=ss.str();
		ofstream input;
		input.open(fileName+".in");
		input<<"(x+"<<dis(gen)<<")(x+"<<dis(gen)<<")="<<dis(gen)<<endl;
		input.close();
		solve(fileName+".in",fileName+".out");
	}		
	return 0;
}
