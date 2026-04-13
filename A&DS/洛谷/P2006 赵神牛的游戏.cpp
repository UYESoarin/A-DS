#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll k,m,n;cin>>k>>m>>n;
	vector<int> res;
	for(int i=1;i<=m;i++){
		ll a,b;cin>>a>>b;
		if((a==0 && b>0)||(a>0 && k/a*b>=n))
			res.push_back(i);
	}
	if(res.empty())cout<<-1;
	else for(int ans:res)cout<<ans<<' ';
	return 0;
} 
