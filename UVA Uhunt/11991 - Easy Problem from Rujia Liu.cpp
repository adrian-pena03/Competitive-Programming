#include <bits/stdc++.h>
using namespace std;

void solve(int n, int q){
	vector<vector<int>> positions(1000001);
	int hold;
	for(int i=1; i<=n; i++){
		cin>>hold;
		positions[hold].push_back(i);
	}
	
	int query, num;
	for(int i=0; i<q; i++){
		cin>>query>>num;
		if(positions[num].size()<query) cout<<"0"<<endl;
		else cout<<positions[num][query-1]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    while(cin>>n>>q) solve(n, q);
	
	return 0;
}
