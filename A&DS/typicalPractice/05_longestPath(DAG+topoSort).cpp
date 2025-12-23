#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
const int NINF=INT_MIN;
//mostValuePath in DAG with topoSequence
//Dynamic store path
vector<vector<pair<int,int>>> G;
vector<vector<int>> paths;
vector<int> dist;
//vector<int> prv;

vector<int> topoSort(int n){
	vector<int> indeg(n,0);
	for(int u=0;u<n;u++)
		for(auto& nx:G[u])indeg[nx.first]++;
	queue<int> q;
	for(int u=0;u<n;u++)if(indeg[u]==0)q.push(u);
	vector<int> topo;
	while(!q.empty()){
		int u=q.front();q.pop();
		topo.push_back(u);
		for(auto& nx:G[u])if(--indeg[nx.first]==0)q.push(nx.first);
	}
	if(topo.size()!=n)return {};
	return topo;
}
pair<int,vector<int>> longestPath(int s,int t,int n,const vector<int>& topo){
	dist.assign(n,NINF);
	paths.assign(n,{});
//	prv.assign(n,-1);
	
	dist[s]=0;
	paths[s]={s};
	
	for(int u:topo){
		if(dist[u]==NINF)continue;
		for(const auto& nx:G[u]){
			int v=nx.first;int w=nx.second;
			int newDist=dist[u]+w;
			
			vector<int> newPath=paths[u];
			newPath.push_back(v);
			
			if(newDist>dist[v]){
				dist[v]=newDist;
				paths[v]=newPath;
//				prv[v]=u;
			}else if(newDist==dist[v]){
//				prv[v]=min(u,prv[v]);
				//dictionarySequence Comparison by vector
				if(paths[v].empty() || newPath<paths[v]){
					paths[v]=newPath;
				}
			}
		}
	}
	if(dist[t]==NINF)return {NINF,{}};
	vector<int> path=paths[t];
//	for(int curr=t;curr!=-1;curr=prv[curr])path.push_back(curr);
//	reverse(path.begin(),path.end());
	return {dist[t],path};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,e;
	cin>>n>>e;
	
	G.assign(n,{});
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
	}
	
	int s,t;
	cin>>s>>t;
	vector<int> topo=topoSort(n);
	auto res=longestPath(s,t,n,topo);
	int length=res.first;
	vector<int> path=res.second;
	if(path.empty())cout<<"none";
	else{
		for(int i=0;i<path.size();i++){
			if(i)cout<<"->";
			cout<<path[i];
		}
	}
	return 0;
}
