#include<iostream>
#include<vector>
using namespace std;

void MinHeapify(vector<int>& v,int k,int n){
	int i=k,j=2*i;
	while(j<=n){
		if(j+1<=n && v[j]>v[j+1])j++;
		if(v[i]>v[j]){
			swap(v[i],v[j]);
			i=j;
			j*=2;
		}
		else break;
	}
}
void DownHeapSort(vector<int>& v,int n){
	for(int i=n/2;i>=1;i--){
		MinHeapify(v,i,n);
	} 
	for(int i=n;i>=2;i--){
		swap(v[1],v[i]);
		MinHeapify(v,1,i-1);
	}
}

void MaxHeapify(vector<int>& v,int k,int n){
	int i=k,j=2*k;
	while(j<=n){
		if(j+1<=n && v[j]<v[j+1])j++;
		if(v[i]<v[j]){
			swap(v[i],v[j]);
			i=j;
			j*=2;
		}else break;
	}
}
void UpHeapSort(vector<int>& v,int n){
	for(int i=n/2;i>=1;i--){
		MaxHeapify(v,i,n);
	} 
	for(int i=n;i>=2;i--){
		swap(v[i],v[1]);
		MaxHeapify(v,1,i-1);
	}
}
int main(){
	vector<int> v={0,4,10,3,5,1,7,2,8,6,9};
	DownHeapSort(v,v.size()-1);
	for(int i=1;i<v.size();i++)cout<<v[i]<<' ';
	UpHeapSort(v,v.size()-1); 
	cout<<endl;
	for(int i=1;i<v.size();i++)cout<<v[i]<<' '; 
	return 0;
}
