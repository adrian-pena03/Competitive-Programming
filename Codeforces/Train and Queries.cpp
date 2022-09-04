#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin>>n>>q;
    
    vector<int> f(200001, 0), l(200001, 0);
	//map<int, int> f, l;
    
    for(int i = 1; i <= n ; i++){
    	int hold;
    	cin>>hold;
    	if(f[hold] == 0){
    		f[hold] = i;
    		l[hold] = i;
		} 
    	else l[hold] = max(l[hold], i);
	}
	
	while(q--){
		int a, b; cin>>a>>b;
		
		if(f[a] == 0 || f[b] == 0){
			cout<<"NO"<<endl;
			continue;
		}
		
		if(f[a] < l[b]) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}    
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
		solve();

	return 0;
}
