/*
La idea es indexar a los primeros n conjuntos a representantes entre n+1 y 2n, esto para evitar problemas cuando
debamos remover a un nodo a otro conjunto (no incluyendo a sus hijos)
*/

#include <bits/stdc++.h>
using namespace std;

int parent[100001], size[100001], sum[100001];
int n;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v, int n) {
    parent[v] = v+n;
    size[v] = 1;
    sum[v] = v;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(a<=n) //checamos que el representante siempre este entre n+1 y 2n 
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        sum[a]+=sum[b];
        sum[b]=sum[a];
        size[b]=size[a];
    }
}

void solve(int n, int m){
	for(int i=1; i<=2*n; i++) //Inicializamos los conjuntos
		make_set(i, n);
	
	for(int i=n+1; i<=2*n; i++){ //conjuntos auxiliares para indexar los primeros n
		parent[i]=i; 
		sum[i]=i-n;
	}
	
	int q, a, b, dad;
	for(int i=0; i<m; i++){
		cin>>q;
		switch(q){
			case 1: cin>>a>>b;
					union_sets(a, b); break;
			case 2: cin>>a>>b;
					dad=find_set(a);
					if(dad!=find_set(b)){
						sum[dad]-=a;
						size[dad]--;
						make_set(a, 0);
					}
					union_sets(a, b); break;
			case 3: cin>>a;
					dad=find_set(a);
					cout<<size[dad]<<" "<<sum[dad]<<endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    while(cin>>n>>m)
    	solve(n, m);

	return 0;
}
