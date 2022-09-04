#include <bits/stdc++.h>
using namespace std;
struct custom_type {
    int val;
    int pos;

    bool operator < (const custom_type &B) const {
        return val > B.val; // min heap
    }
};
int main()
{
    int K, L1[800], L2[800];
    while (scanf("%d", &K) != EOF) {
        for (int i = 0; i < K; ++i) scanf("%d", &L1[i]);
        sort(L1, L1 + K);

        for (int k = 1; k < K; ++k) {
        	cout<<"guardando vector "<<k<<endl;
            for (int i = 0; i < K; ++i) 
				scanf("%d", &L2[i]);
            sort(L2, L2 + K);
            
            priority_queue<custom_type> PQ;
            for (int i = 0; i < K; ++i){
            	PQ.push({L1[i] + L2[0], 0});
            	cout<<"insertando par ("<<L1[i] + L2[0]<<", "<<0<<endl;
			}
            
            
            for (int i = 0; i < K; ++i) {
                custom_type tmp = PQ.top();
                cout<<"tope de cola: "<<tmp.val<<" pos: "<<tmp.pos<<endl;
                PQ.pop();
                L1[i] = tmp.val;
                if (tmp.pos+1 < K){
                	PQ.push({tmp.val - L2[tmp.pos] + L2[tmp.pos+1], tmp.pos + 1});
                	cout<<" comparando ("<<tmp.val - L2[tmp.pos] + L2[tmp.pos+1]<<"  "<<tmp.pos + 1<<")"<<endl;
				}
                    
            }
            
            cout<<"\t";
            for (int i = 0; i < K; i++){
            	cout<<L1[i]<<" ";
			}cout<<endl;
            
            
        }
        for (int i = 0; i < K - 1; ++i)
            printf("%d ", L1[i]);
        printf("%d\n", L1[K-1]);
    }
}/*#include <bits/stdc++.h>
using namespace std;

ofstream f;

void solve(int k){
    vector<int> arr[k];
	vector<int> rep(k, 1); //Vector de repeticiones de minimo en cada arreglo
    int hold, sum=0, prod=1;
    
    priority_queue<int> dif; //pq de las minimas diferencias del primer elemento con los demas vecinos de su propio arreglo
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cin>>hold;
            arr[i].push_back(hold);
        }
        sort(arr[i].begin(), arr[i].end());
        sum+=arr[i][0];

		//llenamos vector de repeticiones
        for(int l=1; l<k; l++){
        	if(arr[i][0]-arr[i][l]==0){
        		rep[i]++;
			}
            //dif.push(arr[i][0]-arr[i][l]);
        }
        prod*=rep[i];
    }
    
    
    for(int i=0; i<k; i++){
        for(int j=1; j<k; j++){
        	for(int l=0; l<(prod/rep[i]); l++){
        		dif.push(arr[i][0]-arr[i][j]);
			}
        }
    }
    
    priority_queue<int>cpy=dif;
    while(!cpy.empty()){
    	cout<<-1*cpy.top()<<" ";
    	cpy.pop();
	}
	return;
    
    cout<<sum;
    f<<sum;
    for(int i=0; i<k-1; i++){
        sum-=dif.top();
        cout<<" "<<sum;
        f<<" "<<sum;
        sum+=dif.top();
        dif.pop();
    } cout<<endl;
    f<<"\n";

}

int main(){
	f.open("output.txt");
    int k;
    while(cin>>k)
        solve(k);
	f.close();
    return 0;
} */
