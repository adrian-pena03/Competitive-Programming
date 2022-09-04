#include <bits/stdc++.h>
using namespace std;

fstream input;
ofstream output;
int cases = 0;

void solve(){
	cases++;
    int r, c; input>>r>>c;

    int trees = 0;
    vector<vector<char>> grid(r, vector<char> (c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            input>>grid[i][j];
            trees += (grid[i][j] == '^');
        }
    
    if(c == 1 || r == 1){
        if(trees > 0)
            output<<"Case #"<<cases<<": Impossible"<<endl;
        else{
            output<<"Case #"<<cases<<": Possible"<<endl;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++)
                    output<<".";
                output<<endl;
            }
        }
        return;
    }

    output<<"Case #"<<cases<<": Possible"<<endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            output<<"^";
        output<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input.open("second_friend_input.txt");
    output.open("outputB.txt");


    int t; input>>t;
    while(t--)
        solve();

    input.close();
    output.close();

    return 0;
}