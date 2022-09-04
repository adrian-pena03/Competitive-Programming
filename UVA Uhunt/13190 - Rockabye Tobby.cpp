#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, doses, time;
    cin>>m>>doses;
    string med;
    map<string, int> tiempo; //Tiempo de cada medicina

    priority_queue<tuple<int, int, string>> pq; //tiempo de dosis, prioridad, nombre
    tuple<int, int, string> hold;
    for(int i=0; i<m; i++){
        cin>>med>>time;
        hold=make_tuple(-1*time, m-i, med);
        pq.push(hold);
        tiempo[med]=time;
    }

    int moment;
    for(int i=0; i<doses; i++){
        hold=pq.top(); pq.pop();
        cout<<-1*get<0>(hold)<<" "<<get<2>(hold)<<endl;
        get<0>(hold)-=tiempo[get<2>(hold)];
        pq.push(hold);
    }

}

int main(){
	int t; cin>>t;
    while(t--) solve();
    return 0;
}
