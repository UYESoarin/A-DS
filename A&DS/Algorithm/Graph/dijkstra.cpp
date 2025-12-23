#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<tuple>
#include<algorithm>
#include<set>
#include<functional>
using namespace std;

const int INF=INT_MAX;

vector<vector<int>> adj;
vector<int> dist;
vector<int> cost;
vector<int> cnt;
vector<int> prevS;
vector<set<int>> prevA;
vector<int> nextS;
vector<set<int>> nextA;
vector<int> pathS;
vector<vector<int>> pathA;
vector<int> pathSN;
vector<vector<int>> pathAN;
vector<vector<tuple<int,int,int>>> graph;

struct State{
	int node;
	int dist;
	int cost;
	//greater<State>
	bool operator>(const State& other)const{
		if(dist==other.dist)return cost>other.cost;
		return dist>other.dist;
	}
};

void dijkstra(int n,int start,int end){//graph <node,weight,fee>

	dist.assign(n,INF);
	cost.assign(n,INF);
	cnt.assign(n,0);
	prevS.assign(n,-1);
	prevA.assign(n,set<int>());//empty set
	nextS.assign(n,-1);
	nextA.assign(n,set<int>());
	
	pathS.clear();
	pathA.clear();
	pathSN.clear();
	pathAN.clear();
	
	priority_queue<State,vector<State>,greater<State>> pq;//<node,dist,cost>
	//pq variable corresponded
	
	//beginning initialize
	dist[start]=0;
	cost[start]=0;
	cnt[start]=1;
	pq.push({start,0,0});
	
	while(!pq.empty()){
		State curr=pq.top();
		pq.pop();
		
		int u=curr.node;
		int d=curr.dist;
		int c=curr.cost;
		
		if(u==end)break;
		if(d>dist[u] || d==dist[u] && c>cost[u])continue;
		
		//tranverse neighbor
		for(auto& edge:graph[u]){
			//tuple<int node,int weight,int fee>
			int v=get<0>(edge);
			int w=get<1>(edge);
			int f=get<2>(edge);
			
			int newDist=dist[u]+w;
			int newCost=cost[u]+f;
			//shorter path
			if(newDist<dist[v]){
				dist[v]=newDist;
				cost[v]=newCost;
				cnt[v]=cnt[u];
				
				prevS[v]=u;
				
				prevA[v].clear();
				prevA[v].insert(u);
				
				nextS[u]=v;
				
				nextA[u].clear();
				nextA[u].insert(v);
				
				pq.push({v,newDist,newCost});
				
			}else if(newDist==dist[v]){//cheaper path
				if(newCost<cost[v]){
					cost[v]=newCost;
					cnt[v]=cnt[u];
					
					prevS[v]=u;
					
					prevA[v].clear();
					prevA[v].insert(u);
					
					nextS[u]=v;
					
					nextA[u].clear();
					nextA[u].insert(v);
					
					pq.push({v,newDist,newCost});
					
				}else if(newCost==cost[v]){//equivalent path
					cnt[v]+=cnt[u];
					prevA[v].insert(u);
					nextA[u].insert(v);
				}
			}
		}
	}
	//rebuild singlePath byPrev
	if(dist[end]!=INF){
		for(int curr=end;curr!=-1;curr=prevS[curr]){
			pathS.push_back(curr);
		}
		reverse(pathS.begin(),pathS.end());
	}
	//rebuild allPath byPrev
	if(dist[end]!=INF){	
		vector<int> currpath;
		function<void(int)> DFSprev=[&](int node){
			currpath.push_back(node);
			if(node==start){
				//store path to reverse
				vector<int> path=currpath;
				reverse(path.begin(),path.end());
				pathA.push_back(path);
			}
			else {
				for(auto prev:prevA[node]){
					DFSprev(prev);
				}
			}
			currpath.pop_back();
		};//";" watch out
		DFSprev(end);
	}
	//rebuild singlePath byPost
	if(dist[end]!=INF){
		int curr=start;
		pathSN.push_back(curr);
		while(curr!=end){
			curr=nextS[curr];
			//avoid noPath with -1
			if(curr==-1)break;
			pathSN.push_back(curr);
		}
	}
	//rebuild allPath bePost
	if(dist[end]!=INF){
		vector<int> currpath;
		function<void(int)> DFSpost=[&](int curr){
			currpath.push_back(curr);
			if(curr==end){
				pathAN.push_back(currpath);
			}else{
				for(auto next:nextA[curr]){
					DFSpost(next);
				}
			}
			currpath.pop_back();
		};
		DFSpost(start);
	}
}
