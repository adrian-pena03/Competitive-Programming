#include <bits/stdc++.h>
using namespace std;

void solve(int i){
    for(int j = 1; j < i; j++)
        for(int k = j; k < i; k++){
            int target = i*i*i - j*j*j - k*k*k;
            if(target <= 0)
                continue;
                
            int l = k, r = i - 1;
            while(l <= r){
                int m = (l + r)/2;
                int cube = m*m*m;
                if(cube == target){
                    cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<m<<")"<<endl;
                    r = l - 1;
                }else if(cube < target) l = m + 1;
                else r = m - 1;
            }
        }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 1; i <= 200; i++)
        solve(i);

	return 0;
}
