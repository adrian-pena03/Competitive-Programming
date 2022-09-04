#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	ll n; cin>>n;
	vector<ll> nums(n), e(n), a(n);
	for(ll i = 0; i < n; i++)
		cin>>nums[i];
		
	e[0] = nums[0];
	for(ll i = 1; i < n; i++)
		e[i] = e[i - 1] + nums[i];
		
	for(ll i = 0; i < n; i++)
		a[i] = e[i] - nums[i];
		
	if(e[n - 1] != 0 || a[0] != 0){
		cout<<"No\n";
		return;
	}
	
	for(ll i = 0; i < n; i++){
		if(e[i] < 0){
			cout<<"No\n";
			return;
		}else if(e[i] == 0){
			for(ll j = i + 1; j < n; j++)
				if(e[j] != 0){
					cout<<"No\n";
					return;
				}
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"Yes\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
