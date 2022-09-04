#include <bits/stdc++.h>
using namespace std;

/*La idea es ver el ultimo max grande con el while*/

void solve(int n){
	vector<string> names;
	string hold;
	for(int i=0; i<n; i++){
		cin>>hold; names.push_back(hold);
	}
	
	sort(names.begin(), names.end());
	
	string s1=names[n/2-1], s2=names[n/2];
	//cout<<"mitades: "<<s1<<" "<<s2<<endl;
	
	int last=0;
	for(int i=0; i<min(s1.size(), s2.size()); i++){
		if(s1[i]==s2[i])
			last++;
		else break;
	}
	
	string ans;
	if(last==s1.size()){
		//cout<<"el string esta contenido en otro"<<endl;
		ans=s1;
	}else if(s2[last]-s1[last]!=1){
		//cout<<"los de enmedio no son consecutivos"<<endl;
		
		//if(last+1==s2.size()){
			if(last+1==s1.size())
				ans=s1;
			else{
				char aux=s1[last]+1; //cout<<"aux: "<<aux<<"\t";
				for(int i=0; i<last; i++){
					ans.push_back(s1[i]);
				} //cout<<"ans: "<<ans<<endl;
				ans+=aux;
			}
		
		
	}else{
		//cout<<"los de enmedio son consecutivos"<<endl;
		
		if(last+1==s2.size()){ //el 2do es de una letra distinta
			if(last+1==s1.size()){
				ans=s1;
			}else{
				int cpy=last+1;
				while(s1[cpy]=='Z')
					cpy++;
				if(cpy==s1.size() || cpy+1==s1.size())
					ans=s1;
				else{
					for(int i=0; i<cpy; i++)
						ans.push_back(s1[i]);
					char aux=s1[cpy]+1;
					ans+=aux;
				}
			}
		}else{
			if(last+1==s1.size())
				ans=s1;
			else
				for(int i=0; i<=last; i++)
					ans.push_back(s2[i]);
		}
		
	}
	cout<<ans<<endl;
}

int main(){
	int n; cin>>n;
	while(n!=0){
		solve(n);
		cin>>n;
	}
	
	return 0;
}
