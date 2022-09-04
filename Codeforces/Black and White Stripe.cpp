#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;

    int f = 0;
    for(int i = 0; i < k; i++)
        if(s[i] == 'W')
            f++;

    int ans = f;

    for(int i = k; i < n; i++){
        if(s[i] == 'W')
            f++;
        if(s[i - k] == 'W')
            f--;
        ans = min(ans, f);
    }
    cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
        solve();

	return 0;
}
