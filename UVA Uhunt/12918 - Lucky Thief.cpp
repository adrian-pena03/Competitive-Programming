#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	unsigned long long m, n;
	
	while(t--){
		cin>>n>>m;
		cout<<m*n-n*(n+1)/2<<endl;
	}
	
	return 0;
}
