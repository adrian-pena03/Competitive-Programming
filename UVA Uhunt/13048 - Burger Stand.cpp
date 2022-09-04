#include <bits/stdc++.h>
using namespace std;

int cases=1;

void solve(){
	string road; cin>>road;
	int free[100];
	int size=road.size();
	
	for(int i=0; i<size; i++)
		free[i]=0;
	
	for(int i=0; i<size; i++){
		switch(road[i]){
			case 'B': free[i]=-1;
					  if(i>=2){
							free[i-1]=-1; 
							free[i-2]=-1; break;
					  }
					  if(i==1){
					  	free[i-1]=-1; break;
					  }					  
					  break;
			case 'S': free[i]=-1;
					  if(1<=i && i<=size-2){
							free[i-1]=-1; 
							free[i+1]=-1; break;
					  }
					  if(i==0){
					  		free[i+1]=-1; 
							break;
					  }
					  if(i==size-1){
					  		free[i-1]=-1; 
							break;
					  }
			case 'D': free[i]=-1; break;
		}
	}
	
	int ans=0;
	cout<<"Case "<<cases<<": ";
	for(int i=0; i<size; i++){
		if(free[i]==0){
			ans++;
		}
	}
	cout<<ans<<endl; cases++;
	
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
