#include <bits/stdc++.h>
using namespace std;

void solve(string aux){
	map<char, int> freq;
	
	for(int i=0; i<aux.size(); i++){
		if(aux[i]!=' ' && aux[i]!='.')
			freq[aux[i]]++;
	}
	
	int max=0;
	for(auto it : freq)
		if(it.second>max)
			max=it.second;
	
	for(auto it : freq)
		if(it.second==max)
			cout<<it.first;
			
	cout<<" "<<max<<endl;
}

int main(){
	string aux;
	while(getline(cin, aux)){
		solve(aux);
	}
}
