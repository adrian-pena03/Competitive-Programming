#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
//ofstream f;

void solve(ull n){
	multiset<ull> urn;
	
	ull k, ans=0;
	for(ull i=0; i<n; i++){
		cin>>k;
		ull hold;
		for(ull j=0; j<k; j++){
			cin>>hold;
			urn.insert(hold);
		}
		
		multiset<ull>::iterator it=urn.end();
		ans+=*(--it)-*(urn.begin());
		if(!urn.empty()) urn.erase(it);
		if(!urn.empty()) urn.erase(urn.begin());
	}
	cout<<ans<<endl;
	//f<<ans<<endl;
}

int main(){
	
    //f.open("output.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ull n; cin>>n;
    while(n!=0){
    	solve(n);
    	cin>>n;
	}
	//f.close();
	return 0;
}
