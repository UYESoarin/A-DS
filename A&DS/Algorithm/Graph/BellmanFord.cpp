#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<climits>
using namespace std;
const int INF=INT_MAX/2;
struct Edge{
	int u;
	int v;
	int w;
	Edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<vector<pair<int,int>>> adj;
vector<Edge> edges;
class BellmanFord{
public:
	static bool bellmanFord(int s,int n){
		vector<int> dist(n,INF);dist[s]=0;//0~n-1
		//looseLoop n-1
		for(int i=1;i<n;++i){
			bool updated=false;
			for(auto& e:edges){
				int u=e.u,v=e.v,w=e.w;
				if(dist[u]!=INF && dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					updated=true;
				}
			}
			if(!updated)break;
		}
		//detect negativeCycle
		for(auto& e:edges){
			int u=e.u,v=e.v,w=e.w;
			if(dist[u]!=INF && dist[v]>dist[u]+w)return true;
		}
		for(auto x:dist)cout<<x<<' ';cout<<endl;
		return false; 
	}
	
	static bool SPFA(int s,int n){
		vector<int> dist(n,INF), cnt(n,0);
		vector<bool> inq(n,false);
		queue<int> q;
		dist[s]=0; q.push(s); inq[s]=true;
		while(!q.empty()){
			int u=q.front(); q.pop(); inq[u]=false;
			for(auto& cur:adj[u]){
				int v=cur.first,w=cur.second;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					if(!inq[v]){
						q.push(v);inq[v]=true;
						if(++cnt[v]>=n)return true;//n-1 times
					}
				}
			}
		}return false;
	}
	
	static bool SLF(int s,int n){
		vector<int> dist(n,INF), cnt(n,0);
		vector<bool> inq(n,false);
		deque<int> dq;
		dist[s]=0; dq.push_back(s); inq[s]=true;
		
		while(!dq.empty()){
			int u=dq.front(); dq.pop_front(); inq[u]=false;
			for(auto& cur:adj[u]){
				int v=cur.first, w=cur.second;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					if(!inq[v]){
						if(!dq.empty() && dist[v]<dist[dq.front()])
							dq.push_front(v);
						else dq.push_back(v);
						inq[v]=true;
						if(++cnt[v]>=n)return true;
					}
				}
			}
		}return false;
	}
};
