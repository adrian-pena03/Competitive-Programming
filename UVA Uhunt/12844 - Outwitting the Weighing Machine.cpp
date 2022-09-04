/* La idea es checar que los primeros dos sumas W1 y los ultimos 2 suman W10, y que estos 4 definen el tercer peso, 
   pues la suma de los 5 es iguala a la suma de los Wi/4.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> weights(10);

void solve(int t){
    int totSum = 0;
    for(int i = 0; i < 10; i++){
        cin>>weights[i];
        totSum += weights[i];
    }
    
    vector<int> p(5), aux;

    for(p[0] = 1; p[0] <= weights[0]/2; p[0]++){
        p[1] = weights[0] - p[0];
        for(p[3] = p[1]; p[3] <= weights[9]/2; p[3]++){ //podemos acotar, pues p[3] >= p[1] por ser crecientes
            p[4] = weights[9] - p[3];
            p[2] = totSum/4 - p[0] - p[1]- p[3] - p[4];

            if(!aux.empty()) 
                aux.clear();
            for(int i = 0; i < 4; i++)
                for(int j = i + 1; j < 5; j++)
                    aux.push_back(p[i] + p[j]);
            sort(aux.begin(), aux.end());
            
            if(aux == weights){
                cout<<"Case "<<t<<":";
                for(auto it : p)
                    cout<<" "<<it;
                cout<<endl;
                return;
            }
        }
    }    
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    for(int i = 1; i <= t; i++)
        solve(i);

	return 0;
}
