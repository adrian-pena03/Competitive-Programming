#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin>>n>>x;
    vector<int> nums(2*n);
    
    for(int i = 0; i < 2*n; i++)
        cin>>nums[i];

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
        if(nums[i + n] - nums[i] < x){
            cout<<"NO"<<endl;
            return;
        }

    cout<<"YES"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t; cin>>t;
    while(t--)
    solve();

	return 0;
}
