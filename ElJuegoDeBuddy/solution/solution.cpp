#include<iostream>
using namespace std;

bool M[1010][1010];

int main()
{
	int n,m,x,y,a,b;
	bool bul=1;
	cin>>n;
	for(x=0;x<n;x++) {
		for(y=0;y<n;y++) {
			cin>>a>>b;
			M[a-1][b-1]=bul;
			bul=!bul;
		}
	}
	bul=1;
	//Verificar primer diagonal
	for(x=1;x<n && bul;x++)
		bul=M[x][x]==M[x-1][x-1];
	if(bul) {
		if(M[0][0])
			cout<<"El ganador es Buddy!\n";
		else
			cout<<"El ganador es CJ!\n";
		return 0;
	}
	//Verificar segunda diagonal.
	bul=1;
	for(x=1;bul && x<n;x++)
		bul=M[n-1-x][x]==M[n-x][x-1];
	if(bul) {
		if(M[n-1][0])
			cout<<"El ganador es Buddy!\n";
		else
			cout<<"El ganador es CJ!\n";
		return 0;
	}
	//Verificar filas.
	for(x=0;x<n;x++) {
		bul=1;
		for(y=1;bul && y<n;y++)
			bul=M[x][y]==M[x][y-1];
		if(bul) {
			if(M[x][0])
				cout<<"El ganador es Buddy!\n";
			else
				cout<<"El ganador es CJ!\n";
			return 0;
		}
	}
	//Verificar columnas.
	for(x=0;x<n;x++) {
		bul=1;
		for(y=1;bul && y<n;y++) 
			bul=M[y][x]==M[y-1][x];
		if(bul) {
			if(M[0][x])
				cout<<"El ganador es Buddy!\n";
			else
				cout<<"El ganador es CJ!\n";
			return 0;
		}
	}
	//Default
	cout<<"Empate!\n";
	return 0;
}
