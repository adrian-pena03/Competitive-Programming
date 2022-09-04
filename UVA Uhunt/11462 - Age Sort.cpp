#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	vector<short int> s;
	short int hold;
	for(int i=0; i<n; i++){
		cin>>hold;
		s.push_back(hold);
	}
	sort(s.begin(), s.end());
	for(int i=0; i<s.size(); i++){
		cout<<s[i]; 
		if(i!=s.size()-1){
			cout<<" "; 
		} cout<<endl;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	//f.open("output.txt");
	int n; cin>>n;
	while(n!=0){
		solve(n); cin>>n;
	}
	//f.close();
	
	return 0;
}

