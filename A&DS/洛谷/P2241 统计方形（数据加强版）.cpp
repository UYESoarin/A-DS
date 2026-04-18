#include<bits/stdc++.h> 
#define ll long long
using namespace std;
//方格：n*m边,(n+1)*(m+1)顶点 
//坍缩取均法求特定矩形数：同边长为i的边数n-(i-1)
//组合法取点求总矩形数：C(n+1,2)*C(m+1.2)=(n+1)*n/2 * (m+1)*m/2 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	ll rec=((n+1)*n*(m+1)*m)/4;
	ll sqt=0;
	for(ll i=1;i<=min(m,n);i++){
		ll row=m-i+1,col=n-i+1;
		sqt+=row*col;
	}cout<<sqt<<" "<<rec-sqt;
	//只用坍缩法
	/*
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(i==j)sqt+=(m-i+1)*(n-j+1);
			else noSqtRec+=(m-i+1)*(n-j+1);
		}
	}
	*/
	return 0;
}
