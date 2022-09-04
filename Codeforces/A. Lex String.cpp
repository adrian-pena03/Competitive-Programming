#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, k; cin>>n>>m>>k;
    string a, b, c;
    cin>>a>>b;
    //vector<bool> Aused(asz, false), Bused(bsz, false);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int aptr=0, bptr=0;
    int opa=0, opb=0;
    while(aptr<n && bptr<m){
        if((a[aptr]<=b[bptr] && opa<k) || opb>=k){
            c.push_back(a[aptr]);
            aptr++;
            opa++;
            opb=0;
        }else if((a[aptr]>=b[bptr] && opb<k) || opa>=k){
            c.push_back(b[bptr]);
            bptr++;
            opb++;
            opa=0;
        }
    }
    cout<<c<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
    
	return 0;
}
