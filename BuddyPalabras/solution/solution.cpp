#include<iostream>
using namespace std;

string upperCase(string s) {
	for(int x=0;x<s.size();x++) 
		s[x]-=' ';
	return s;
}

string change(string s) {
	for(int x=0;x<s.size();x++) {
		if(s[x]>'m')
			s[x]-=13;
		else
			s[x]+=13;
	}
	return s;
}

string reverse(string s) {
	for(int x=0;x<s.size()/2;x++) 
		swap(s[x],s[s.size()-1-x]);
	return s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,i=0,m=0,k=0;
	char c;
	string s;
	cin>>n>>q>>s;
	while(q--) {
		cin>>c;
		i+=c=='I';
		m+=c=='M';
		k+=c=='C';
	}
	if(k%2)
		s=change(s);
	if(i%2)
		s=reverse(s);
	if(m%2) 
		s=upperCase(s);
	cout<<s<<endl;
	return 0;
}
