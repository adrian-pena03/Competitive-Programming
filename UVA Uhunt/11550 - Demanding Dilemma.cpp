#include <bits/stdc++.h>
using namespace std;

void solve(){
	int m, e; cin>>m>>e;
	int mat[m][e];
	
	vector<int> sums(e, 0);
	for(int i=0; i<m; i++)
		for(int j=0; j<e; j++){
			cin>>mat[i][j];
			if(mat[i][j]!=0 && mat[i][j]!=1){
				cout<<"No1\n";
				return;
			}
			sums[j]+=mat[i][j];
		}
	
	for(auto x : sums)
		if(x!=2){
			cout<<"No2\n";
			return;
		}
	
	set<pair<int, int>> edges;
	for(int i=0; i<e; i++){
		int u=-1, v=-1;
		int j=0;
		while(u!=1){
			u=mat[j][i];
			j++;
		}
		while(v!=1){
			v=mat[j][i];
			j++;
		}
		if(!edges.count({u,v})){
			edges.insert({u,v});
		}else{
			cout<<"No3\n";
			return;
		}
		/*if(!edges.count({v,u})){
			edges.insert({v,u});
		}else{
			cout<<"No4["<<i<<"\n";
			return;
		}*/
	}
	cout<<"Yes\n";
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
	
	return 0;
}
