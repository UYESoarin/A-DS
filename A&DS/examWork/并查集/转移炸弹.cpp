#include<iostream>
#include<vector>
using namespace std;
vector<int> bomb;
vector<int> city;
int Find(int x){
	if(bomb[x]==x)return x;
	return bomb[x]=Find(bomb[x]);
}
void Union(int x,int y){
	int rootX=Find(x);
	int rootY=Find(y);
	if(rootX==rootY)cout<<"ERROR\n";
	else{
		bomb[rootX]=rootY;
		city[rootY]+=city[rootX];
	} 
}

int main(){
	int N,Q;
	cin>>N>>Q;
	city.resize(N+1,1);
	bomb.resize(N+1);
	for(int i=1;i<=N;i++){
		bomb[i]=i;
	}
	int op;
	while(Q-- && cin>>op){
		int a,b;
		if(op==1){
			cin>>a>>b;
			Union(a,b);
		}else if(op==2){
			cin>>a;
			cout<<Find(a)<<' '<<city[Find(a)]<<endl;
		}
	}
}
