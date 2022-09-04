#include <bits/stdc++.h>
using namespace std;

void solve(int n, int r){
	
	vector<int> plates(n, 0);
	int aux;
	for(int i=0; i<r; i++){
		cin>>aux;
		plates[aux-1]=1;
	}
	
	if(n==r){
		cout<<"*\n";
		return;
	}
	
	for(int i=0; i<n; i++)
		if(plates[i]==0)
			cout<<i+1<<" ";
	cout<<endl;
}

int main(){
	int n, r;
	while(cin>>n){
		cin>>r;
		solve(n, r);
	}
	
	return 0;
}
