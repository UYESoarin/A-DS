#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> makeV(n+1);
	vector<int> meltV(n+1);
	for(int i=1;i<=n;i++)cin>>makeV[i];
	for(int i=1;i<=n;i++)cin>>meltV[i],meltV[i]+=meltV[i-1];
	priority_queue<int,vector<int>,greater<int>> snowMan;
	vector<int> res(n+1);
	for(int i=1;i<=n;i++){
		//owe for pay
		snowMan.push(makeV[i]+meltV[i-1]);
		while(!snowMan.empty() && meltV[i]>=snowMan.top()){
			res[i]+=snowMan.top()-meltV[i-1];
			snowMan.pop();
		}res[i]+=snowMan.size()*(meltV[i]-meltV[i-1]);
	}for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	return 0;
}
