#include <bits/stdc++.h>
using namespace std;

/*
Josue Alejandro Perez Lara

Dado que las queries son maximo 30,000 y los posibles valores de estas son entre 0 y 229, es mas eficiente realizar
 el precalculo de estos 230 valores para despues consultar
 
 Para cada a entre 0 y 229 calculamos su maximo con la secuencia de x_i, y las guardamos en el vector maxAnd
 
 Finalmente, consultamos los valores con las querys dadas*/

void solve(){
	int n, q; cin>>n>>q;
	vector<unsigned int> maxAnd(230);
	vector<unsigned int> seq(n);
	
	for(int i=0; i<n; i++) 
		cin>>seq[i];
	
	unsigned int hold;
	maxAnd[0]=0;
	for(int i=1; i<230; i++){
		hold=0;
		for(int j=0; j<n; j++)
			if(hold<(i&seq[j]))
				hold=(i&seq[j]);
		maxAnd[i]=hold;
	}
	
	
	for(int i=0; i<q; i++){
		cin>>hold;
		cout<<maxAnd[hold]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; cin>>t;
	while(t--)
		solve();
	
	
	return 0;
}
