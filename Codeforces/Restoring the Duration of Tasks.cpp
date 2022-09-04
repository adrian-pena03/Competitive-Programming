#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> begin(n), end(n);
	for(int i=0; i<n; i++)
		cin>>begin[i];
	for(int i=0; i<n; i++)
		cin>>end[i];
		
	vector<int> times(n);
	times[0]=end[0]-begin[0];
	
	for(int i=1; i<n; i++){
		int hold=max(end[i-1], begin[i]);
		times[i]=end[i]-hold;
	}
	
	for(auto it : times)
		cout<<it<<" ";
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
    
	return 0;
}
