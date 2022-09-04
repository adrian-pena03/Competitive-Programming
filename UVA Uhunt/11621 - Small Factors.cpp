#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> powers;

void fill(){
	for(int i=0; i<32; i++)
		for(int j=0; j<32; j++){
			unsigned long long num = pow(2, i) * pow(3, j);
			powers.push_back(num);
		}
	sort(powers.begin(), powers.end());
}

void solve(int n){
	vector<unsigned long long>::iterator it = lower_bound(powers.begin(), powers.end(), n);
	cout<<*it<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    
    fill();
    while(n){
    	solve(n);
    	cin>>n;
	}
    
	return 0;
}
