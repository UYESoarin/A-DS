#include<iostream>
#include<vector>
#include<queue>
#define VALID src>=0 && src<V && dest>=0 && dest<V
using namespace std;
//Adjacency_Marix_Graph
class AdjMatrixGraph{
	int V;
	vector<vector<int>> adj;
	bool directed;
	
	public:
		//constructor
		AdjMatrixGraph(int vertices,bool isDirected=false)
		:V(vertices),directed(isDirected){
			adj.resize(V,vector<int>(V,0));
		}
		
		//edge operation
		void addEdge(int src,int dest,int weight=1){
			if(VALID){
				adj[src][dest]=weight;
				if(!directed){
					adj[dest][src]=weight;
				}
			}
		}
		
		void removeEdge(int src,int dest){
			if(VALID){
				adj[src][dest]=0;
				if(!directed){
					adj[dest][src]=0;
				}
			}
		}
		
		//basic parameter
		bool hasEdge(int src,int dest){
			if(VALID){
				return adj[src][dest]!=0;
			}
			return false;
		}
		
		int getweight(int src,int dest){
			if(VALID)return adj[src][dest];
			return 0;
		}
		
		//Row&Column print
		void printMatrix()const{
			cout<<"AdjMatrixGraph:"<<endl<<"   ";			
			for(int i=0;i<V;i++)cout<<i<<' ';
			cout<<endl;
			for(int i=0;i<V;i++){
				cout<<i<<": ";
				for(int j=0;j<V;j++){
					cout<<adj[i][j]<<' ';
				}cout<<endl; 
			} 
		}
		
		//search
		void BFS(int start){
			vector<bool> visited(V,false);
			queue<int> q;
			
			cout<<"BFS:";
			visited[start]=true;
			q.push(start);
			
			while(!q.empty()){
				int curr=q.front();
				q.pop();
				cout<<curr<<' ';
				
				for(int i=0;i<V;i++){
					if(adj[curr][i]!=0 && !visited[i]){
						visited[i]=true;
						q.push(i);
					}
				} 
			}
			cout<<endl;
		}
		void DFS(int start){
			vector<bool> visited(V,false);
			cout<<"DFS(Rescusive):"
			DFSRescusive(start,visited);
			cout<<endl;
		}
		
		//degree
		int getDegree(int v)const{
			if(directed || v>=V)return -1;
			int degree=0;
			for(int i=0;i<V;i++){
				if(adj[v][i]!=0)degree++;
			}
			return degree;
		} 
		pair<int,int> getInOutDegree(int v){
			int inDegree=0,outDegree=0;
			if(v>=0 && v<V){
				for(int i=0;i<V;i++){
					if(adj[i][v]!=0)inDegree++;
					if(adj[v][i]!=0)outDegree++;
				}
			}
			return {inDegree,outDegree};
		} 
		private:
			void DFSRescusive(int v,vector<bool>& visited£©{
				visited[v]=true;
				cout<<v<<' ';
				
				for(int i=0;i<V;i++){
					if(adj[v][i]!=0 && !visited[i]){
						DFSRescusive(i,visited);
					} 
				}
				
			} 
};
