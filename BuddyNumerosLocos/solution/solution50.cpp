#include<iostream>
using namespace std;

int A[65536];

int main() {
	int n,i=0,j=0;
	cin>>n;
	for(int x=1;x<=n/2;x++) {
		if(n%x==0)
			A[i++]=x;
	}
	for(int x=0;x<i;x++)
		cout<<A[x]<<" ";
	if(n)
		cout<<n<<endl;
	return 0;
}
