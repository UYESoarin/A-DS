#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
int find(int x,unordered_map<int,int>& hub){return x==hub[x]?x:hub[x]=find(hub[x],hub);}
bool unite(int x,int y,unordered_map<int,int>& hub){
	int rx=find(x,hub),ry=find(y,hub);
	if(rx==ry)return false;
	hub[rx]=ry;
	return true;
}
int main(){
	vector<bool> res;
	int b1,b2;
	while(cin>>b1>>b2 && !(b1==-1 && b2==-1)){
		unordered_map<int,int> hub;
		set<int> urban;
		vector<pair<int,int>> path;
		int a=b1,b=b2;
		bool value=true;
		do{
			if(!hub.count(a)){
				hub[a]=a;
				urban.insert(a);
			}if(!hub.count(b)){
				hub[b]=b;
				urban.insert(b);
			}
			path.push_back({a,b});
			if(!unite(a,b,hub))value=false;//circleDetect
		}while(cin>>a>>b && !(a==0 && b==0));
		if(urban.size()-1!=path.size())value=false;//isTree/connectedDetect
		res.push_back(value);
	}
	for(bool val:res)cout<<(val?"Yes\n":"No\n");
	return 0;
}
