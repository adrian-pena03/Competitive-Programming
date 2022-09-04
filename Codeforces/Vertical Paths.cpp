#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000], aux;
vector<bool> visited(200000, false);
vector<vector<int>> paths;

void DFS(int nodo, int* ans){
	if(visited[nodo-1]) return;
	
	visited[nodo-1] = true;
	aux.push_back(nodo); //agregamos al camino
	
	if( ( (adj[nodo-1].size() == 1) && visited[adj[nodo-1][0]-1]) || (adj[nodo-1].empty())){
		(*ans)++;
		paths.push_back(aux);
		aux.clear();
	}
	
	for(int i=0; i<adj[nodo - 1].size(); i++)
		DFS(adj[nodo-1][i], ans);
}

void solve(){
	int n; cin>>n;
	
	if(!paths.empty())
		paths.clear();
	for(int i=0; i<=n; i++){
		if(adj[i].size() != 0) 
			adj[i].clear();
		visited[i]=false;
	}
	
	//guardar el grafo
	int root, nodo;
	for(int i = 0; i < n; i++){
		cin>>nodo;
		if(i + 1 == nodo){
			root = i + 1;
			continue;
		}
		adj[i].push_back(nodo);
		adj[nodo-1].push_back(i+1);
	}
	
	int ans=0;
	DFS(root, &ans);
	
	cout<<ans<<endl;
	for(int i=0; i<paths.size(); i++){
		cout<<paths[i].size()<<endl;
		for(auto it : paths[i])
			cout<<it<<" ";
		cout<<endl;
	}   cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
    
	return 0;
}
