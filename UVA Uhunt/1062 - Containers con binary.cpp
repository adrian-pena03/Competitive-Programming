#include <bits/stdc++.h>
using namespace std;

//ofstream f;
int cases=1;

void solve(string s){
	vector<char> canales;
	
	canales.push_back(s[0]);
	
	int l, r, c;
	for(int i=1; i<=s.size(); i++){
		l=0; r=s.size()-1;
		while(l<=r){
			c=(l+r)/2;
			if(l==r){
				if(canales[c]>=s[i]){
					canales[c]=s[i];
				}else{
					if(c+1<canales.size()){
						canales[c+1]=s[i];
					}else{
						canales.push_back(s[i]);
					}
				}
				break;
			}
			
			if(canales[c]<s[i]){
				l=c+1;
			}else if(canales[c]>=s[i]){
				r=c-1;
			}
		}
	}
			
	cout<<"Case "<<cases<<": "<<canales.size()<<endl; 
	//f<<"Case "<<cases<<": "<<canales.size()<<endl; 
	cases++;
}

int main(){
	//f.open("output.txt");
	string s; cin>>s;
	
	while(s.compare("end")!=0){
		solve(s); cin>>s;
	}
	//f.close();
	
	return 0;
}
