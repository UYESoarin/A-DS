#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n;cin>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		pq.push(x);
	}
	int total=0;
	//leave OneRoot in pq
	while(pq.size()>1){
		int x=pq.top();pq.pop();
		int y=pq.top();pq.pop();
		int sum=x+y;
		total+=sum;
		pq.push(sum);
	}cout<<total;
	return 0;
}
