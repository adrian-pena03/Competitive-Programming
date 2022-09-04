#include <bits/stdc++.h>
using namespace std;

/*La idea es ir guardando en un set el precio de cada receta y su nombre comp pairs*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int bli; cin>>bli;
    string blinder;
    getline(cin, blinder);
    for(int l=0; l<bli; l++){
    	getline(cin, blinder);
    	
    	int m, recipes, budget; cin>>m>>recipes>>budget;
    	string ingredient;
    	int price;
    	map<string, int> priceList;
    	for(int i=0; i<m; i++){
    		cin>>ingredient>>price;
    		priceList[ingredient]=price;
		}
		
		map<string, int> recipePrice;
		set<pair<int, string>> cheapRecipes;
		string name;
		int p, tot;
		getline(cin, name);
		for(int i=0; i<recipes; i++){
			getline(cin, name);
			cin>>tot;
			for(int j=0; j<tot; j++){
				cin>>ingredient>>p;
				recipePrice[name]+=p*priceList[ingredient];
			}
			string aux; getline(cin, aux);
			if(recipePrice[name]<=budget)
				cheapRecipes.insert({recipePrice[name], name});
		}
		
		transform(blinder.begin(), blinder.end(), blinder.begin(), ::toupper);
		cout<<blinder<<endl;
		if(cheapRecipes.empty()) cout<<"Too expensive!"<<endl;
		else
			for(auto it : cheapRecipes)
				cout<<it.second<<endl;
		
		priceList.clear();
		recipePrice.clear();
		cheapRecipes.clear();
		cout<<endl;
	}
	
	return 0;
}
