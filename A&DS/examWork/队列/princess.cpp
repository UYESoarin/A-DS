#include<iostream>
#include<vector> 
#include<queue>
#include<string>
#include<climits>
using namespace std;

const int INF=INT_MAX;
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<pair<int,int>>> adj(N,vector<pair<int,int>>(M));
	//<dist,weight>
	string row;
	int startX,startY,endX,endY;
	for(int i=0;i<N;i++){
		cin>>row;
		for(int j=0;j<M;j++){
			adj[i][j].first=INF;
			if(row[j]=='#')adj[i][j].second=INF;
			else if(row[j]=='.')adj[i][j].second=1;
			else if(row[j]=='x')adj[i][j].second=2;
			else if(row[j]=='r'){
				startX=i;
				startY=j;
				adj[startX][startY].second=0;
			}
			else if(row[j]=='a'){
				adj[i][j].second=1;
				endX=i;
				endY=j;
			}
		} 
	}
	adj[startX][startY]={0,0};
	vector<pair<int,int>> deltaV={{0,1},{0,-1},{-1,0},{1,0}};
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	//<dist,index>
	pq.push({0,{startX,startY}});
	
	while(!pq.empty()){
		int currX=pq.top().second.first;
		int currY=pq.top().second.second;
		int currDist=pq.top().first;
		pq.pop();
		if(currX==endX && currY==endY){
			cout<<currDist;
			return 0;
		}
		
		if(currDist>adj[currX][currY].first)continue;

		for(int i=0;i<4;i++){
			int nextX=currX+deltaV[i].first;
			int nextY=currY+deltaV[i].second;
			if(nextX<0 || nextX>=N || nextY<0 || nextY>=N)continue;
			if(adj[nextX][nextY].second==INF)continue;//跳过不可达 
			int nextDist=adj[nextX][nextY].second+adj[currX][currY].first;
			if(nextDist<adj[nextX][nextY].first){
				adj[nextX][nextY].first=nextDist;
				pq.push({nextDist,{nextX,nextY}});
			}
		}		
	}
	cout<<-1;
	return 0;
}
//7 8
//#.#####.
//#.a#..r.
//#..#x...
//..#..#.#
//#...##..
//.#......
//........
