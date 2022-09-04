#include <bits/stdc++.h>
using namespace std;

void solve(){
	string op;
	string aux;
	getline(cin, aux);
	
	while(getline(cin, aux)){
		if(aux.size() == 0 || !cin)
			break;
		
		op.push_back(aux[0]);
	}
	cout<<op;
	
}

int main(){
	int t; cin>>t;
	while(t--)
		solve();
	
	return 0;
}
