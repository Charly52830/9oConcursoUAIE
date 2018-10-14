#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#define mp make_pair
#define ABS(a) (a>=0?a:-a)
using namespace std;

typedef pair<double,double> pdd;

pdd chicharronera(int a,int b,int c) {
	double k=sqrt(b*b-4*a*c);
	return mp((-b+k)/(2*a),(-b-k)/(2*a));
}

int main() {
	//Solucion original.
	FILE *entradaOriginal;
	entradaOriginal=fopen("data.in","r");
	int a,b,c;
	fscanf(entradaOriginal,"(x+%d)(x+%d)=%d",&a,&b,&c);
	pdd p=chicharronera(1,a+b,a*b-c);
	if(p.second<p.first)
		swap(p.first,p.second);
	fclose(entradaOriginal);
	//Solucion del alumno.
	double x1,x2;
	if(!(scanf("x1= %lf x2= %lf",&x1,&x2))) {
		fprintf(stderr,"Error en el formato de salida del competidor\n");
		printf("0.0\n");
		return 0;
	}
	//Comparacion de salidas.
	if(x2<x1)
		swap(x2,x1);
	if(ABS((x1-p.first))>1e-5 || ABS((x2-p.second))>1e-5) {
		fprintf(stderr,"Error en el resultado\n");
		printf("0.0\n");
	}
	else
		printf("1.0\n");
	return 0;
}
