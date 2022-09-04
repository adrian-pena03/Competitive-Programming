#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];
int m, n, cases=0;
int par, impar;
vector<pair<int, int>> hijos[100][100];

void BFS(int r, int c){
	int dirX[]={m,m,-m,-m,n,n,-n,-n};
	int dirY[]={n,-n,-n,n,m,-m,-m,m};
    // Create a queue for BFS
    queue<pair<int, int>> q;
 
    // Mark the current node as visited and enqueue it
    //visited[0][0] = true;
    q.push({0,0});
 
 	pair<int, int> aux;
    while(!q.empty()){
        aux = q.front();
        cout<<"\tvisitando casilla "<<aux.first<<" "<<aux.second<<endl;
        q.pop();
        
        visited[aux.first][aux.second]=true;
        for(int k=0; k<8; k++){
        	//cout<<"vuelta para visitar la casilla "<<aux.first+dirX[k]<<" "<<aux.second+dirY[k];
        	//cout<<"   estado: "<<visited[aux.first+dirX[k]][aux.second+dirY[k]]<<endl;
        	int cx = aux.first + dirX[]
        	if(0<=aux.first+dirX[k] && aux.first+dirX[k]<=c-1 && 0<=aux.second+dirY[k] && aux.second+dirY[k]<=r-1 
			&& visited[aux.first+dirX[k]][aux.second+dirY[k]]==false){
				cout<<"agregando a la cola la casilla: "<<aux.first+dirX[k]<<" "<<aux.second+dirY[k]<<endl;
        		//visited[aux.first+dirX[k]][aux.second+dirY[k]]=true;
        		q.push({aux.first+dirX[k],aux.second+dirY[k]});
        		//visited[aux.first+dirX[k]][aux.second+dirY[k]]=true;
        		hijos[aux.first+dirX[k]][aux.second+dirY[k]].push_back({aux.first, aux.second});
        		hijos[aux.first][aux.second].push_back({aux.first+dirX[k], aux.second+dirY[k]});
			}
		}
		
    }
}


void solve(){
	int water[100][100];
	int r, c; cin>>r>>c>>m>>n;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			visited[i][j]=false;
			if(!hijos[i][j].empty())
				hijos[i][j].clear();
			water[i][j]=0;
		}
			
	
	int w; cin>>w;
	
	
	//vector<pair<int, int>> water;
	int x, y;
	for(int i=0; i<w; i++){
		cin>>x>>y;
		visited[x][y]=true;
		water[x][y]=1;
		
	}
	
	par=0;
	impar=0;
	BFS(r,c);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			if(water[i][j]==0 && hijos[i][j].size()>0){
				cout<<"hijos de "<<i<<","<<j<<": "<<hijos[i][j].size()<<"\n";
				par+= (hijos[i][j].size()%2==1)? 0 : 1;
				impar+= (hijos[i][j].size()%2==1)? 1 : 0;
			}
		}
		
	
	cases++;
	cout<<"Case "<<cases<<": "<<par<<" "<<impar<<endl;
}

int main(){
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
