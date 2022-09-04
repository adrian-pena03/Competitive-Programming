#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, string, int> player;

ofstream _file;

void solve(int i){
    vector<player> team;
    vector<string> names(10);
    player aux = make_tuple(0, 0, "a", 0);
    
    for(int i = 0; i < 10 ; i++){
        cin>>names[i];
        get<2>(aux) = names[i];
        cin>>get<0>(aux);
        cin>>get<1>(aux);
        get<1>(aux) *= -1;
        get<3>(aux) = i;

        team.push_back(aux);
    }
    
    sort(team.begin(), team.end());
    
    vector<string> ans(5);
    for(int i = 5; i <= 9; i++){
    	ans[i - 5] = names[get<3>(team[i])];
	}
	sort(ans.begin(), ans.end());
	_file<<"Case "<<i<<":"<<endl;
    _file<<"(";
    for(int i = 0; i < 4; i ++)
        _file<<ans[i]<<", ";
    _file<<ans[4]<<")"<<endl;
    
    for(int i = 0; i < 5; i++){
    	ans[i] = names[get<3>(team[i])];
	}
	sort(ans.begin(), ans.end());
    _file<<"(";
    for(int i = 0; i < 4; i ++)
        _file<<ans[i]<<", ";
    _file<<ans[4]<<")"<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    _file.open("output.txt");
    int t; cin>>t;
    for(int i = 1; i <= t; i++)
        solve(i);
    _file.close();

	return 0;
}
