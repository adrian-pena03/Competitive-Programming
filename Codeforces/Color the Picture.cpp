#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll r, ll c, vector<ll>& colors, ll k){
    for(ll i = 0; i < k; i++){
        if(c <= 0)
            return true;

        if(colors[i] < 2*r)
            continue;

        ll maxCols = colors[i]/r;
        if(maxCols == c - 1){
            if(maxCols > 2)    
                c = 2;
            continue;
        }
        c -= maxCols;
    }

    return (c <= 0);
}

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vector<ll> colors(k);
    for(ll i = 0; i < k; i++)
        cin>>colors[i];
    sort(colors.begin(), colors.end());

    bool f = check(n, m, colors, k);
    if(check(n, m, colors, k) || check(m, n, colors, k))
        cout<<"Yes";
    else 
        cout<<"No";
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
