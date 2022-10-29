#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; char c; cin >> n >> c;
    string s; cin >> s; s += s;

    int ans = -1, start = -1, end = -1;
    for(int i = 0; i < n; i++)
        if(s[i] == c){
            start = i;
            while(s[i] != 'g')
                i++;
            ans = max(ans, i -  start);
        }

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
