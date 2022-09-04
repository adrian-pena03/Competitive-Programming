#include <bits/stdc++.h>
using namespace std;

void solve(int n, int cases){
	vector<int> num(n);
	for(int i = 0; i < n; i++)
		cin>>num[i];
	sort(num.begin(), num.end());
	
	int q; cin>>q;
	vector<int> query(q);
	for(int i = 0; i < q; i++)
		cin>>query[i];
	
	
	cout<<"Case "<<cases<<":"<<endl;
	for(auto it : query){
		cout<<"Closest sum to "<<it<<" is ";
		int aux = INT_MAX, sum;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				if(abs(it - num[i] - num[j]) < aux){
					aux = abs(it - num[i] - num[j]);
					sum = num[i] + num[j];
				}
			}	
		
		cout<<sum<<"."<<endl;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, cases = 1; cin>>n;
    while(n){
		solve(n, cases);
		cin>>n;
		cases++;
	}
    
	return 0;
}
