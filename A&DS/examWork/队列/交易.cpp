#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	queue<int> q;
	vector<int> res;
	for(int i=1;i<=n;i++)q.push(i);
	while(q.size()>1){
		res.push_back(q.front());q.pop();
		q.push(q.front()),q.pop();
	}
	if(!res.empty()){
		for(int i=0;i<res.size();i++){
			if(i)cout<<" ";
			cout<<res[i];
		}cout<<endl;
	}cout<<q.back();
}
