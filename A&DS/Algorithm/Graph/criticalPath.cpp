#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<utility>
using namespace std;

pair<int,vector<pair<int,int>>> criticalPath(int n,vector<vector<pair<int,int>>>& g){
	vector<int> indeg(n,0),topo;
	for(int u=0;u<n;u++) for(auto neb:g[u])indeg[neb.first]++;
	queue<int> q; for(int i=0;i<n;i++)if(indeg[i]==0)q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();topo.push_back(u);
		for(auto neb:g[u])if(--indeg[neb.first]==0)q.push(neb.first);
	} 
	if(topo.size()!=n)return {-1,{}};
	
	vector<int> ve(n,0);
	for(int u:topo)for(auto neb:g[u])ve[neb.first]=max(ve[u]+neb.second,ve[neb.first]);
	
	int T=*max_element(ve.begin(),ve.end());
	vector<int> vl(n,T);
	
	reverse(topo.begin(),topo.end());
	for(int u:topo)for(auto neb:g[u])vl[u]=min(vl[neb.first]-neb.second,vl[u]);
	
	vector<pair<int,int>> ac;
	for(int u=0;u<n;u++)for(auto neb:g[u])if(ve[u]==vl[neb.first]-neb.second)ac.push_back({u,neb.first});
	
	return {T,ac};
}

//class criticalPathSolver{
//	vector<vector<pair<int,int>>> graph;
//	//{v,weight}
//	vector<int> topoSort(int n){
//		vector<int> indegree(n,0);
//		for(int curr=0;curr<n;curr++)for(auto [next,w]:graph[curr])indegree[next]++;
//		
//		queue<int> q;
//		for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
//		
//		vector<int> res;
//		while(!q.empty()){
//			int curr=q.front();
//			res.push_back(curr);
//			q.pop();
//			for(auto [next,w]:graph[curr])if(--indegree[next]==0)q.push(next);
//		}
//		return res.size()==n?res:vector<int>();
//	}
//	void earliestTime(vector<int>& earliest,const vector<int>& topo){
//		for(int curr:topo){
//			for(auto [next,w]:graph[curr]){
//				earliest[next]=max(earliest[next],earliest[curr]+w);
//			}
//		}
//	}
//	void latestTime(vector<int>& latest,const vector<int>& revTopo){
//		for(int curr:revTopo){
//			for(auto [next,w]:graph[curr]){
//				latest[curr]=min(latest[curr],latest[next]-w);
//			}
//		}
//	}
//	public:
//		pair<int,vector<int>> criticalPath(int n){
//			vector<int> topo=topoSort(n);
//			if(topo.empty())return {-1,{}};
//			
//			vector<int> earliest(n,0);
//			earliestTime(earliest,topo);
//			
//			int totalTime=*max_element(earliest.begin(),earliest.end());
//			reverse(topo.begin(),topo.end());
//			
//			vector<int> latest(n,totalTime);
//			latestTime(latest,topo);
//		
//			vector<pair<int,int>> criticalActivties;
//			for(int curr=0;curr<n;curr++){
//				for(auto [next,w]:graph[curr]){
//					if(earliest[curr]==latest[next]-w){
//						criticalActivities.push_back({curr,next});
//					}
//				}
//			}
//			return {totalTime,criticalActivities};
//		}
//};

