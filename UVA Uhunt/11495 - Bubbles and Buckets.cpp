#include <bits/stdc++.h>
using namespace std;

long long _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid,	long long right);

//Ordenar el arreglo y devolver el total de inversiones
long long mergeSort(long long arr[], long long array_size){
	long long temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

long long _mergeSort(long long arr[], long long temp[], long long left, long long right){
	long long mid, inv_count=0;
	if(right>left){
		mid=(right + left)/2;

	//Contamos las inversiones de las mitades
		inv_count+=_mergeSort(arr, temp, left, mid);
		inv_count+=_mergeSort(arr, temp, mid+1, right);

	//Contamos las inversiones al unir las mitades
		inv_count+=merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}

long long merge(long long arr[], long long temp[], long long left, long long mid, long long right){
	long long i, j, k;
	long long inv_count=0;

	i=left; 
	j=mid; 
	k=left; 
	while((i<=mid-1) && (j<=right)){
		if (arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
			inv_count=inv_count+(mid-i);
		}
	}

	//Copaimos los elementos restantes
	while(i<=mid-1)
		temp[k++]=arr[i++];

	while(j<=right)
		temp[k++]=arr[j++];

	for(i=left;i<=right;i++)
		arr[i]=temp[i];

	return inv_count;
}

void solve(int n){
	long long arr[n];
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	
	long long changes=mergeSort(arr, n);
	
	if(changes%2==1) cout<<"Marcelo\n";
	else cout<<"Carlos\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t; cin>>t;
	while(t!=0){
		solve(t); cin>>t;
	}
	
	return 0;
}
