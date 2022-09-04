#include <bits/stdc++.h>
using namespace std;

int stree[2*1024000], t[2*1024000];   //bool marked[2*1024000], inv[2048000];
char marked[2048000]; // m es si el segmento tiene el mismo numero, i si esta listo para invertir, a es neutro
set<int> dads;

void build(string land, int v, int l, int r){
	dads.insert(v);
	if(l==r)
		stree[v] = (land[l]=='1')? 1 : 0;
	else{
		int m = (l + r)/2;
		build(land, 2*v+1, l, m);
		build(land, 2*v+2, m+1, r);
		stree[v]=stree[2*v+1] + stree[2*v+2];
	}
}

void push(int v){
    switch(marked[v]){
    	case 'm': 
        	t[v*2+1] = t[v*2+2] = t[v]; //Asignas el numero a los hijos
        	marked[v*2+1] = marked[v*2+2] = marked[v]; //marcas a los hijos
        	marked[v] = 'a'; //te desmarcas
        	break;
        case 'i':
        	marked[v*2+1] = marked[v*2+2] = marked[v];
    		marked[v] = 'a';
    }
}

int sum(int v, int l, int r, int a, int b){
	cout<<"sumando en nodo "<<v<<" con ["<<l<<", "<<r<<"] y ("<<a<<", "<<b<<")"<<endl;
	if(a > b)
		return 0;
	if(l==a && r==b){
		/*if(marked[v] == 'm')
			stree[v] = t[v] * (r - l + 1);
		else if(marked[v] == 'i'){
			stree[v] = (r - l + 1) - stree[v];
		}*/
		//push(v);
		return stree[v];
	}
	push(v);
	
	int m = (l + r)/2;
	int ans=sum(2*v+1, l, m, a, min(m, b)) + sum(2*v+2, m+1, r, max(a, m+1), b);
	cout<<"\tsuma parcial "<<v<<": "<<ans<<endl;
	return ans;
}

void updateRange(int v, int l, int r, int a, int b, int new_val){
	cout<<"Entrando al nodo "<<v<<" con ["<<l<<", "<<r<<"] y ("<<a<<", "<<b<<")"<<endl;
    if(a > b) 
        return;
    if(a == l && r == b){
    	if(new_val == -1){ //cambiamos la suma
    		marked[v] = 'i';
    		stree[v] = (r - l + 1) - stree[v];
		}else{
			t[v] = new_val;
        	marked[v] = 'm';
        	stree[v] = t[v] * (r - l + 1);
		}
    }else{
        push(v);
        int m = (l + r) / 2;
        updateRange(v*2+1, l, m, a, min(b, m), new_val);
        updateRange(v*2+2, m+1, r, max(a, m+1), b, new_val);
        //
		//stree[v] = stree[2*v+1] + stree[2*v+2];
    }
}

void solve(int cases){
	int pairs; cin>>pairs;
	string land;
	for(int i=0; i<pairs; i++){
		int rep; cin>>rep;
		string hold; cin>>hold;
		while(rep--)
			land+=hold;
	}
	
	int sz=land.size();
	for(int i=0; i<4*land.size(); i++)
		marked[i]='a';
	build(land, 0, 0, sz-1);
	
	int query, Q=1; cin>>query;
	cout<<"Case "<<cases<<":"<<endl;
	for(int i=1; i<=query; i++){
		char q;
		int a, b;
		cout<<"PADRES"<<endl; for(auto it : dads){	cout<<"status: "<<marked[it]<<" "<<it<<" -> "<<stree[it]<<"\t T: "<<t[it]<<endl; }
		cin>>q>>a>>b;
		switch(q){
			case 'F':
				updateRange(0, 0, sz-1, a, b, 1); break;
			case 'E':
				updateRange(0, 0, sz-1, a, b, 0); break;
			case 'I':
				// -1 es que se inviertan todos
				updateRange(0, 0, sz-1, a, b, -1); break;
			case 'S':
				cout<<"Q"<<Q<<": "<<sum(0, 0, sz-1, a, b)<<endl;
				Q++;
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    for(int i=1; i<=t; i++)
		solve(i);
    
	return 0;
}
