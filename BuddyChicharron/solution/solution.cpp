#include<math.h>
#include<stdio.h>
#include<iostream>
#define mp make_pair
using namespace std;

typedef pair<float,float> pdd;

pdd chicharronera(int a,int b,int c) {
	float k=sqrt(b*b-4*a*c);
	return mp((-b+k)/(2*a),(-b-k)/(2*a));
}

int main() {
	int a,b,c;
	scanf("(x+%d)(x+%d)=%d",&a,&b,&c);
	pdd p=chicharronera(1,a+b,a*b-c);
	printf("x1= %.5lf x2= %.5lf\n",p.first,p.second);
	return 0;
}
