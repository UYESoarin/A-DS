#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> topoSort(int n,vector<vector<int>>& adj){
	vector<int> indegree(n,0);
	for(auto& curr:adj)
		for(auto next:curr)indegree[next]++;
	
	queue<int> q;
	for(int i=0;i<n;i+)if(indegree[i]==0)q.push(i);
	
	vector<int> res;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		res.push_back(curr);
		for(auto next:adj[curr])if(--indegree[next]==0)q.push(next);
	}
	return res.size()==n?res:vector<int>();
} 
