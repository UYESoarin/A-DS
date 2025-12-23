#include<iostream>
#include<list>
#include<vector>
#include<queue>>
using namespace std;
vector<list<int>> adj;
vector<bool> visited;

void DFS(int v){
	visited[v]=true;
	cout<<v<<' ';
	priority_queue<int,vector<int>,greater<int>> sequence;
	for(auto curr:adj[v]){
		if(!visited[curr]){
			sequence.push(curr);
			visited[curr]=true;
		}
	}
	while(!sequence.empty()){
		DFS(sequence.top());
		sequence.pop();
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	adj.resize(n);
	visited.resize(n,false);
	int a,b;
	while(e-- && cin>>a>>b){
		adj[a].push_front(b);
	} 
	DFS(0);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			DFS(i);
		}
	}
	return 0;
}
