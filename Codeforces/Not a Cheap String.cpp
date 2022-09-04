#include <bits/stdc++.h>
using namespace std;

int val(char x){
	return (int) x - (int) 'a' + 1;
}

void solve(){
    string s;
    int p, cost = 0;
    cin>>s>>p;
    
    for(auto it : s)
	    cost += val(it);
	    
	if(cost <= p){
		cout<<s<<endl;
		return;
	}
	
	vector<pair<char, int>> key;
	for(int i = 0; i < s.size(); i++)
		key.push_back({s[i], i});
	sort(key.begin(), key.end());
	
	int sz = s.size() - 1;
	vector<bool> check(s.size(), true);
	while(cost > p){
		check[key[sz].second] = false;
		cost -= val(key[sz].first);
		sz--;
	}
	
	for(int i = 0; i < s.size(); i++)
		if(check[i])
			cout<<s[i];
			
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
