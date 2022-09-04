#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	string word; cin>>word;
	map<string, int> rep;
	string aux;
	for(int i=0;  i<word.size()-n; i++){
		aux=word.substr(i, n);
		rep[aux]++;
	}
	
	map<string, int>::iterator i, cpy=rep.begin();
	aux=cpy->first;
	int max=cpy->second;
	for(i=rep.begin(); i!=rep.end(); i++){
		aux=i->first;
		if(max<rep[aux]){
			max=rep[aux];
			cpy=i;
		}
	}
	
	cout<<cpy->first<<endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while(cin>>n){
    	solve(n);
	}
	
	return 0;
}
