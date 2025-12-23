#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct Edge{
	int u,v,w;
	bool operator<(const Edge& e)const{return w<e.w;}
	Edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<Edge> edges;
vector<int> parent;

void initUF(int n){
	for(int i=0;i<n;i++)parent[i]=i;
}

int find(int x){
	return parent[x]==x?x:parent[x]=find(parent[x]);
}

bool unite(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx==ry)return false;
	parent[rx]=ry;
	return true;
}

int kruskal(int n){
	initUF(n);
	vector<Edge> es=edges;
	sort(es.begin(),es.end());
	int total=0,cnt=0;
	for(auto& e:es){
		if(unite(e.u,e.v)){
			total+=e.w;
			if(++cnt==n-1)break;
		}
	}
	return cnt==n-1?total:-1;
}
bool isMSTUnique(int n){
	initUF(n);
	vector<Edge> es=edges;
	sort(es.begin(),es.end());
	
	for(int i=0;i<es.size();){
		int j=i;
		while(j<es.size() && es[j].w==es[i].w)j++;
		int possible=0;
		for(int k=i;k<j;k++){
			if(find(es[k].u)!=find(es[k].v))possible++;
		}
		
		int selected=0;
		for(int k=i;k<j;k++){
			if(unite(es[k].u,es[k].v))selected++;
		}
		if(possible>selected)return false;
		i=j;
	}
	return true;
}
bool countComponents(int n){
	initUF(n);
	for(auto& e:edges)unite(e.u,e.v);
	set<int> roots;
	for(int i=0;i<n;i++)roots.insert(find(i));
	return roots.size();
}
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back(Edge(u-1,v-1,w));
	}
	int total=kruskal(N);
	if(total==-1){
		cout<<"No MST"<<endl<<countComponents(N)<<endl;
	}
	else{
		cout<<total<<endl;
		if(isMSTUnique(N))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}










 
