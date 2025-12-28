#include<bits/stdc++.h> 
using namespace std;

struct Edge{
	int from;
	int to;
	int cost;
};

bool cmp(Edge& a , Edge& b){
	return a.cost < b.cost;
}

int parent[1000];

int find(int x){
	if(parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void unite(int a , int b){
	parent[find(b)] = find(a);
}

int main() {
	int n,m;
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		parent[i] = i;
	}
	
	vector<Edge> edges;
	
	for(int i = 0 ; i < n ; i++){
		int from,to,weight;
		cin >> from >> to >> weight;
		edges.emplace_back(from,to,weight);
	}     
	
	sort(edges.begin(),edges.end(),cmp);
	
	int total = 0;
	
	for(auto edge : edges){
		if(find(edge.from) != find(edge.to)){
			unite(edge.from,edge.to);
			total += edge.cost;
		}
	}
	
	int root = parent[0];
	for(int i = 0 ; i < n ; i++){
		if(parent[i] != root){
			cout << "Impossible" ;
			return 0;
		}
	}
	
	cout << total;

    return 0;
}
