#include <bits/stdc++.h>
using namespace std;

void solve(){
	map<char, int> freq;
	string aux;

	getline(cin, aux);
	
	for(int i=0; i<aux.size(); i++){
		if((97<=(int) aux[i] && (int) aux[i] <=122) || (65<=(int) aux[i] && (int) aux[i]<=90)){
			aux[i]=tolower(aux[i]);
			freq[aux[i]]++;
		}
	}
	
	int max=0;
	for(auto it : freq)
		if(it.second>max)
			max=it.second;
	
	//cout<<"\t->";
	for(auto it : freq)
		if(it.second==max)
			cout<<it.first;
			
	cout<<endl;
}

int main(){
	string aux;
	int t; cin>>t;
	getline(cin, aux);
	while(t--){
		solve();
	}
}
