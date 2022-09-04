#include <bits/stdc++.h>
using namespace std;

void solve(int n, int cases){
	cout<<"Case "<<cases<<": ";
	long long num=n;
	num=num*(num-1);
	
	if(num%4==0){
		cout<<num/4; 
	}else if(num%4==2){
		cout<<num/2<<"/"<<2;
	}else{
		cout<<num<<"/"<<4;
	}
	cout<<endl;
}

int main(){
	int t; cin>>t;
	int n;
	for(int i=1; i<=t; i++){
		cin>>n;
		solve(n, i);
	}
	
	return 0;
}
