#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin>>s;
	
	int m, e;
	bool fm=false, fe=false; //para checar que aparezca M y E excatamente una vez
	for(int i=0; i<s.size(); i++){
		if(s[i]!='?' && s[i]!='M' && s[i]!='E'){
			cout<<"no-theorem\n";
			return;
		}
		if(s[i]=='E')
			if(fe==false){
				e=i;
				fe=true;
			}else{
				cout<<"no-theorem\n";
				return;
			}
		
		if(s[i]=='M')
			if(fm==false){
				m=i;
				fm=true;
			}else{
				cout<<"no-theorem\n";
				return;
			}
	}
	
	int y=e-m-1, z=s.size()-e-1;
	//check if it is axiom
	if(m>1 && y==1 && e<s.size()-1 && m==z-1)
		cout<<"theorem\n";
	else if(y<z && m==z-y && y>0) //checar si viene de un axioma reduciendo varias veces
		cout<<"theorem\n";
	else
		cout<<"no-theorem\n";
	
}

int main(){
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
