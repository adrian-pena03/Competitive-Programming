#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int piv=(int) sqrt(n);
	int a, b;
	
	if(piv*piv==n){
		a= (n%2==1)? 1 : piv;
		b= (n%2==1)? piv : 1;
	}else if(n-piv*piv<pow(piv+1, 2)-n){
		a= (piv%2==1)? n-pow(piv, 2) : piv+1;
		b= (piv%2==1)? piv+1 : n-pow(piv, 2);
	}else{
		a= ((piv+1)%2==1)? pow(piv+1,2)-n+1 : piv+1;
		b= ((piv+1)%2==1)? piv+1 : pow(piv+1,2)-n+1;
	}
	cout<<a<<" "<<b<<endl;
}

int main(){
	int n; cin>>n;
	while(n!=0){
		solve(n);
		cin>>n;
	}
	
	return 0;
}
