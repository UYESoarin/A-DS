#include<bits/stdc++.h>
#define pii pair<int,int>
#define ft first
#define sd second
#define vct vector
using namespace std;
//按结束时间排序贪心 
int main(){
	int n;cin>>n;
	vct<pii> cpt;
	for(int i=0;i<n;i++){
		int b,a;cin>>a>>b;
		cpt.push_back({b,a});
	}sort(cpt.begin(),cpt.end());
	int end=0,ans=0;
	for(int i=0;i<n;i++){
		int st=cpt[i].sd,et=cpt[i].ft;
		if(st>=end)end=et,ans++;
	}cout<<ans;
	return 0;
}
