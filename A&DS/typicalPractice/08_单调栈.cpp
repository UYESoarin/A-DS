#include<iostream>
#include<numeric>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<long long> ai(N), Partial_sum(N+1,0);
	for(int i=0; i<N; i++){
		cin>>ai[i];
	}
	for(int i=0; i<N; i++){
		Partial_sum[i+1]=Partial_sum[i]+ai[i];
	}
	
	vector<long long> left(N,-1), right(N,N);
	stack<long long> procedure; 
	for(int i=0; i<N; i++){
		while(!procedure.empty() && ai[procedure.top()]>=ai[i]){
			procedure.pop();
		}
		if(!procedure.empty()){
			left[i]=procedure.top();
		}
		procedure.push(i);
	}
	while(!procedure.empty()){
		procedure.pop();
	}
	for(int i=N-1; i>-1; i--){
		while(!procedure.empty() && ai[procedure.top()]>=ai[i]){
			procedure.pop();
		}
		if(!procedure.empty()){
			right[i]=procedure.top();
		}
		procedure.push(i);
	}
	
	long long max_value=0;
	for(int i=0; i<N; i++){
		long long l=left[i]+1, r=right[i]-1;
		long long value=ai[i]*(Partial_sum[r+1]-Partial_sum[l]);
		if(max_value<value)max_value=value;
	}
	cout<<max_value;
	return 0;
}
