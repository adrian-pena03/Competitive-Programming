#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(201, false);
int ami, ene;
vector<int> g[201];

void DFS(int nodo, int id){
	if(visited[nodo]) return;
	else visited[nodo]=true;
	cout<<"visitando "<<id<<" "<<nodo<<endl;
	
	(id==1)? ami++ : ene++;
	
	for(int i=0; i<g[nodo].size(); i++){
		DFS(g[nodo][i], -1*id);
	}
	
}

void solve(){
	int n; cin>>n;
	ami=0; ene=0;
	//vector<int> g[n+1];
	
	for(int i=1; i<=n; i++){
		g[i].clear();
		visited[i]=false;
	}
	
	int aux, hold;
	for(int i=1; i<=n; i++){
		
		cin>>aux;
		for(int j=0; j<aux; j++){
			cin>>hold;
			cout<<"enemistando a "<<i<<" y "<<hold<<endl;
			g[i].push_back(hold);
			g[hold].push_back(i);
		}
	}
	
	DFS(1,1);
	
	
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			DFS(i, 1);
		}
	}
	
	cout<<max(ami, ene)<<endl;
}

int main(){
	int t; cin>>t;
	
	while(t--) solve();
	
	return 0;
}
