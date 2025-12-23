#include<iostream>
#include<list>
#include<vector> 
#include<queue>
#include<climits>
using namespace std;
const int INF=INT_MAX;
class AdjListGraph{
	int V;
	vector<list<pair<int,int>>> adj;
	//<node,weight>
	public:
		//constructor
		AdjListGraph(int v):V(v){
			adj.resize(V);
		}
		//destructor isn't demanded
		
		//list when push_front demanded
		void insertEdgeDirected(int src,int dest,int weight=1){
			if(src>=0 && src<V && dest>=0 && dest<V)
			adj[src].push_front({dest,weight});
		}
		void insertEdgeUndire(int src,int dest,int weight=1){
			if(src>=0 && src<V && dest>=0 && dest<V){
				adj[src].push_front({dest,weight});
				adj[dest].push_front({src,weight});
			}
		} 
		
		void print(){
			for(int i=0;i<V;i++){
				cout<<i<<':';
				for(auto node:adj[i]){
					cout<<node.first<<"("<<node.second<<") ";
				}
//				for(list<pair<int,int>>::iterator it=adj[i].begin();it!=adj[i].end();it++){
//					cout<<*it.first<<"("<<*it.second<<") ";
//				} 
				cout<<endl;
			}
		}
		
		void DFS(int start){
			vector<bool> visited(V,false);
			cout<<"DFS(R): ";
			DFSRescusive(start,visited);
			cout<<endl;
		}
		void BFS(int start){
			vector<bool> visited(V,false);
			queue<int> q;
			cout<<"BFS: ";
			visited[start]=true;
			q.push(start);
			
			while(!q.empty()){
				int curr=q.front();
				q.pop();
				cout<<curr<<' ';
				
				for(auto& node:adj[curr]){
					int dest=node.first;
					if(!visited[dest]){
						visited[dest]=true;
						q.push(dest);
					}
				}
			} 
		}
		//Dijkstra
		vector<int> Dijkstra(int start){
			vector<int> dist(V,INF);//distance
			dist[start]=0;
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			pq.push({0,start});
			//<weight,node>
			while(!pq.empty()){
				int currNode=pq.top().second;
				int currDist=pq.top().first;
				pq.pop();
				
				if(currDist>dist[currNode])continue;
				for(auto neighbor:adj[currNode]){
					int nextNode=neighbor.first;
					int weight=neighbor.second;
					int nextDist=dist[currNode]+weight; 
					if(nextDist<dist[nextNode]){
						dist[nextNode]=nextDist;
						pq.push({nextDist,nextNode});
					}
				} 
			}return dist;
		}
		
		
		private:
			//ÉîËÑµÝ¹éº¯Êý 
			void DFSRescusive(int v,vector<bool> visited){
				visited[v]=true;
				cout<<v<<' ';
				for(auto node:adj[v]){
					int dest=node.first;
					if(!visited[dest]){
						DFSRescusive(dest,visited);
					} 
				}
			}
};



 
