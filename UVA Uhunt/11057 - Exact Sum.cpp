#include <bits/stdc++.h>
using namespace std;

vector<int> prices(10000);

void solve(int n){
	multiset<int> prices;
	for(int i=0; i<n; i++){
		int hold; cin>>hold;
		prices.insert(hold);
	}
	
	int m; cin>>m;
	
	int ans=0;
	for(auto it : prices){
		if(prices.count(m - it) != 0 && (abs(m - 2 * it) < abs(m - 2 * ans))){
			if((it != m - it) || (prices.count(m - it) != 1))
				ans = it;
		}
	}
	
	int x = min(ans, m - ans);
	cout<<"Peter should buy books whose prices are "<<x<<" and "<<m - x<<"."<<endl<<endl;
	
}

/*
void solve(int n){
	for(int i=0; i<n; i++)
		cin>>prices[i];
	sort(prices.begin(), prices.begin() + n);
	
	int m; cin>>m;
	
	int ans = -1;
	for(int i = 0; i < n; i++){
		int a = prices[i];
		
		int l = 1, r = n - 1;
		while(l <= r){
			int mid = (l + r)/2;
			if(prices[mid] == m - a){
				if(((m - 2*a) < (m - 2*ans)) && (mid != i)){
					ans = a;
					break;
				}else{
					if((1 <= mid) && prices[mid - 1] == m - a && ((m - 2*a) < (m - 2*ans))){
						ans = a;
						break;
					}else if((n - 2 >= mid) && prices[mid + 1] == m - a && ((m - 2*a) < (m - 2*ans))){
						ans = a;
						break;
					}else{
						
					}
				}
			}else if(m - a < prices[mid]){
				r = mid - 1;
			}else if(m - a > prices[mid]){
				l =  mid +1;
			}
		
			if(l >= n || r <= -1){
				break;
			}
		}
	}
	int x = min(ans, m - ans);
	cout<<"Peter should buy books whose prices are "<<x<<" and "<<m - x<<"."<<endl;
} */

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while(cin>>n)
    	solve(n);
    
	return 0;
}
