#include<iostream>
using namespace std;

int main() {
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
