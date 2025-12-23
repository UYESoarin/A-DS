#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;
template <typename T>
class UnionFindSet{
	private:
		unordered_map<T,T> parent;//UFset
		unordered_map<T,int> setSize;
		int setCount;
	public:
		UnionFindSet():setCount(0){}
		void Insert(T ele){
			if(!parent.count(ele)){
				parent[ele]=ele;
				setSize[ele]=1;
				setCount++;
				//set<T> element.insert(ele);
			}else cout<<"It has been exist!\n";
		}
		T Find(T x){
			if(parent.find(x)==parent.end())Insert(x);
			if(parent[x]==x)return x;
			return parent[x]=Find(parent[x]);
		}
		void Union(T x,T y){
			T rootX=Find(x);
			T rootY=Find(y);
			if(rootX!=rootY){
				if(setSize[rootX]<setSize[rootY]){
					parent[rootX]=rootY;
					setSize[rootY]+=setSize[rootX];
				}else{
					parent[rootY]=rootX;
					setSize[rootX]+=setSize[rootY];
				} 
				setCount--;
			}
		}
		vector<T> getElementVector(){
			vector<T> element;
			for(auto& p:parent){//pair<T,T> p
				element.push_back(p.first);
			}return element;
		}
		set<T> getRootSet(){
			set<T> root;
			for(auto& p:parent){
				if(p.first==p.second)root.insert(p.first);
			}return root;
		}
		int getSetSize(T x){
			return setSize[Find(x)];
		}
		bool isConnected(T x,T y){
			return Find(x)==Find(y);
		}
};
int main(){
	UnionFindSet<string> ufset;
	int N;
	cin>>N;
	string name;
	while(N--){
		cin>>name;
		ufset.Insert(name);
	}
	int M;
	cin>>M;
	string n1,n2;
	while(M--){
		cin>>n1>>n2;
		ufset.Union(n1,n2);	
	}
	set<string> root=ufset.getRootSet();
	int maxSize=0;
	for(auto& name:root){
		maxSize=max(maxSize,ufset.getSetSize(name));
	}
	cout<<root.size()<<' '<<maxSize;
}
