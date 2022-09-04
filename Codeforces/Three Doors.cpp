#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> doors(3), opened;

    int key; cin>>key;
    cin>>doors[0]>>doors[1]>>doors[2];

    while(opened.size() != 3){
        opened.push_back(key);
        key = doors[key - 1];
        if(key == 0 && opened.size() != 3){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; cin>>t;
    while(t--)
        solve();
}
