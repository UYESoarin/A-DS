#include<bits/stdc++.h>
using namespace std;
int main(){//模拟：标记数组 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int l,m;cin>>l>>m;
	vector<bool> rmt(l+1,false);
	while(m--){
		int u,v;cin>>u>>v;
		for(int i=u;i<=v;i++)rmt[i]=true;
	}
	int ans=0;
	for(auto t:rmt)if(!t)ans++;
	cout<<ans;
	return 0;
}
