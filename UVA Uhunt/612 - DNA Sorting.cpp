#include <bits/stdc++.h>
using namespace std;

int M;

int unsortedness(string s, int size){
	int tot=0;
	for(int i=0; i<size; i++)
		for(int j=i+1; j<size; j++){
			if(s[i]>s[j])
				tot++;
		}
	return tot;
}

void solve(){
	int n, m; cin>>n>>m;
	vector<pair<int, int>> pos(m);
	vector<string> dna(m);
	
	string hold;
	for(int i=0; i<m; i++){
		cin>>hold;
		dna[i]=hold;
		pos[i].first=unsortedness(hold, n);
		pos[i].second=i;
	}
	
	sort(pos.begin(), pos.end());

	for(int i=0; i<m; i++)		cout<<dna[pos[i].second]<<endl;
	
	if(M!=0)	cout<<endl; 
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>M;
    while(M--) solve();
	
	return 0;
}
