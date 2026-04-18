#include<bits/stdc++.h>
#define INF INT_MAX/2
#define isValid nf>=1 && nf<=n
using namespace std;
int n,a,b;
int to[]={1,-1};
queue<int> q;
int main(){
	cin>>n>>a>>b;
	vector<int> k(n+1),ans(n+1,INF);
	for(int i=1;i<=n;i++)cin>>k[i];
	q.push(a);
	ans[a]=0;
	while(!q.empty()){
		int cf=q.front();
		q.pop();
		if(cf==b)break;
		for(int i=0;i<2;i++){
			int nf=cf+to[i]*k[cf];
			if(isValid && ans[nf]==INF){//一次抵达即可（步长相同时最短） 
				ans[nf]=ans[cf]+1;
				q.push(nf);
			}
		}
	}
	cout<<((ans[b]<INF)?ans[b]:-1);//运算发输出括号补齐 
	return 0;
}
