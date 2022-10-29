#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    string s;
 
    for(int i = 0; i < n; i++) cin >> nums[i];
    cin >> s;
 
    map<int, char> key;
    for(int i = 0; i < n; i++)
        if(key.count(nums[i]) == 0)
            key[nums[i]] = s[i];
        else if(key[nums[i]] != s[i]){
            cout << "NO" << endl;
            return;
        }
 
    cout << "YES" << endl;
}
 
int main(){
    int t; cin >> t;
    while(t--) solve();
 
    return 0;
}
