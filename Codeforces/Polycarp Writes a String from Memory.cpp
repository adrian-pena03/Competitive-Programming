#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    int sz = s.size();
    
    int tot = 1;
	set<char> key;
    for(int i = 0; i < sz; i++){
    	if(key.size() < 3)
    		key.insert(s[i]);
    	else if(key.count(s[i]) == 0){
    		tot++;
    		key.clear();
    		key.insert(s[i]);
		}
	}
    cout<<tot<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
		solve();

	return 0;
}
