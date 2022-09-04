#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>>n;
	string stud[100];
	int names[100], tot=0;
	
	for(int i=0; i<n; i++){
		cin>>stud[i];
		if(stud[i].compare("?")!=0){
			names[tot]=i;
			tot++;
		}
	}
	
	int q; cin>>q;
	int query;
	int a,b,c;
	for(int i=0; i<q; i++){
		cin>>query; query--;
		a=0;
		c=tot-1;
		while(a<=c){
			b=(a+c)/2;
			if(names[b]==query){ //Cae en un nombre que existe
			 	//cout<<"El nombre existe."<<endl;
				cout<<stud[query]<<endl; break;
			}
			if((c-a)<=1){ //Cuando queda entre los dos ultimos elementos
				if(query>names[c]){ //Si se pasa de ellos
					//cout<<"El alumno esta hasta la derecha"<<endl;
					for(int j=names[c]; j<query; j++){
						cout<<"right of ";
					} cout<<stud[names[c]]<<endl; break;
				}
				
				if(query<names[a]){ //Si es menor a ellos
				//cout<<"El alumno esta hasta la izquierda"<<endl;
					for(int j=query; j<names[a]; j++){
						cout<<"left of ";
					} cout<<stud[names[a]]<<endl; break;
				}
				
				//Si esta entre ellos dos
				if(query==(names[a]+names[c])/2 && (names[a]+names[c])%2==0){
					//cout<<"El alumno esta entre ambos"<<endl;
					cout<<"middle of "<<stud[names[a]]<<" and "<<stud[names[c]]<<endl;
					break;
				}else{
					int l=query-names[a];
					int r=names[c]-query;
					if(l<r){
						//cout<<"El alumno esta mas cerca de la izq"<<endl;
						for(int j=0; j<l; j++){
							cout<<"right of ";
						} cout<<stud[names[a]]<<endl; break;
					}else if(r<l){
						//cout<<"El alumno esta mas cerca de la der"<<endl;
						for(int j=0; j<r; j++){
							cout<<"left of ";
						} cout<<stud[names[c]]<<endl; break;
					}
				}
			}
			
			//Seguir buscando
			if(query>names[b]){
				a=b;
			}else if(query<names[b]){
				c=b;
			}
		}
		//cout<<"\tquery "<<i+1<<" terminado\n";
	}
	
}

int main(){
	solve();
	
	return 0;
}
