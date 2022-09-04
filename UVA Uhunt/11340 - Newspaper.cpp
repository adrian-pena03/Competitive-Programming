#include <bits/stdc++.h>
using namespace std;

ofstream f;

void solve(){
	int k; cin>>k;
	
	map<char, int> pay;
	string aux, sub;
	getline(cin, aux);
	for(int i=0; i<k; i++){
		getline(cin, aux);
		
		sub=aux.substr(2, aux.size()-2);
		pay[aux[0]]=stoi(sub);
	}
	
	int m; cin>>m;
	int paid=0;
	for(int i=0; i<=m; i++){
		getline(cin, aux);
		for(int j=0; j<aux.size(); j++){
			auto it=pay.find(aux[j]);
			paid+=it->second;
		}
	}
	
	if((paid%100)!=0){
		cout<<(float) paid/100<<"$\n";
		f<<(float) paid/100<<"$\n";
	}else{
		cout<<paid/100<<".00$\n";
		f<<paid/100<<".00$\n";
	}
	
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	f.open("output.txt");
	int n; cin>>n;
	while(n--)
		solve();
	
	f.close();
	return 0;
}
