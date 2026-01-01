#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
const int INF=INT_MAX;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
struct Node{
	int d,x,y;
	Node(int d,int x,int y):d(d),x(x),y(y){}
	//heapGreater '>' & 'const'
	bool operator>(const Node& other)const{return d>other.d;}
};
int main(){
	int n,m;
	cin>>n>>m;
	//initialization
	vector<string> g(n);
	int sx,sy,ex,ey;
	for(int i=0;i<n;i++){
		cin>>g[i];
		for(int j=0;j<m;j++)
			if(g[i][j]=='r')sx=i,sy=j;
			else if(g[i][j]=='a')ex=i,ey=j;
	}
	
	//2D dijkstra
	vector<vector<int>> dist(n,vector<int>(m,INF));
	priority_queue<Node,vector<Node>,greater<Node>> pq;
	dist[sx][sy]=0;
	pq.push(Node(0,sx,sy));
	
	while(!pq.empty()){
		Node cur=pq.top();
		pq.pop();
		int d=cur.d;
		int x=cur.x;
		int y=cur.y;
		//enSure minDist firstly
		if(d>dist[x][y])continue;
		if(x==ex && y==ey){
			cout<<d<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			//rangeSecurity
			if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
			if(g[nx][ny]=='#')continue;
			
			int cost=1;
			if(g[nx][ny]=='x')cost++;
			int nd=d+cost;
			if(nd<dist[nx][ny]){
				dist[nx][ny]=nd;
				pq.push(Node(nd,nx,ny));
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
