#include <bits/stdc++.h>
using namespace std;

/*La idea es usar priority queue para simular el campo de batalla*/ 

void solve(){
	int fields, sg, sb; cin>>fields>>sg>>sb;
	priority_queue<int> green, blue;
	vector<int> dif(fields);
	
	int hold;
	for(int i=0; i<sg; i++){
		cin>>hold;
		green.push(hold);
	}
	for(int i=0; i<sb; i++){
		cin>>hold;
		blue.push(hold);
	}
	
	while(1){
		int aux=min(green.size(), blue.size());
		int battles=min(fields, aux);
		for(int i=0; i<battles; i++){
			dif[i]=green.top()-blue.top();
			green.pop();
			blue.pop();
		}
		//hacemos la insercion hasta despues de las batallas
		for(int i=0; i<battles; i++)
			if(dif[i]>0)	green.push(dif[i]);
			else if(dif[i]<0)	blue.push(-1*dif[i]);
		
		if(green.empty() && blue.empty()){
			cout<<"green and blue died\n";
			return;
		}else if(blue.empty()){
			cout<<"green wins\n";
			while(!green.empty()){
				cout<<green.top()<<endl;
				green.pop();
			}
			return;
		}else if(green.empty()){
			cout<<"blue wins\n";
			while(!blue.empty()){
				cout<<blue.top()<<endl;
				blue.pop();
			}
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
    	solve();
    	if(t) cout<<endl;
	}
	
	return 0;
}
