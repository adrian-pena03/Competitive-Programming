#include <bits/stdc++.h>
using namespace std;

/*d siempre es d=2, la idea es primero potencias de 2, luego 3x potencias de 2, es decir,
 los multiplos potencias de 2 de cada primo*/

void solve(){
    int n; cin>>n;
    int idx = 1, available = n;
    vector<bool> check(n + 1, true);
    
    vector<int> aux;
    while(available != 0){
        aux.push_back(idx);
        available--;
        if(available == 0)
            break;
        check[idx]= false;

        idx *= 2;
        if(idx > n){
            while(idx%2 == 0)
                idx /= 2;
            while(!check[idx])
                idx++;
        }
    }

    cout<<2<<endl;
    for(auto it : aux)
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
