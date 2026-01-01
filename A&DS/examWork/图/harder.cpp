#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
struct Edge{
	int u,v,w;
	Edge(int u,int v,int w):u(u),v(v),w(w){}
};
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<pii>> g(n+1);//{v,w}
	vector<Edge> edge;
	
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		edge.push_back(Edge(u,v,w));
	}
	
	int s,t;cin>>s>>t;
	vector<int> dist(n+1,INF);
	priority_queue<pii,vector<pii>,greater<pii>> pq;//{d,u}
	dist[t]=0;pq.push({0,t});
	while(!pq.empty()){
		auto p=pq.top();pq.pop();
		int d=p.first,u=p.second;
		if(d>dist[u])continue;
		for(auto& nx:g[u]){
			int v=nx.first,w=nx.second;
			int newDist=d+w;
			if(newDist<dist[v]){
				dist[v]=newDist;
				pq.push({newDist,v});
			}
		}
	}
	if(dist[s]==INF){
		cout<<-1;return 0;
	}
	//DAG rbuild
	vector<vector<int>> dag(n+1);
	for(auto& e:edge){
		int u=e.u,v=e.v,w=e.w;
		if(dist[v]==INF || dist[u]==INF)continue;
		if(dist[v]<dist[u])dag[u].push_back(v);
		else if(dist[u]<dist[v])dag[v].push_back(u);
	}
	vector<int> node;
	for(int i=1;i<=n;i++){
		if(dist[i]==INF)continue;
		node.push_back(i);
	}//closerFirstAssigned
	sort(node.begin(),node.end(),[&](int a,int b){
		return dist[a]<dist[b];
	});
	//stateSwitch(u->v): dp[u] = Sum_dp[v]
	vector<int> dp(n+1);
	dp[t]=1;//base
	for(int u:node){
		for(auto v:dag[u]){
			dp[u]+=dp[v];
		}
	}
	cout<<dp[s];
	return 0;
}
