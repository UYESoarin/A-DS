#include<iostream>
#include<vector>
#include<stack>
#define ll long long
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<ll> a(N+1);
	//partial_sum(ps[0]=0 for compute): 0, 1~N
	vector<ll> ps(N+1);
	for(int i=1;i<=N;i++)cin>>a[i],ps[i]=ps[i-1]+a[i];
	//doubleSides firstSmaller elementIdx
	vector<int> left(N+1,0);
	vector<int> right(N+1,N+1);
	stack<int> st;
	for(int i=1;i<=N;i++){
		while(!st.empty() && a[st.top()]>=a[i])st.pop();
		left[i]=st.empty()?0:st.top();
		st.push(i);
	}while(!st.empty())st.pop();
	for(int i=N;i>=1;i--){
		while(!st.empty() && a[st.top()]>=a[i])st.pop();
		right[i]=st.empty()?N+1:st.top();
		st.push(i);
	}
	ll ans=0;
	for(int i=1;i<=N;i++){
	//a[i] asMinRange: [left[i]+1,right[i]-1]
		int r=right[i]-1;
		int l=left[i]+1;
		ans=max(ans,(ps[r]-ps[l-1])*a[i]);
	}cout<<ans;
	return 0;
}
