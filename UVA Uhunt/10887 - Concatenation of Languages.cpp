#include <bits/stdc++.h>
using namespace std;

void solve(int cases){
	int m, n; cin>>m>>n;
	
	set<string> l1, l2, lang;
	string aux;
	getline(cin, aux); //para no contar el enter despues de ingresar m y n
	for(int i=0; i<m; i++){
		getline(cin, aux);
		l1.insert(aux);
	}
	for(int i=0; i<n; i++){
		getline(cin, aux);
		l2.insert(aux);
	}
	
	int ans=0;
	set<string>::iterator i, j;
	for(i=l1.begin(); i!=l1.end(); i++)
		for(j=l2.begin(); j!=l2.end(); j++){
			aux=(*i)+(*j);
			if(lang.count(aux)==0){
				lang.insert(aux);
				ans++;
			}
		}
	
	cout<<"Case "<<cases<<": "<<lang.size()<<endl;
}

int main(){
	int t; cin>>t;
	int cases=1;
	while(t--){
		solve(cases);
		cases++;
	}
	return 0;
}
