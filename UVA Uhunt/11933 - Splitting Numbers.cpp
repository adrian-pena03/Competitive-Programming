#include <bits/stdc++.h>
using namespace std;

void solve(unsigned int n){
	vector<unsigned int> idx1;
	
	unsigned int i=1, hold;
	while(i<=n){
		if((n&i)==i){
			hold=log(i)/log(2);
			idx1.push_back(hold);
		}
		i<<=1;
	}
	
	unsigned int a=0, b=0;
	for(int i=0; i<idx1.size(); i+=2)
		a+=pow(2, idx1[i]);
	
	for(int i=1; i<idx1.size(); i+=2)
		b+=pow(2, idx1[i]);
	
	cout<<a<<" "<<b<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	unsigned int n; cin>>n;
	while(n!=0){
		solve(n); cin>>n;
	}
	
	return 0;
}
