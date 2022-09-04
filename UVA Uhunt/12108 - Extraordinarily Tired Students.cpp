#include <bits/stdc++.h>
using namespace std;

ofstream f;

void solve(int n, int cases){
	int posini[n], state[n], it[n];
	int awa=0, sleep=0;
	int a[n], b[n];
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i]>>posini[i]; //despertar, dormir y pos ini
		it[i]=posini[i];
		state[i]= (posini[i]<=a[i])? 0 : 1;
		sleep+= ((state[i]==1)? 1 : 0);
	}
	awa=n-sleep;
		
	cout<<"Case "<<cases<<": ";
	f<<"Case "<<cases<<": ";
	
	int ans=0;
	//bool flag=true;
	while(true){
		
		ans++; 
		
		
		if(awa==n){
			cout<<ans<<endl;
			f<<ans<<endl;
			return;
		}
		
		for(int i=0; i<n; i++){
			if(it[i]==a[i]){// se va a dormir
				//cout<<i+1<<" checando si dormira\n";
				if(sleep>awa){ //Si hay mas dormidos
					//cout<<"  se dormira en el siguiente momento\n";
					state[i]=1;
					//change[i]=1;
					//sleep++;
					//awa--;
					it[i]++;
				}else{
					//cout<<"  se queda despierto\n";
				}
			}else if(it[i]==a[i]+b[i]){ //Se va a despertar
					//cout<<i+1<<" se despertara en el siguiente momento\n";
					state[i]=0;
					it[i]=1;
			}else{
				it[i]++;
			}
		}
		
		sleep=0;
		for(int i=0; i<n; i++){
			sleep+=state[i];
		}
		awa=n-sleep;
		
		
		int aux=n;
		for(int i=0; i<n; i++){
			if(it[i]==posini[i]){
				aux--;
			}
		}
		if(aux==0){
			cout<<-1<<endl;
			f<<-1<<endl;
			return;
		}
	}	
}

int main(){
	f.open("output.txt");
	int n; cin>>n;
	int cases=1;
	while(n!=0){
		solve(n, cases);
		cases++;
		cin>>n;
	}
	f.close();
	
	return 0;
}
