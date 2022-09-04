#include <bits/stdc++.h>
using namespace std;

int m;
ofstream myfile;

bool comp(int a, int b){
	if(a%m!=b%m)
		return a%m<b%m;
	
	if(a%2==1){
		if(b%2==1)
			return a>b;
		return true;
	}
	if(b%2==1)
		return false;
	return a<b;
}

void solve(int n, int m){
	//impar, par	
	vector<int> arr(n);
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	sort(arr.begin(), arr.end(), comp);
	
	cout<<n<<" "<<m<<endl;
	myfile<<n<<" "<<m<<endl;
	for(auto x : arr){
		cout<<x<<endl;
		myfile<<x<<endl;
	}
}

int main(){
	myfile.open("output.txt");
	
	int n; cin>>n>>m;
	while(m!=0 || n!=0){
		solve(n,m); cin>>n>>m;
	}
		
	cout<<"0 0\n";
	myfile<<"0 0\n";
	myfile.close();
	return 0;
}
