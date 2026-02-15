#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<functional>
#include<set>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct Vertex{
	int x,y;
	Vertex(int x=0,int y=0):x(x),y(y){}//add default value for map
	bool operator==(const Vertex& other)const{
		return x==other.x && y==other.y;
	}
	bool operator!=(const Vertex& other)const{
		return x!=other.x || y!=other.y;
	}
	bool operator<(const Vertex& other)const{
        if(x!=other.x) return x<other.x;
        return y<other.y;
    }//add compare funcion for set
};
struct Edge{
	Vertex p,q;
	double len;
	Edge(const Vertex& p,const Vertex& q):p(p),q(q){
		int dx=p.x-q.x;
		int dy=p.y-q.y;
		len=sqrt(dx*dx+dy*dy);
	}
	bool operator<(const Edge& other)const{
        return len<other.len;
    }
};
int main(){
	int n;
	cin>>n;
	set<Vertex> vertices;//avoid repead
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		vertices.insert(Vertex(x,y));
	}
	vector<Vertex> V;
	for(const auto& u:vertices){
		V.push_back(u);
	}
	vector<Edge> edges;
	for(int i=0;i<V.size();i++){
		for(int j=i+1;j<V.size();j++){
			edges.emplace_back(V[i],V[j]); 
		}
	}
	//kruskal
	sort(edges.begin(),edges.end());
	double total=0;
	int vnum=vertices.size();
	int cnt=0;
	map<Vertex,Vertex> parent;
	for(const auto& v:vertices){
		parent[v]=v;
	}
	function<Vertex(const Vertex&)> find=[&](const Vertex& p){
		return parent[p]==p?p:parent[p]=find(parent[p]);
	};
	for(const auto& e:edges){
		Vertex rp=find(e.p);
		Vertex rq=find(e.q);
		if(rp!=rq){
			parent[rp]=rq;
			total+=e.len;
			if(++cnt==vnum-1)break;
		}
	}
	cout<<fixed<<setprecision(2)<<total<<endl;
	return 0;
}
