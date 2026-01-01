#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	//前缀和预处理 
	vector<int> arr(n+1);
	for(int i=1;i<arr.size();i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int l,r;
	//奇偶异或算法 
	vector<int> result;
	while(m-- && cin>>l>>r)result.push_back((arr[r]-arr[l-1])%2);
	
	for(auto value:result)cout<<value<<endl;
	return 0;
} 
