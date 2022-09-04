#include <bits/stdc++.h>
using namespace std;

int parent[1000], size[1000];
ofstream f;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(int c, int r){
	unordered_map<string, int> key;
	string aux;
	for(int i=0; i<c; i++){
		cin>>aux;
		key[aux]=i;
		make_set(i);
	}
	
	string prey, predator;
	for(int i=0; i<r; i++){
		cin>>prey>>predator;
		union_sets(key[prey], key[predator]);
	}
	
	int max=0;
	for(int i=0; i<c; i++)
		if(max<size[i]) 
			max=size[i];
	
	cout<<max<<endl<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, r; cin>>c>>r;
    while(c+r){
    	solve(c, r);
    	cin>>c>>r;
	}
	return 0;
}
