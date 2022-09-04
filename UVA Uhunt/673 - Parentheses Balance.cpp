#include <bits/stdc++.h>
using namespace std;

void solve(string s){
	stack<char> par;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='(' || s[i]=='['){
			par.push(s[i]);
		}else if(s[i]==')' || s[i]==']'){
			if(par.empty()){
				cout<<"No\n";
				return;
			}else{
				if(s[i]==')'){
					if(par.top()=='('){
						par.pop();
					}else{
						cout<<"No\n";
						return;
					}
				}else{
					if(par.top()=='('){
						cout<<"No\n";
						return;
					}else{
						par.pop();
					}
				}
			}
		}
	}
	
	
	if(par.empty()){
		cout<<"Yes\n";
	}else if(par.top()=='[' || par.top()=='('){
		cout<<"No\n";
	}
}

int main(){
	int n; cin>>n;
	string s;
	getline(cin, s);
	while(n--){
		getline(cin, s);
		solve(s);
	}
	
	return 0;
}
