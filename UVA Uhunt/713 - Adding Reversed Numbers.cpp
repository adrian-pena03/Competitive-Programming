#include <bits/stdc++.h>
using namespace std;

int ctoint(char x){
	return (int) x-48;
}

char itoc(int x){
	return (char) x+48;
}

void reversed(string s, string *rev){
	bool band=false;
	for(int i=s.size()-1; i>=0; i--)
		if(s[i]!='0' || band==true){
			(*rev).push_back(s[i]);
			band=true;
		}
}

void solve(){
	string a, b; cin>>a>>b;
	
	string reva="0", revb="0";
	if(a.size()>b.size())
		for(int i=0; i<a.size()-b.size(); i++)
			revb.push_back('0');
	else if(b.size()>a.size())
		for(int i=0; i<b.size()-a.size(); i++)
			reva.push_back('0');
	
	reversed(a, &reva); reversed(b, &revb);
	
	string ans;
	int acarreo=0, d1; 
	for(int i=reva.size()-1; i>=0; i--){
		d1=ctoint(reva[i])+ctoint(revb[i])+acarreo;
		acarreo=d1/10;
		d1%=10;
		ans.push_back(itoc(d1));
	}
	string aux, ansrev;
	reversed(ans, &aux);
	reversed(aux, &ansrev);
	cout<<ansrev<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n; cin>>n;
	for(int i=0; i<n; i++)
		solve();
	
	return 0;
}
