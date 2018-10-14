#include<iostream>
using namespace std;

int A[65536];

int main() {
	int n,i=0,j=0;
	cin>>n;
	for(int x=1;x<=n;x++) {
		if(n%x==0)
			A[i++]=x;
	}
	for(int x=0;x<i;x++)
		cout<<A[x]<<" ";
	cout<<endl;
	return 0;
}
