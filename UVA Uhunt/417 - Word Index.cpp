#include <bits/stdc++.h>
using namespace std;
// idea-> hacer precalculo

char valc(int x){
	return (char) x+'a'-1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string aux=" ";
	map<string, int> key;
	int last=0;
	for(int i=1; i<=26; i++){
		aux.clear();
		aux.push_back(valc(i));
		last++;
		key[aux]=last;
	}
	
	for(int i=1; i<=26; i++){
		for(int j=i+1; j<=26; j++){
			aux.clear();
			last++;
			aux.push_back(valc(i));
			aux.push_back(valc(j));
			key[aux]=last;
		}
	}
	for(int i=1; i<=26; i++){
		for(int j=i+1; j<=26; j++){
			for(int k=j+1; k<=26; k++){
				aux.clear();
				last++;
				aux.push_back(valc(i));
				aux.push_back(valc(j));
				aux.push_back(valc(k));
				key[aux]=last;
			}
		}
	}
	for(int i=1; i<=26; i++){
		for(int j=i+1; j<=26; j++){
			for(int k=j+1; k<=26; k++){
				for(int l=k+1; l<=26; l++){
					aux.clear();
					last++;
					aux.push_back(valc(i));
					aux.push_back(valc(j));
					aux.push_back(valc(k));
					aux.push_back(valc(l));
					key[aux]=last;
				}
			}
		}
	}
	
	for(int i=1; i<=26; i++){
		for(int j=i+1; j<=26; j++){
			for(int k=j+1; k<=26; k++){
				for(int l=k+1; l<=26; l++){
					for(int m=l+1; m<=26; m++){
						aux.clear();
						last++;
						aux.push_back(valc(i));
						aux.push_back(valc(j));
						aux.push_back(valc(k));
						aux.push_back(valc(l));
						aux.push_back(valc(m));
						key[aux]=last;
					}
				}
			}
		}
	}
	
	while(cin>>aux){
		cout<<key[aux]<<endl;
	}
	
	return 0;
}
