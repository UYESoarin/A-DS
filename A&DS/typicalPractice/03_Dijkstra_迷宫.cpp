#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;
struct Node{
	int x, y, time;
	Node(int x, int y, int time):x(x), y(y), time(time){}
	bool operator>(const Node& other)const{
		return time>other.time;
	}
};
int main(){
	int n, m;
	cin>>n>>m;
	int start_x=-1, start_y=-1, end_x=-1, end_y=-1;
	//迷宫网格 
	vector<string> grap(n);
	for(int i=0; i<n; i++){
		cin>>grap[i];
		for(int j=0; j<m; j++){
			if(grap[i][j]=='r'){
				start_x=i;
				start_y=j;
			}if(grap[i][j]=='a'){
				end_x=i;
				end_y=j;
			}
		}
	}
	
	//距离矩阵 
	vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
	dist[start_x][start_y]=0;
	
	//位移向量 
	int dx[]={1, -1, 0, 0};
	int dy[]={0, 0, 1, -1};
	
	//优先路径
	priority_queue<Node, vector<Node>, greater<Node> > pq;
	pq.push(Node(start_x, start_y, 0)); 
	
	//Dijkstra 
	while(!pq.empty()){
		Node curr=pq.top();
		pq.pop();
		
		if(curr.x==end_x && curr.y==end_y){
			cout<<curr.time<<endl;
			return 0;
		}
		
		if(curr.time>dist[curr.x][curr.y]){
			continue;
		}
		
		for(int i=0; i<4; i++){
			int nx=curr.x+dx[i];
			int ny=curr.y+dy[i];	
			if(nx>=0 && nx<n && ny>=0 && ny<m && grap[nx][ny]!='#'){
				int cost=1;
				if(grap[nx][ny]=='x'){
					cost=2;
				}
				int new_time=curr.time+cost;
				if(new_time<dist[nx][ny]){
					dist[nx][ny]=new_time;
					pq.push(Node(nx, ny, new_time));
				}
			}
			
		}
	}
	cout<<-1<<endl;
	return 0;
}
