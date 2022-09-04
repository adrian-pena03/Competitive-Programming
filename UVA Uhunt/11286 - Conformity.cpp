#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	vector<int> c[n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			int hold; cin>>hold;
			c[i].push_back(hold);
		}
		sort(c[i].begin(), c[i].end());
	}
	
	map<vector<int>, int> popu;
	for(int i=0; i<n; i++){
		popu[c[i]]++;
	}
	
	map<vector<int>, int>::iterator i;
	int max=0, ans=0;
	for(i=popu.begin(); i!=popu.end(); i++){
		//cout<<"max: "<<max<<endl;
		if(max<(i->second)){
			max=i->second;
		}
	}
	for(int i=0; i<n; i++){
		if(popu[c[i]]==max){
			ans++;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    while(n){
    	solve(n);
    	cin>>n;
	}
	
	return 0;
}
