#include <bits/stdc++.h>
using namespace std;

vector<int> nums(30);

void check(int *p, int l, int r, bool* end){
	if(l==r) return;
	
	for(int i=l+1; i<=r; i++){
		bool flag=false;
		while(nums[i - 1] >= nums[i]){
			if(nums[i - 1] == nums[i] && nums[i] == 0){
				(*end) = true;
				return;
			}
			nums[i - 1]/=2;
			(*p)++;
			flag=true;
		}
		
		if(flag){
			check(p, max(0, i - 2), i - 1, end);
		}
	}	
}

void solve(){
	int n; cin>>n;
	for(int i = 0; i < n; i++)
		cin>>nums[i];
	
	int ans = 0;
	bool end=false;
	check(&ans, 0, n - 1, &end);
	
	if(end) ans = -1;
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
    
	return 0;
}
