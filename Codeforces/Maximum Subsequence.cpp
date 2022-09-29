#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll>::iterator vit;
ll n, m, maxSum;
 
//get the sums of every subsequence
void subs(vector<ll>& arr, ll idx, ll last, ll currSum, vector<ll>& SUMS){
    currSum %= m;
    if(idx == last){
        maxSum = max(maxSum%m, currSum);
        SUMS.push_back(currSum);
        return;
    }
 
    subs(arr, idx + 1, last, (currSum + arr[idx])%m, SUMS);
    subs(arr, idx + 1, last, currSum, SUMS);
}
 
void solve(){
    cin >> n >> m;
    vector<int> arr(n);
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    
    ll mid = (n - 1)/2;
    vector<ll> half1, half2;
    for(ll i = 0; i <= mid; i++)
        half1.push_back(arr[i]);
    for(ll i = mid + 1; i < n; i++)
        half2.push_back(arr[i]);
 
    vector<ll> sums1, sums2;
    maxSum = 0;
    //compute all possible sub sums of every half and update
    subs(half1, 0, mid + 1, 0, sums1);
    subs(half2, 0, n - mid - 1, 0, sums2);
	
    sort(sums2.begin(), sums2.end());
    for(auto s : sums1){ //for each sum in the left half, we try to maximize it with a sum in the right half
        ll target = m - 1 - s;
        vit low = lower_bound(sums2.begin(), sums2.end(), target);
        vit sup = upper_bound(sums2.begin(), sums2.end(), target);
		if(low != sums2.end()) maxSum = max(maxSum, (s + (*low))%m);
        maxSum = max(maxSum, (s + (*(sup - 1))%m ));
    }
 
    cout<<maxSum<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    solve();
 
    return 0;
}
