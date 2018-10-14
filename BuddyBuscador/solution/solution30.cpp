#include<iostream>
using namespace std;

int main() {
	int n,s=0;
	cin>>n;
	for(int x=1;x<=2*n;x+=2)
		s+=x;
	cout<<s<<endl;
	return 0;
}
