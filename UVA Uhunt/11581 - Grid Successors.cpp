#include <bits/stdc++.h>
using namespace std;

int mat[3][3];

int val(char x){
	return (int) x-(int) '0';
}

bool checkZero(int matr[3][3]){
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(matr[i][j]!=0) return false;
		
	return true;
}

void solve(){
	int aux[3][3];
	
	string s;
	for(int i=0; i<3; i++){
		cin>>s;
		for(int j=0; j<3; j++)
			mat[i][j]=val(s[2-j]);
	}
	
	if(checkZero(mat)){
		cout<<-1<<endl;
		return;
	}
	
	bool flag=true;
	int ans=0;
	while(flag){
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++){
				aux[i][j]=0;
				if(i-1>=0)
					aux[i][j]+=mat[i-1][j];
				if(i+1<=2)
					aux[i][j]+=mat[i+1][j];
				if(j-1>=0)
					aux[i][j]+=mat[i][j-1];
				if(j+1<=2)
					aux[i][j]+=mat[i][j+1];
				aux[i][j]%=2;
			}
			
		if(checkZero(aux)){
			cout<<ans<<endl;
			return;
		}
		
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				mat[i][j]=aux[i][j];
		ans++;
	}
}

int main(){
	int n; cin>>n;
	while(n--)
		solve();
	
	return 0;
}
