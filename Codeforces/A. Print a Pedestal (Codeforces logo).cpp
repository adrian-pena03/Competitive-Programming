#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
    	int n; cin>>n;
    	int x;
    	switch(n%3){
    		case 1: 
    			x=(n-4)/3;
    			cout<<x+1<<" "<<x+3<<" "<<x<<endl; break;
    		case 2: 
    			x=(n-5)/3;
    			cout<<x+2<<" "<<x+3<<" "<<x<<endl; break;
    		case 0: 
    			x=(n-3)/3;
    			cout<<x+1<<" "<<x+2<<" "<<x<<endl;
		}
	}
    
	return 0;
}
