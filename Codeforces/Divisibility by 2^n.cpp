#include <bits/stdc++.h>
using namespace std;

int getTwos(int x){
    int twos = 0;
    while(x%2 == 0){
        twos++;
        x /= 2;
    }

    return twos;
}

void solve(){
    int n; cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    int twos = 0;
    for(auto n : nums) twos += getTwos(n);

    if(twos >= n){
        cout << 0 << endl;
        return;
    }

    int missing = n - twos, ans = 0;
    int add = (int) log2(n), upper = pow(2, add);
    while(1){
        if(upper == 1){
            cout << -1 << endl;
            return;
        }

        int tot = n/upper - n/(2*upper);
        for(int i = 1; i <= tot; i++){
            ans++;
            missing -= add;
            if(missing <= 0){
                cout << ans << endl;
                return;
            }
        }
        upper /= 2;
        add--;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
