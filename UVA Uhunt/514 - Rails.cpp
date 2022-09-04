#include <bits/stdc++.h>
using namespace std;

ofstream f;

void solve(int n){
	stack<int> train;
	vector<int> perm(n);
	
	cin>>perm[0];
	
	bool flag;
	while(perm[0]!=0){
		for(int i=1; i<n; i++)
			cin>>perm[i];
		//cout<<"bien\n";
		
		flag=true;
		vector<int> aux(n+1, 0);
		int j=1, k=0;
		train.push(1); aux[1]=-1;
		int tot=0;
		while(flag){ //-1 si esta en la estacion
					// 0 si esta en espera
					// 1 si ya fue colocado
			if(tot==n){
			//cout<<"ya se acomodo todo\n";
			break;}
			//cout<<"\tvuelta\telemento a cotejar "<<perm[k]<<endl;;
			if(!train.empty())
			if(perm[k]==train.top()){
				//cout<<"encontrado\n";
				aux[perm[k]]=1;
				train.pop();
				k++;
				tot++;
				if(tot>0)
					continue;
			}
			//cout<<" 1er filtro\n";
			
			if(aux[perm[k]]==-1){
				flag=false;
				//cout<<"no se puede acceder a "<<perm[k]<<endl;
			}
			
			j++;
			if(j<=n){
				//cout<<"insertando "<<j<<endl;
				train.push(j); 
				aux[j]=-1;
				}
				
			if(tot==n){
			//cout<<"ya se acomodo todo\n";
				break;
			}
		}
		
		if(flag){
			cout<<"Yes"<<endl;
			f<<"Yes"<<endl;	
		} 
		else{
			cout<<"No"<<endl;
			f<<"No"<<endl;	
		} 
		cin>>perm[0];
		if(perm[0]==0)  return;
	}
	
}

int main(){
	f.open("output.txt");
	int n; cin>>n;
	
	while(n!=0){
		solve(n);
		cout<<endl;
		f<<endl;
		cin>>n;
	}
	f.close();
	return 0;
}
