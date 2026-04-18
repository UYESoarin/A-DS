#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int mx=0;
	vector<int> t(n);
	for(int i=0;i<n;i++){
		cin>>t[i];
		mx=max(mx,t[i]);
	}
	//binarySearch for Maximum:low able, high enable
	int low=0,high=mx+1;
	while(low+1<high){
		int mid=low+(high-low)/2;
		ll sum=0;
		for(int i=0;i<n;i++)
			if(t[i]>mid)sum+=t[i]-mid;
		if(sum>=m)low=mid;
		else high=mid;
	}
	cout<<low;
	return 0;
}
