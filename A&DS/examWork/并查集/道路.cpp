#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
vector<bool> result; 
int Find(int x,unordered_map<int,int>& hub){
	if(hub[x]==x)return x;
	return hub[x]=Find(hub[x],hub); 
}
bool Union(int x,int y,unordered_map<int,int>& hub){
	int rootX=Find(x,hub);
	int rootY=Find(y,hub);
	//两点再添成环 
	if(rootX!=rootY){
		hub[rootX]=rootY;
		return true;
	}else return false;
}
int main(){
	int b1,b2;
	while(cin>>b1>>b2){
		if(b1==-1 && b2==-1)break;
		unordered_map<int,int> hub;
		set<int> urban;
		vector<pair<int,int>> path;
		int a=b1,b=b2;
		bool isTree=true;
		do{
			if(a==0 && b==0)break;
			if(!hub.count(a)){
				hub[a]=a;
				urban.insert(a);
			}
			if(!hub.count(b)){
				hub[b]=b;
				urban.insert(b);
			}
			path.push_back({a,b});
			if(!Union(a,b,hub)){
				isTree=false;
			}
		}while(cin>>a>>b);
		//节点间可达 
		if(urban.size()-1!=path.size())isTree=false;
		result.push_back(isTree);
	}
	for(auto isTree:result)cout<<(isTree?"Yes\n":"No\n");
	return 0;
} 
