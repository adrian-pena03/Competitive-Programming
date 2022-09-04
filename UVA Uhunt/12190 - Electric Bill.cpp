/*La idea es hacerlo con binary search sobre los posibles consumos. Se obtiene cuanto es el consumo de ambos,
y se sigue la bs */
#include <bits/stdc++.h>
using namespace std;

int getConsumption(int cost){
    int con = 0, aux;
    aux = min(200, cost);
    con += aux/2;
    cost -= aux;

    aux = min(29700, cost);
    con += aux/3;
    cost -= aux;

    aux = min(4950000, cost);
    con += aux/5;
    cost -= aux;

    con += cost/7;
    return con;
}

int getPrice(int cost){
    int con = 0, aux;
    aux = min(100, cost);
    con += aux*2;
    cost -= aux;

    aux = min(9900, cost);
    con += aux*3;
    cost -= aux;

    aux = min(990000, cost);
    con += aux*5;
    cost -= aux;

    con += cost*7;
    return con;
}

void solve(int a, int b){
    int target = getConsumption(a);
    int l = 1, r = target/2;
    while(l <= r){
        int m = (l + r)/2;
        cout<<"m: "<<m;
        int dif = getPrice(target - m) - getPrice(m);
        if(dif == b){
            cout<<getPrice(m)<<endl;
            return;
        }else if(dif < b) r = m - 1;
        else l = m + 1;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int a, b; cin>>a>>b;
    while(a + b){
        solve(a, b);
        cin>>a>>b;
    }

	return 0;
}
