#include<bits/stdc++.h>
#define ft first
#define sd second
#define pii pair<int,int>
#define v vector
#define isValid nx>=0 && nx<n && ny>=0 && ny<m
using namespace std;
const int INF=INT_MAX/2;
v<pii> dt=
{{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int main(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	x--,y--;
	v<v<int>> mat(n,v<int>(m,-1));
	queue<pii> q;
	q.push({x,y});
	mat[x][y]=0;
	while(!q.empty()){
		pii cur=q.front();
		q.pop();
		int cx=cur.ft,cy=cur.sd;
		for(int i=0;i<8;i++){
			int nx=cx+dt[i].ft,ny=cy+dt[i].sd;
			if(isValid && mat[nx][ny]==-1){
				mat[nx][ny]=mat[cx][cy]+1;
				q.push({nx,ny});
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<" ";
		}cout<<"\n";
	}
	return 0;
} 
