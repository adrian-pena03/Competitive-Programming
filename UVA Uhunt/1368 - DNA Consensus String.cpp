#include <bits/stdc++.h>
using namespace std;

/*La idea es checar el caracter maximo de cada columna, y ese sera parte de la respuesta*/

int val(char c){
	return (int) c- (int) 'A';
}

void solve(int m, int n){
    string DNA[m];
    for(int i=0; i<m; i++)
        cin>>DNA[i];

    string aux;
    int hemm=0;
    for(int i=0; i<n; i++){
    	vector<int> rep(26, 0);
        for(int j=0; j<m; j++)
            rep[val(DNA[j][i])]++;
        
        int mRep=0;
    	char key='A';
    	for(int k=0; k<26; k++)
    		if(mRep<rep[k] && rep[k]>0){
    			mRep=rep[k];
    			key='A'+k;
			}
		
		hemm+=m-mRep;
		aux.push_back(key);
    }
    cout<<aux<<"\n"<<hemm<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int m, n; cin>>m>>n;
        solve(m,n);
    }

    return 0;
}
