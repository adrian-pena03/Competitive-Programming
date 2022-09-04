#include <bits/stdc++.h>
using namespace std;

int inter(int a, int b, int c, int d){
	if((b < c) || (d < a)) return 0;
	if((a <= c) && (d <= b)) return d - c + 1;
	if((c <= a) && (b <= d)) return b - a + 1;
	if(c >= a) return b - c + 1;
	if(c <= a) return d - a + 1;
}

void solve(int n, int m){
	vector<int> hor[n], ver[m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			int hold; cin>>hold;
			hor[i].push_back(hold);
			ver[j].push_back(hold);
		}
	
	int q; cin>>q;
	while(q--){
		int a, b; cin>>a>>b;
		vector<int>::iterator up, low;
		low = lower_bound(hor[0].begin(), hor[0].end(), a); 
		up = upper_bound(hor[0].begin(), hor[0].end(), b); up--;
		
		cout<<"cotas horizontales"<<endl;
		cout<<"low: "<<*low<<" up: "<<*up<<endl;
		
		int x = low - hor[0].begin(), y = up - hor[0].begin();
		int minS= x - y;
		
		for(int i=1; i<n; i++){
			low = lower_bound(hor[i].begin(), hor[i].end(), a);
			up = upper_bound(hor[i].begin(), hor[i].end(), b); up--;
			cout<<"cotas horizontales"<<endl;
			cout<<"low: "<<*low<<" up: "<<*up<<endl;
			int w = low - hor[i].begin(), z = up - hor[i].begin();
			minS = min(minS, inter(x, y, w, z));
			x = w;
			y = z;
		}
		cout<<"cotas verticlaes"<<endl;
		cout<<"low: "<<*low<<" up: "<<*up<<endl;
		low = lower_bound(ver[0].begin(), ver[0].end(), a);
		up = upper_bound(ver[0].begin(), ver[0].end(), b);
		x = low - ver[0].begin(), y = up - ver[0].begin();
		
		minS= x - y;
		
		for(int i=1; i<n; i++){
			low = lower_bound(ver[i].begin(), ver[i].end(), a);
			up = upper_bound(ver[i].begin(), ver[i].end(), b);
			int w = low - hor[i].begin(), z = up - hor[i].begin();
			minS = min(minS, inter(x, y, w, z));
			x = w;
			y = z;
		}
		cout<<minS<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    //while(n + m)
    	solve(n, m);
    
	return 0;
}
