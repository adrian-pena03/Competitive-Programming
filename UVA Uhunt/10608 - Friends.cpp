#include <bits/stdc++.h>
using namespace std;

int parent[30001], size[30001];

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

void solve(){
	int n, m; cin>>n>>m;
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	
	int a, b;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		union_sets(a, b);
	}
	
	int max=0;
	for(int i=1; i<=n; i++)
		if(max < size[i])
			max = size[i];
	cout<<max<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
	
	return 0;
}
