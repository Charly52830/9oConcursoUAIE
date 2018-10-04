#include<iostream>
using namespace std;

string upperCase(string s) {
	for(int x=0;x<s.size();x++) 
		s[x]-=' ';
	return s;
}

string lowerCase(string s) {
	for(int x=0;x<s.size();x++) 
		s[x]+=' ';
	return s;
}

string change(string s) {
	if(s[0]>'Z') { //minúsculas
		for(int x=0;x<s.size();x++) {
			if(s[x]>'m')
				s[x]-=13;
			else
				s[x]+=13;
		}
	}
	else {	//mayúsculas
		for(int x=0;x<s.size();x++) {
			if(s[x]>'M')
				s[x]-=13;
			else
				s[x]+=13;
		}
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
	int n,q;
	string s;
	char c;
	cin>>n>>q>>s;
	while(q--) {
		cin>>c;
		if(c=='I') 
			s=reverse(s);
		else if(c=='C')
			s=change(s);
		else {
			if(s[0]>'Z')  //minúsculas
				s=upperCase(s);
			else	//mayúsculas
				s=lowerCase(s);
		}
	}
	cout<<s<<endl;
	return 0;
}
