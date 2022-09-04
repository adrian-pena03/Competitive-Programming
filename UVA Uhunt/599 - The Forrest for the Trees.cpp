#include <bits/stdc++.h>
using namespace std;

int val(char x){
	return (int)x -(int)'A';
}

void DFS(char nodo, vector<bool>& visited, vector<int> *adj){
	if(visited[val(nodo)]) return;
	
	visited[val(nodo)]=true;
	for(auto it : adj[val(nodo)]){
		DFS(it, visited, adj);
	}
}

void solve(bool flag){	
	vector<int> adj[26];
	vector<char> nodes;
	
	string line; 
	if(!flag) getline(cin, line); //esta bandera es para no leer este getline extra
	getline(cin, line);
	while(line[0]!='*'){
		char u, v;
		u=line[1];
		v=line[3];
		adj[val(u)].push_back(v);
		adj[val(v)].push_back(u);
		getline(cin, line);
	}
	
	getline(cin, line);
	for(int i=0; i<line.size(); i+=2){
		nodes.push_back(line[i]);
	}
	
	int conexComp=0;
	vector<bool> visited(26, false);
	for(auto l : nodes)
		if(!visited[val(l)]){
			DFS(l, visited, adj);
			conexComp++;
		}
	
	
	int acorns=0;
	for(auto it : nodes)
		if(adj[val(it)].empty())
			acorns++;
	cout<<"There are "<<conexComp-acorns<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool flag=false;
    int t; cin>>t;
    while(t--){
    	solve(flag);
    	flag=true;
	}
    	
	return 0;
}
