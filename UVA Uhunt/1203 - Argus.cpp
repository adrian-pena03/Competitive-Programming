#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<pair<int, int>> pq;//tiempo, id
	map<int, int> tiempo; //guardar la pareja ID, tiempo
	
	pair<int, int> hold; //pair auxiliar
	
    int time, id;
    string aux;
    cin>>aux;
    while(aux.compare("#")!=0){
		cin>>id>>time;
		hold.first=-1*time;
		hold.second=-1*id;
        pq.push(hold);
        
        //Relacion id - tiempo
        tiempo[hold.second]=hold.first;
        
        cin>>aux;
    }
    
    int query; cin>>query;
    
    for(int i=0; i<query; i++){
    	//Imprimimos, y mandamos a la pq denuevo con el tiempo con el que va a aparecer
        hold=pq.top();
        cout<<-1*hold.second<<endl;
        pq.pop();
        hold.first+=tiempo[hold.second];
        pq.push(hold);
    }

    return 0;
}
