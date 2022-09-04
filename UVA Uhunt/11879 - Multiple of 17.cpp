#include <bits/stdc++.h>
using namespace std;;

int val(char c){
	return (int) c-(int) '0';
}

map<int, int> mod17;

void solve(string n){
	int mod=0;
	for(int i=0; i<n.size(); i++){
		mod+=val(n[n.size()-1-i])*mod17[i%16];
		mod%=17;
	}
	
	if(mod==0) cout<<1<<endl;
	else cout<<0<<endl;
}

int main(){
	string s; cin>>s;
	int aux=1;
	for(int i=0; i<=15; i++){
		mod17[i]=aux;
		aux*=10;
		aux%=17;
	}
	
	while(s.compare("0")!=0){
		solve(s);
		cin>>s;
	}
	return 0;
}
