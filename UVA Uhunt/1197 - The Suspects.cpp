#include <bits/stdc++.h>
using namespace std;

int parent[30000], size[30000];

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

void solve(int s, int g){
	for(int i=0; i<s; i++){
		make_set(i);
	}
	int grp; //strudents group
	for(int i=0; i<g; i++){
		cin>>grp;
		bool flag=false;
		int stud, aux=-1;
		
		if(grp) cin>>aux;
		if(aux==0) flag=true;
		
		for(int j=1; j<grp; j++){
			cin>>stud;
			union_sets(aux, stud);
			if(!stud)
				flag=true;
			aux=stud;
		}
		if(flag) union_sets(0, stud);
	}
	cout<<size[find_set(0)]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s, g; cin>>s>>g;
    while(s+g){
    	solve(s, g);
    	cin>>s>>g;
	}
	
	return 0;
}
