#include <bits/stdc++.h>
using namespace std;

/*La idea es ver cuantos cuadros negros hay en el subrectangulo traslandando el tablero*/

void solve(int n, int m, int c){
	if(n<8 || m<8){
		cout<<0<<endl;
		return;
	}
	
	int tot=(m-7)*(n-7)/2;
	if(c==1 && (((m-7)*(n-7))%2==1))
		tot++;

	cout<<tot<<endl;
}

int main(){
	int m,n,c; cin>>n>>m>>c;
	while(n+m+c){
		solve(n,m,c);
		cin>>n>>m>>c;
	}
	
	return 0;
}
