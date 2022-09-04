#include <bits/stdc++.h>
using namespace std;

map<char, int> r;
map<int, char> p;

void solve(){
	vector<int> ava(6, 0);
	string s; cin>>s;
	for(int i=0; i<s.size(); i++)
		switch(s[i]){
			case 'M': ava[0]++; break;
			case 'A': ava[1]++; break;
			case 'R': ava[2]++; break;
			case 'G': ava[3]++; break;
			case 'I': ava[4]++; break;
			case 'T': ava[5]++;
		}
	
	int tot=ava[0]/r[p[0]];
	for(int i=1; i<6; i++)
		if(tot>(ava[i]/r[p[i]]))
			tot=ava[i]/r[p[i]];

	cout<<tot<<endl;
}

int main(){
	r['M']=1;
	r['A']=3;
	r['R']=2;
	r['G']=1;
	r['I']=1;
	r['T']=1;
	p[0]='M';
	p[1]='A';
	p[2]='R';
	p[3]='G';
	p[4]='I';
	p[5]='T';
	
	int n; cin>>n;
	while(n--)
		solve();
	
	return 0;
}
