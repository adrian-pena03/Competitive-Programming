#include <bits/stdc++.h>
using namespace std;

int val(char x){
	return (int) x- (int) '0';
}

void solve(int n, int cases){
	int mat[n][n];
	string aux;
	for(int i=0; i<n; i++){
		cin>>aux;
		for(int j=0; j<n; j++)
			mat[i][j]=val(aux[j]);
	}
	
	int m; cin>>m;
	string query;
	int a,b;
	for(int i=0; i<m; i++){
		cin>>query;
		if(query.compare("row")==0){
			cin>>a>>b;
			for(int j=0; j<n; j++)
				swap(mat[a-1][j], mat[b-1][j]);
		}else if(query.compare("col")==0){
			cin>>a>>b;
			for(int j=0; j<n; j++)
				swap(mat[j][a-1], mat[j][b-1]);
		}else if(query.compare("inc")==0){
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++){
					mat[j][k]+=1;
					mat[j][k]%=10;
				}
		}else if(query.compare("dec")==0){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					mat[j][k]+=9;
					mat[j][k]%=10;
				}
			}
		}else if(query.compare("transpose")==0){
			for(int j=0; j<n; j++)
				for(int k=0; k<j; k++)
					swap(mat[j][k], mat[k][j]);
		}
	}
	
	cout<<"Case #"<<cases<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<mat[i][j];
		cout<<"\n";
	} cout<<"\n";
}

int main(){
	int t, n; cin>>t;
	for(int i=1; i<=t; i++){
		cin>>n;
		solve(n, i);
	}

	return 0;
}
