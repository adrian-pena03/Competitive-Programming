#include <bits/stdc++.h>
using namespace std;

void solve(int s, int b){
	int lb[100001], rb[100001], lk[100001], rk[100001];
	
	for(int i=1; i<=b; i++){
		cin>>lk[i]>>rk[i];
	}
	
	lb[1]=0;
	rb[1]=2;
	for(int i=2; i<=s-1; i++){
		lb[i]=i-1;
		rb[i]=i+1;
	}
	lb[s]=s-1;
	rb[s]=0;
	
	for(int i=1; i<=b; i++){
		rb[lb[lk[i]]]=rb[rk[i]];
		lb[rb[rk[i]]]=lb[lk[i]];
		
		if(lb[rb[rk[i]]]!=0){
			cout<<lb[rb[rk[i]]];
		}else{
			cout<<"*";
		}  cout<<" ";
		if(rb[lb[lk[i]]]!=0){
			cout<<rb[lb[lk[i]]];
		}else{
			cout<<"*";
		}
		
		cout<<endl;
	}
	
	
	cout<<"-\n";
}

int main(){
	int s, b; cin>>s>>b; 
	while(s!=0 && b!=0){
		solve(s,b);
		cin>>s>>b;
	}
	
	return 0;
}
