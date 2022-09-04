#include <bits/stdc++.h>
//#include <vector>
using namespace std;
#define ll long long

int ver[32768], pot[32768];

void solve(int n){
	for(int i=0; i<pow(2,n); i++){
		cin>>ver[i];
	}
	
	int aux;
	for(int i=0; i<pow(2,n); i++){
		pot[i]=0;
		for(int j=0; j<n; j++){ 
			aux=pow(2,j);
			pot[i]+=ver[i^aux];
		}
	}
	
	int max=0, hold;
	for(int i=0; i<pow(2,n); i++){
		for(int j=0; j<n; j++){ 
			aux=pow(2,j);
			hold=pot[i]+pot[i^aux];
			if(max<hold){
				max=hold;
			}
		}
	}
	
	cout<<max<<endl;
}

int main(){
  	std::ios_base::sync_with_stdio(false);
  	std::cin.tie(0);
  	int N;
  	while(std::cin>>N){
    	solve(N);
  	}
    
	
	return 0;
}
