#include <bits/stdc++.h>
using namespace std;
//cuenta los bist prendidos que hay en la representacion binaria de un numero
typedef unsigned long long ull;

void solve(){
    ull n; cin>>n;
    ull mask = 1, ans = 0;
    while(n >= mask){
        if( (n & mask) != 0)
            ans++;
        mask <<= 1;
    }
    cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();

	return 0;
}
