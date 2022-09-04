#include <bits/stdc++.h>
using namespace std;

vector<long long> vec;

void solve(long long x){
	
	if(vec.size()==0){
		vec.push_back(x); cout<<x<<endl; return;
	}
	
	
	long long p=0, q, r=vec.size()-1;
	while(p<=r){
		q=(p+r)/2;
		if(p==r){
			if(x>vec[r]){
				//cout<<"ins a der"<<endl;
				vec.insert(vec.begin()+q+1,x);
			}else{
				//cout<<"ins a izq"<<endl;
				vec.insert(vec.begin()+q,x);
			}
			break;
		}
		if(r-p==1){
			if(x>=vec[p] && x<vec[r]){
				vec.insert(vec.begin()+r, x); break;
			}else if(x<vec[p]){
				vec.insert(vec.begin()+p, x); break;
			}else if(x>vec[r]){
				vec.insert(vec.begin()+r+1, x); break;
			}
		}
		
		if(x>vec[q]){
			if(q==vec.size()-1){
				//cout<<"al final"<<endl;
				vec.push_back(x);  break;
			}
			p=q+1;
		}else if(x<vec[q]){
			if(q==0){
				//cout<<"al inicio"<<endl;
				vec.insert(vec.begin(), x); break;
			}
			r=q-1;
		}else{
			//cout<<"insertando"<<endl;
			vec.insert(vec.begin()+q, x); break;
		}
	}
	
	int s=vec.size();
	if(s%2==0){
		s--;
		cout<<(vec[s/2]+vec[s/2+1])/2<<endl;
	}else{
		s--;
		cout<<vec[s/2]<<endl;
	}
}

int main(){
	long long x;
	while(cin>>x)
		solve(x);
		
	
	return 0;
}
