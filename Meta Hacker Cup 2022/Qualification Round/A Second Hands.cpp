#include <bits/stdc++.h>
using namespace std;

fstream input;
ofstream output;
int cases = 0;

void solve(){
	cases++;
    int n, k; input>>n>>k;

    map<int, int> rep;
    bool no = false;
    for(int i = 0; i < n; i++){
        int part; input>>part;
        if(rep[part] == 2)
            no = true;
        
        rep[part]++;
    }
    
    if(2*k < n || no){
        output<<"Case #"<<cases<<": NO"<<endl;
        return;
    }
    
    output<<"Case #"<<cases<<": YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input.open("second_hands_input.txt");
    output.open("outputA.txt");


    int t; input>>t;
    while(t--)
        solve();

    input.close();
    output.close();

    return 0;
}
