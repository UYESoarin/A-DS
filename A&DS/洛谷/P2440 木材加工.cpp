#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bsmax(int a,int b,int k,vector<int> w){
	int l=a,h=b+1;//[1,max+1)
	while(l+1<h){
		int mid=l+(h-l)/2;
		ll cnt=0;
		for(int i=0;i<w.size();i++){
			cnt+=w[i]/mid;
		}
		if(cnt>=k)l=mid;
		else h=mid;
	}
	return l;
}

int main(){
	int n,k;cin>>n>>k;
	vector<int> w(n);
	int mx=0,tot=0;
	for(int i=0;i<n;i++){
		cin>>w[i];
		mx=max(mx,w[i]);
        tot+=w[i];
	}
	ll ans=bsmax(0,mx,k,w);
	cout<<ans;
	return 0;
}

