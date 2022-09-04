#include <bits/stdc++.h>
using namespace std;

int val(char c){
	return (int) c-(int) '0';
}

void eval(int b, int *len, bool *flag, string a){
	for(int j=0; j<a.size(); j++){
		if(b==1 && val(a[a.size()-1-j])!=1){
			*flag=false;
			return;
		}else if(val(a[a.size()-1-j])>=b && b>1){
			*flag=false;
			return;
		}
		*len+=val(a[a.size()-1-j])*pow(b, j);
	}
}

void solve(){
	string a, b, c;
	char aux;
	cin>>a>>aux>>b>>aux>>c;
	
	int lena, lenb, lenc;
	bool flag;
	for(int i=1; i<=19; i++){
		flag=true;
		lena=0, lenb=0, lenc=0;
		eval(i, &lena, &flag, a);
		eval(i, &lenb, &flag, b);
		eval(i, &lenc, &flag, c);
		
		if(!flag) continue;
		else if(lena+lenb==lenc){
			cout<<i<<endl;
			return;
		}
	}

	cout<<0<<endl;
}

int main(){
	int n; cin>>n;
	while(n--)
		solve();
	
	return 0;
}
