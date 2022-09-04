#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> rep(10, 0);

    for(int i = 1; i <= n; i++){
        int cpy = i;
        while(cpy > 0){
            rep[cpy%10]++;
            cpy /= 10;
        }
    }

    for(int i = 0; i < rep.size() - 1; i++)
        cout<<rep[i]<<" ";
    cout<<rep[rep.size() - 1]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t; cin>>t;
    while(t--)
        solve();

	return 0;
}
