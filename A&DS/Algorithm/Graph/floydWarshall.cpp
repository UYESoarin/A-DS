#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;

//#define INF INT_MAX / 2

class FloydWarshallAllApply{
	private:
		const int INF=INT_MAX/2;
		
		vector<vector<int>> dist;
		vector<vector<set<int>>> next;
		vector<vector<int>> cost;	
		vector<vector<long long>> count;
		int V;
		
		void initDataStructures();
		void initDiagonal();
		
	public:
		FloydWarshallAllApply(int );
		FloydWarshallAllApply(int,const vector<vector<int>>& ,const vector<vector<int>>& );
		void Floyd();
		vector<vector<int>> getAllPaths(int ,int );
		vector<int> getSinglePath(int ,int );
		void printPathInfo(int ,int );
		void printDistMatrix();
		bool hasNegativeCycle();
		
		int getDist(int src,int dest){return dist[src][dest];}
		int getCost(int src,int dest){return cost[src][dest];}
		long long getPathCount(int src,int dest){return count[src][dest];}
		
		static void Main(){
			cout<<"=== Floyd-Warshall Algorithm Application Instance ==="<<endl;
			cout<<"Input number of vertices: ";
			int V;
			cin>>V;
			
			FloydWarshallAllApply floyd(V);
			floyd.Floyd();
			
			int src,dest;
			cout<<"\nInput source and destination to inquire (formate: src dest): ";
			cin>>src>>dest;
			
			floyd.printPathInfo(src,dest);
			
			cout<<"\nWhether to print DistMatrix or not?(1 = Yes, 0 = No): ";
			int choice;
			cin>>choice;
			if(choice){
				floyd.printDistMatrix();
			}
		}
};


int main(){
	FloydWarshallAllApply::Main();
	return 0;
}

void FloydWarshallAllApply::initDataStructures(){
	dist.assign(V,vector<int>(V,INF));
	next.assign(V,vector<set<int>>(V));
	cost.assign(V,vector<int>(V,INF));
	count.assign(V,vector<long long>(V,0));
}

void FloydWarshallAllApply::initDiagonal(){
	for(int i=0;i<V;i++){
		dist[i][i]=0;
		cost[i][i]=0;
//		next[i][i].clear();
		count[i][i]=1;
	}
}

FloydWarshallAllApply::FloydWarshallAllApply(int vertices):V(vertices){
	initDataStructures();
	initDiagonal();
	cout<<"Input edge information (Format: src dest weight fee), finish with -1 -1: "<<endl;
	int src,dest,weight,fee;
	while(cin>>src>>dest>>weight>>fee && src!=-1 && dest!=-1){
		if(src>=0 && src<V && dest>=0 && dest<V){
			dist[src][dest]=weight;
			cost[src][dest]=fee;
			count[src][dest]=1;
			next[src][dest].insert(dest);
		}else cout<<"Invalid node"<<endl;
	}
}

FloydWarshallAllApply::FloydWarshallAllApply(int vertices,
const vector<vector<int>>& initDist,const vector<vector<int>>& initCost):V(vertices){
	initDataStructures();
	initDiagonal();
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i!=j && initDist[i][j]!=INF){
				dist[i][j]=initDist[i][j];
				cost[i][j]=initCost[i][j];
				count[i][j]=1;
				next[i][j].insert(j);
			}				
		}
	}
}

void FloydWarshallAllApply::Floyd(){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			if(dist[i][k]==INF)continue;
			for(int j=0;j<V;j++){
				if(dist[k][j]==INF)continue;
				if(k==i || k==j)continue;
				int newDist=dist[i][k]+dist[k][j];
				int newCost=cost[i][k]+cost[k][j];
				if(newDist<dist[i][j]){
					dist[i][j]=newDist;
					cost[i][j]=newCost;
					count[i][j]=count[i][k]*count[k][j];
					next[i][j]=next[i][k];
				}
				else if(newDist==dist[i][j]){
					count[i][j]+=count[i][k]*count[k][j];
					for(auto node:next[i][k]){
						next[i][j].insert(node);
					}
					if(newCost<cost[i][j]){
						cost[i][j]=newCost;
					}
				}
			}
		}
	}
}

vector<vector<int>> FloydWarshallAllApply::getAllPaths(int src,int dest){
	vector<vector<int>> allpath;
	vector<int> currpath;
	if(dist[src][dest]==INF)return allpath;
	if(src==dest){
		allpath.push_back({src}); 
		return allpath;
	}
	function<void(int,int)> dfs=[&](int curr,int target){
		currpath.push_back(curr);
		if(curr==target)allpath.push_back(currpath);
		else{
			for(auto node:next[curr][target]){
				dfs(node,target);
			}
		}currpath.pop_back();
	};
	dfs(src,dest);
	return allpath;
}

vector<int> FloydWarshallAllApply::getSinglePath(int src,int dest){
	vector<int> path;
	if(dist[src][dest]==INF)return path;
	if(src==dest){
		path.push_back(src);
		return path;
	}
	int curr=src;
	path.push_back(curr);
	while(curr!=dest){
		if(next[curr][dest].empty()){
			return vector<int>();
		}
		int nextNode=*next[curr][dest].begin();
		path.push_back(nextNode);
		curr=nextNode;
	}
	return path;
}

void FloydWarshallAllApply::printPathInfo(int src,int dest){
	cout<<"\n"<<src<<" to "<<dest<<" information: "<<endl;
	if(dist[src][dest]==INF){
		cout<<"No path"<<endl;
		return ;	
	}
	cout<<"minDistance: "<<dist[src][dest]<<endl;
	cout<<"minCost: "<<cost[src][dest]<<endl;
	cout<<"pathCount: "<<count[src][dest]<<endl;
	
	vector<vector<int>> allpath=getAllPaths(src,dest);
	if(allpath.empty()){
		cout<<"No path found"<<endl;
		return;
	}
	cout<<"allPath ("<<allpath.size()<<"): "<<endl;
	for(int i=0;i<allpath.size();i++){
		cout<<"Path "<<i+1<<": ";
		for(int j=0;j<allpath[i].size();j++){
			cout<<allpath[i][j];
			if(j<allpath[i].size()-1)cout<<"->";
		}
		int pathCost=0;
		for(int j=0;j<allpath[i].size()-1;j++){
			int u=allpath[i][j];
			int v=allpath[i][j+1];
			pathCost+=cost[u][v];
		}
		cout<<"(cost: "<<pathCost<<")"<<endl;
	}
}

void FloydWarshallAllApply::printDistMatrix(){
	cout<<"\nDistMatrix:"<<endl;
	cout<<"\t";
	for(int i=0;i<V;i++){
		cout<<i<<"\t";
	}cout<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<":\t";
		for(int j=0;j<V;j++){
			if(dist[i][j]==INF)cout<<"INF\t";
			else cout<<dist[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool FloydWarshallAllApply::hasNegativeCycle(){
	for(int i=0;i<V;i++){
		if(dist[i][i]<0)return true;
	}
//	vector<vector<int>> prev=dist;
//	Floyd();
//	for(int i=0;i<V;i++){
//		for(int j=0;j<V;j++){
//			if(dist[i][j]<prev[i][j]){
//				return true;
//			}
//		}
//	}		
	return false;
}
