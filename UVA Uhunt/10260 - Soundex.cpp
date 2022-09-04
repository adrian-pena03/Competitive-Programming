#include <bits/stdc++.h>
using namespace std;

map<char, int> cod;

void solve(string s){
	if(cod[s[0]]!=0)
		cout<<cod[s[0]];
		
	if(s.size()>1)
		for(int i=1; i<s.size(); i++)
			if(cod[s[i]]!=cod[s[i-1]] && cod[s[i]]!=0)
				cout<<cod[s[i]];
	cout<<endl;
}

int main(){
	cod['B']=1;
	cod['F']=1;
	cod['P']=1;
	cod['V']=1;
	cod['C']=2;
	cod['G']=2;
	cod['J']=2;
	cod['K']=2;
	cod['Q']=2;
	cod['S']=2;
	cod['X']=2;
	cod['Z']=2;
	cod['D']=3;
	cod['T']=3;
	cod['L']=4;
	cod['M']=5;
	cod['N']=5;
	cod['R']=6;
	string aux;
	while(cin>>aux)
		solve(aux);

	return 0;
}
