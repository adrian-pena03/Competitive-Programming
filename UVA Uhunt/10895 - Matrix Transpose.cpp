#include <bits/stdc++.h>
using namespace std;

/*La idea es crear listas de columnas que almacenan los valores que van en esa columna, que pasara a ser renglon en 
la transpuesta 
para saber en que columna de la trans estara cada elemento, le guardamos su renglon en un pair y asi preservamos eso
igual use una queue para preservar el orden de impresion  deacuerdo al formato*/


void solve(int m, int n){
	vector<pair<int, int>> cols[n+1];
	int t, aux;
	queue<int> colNum;
	for(int i=1; i<=m; i++){
		cin>>t;
		for(int j=0; j<t; j++){
			cin>>aux;
			colNum.push(aux);
		}
		for(int j=0; j<t; j++){
			cin>>aux;
			cols[colNum.front()].push_back({i, aux});
			colNum.pop();
		}
	}
	
	cout<<n<<" "<<m<<endl;
	for(int i=1; i<=n; i++){
		int sz=cols[i].size();
		cout<<sz;
		for(int j=0; j<sz; j++)
			cout<<" "<<cols[i][j].first;
		cout<<endl;
		for(int j=0; j<sz-1; j++)
			cout<<cols[i][j].second<<" ";
		
		if(sz) cout<<cols[i][sz-1].second; //para no invadir memoria
		cout<<endl;
		cols[i].clear();
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int m, n;
	while(cin>>m>>n){
		solve(m, n);
	}
		
	return 0;
}
