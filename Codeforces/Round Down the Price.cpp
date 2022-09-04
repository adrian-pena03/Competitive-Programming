#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    s[0]--;    
    
	int i = 0;
	while(i < s.size() && s[i] == '0')
		i++;
	if(i == s.size())
		cout<<0;
	else 
		for(int j = i; j < s.size(); j++)
			cout<<s[j];
	
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
		solve();

	return 0;
}
