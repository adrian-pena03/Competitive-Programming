#include <bits/stdc++.h>
using namespace std;

/* Josue Alejandro Perez Lara

Definimos una matrix auxiliar para ir almacenando el resultado de cada batalla, y actualizar la distribucion de tierra

Iremos simulando la batalla entre hermanos horizontales y verticales
*/

void solve(int n, int f, int c, int b){
	int t[f][c], aux[f][c];
	
	for(int i=0; i<f; i++)
		for(int j=0; j<c; j++){
			aux[i][j]=-1;
			cin>>t[i][j];
		}
		
	for(int p=0; p<b; p++){
		for(int i=0; i<f; i++)
			for(int j=0; j<c; j++){
				if(aux[i][j]==-1)  aux[i][j]=t[i][j]; //Si nadie ha atacado, copiamos el mismo valor
				
				//Ataques entre hermanos verticales
				if(i>0 && ((t[i-1][j]-t[i][j])%n==1 || (t[i-1][j]-t[i][j])%n==1-n))
					aux[i-1][j]=t[i][j];
				if(i<f-1 && ((t[i+1][j]-t[i][j])%n==1 || (t[i+1][j]-t[i][j])%n==1-n))
					aux[i+1][j]=t[i][j];
					
				//Ataques entre hermanos horizontales
				if(j>0 && ((t[i][j-1]-t[i][j])%n==1 || (t[i][j-1]-t[i][j])%n==1-n))
					aux[i][j-1]=t[i][j];
				if(j<c-1 && ((t[i][j+1]-t[i][j])%n==1 || (t[i][j+1]-t[i][j])%n==1-n))
					aux[i][j+1]=t[i][j];
			}
		
		//Copiamos a la original
		for(int i=0; i<f; i++)
			for(int j=0; j<c; j++){
				t[i][j]=aux[i][j];
				aux[i][j]=-1;
			}
	}
	
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<t[i][j];
			if(j<c-1) cout<<" ";
		} cout<<endl;
	}
}

int main(){
	int n, f, c, b; cin>>n>>f>>c>>b;
	while(n+f+c+b){
		solve(n,f,c,b);  cin>>n>>f>>c>>b;
	}
	
	return 0;
}
