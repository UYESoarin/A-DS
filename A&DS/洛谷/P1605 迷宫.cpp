#include<bits/stdc++.h>
#define isValid nx>=1 && nx<=n && ny>=1 && ny<=m
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int main(){
	int n,m,t;cin>>n>>m>>t;
	int sx,sy,fx,fy;cin>>sx>>sy>>fx>>fy;
	vector<vector<bool>> vis(n+1,vector<bool>(m+1));
	vis[sx][sy]=1;
	while(t--){
		int ox,oy;cin>>ox>>oy;
		vis[ox][oy]=1;
	}
	int tot=0;
	function<void(int,int)> dfsMaze=[&](int cx,int cy){
		if(cx==fx && cy==fy){
			tot++;
			return;
		}
		for(int i=0;i<4;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if(isValid && !vis[nx][ny]){
				vis[nx][ny]=1;
				dfsMaze(nx,ny);
				vis[nx][ny]=0;
			}
		}
	};
	dfsMaze(sx,sy);
	cout<<tot;
	return 0;
} 
