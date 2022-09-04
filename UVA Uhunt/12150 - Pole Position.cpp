#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int cars[1001], pole[1001], ans[1001];
	for(int i=0; i<1001; i++){
		cars[i]=0;
		pole[i]=0;
		ans[i]=0;
	}
	
	for(int i=1; i<=n; i++)
		cin>>cars[i]>>pole[i];
	
	
	for(int i=1; i<=n; i++)
		if(i+pole[i]<1 || i+pole[i]>n){
			cout<<-1<<endl;
			return;
		}
		if(ans[i+pole[i]]==0)
			ans[i+pole[i]]=cars[i];
		else{
			cout<<-1<<endl;
			return;
		}
	
	
	for(int i=1; i<=n-1; i++){
		cout<<ans[i]<<" ";
	} cout<<ans[n]<<endl;
	
}

int main(){
	int t; cin>>t;
	while(t!=0){
		solve(t);
		cin>>t;
	}
	
	return 0;
}
