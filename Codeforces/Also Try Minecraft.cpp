#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll max(ll a, ll b){
	return  (a > b)? a : b;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll m, q; cin>>m>>q;
    vector<ll> mapp(m), lr(m), rl(m);

    lr[0] = 0, rl[m - 1] = 0;

    for(ll i = 0; i < m; i++)
        cin>>mapp[i];

    for(ll i = 1; i < m; i++)
        lr[i] = max(0, mapp[i - 1] - mapp[i]) + lr[i - 1];

    for(ll i = m - 2; i >= 0; i--)
        rl[i] = max(0, mapp[i + 1] - mapp[i]) + rl[i + 1];

    while(q--){
        ll a, b; cin>>a>>b;
        if(a < b) cout<<lr[b - 1] - lr[a - 1]<<endl;
        else cout<<rl[b - 1] - rl[a - 1]<<endl;
    }
}
