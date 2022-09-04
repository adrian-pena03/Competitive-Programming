#include <bits/stdc++.h>
using namespace std;

int table[27][27][352]; //suma, longitud, letra inicial

void fill(){
	table[0][0][0]=1;
	for(int i=1; i<27; i++){
		for(int j=0; j<=i; j++){
			for(int k=0; k<352; k++){
				table[i][j][k]=table[i-1][j][k];
				if(j>0 && k>=i)
					table[i][j][k]+=table[i-1][j-1][k-i];
			}
		}
	}
}

int main(){
	fill();
	int l, s; cin>>l>>s;
	while(l+s){
		cout<<table[26][l][s]<<endl;
		cin>>l>>s;
	}	
	
	return 0;
}
