#include <bits/stdc++.h>
using namespace std;

void solve(string s){
	list<string> text;
	string hold;
	s.push_back(']');
	char aux='[';
	
	for(int i=0; i<s.size(); i++)
		if(s[i]!='[' && s[i]!=']')
			hold.push_back(s[i]);
		else if((s[i]=='[' || s[i]==']')){
			if(aux=='[' && hold.size()>0){
				text.push_front(hold);
				hold.clear();
			}else if(aux==']' && hold.size()>0){
				text.push_back(hold);
				hold.clear();
			}
			aux=s[i];
		}
	
	for(auto it : text)
		cout<<it;
	cout<<endl;
}

int main(){
	string s;
	while(cin>>s)
		solve(s);
	
	return 0;
}
