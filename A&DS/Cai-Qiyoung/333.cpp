#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int from;
	int to;
	double weight;
	edge(int f, int t, double w) : from(f), to(t), weight(w) {}
};

class point{
	public:
		int x,y;
		point(int a,int b):x(a),y(b){}
		point() : x(0), y(0) {}
		double dis(const point& a){
			return sqrt(pow(a.x-this->x , 2)+ pow(a.y-this->y , 2));
		}
}; 

int parent[6000];

int find(int x){
	if(x != parent[x]) parent[x] = find(parent[x]);
	return parent[x];
}

void unite(int a,int b){
	parent[find(b)] = find(a);
}

bool cmp(const edge a , const edge b){
	return a.weight < b.weight;
}

int main()
{
    int n; cin >> n;
    vector<edge> edges;
    for(int i = 0 ; i < n ; i++) parent[i] = i;
    vector<point> points(n);
    for(int i = 0 ; i < n ; i++){
    	int x,y; cin >> x>>y;
    	points[i] = point(x,y);
    }
    for(int i = 0 ; i < n ; i++){
    	for(int j = 0 ; j < n ; j++){
    		double distance = points[i].dis(points[j]);
            edges.emplace_back(i, j, distance);
		}
	}
	sort(edges.begin(),edges.end(),cmp);
	
	double total = 0;
	
	for(auto e : edges){
		if(find(e.from) != find(e.to)){
			unite(e.from,e.to);
			total  += e.weight;
		}
	}
	
	printf("%.2lf",total);
    

    return 0;
}
