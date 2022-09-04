#include <bits/stdc++.h>
using namespace std;

fstream input;
ofstream output;
int cases = 0, r, c;
bool impossible;

typedef pair<int, int> pii;

vector<int> dirX = {0, 0 ,1, -1}, dirY = {1, -1, 0, 0};

void toRock(pii neig, vector<vector<char>>& grid){
    if(impossible || grid[neig.first][neig.second] == '#')
        return;

    int freeneigs = 0;
    int x = neig.first, y = neig.second;
    for(int k = 0; k < 4; k++){
        int newx = x + dirX[k], newy = y + dirY[k];
        if(0 > newx || newx >= r || 0 > newy || newy >= c)
            continue;
        freeneigs += (grid[newx][newy] == '^' || grid[newx][newy] == '.');
    }

    if(freeneigs >= 2)
        return;
    if(grid[x][y] == '^'){
        impossible = true;
        return;
    }

    grid[x][y] = '#'; //se convierte en roca, pues no puede ser arbol

    for(int k = 0; k < 4; k++){
        int newx = x + dirX[k], newy = y + dirY[k];
        if(newx < 0 || newx >= r || 0 > newy || newy >= c)
            continue;

        toRock({newx, newy}, grid);
    }
}

void solve(){
	cases++;
    input>>r>>c;
    impossible = false;

    int trees = 0;
    vector<vector<char>> forest(r, vector<char> (c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            input>>forest[i][j];
            trees += (forest[i][j] == '^');
        }

    if(c == 1 || r == 1){
        if(trees > 0)
            output<<"Case #"<<cases<<": Impossible"<<endl;
        else{
            output<<"Case #"<<cases<<": Possible"<<endl;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++)
                    output<<forest[i][j];
                output<<endl;
            }
        }
        return;
    }

    vector<vector<char>> grid = forest;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(grid[i][j] != '#')
                toRock({i, j}, grid);

    output<<"Case #"<<cases<<": ";
    if(impossible){
        output<<"Impossible"<<endl;
        return;
    }

    output<<"Possible"<<endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            if(forest[i][j] == '#')
                output<<'#';
            else if(grid[i][j] == '#')
                output<<'.';
            else 
                output<<'^';

        output<<endl;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input.open("second_second_friend_input.txt");
    output.open("output.txt");

    int t; input>>t;
    while(t--)
        solve();

    input.close();
    output.close();

    return 0;
}
