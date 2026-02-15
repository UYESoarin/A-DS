#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm> 
#include<climits>
#define pii pair<int,int>
using namespace std;
const int INF=INT_MAX;
vector<vector<int>> g;//{vertex,weight}

int Prim(int n,int s){
	vector<bool> vis(n,false);
	vector<int> minDist(n,INF);
	priority_queue<pii,vector<pii>,greater<pii>> pq;//{weight,vertex}
	
	int total=0,cnt=0;
	pq.push({0,s});
	minDist[s]=0;
	
	while(!pq.empty() && cnt<n){
		auto p=pq.top();
		pq.pop();
		int u=p.second;
		int w=p.first;
		
		if(vis[u])continue;
		if(w!=minDist[u])continue;
		
		vis[u]=true;
		total+=w;
		cnt++;
		
		for(auto nx:g[u]){
			int v=nx.first;
			int wt=nx.second;
			if(!vis[v] && wt<minDist[v]){
				minDist[v]=wt;
				pq.push({wt,v});	
			}
		}
	}
	return cnt==n?total:-1;
}

struct Edge{int u,v,w;};
bool cmp(Edge a,Edge b){return a.w<b.w;}
vector<Edge> edges;

int kruskal(int n){
	sort(edges.begin(),edges.end(),cmp);
	
	int total=0,cnt=0;
	vector<int> parent(n);
	for(int i=0;i<n;i++)parent[i]=i;
	
	function<int(int)> find=[&](int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	
	for(auto& e:edges){
		int ru=find(r.u);
		int rv=find(r.v);
		if(ru!=rv){i
			parent[ru]=rv;
			total+=e.w;
			if(++cnt==n-1)break;
		}
	}
	return cnt==n-1?total:-1;
}


