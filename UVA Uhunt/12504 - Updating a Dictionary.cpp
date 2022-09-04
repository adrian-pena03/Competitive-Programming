#include <bits/stdc++.h>
using namespace std;

/*La idea es guardar dos maps, compararlos e ir guardando en tres sets los que cambiaron, 
  borraron o agregaron*/

void solve(){
	map<string, string> dic1, dic2;
	string key, value, line;
	
	cin>>line;
	int i=1;
	while(i<line.size()-1){
		while(line[i]!=':'){
			key.push_back(line[i]);
			i++;
		}
		i++;
		while(line[i]!=',' && line[i]!='}'){
			value.push_back(line[i]);
			i++;	
		}
		i++;
		dic1[key]=value;
		key.clear(); value.clear();
	}
	
	cin>>line;
	i=1;
	while(i<line.size()-1){
		while(line[i]!=':'){
			key.push_back(line[i]);
			i++;
		}
		i++;
		while(line[i]!=',' && line[i]!='}'){
			value.push_back(line[i]);
			i++;	
		}
		i++;
		dic2[key]=value;
		key.clear(); value.clear();
	}
	
	set<string> newKeys, erasedKeys, changedKeys;
	map<string, string>::iterator it;
	for(it=dic1.begin(); it!=dic1.end(); it++){
		string hold=it->first;
		if(dic2[hold].size()==0)                    erasedKeys.insert(hold);
		else if(dic1[hold].compare(dic2[hold])!=0)  changedKeys.insert(hold);
	}
	for(it=dic2.begin(); it!=dic2.end(); it++){
		string hold=it->first;
		if(dic1[hold].size()==0)  newKeys.insert(hold);
	}
	
	if(newKeys.empty() && erasedKeys.empty() && changedKeys.empty())  cout<<"No changes\n";
	else{
		if(!newKeys.empty()){
			cout<<'+';
			for(auto x : newKeys){
				cout<<x;
				if(x!=*(--newKeys.end())) cout<<",";
			}
			cout<<endl;
		}
		if(!erasedKeys.empty()){
			cout<<'-';
			for(auto x : erasedKeys){
				cout<<x;
				if(x!=*(--erasedKeys.end())) cout<<",";
			}
			cout<<endl;
		}
		if(!changedKeys.empty()){
			cout<<'*';
			for(auto x : changedKeys){
				cout<<x;
				if(x!=*(--changedKeys.end())) cout<<",";
			}
			cout<<endl;
		}
	}
	cout<<endl;	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
	
	return 0;
}
