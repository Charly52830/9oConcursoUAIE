#include<iostream>
using namespace std;

typedef long long ll;

ll M[1010][1010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q,x,y,a,b;
	cin>>n>>m>>q;
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			cin>>M[x][y];
		}
	}
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			if(y-1>=0)
				M[x][y]+=M[x][y-1];
			if(x-1>=0)
				M[x][y]+=M[x-1][y];
			if(y-1>=0 && x-1>=0)
				M[x][y]-=M[x-1][y-1];
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>a>>b>>x>>y;
		a--;
		b--;
		x--;
		y--;
		ll s=M[x][y];
		if(a-1>=0)
			s-=M[a-1][y];
		if(b-1>=0)
			s-=M[x][b-1];
		if(a-1>=0 && b-1>=0)
			s+=M[a-1][b-1];
		cout<<"Pregunta #"<<i<<": "<<s<<endl;
	}
	return 0;
}
