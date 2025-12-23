#include<iostream>
#include<vector>
#include<list>//if push_front demanded
#include<queue>
#include<climits>
using namespace std;

const int INF=INT_MAX; 
vector<vector<pair<int,int>>> adj;
void insert(int src,int dest,int weight,int directed){
	adj[src].push_back({dest,weight});
	if(!directed)adj[dest].push_back({src,weight});
}
vector<int> dijkstra(int start,int n){
	vector<int> dist(n,INF);
	dist[start]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,
	greater<pair<int,int>>> pq;
	pq.push({0,start});
	while(!pq.empty()){
		int currNode=pq.top().second;
		int currDist=pq.top().first;
		pq.pop();
		
		if(currDist>dist[currNode])continue;
		for(auto neighbor:adj[currNode]){
			int nextNode=neighbor.first;
			int weight=neighbor.second;
			
			if(dist[currNode]+weight<dist[nextNode]){
				dist[nextNode]=dist[currNode]+weight;
				pq.push({dist[nextNode],nextNode});
			}
		}
		
	}
	return dist;
}

	
int main(){
	int N,M,D;
	cin>>N>>M>>D;
	adj.resize(N+1);
	
	int s,d,w;
	for(int i=0;i<M;i++){
		cin>>s>>d>>w;
		insert(s,d,w,D);
	}
	
	int S;
	cin>>S;
	vector<int> path=dijkstra(S,N+1);
	for(int i=1;i<=N;i++){
		cout<<S<<"->"<<i<<':';
		if(path[i]!=INF)cout<<path[i];
		else cout<<"no path";
		cout<<endl;
	}
	return 0;
}
