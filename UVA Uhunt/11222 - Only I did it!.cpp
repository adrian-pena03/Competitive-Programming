#include <bits/stdc++.h>
using namespace std;

//ofstream f;
int cases=1;

void solve(int t){
	int prob[10001], f1[1000], f2[1000], f3[1000];
	for(int i=0; i<10001; i++){
		prob[i]=0;
	}
	
	int totp[3];
	
	for(int i=0; i<3; i++){  
		cin>>totp[i];
		int pAux;
		
		for(int j=0; j<totp[i]; j++){
			cin>>pAux;
			if(prob[pAux]==0){
				prob[pAux]=i+1;
			}else if(prob[pAux]!=i+1){
				prob[pAux]=-1;
			}
		}
		totp[i]=0;
	}
	
	int sp1[1000], sp2[1000], sp3[1000];
	int x=0,y=0,z=0;
	for(int i=1; i<10001; i++){
		if(prob[i]==1){
			totp[0]++;
			sp1[x]=i;
			x++;
		}else if(prob[i]==2){
			totp[1]++;
			sp2[y]=i;
			y++;
		}else if(prob[i]==3){
			totp[2]++;
			sp3[z]=i;
			z++;
		}
	}
	
	int maxF=max(max(totp[0], totp[1]), totp[2]);
	
	int fin;
	for(int i=0; i<3; i++){
		if(maxF==totp[i]){
			fin=i;
		}
	}
	
	cout<<"Case #"<<cases<<":"<<endl; 
	//f<<"Case #"<<cases<<":"<<endl; 
	for(int i=0; i<3; i++){
		if(maxF==totp[i]){
			cout<<i+1<<" "<<totp[i];
			//f<<i+1<<" "<<totp[i];
			if(totp[i]!=0){
			//	f<<" ";
				cout<<" ";
			}
			
			for(int j=0; j<totp[i]; j++){
				if(i==0){
					cout<<sp1[j];
					//f<<sp1[j];
				}
				if(i==1){
					cout<<sp2[j];
					//f<<sp2[j];
				}
				if(i==2){
					cout<<sp3[j];
					//f<<sp3[j];
				}
				if(j<totp[i]-1){
					cout<<" ";
					//f<<" ";
				}			
			} cout<<endl;// f<<endl;
		} 
	} cases++;
}

int main(){
	int t; cin>>t;
	//f.open("output.txt");
	while(t--){
		solve(t);
	}
	//f.close();
	
	return 0;
}
