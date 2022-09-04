#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int arr[3001], ans[3001];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		ans[i]=0;
	} ans[n]=0;
	
	for(int i=1; i<n; i++){
		if(abs(arr[i-1]-arr[i])==0 || abs(arr[i-1]-arr[i])>=n){
			cout<<"Not jolly"<<endl;
			return;
		}else{
			ans[abs(arr[i-1]-arr[i])]=abs(arr[i-1]-arr[i]);
		}
	}
	
	for(int i=1; i<n; i++){
		if(ans[i]!=i){
			cout<<"Not jolly"<<endl;
			return;
		}
	}
	cout<<"Jolly"<<endl;
}

int main(){
	int t;	
	while(cin>>t){
		solve(t);
	}	
	
	return 0;
}
