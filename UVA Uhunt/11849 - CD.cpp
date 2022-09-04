#include <bits/stdc++.h>
using namespace std;

void solve(int m, int n){
	set<int> cd;
	int aux;
	for(int i=0; i<m; i++){
		cin>>aux;
		cd.insert(aux);
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		cin>>aux;
		ans+=cd.count(aux);
	}
	
	cout<<ans<<endl;
}

int main(){
	int m, n; cin>>m>>n;
	while(m+n){
		solve(m,n);
		cin>>m>>n;
	}
	
	return 0;
}
