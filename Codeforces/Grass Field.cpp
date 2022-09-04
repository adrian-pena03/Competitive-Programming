#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

void solve(){
    cin>>a>>b>>c>>d;
    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

    int ans;
    if(a + b + c + d == 0)
        ans = 0;
    else if(a == 1 && d == 1)
        if(b + c <= 1)
            ans = 1;
        else ans = 2;
    else if(b == 1 && c == 1)
        if(a + d <= 1)
            ans = 1;
        else ans = 2;
    else ans = 1;
    
    cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();

	return 0;
}
