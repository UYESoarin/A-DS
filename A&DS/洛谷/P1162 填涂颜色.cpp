#include<bits/stdc++.h>
#define pii pair<int,int>
#define isValid nx>=0 && nx<=n+1 && ny>=0 && ny<=n+1
#define ft first
#define sd second
using namespace std;
//逆向、构造 
vector<pii> dt={{0,1},{0,-1},{-1,0},{1,0}};
int mat[32][32];//扩圈：对非连通区域加圈连接便于搜索 
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mat[i][j];
	queue<pii> q;
	q.push({0,0});
	mat[0][0]=2;
	while(!q.empty()){
		pii cur=q.front();q.pop();
		int cx=cur.ft,cy=cur.sd;
		for(int i=0;i<4;i++){
			int nx=cx+dt[i].ft,ny=cy+dt[i].sd;
			if(isValid && !mat[nx][ny]){
				mat[nx][ny]=2;
				q.push({nx,ny});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int ans=mat[i][j];
			if(ans==2)ans=0;
			else if(ans==0)ans=2;
			cout<<ans<<" ";
		}cout<<"\n";
	}
	return 0;
} 
