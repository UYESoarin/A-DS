#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<int> num;
int find(int x){return x==parent[x]?x:parent[x]=find(parent[x]);};
bool unite(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx==ry)return false;
	parent[rx]=ry;
	num[ry]+=num[rx];
	num[rx]=0;
	return true;
}
int main(){
	int n,q;cin>>n>>q;
	parent.resize(n+1);
	num.resize(n+1,1);
	for(int i=1;i<=n;i++)parent[i]=i;
	while(q--){
		int op;cin>>op;
		if(op==1){
			int a,b;cin>>a>>b;
			if(!unite(a,b))cout<<"ERROR\n";
		}if(op==2){
			int a;cin>>a;
			int ra=find(a);
			cout<<ra<<' '<<num[ra]<<endl;
		}
	}
	return 0;
}

