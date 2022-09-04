#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, c, x, y; cin>>a>>b>>c>>x>>y;
	x -= a;
	y -= b;
	
	int sum = 0;
	if(x >= 0) sum += x;
	if(y >= 0) sum += y;
	if((x<0) && (y<0)){
		cout<<"YES"<<endl;
		return;
	}
	
	if(sum <= c) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
    	solve();
    
	return 0;
}
