#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isPrime(ll x){
	if(x<=3)return x>1;
	if(x%2==0 || x%3==0)return false;
	for(ll i=5;i*i<=x;i+=6)
		if(x%i==0 || x%(i+2)==0)return false;
	return true;
}
//搜索状态：计数、总和、下一个位置 
int n,k,ans=0,cnt=0;
ll sum=0;
vector<ll> vec;

void dfsSelect(int cur){
	if(cnt==k){
		if(isPrime(sum)){
			ans++;
		}
		return;
	}
	for(int i=cur;i<n;i++){
		sum+=vec[i];
		cnt++;
		dfsSelect(i+1);
		cnt--;
		sum-=vec[i];
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		ll num;cin>>num;
		vec.push_back(num);
	}
	dfsSelect(0);
	cout<<ans;
	return 0;
}
