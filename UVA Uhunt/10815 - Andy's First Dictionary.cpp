#include <bits/stdc++.h>
using namespace std;

bool isAletter(char c){
	return (('a'<=c && c<='z') || ('A'<=c && c<='Z'));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//solve
	string word, line;
	set<string> dictionary;
	while(getline(cin, line)){
		for(int i=0; i<line.size(); i++){
			char c=line[i];
			if(isAletter(c)){
				word.push_back(tolower(c));
			}else{ //si encuentra algo que no es caracter, guarda la palabra 
				if(!word.empty()){
					dictionary.insert(word);
					word.clear();
				}
			}
			if(i==line.size()-1 && !word.empty()){ //caso cuando cambia de linea
				dictionary.insert(word);
				word.clear();
			}
		}
	}
	
	for(auto it : dictionary)  cout<<it<<endl;

	return 0;
}
