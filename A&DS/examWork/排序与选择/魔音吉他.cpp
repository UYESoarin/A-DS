#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
//Q: n个区间 [x[i]+l,x[i]+r] 并集包含整数个数  区间长度 r-l+1 
//预处理 + 排序 + 二分查找 + 前缀和
//并区间：
//	x[i+1]-x[i]<=d 无空隙 (空隙长度=0) 
//	x[i+1]-x[i]>d 空隙长度 (x[i+1]-(x[i]+d))-1 
//并集大小：
//	x[n-1]-x[0]+d+1-sumGap 
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	
	vector<ll> x(n);for(int i=0;i<n;i++)cin>>x[i];
	sort(x.begin(),x.end());
	
	vector<ll> gap;
	for(int i=1;i<n;i++)gap.push_back(x[i]-x[i-1]);
	sort(gap.begin(),gap.end());
	int m=gap.size();
	//前缀和：第i和 = 第i值+第i-1和 
	vector<ll> pre(m+1);
	for(int i=0;i<m;i++)pre[i+1]=pre[i]+gap[i];
	
	int q;cin>>q;
	while(q--){
		ll l,r;cin>>l>>r;
		if(l>r){
			cout<<"0 ";continue;
		}
		ll d=r-l;
		if(n==1){
			cout<<d+1<<" ";continue;
		}
		ll thr=d+1;
		//upper_bound 返回第一个较大值迭代器 
		int pos=upper_bound(gap.begin(),gap.end(),thr)-gap.begin();
		ll gapSum=0;
		//实际间距=总间距-总区间长度 
		if(pos<m)gapSum=pre[m]-pre[pos]-thr*(m-pos);
		ll ans=(x.back()-x.front()+d+1)-gapSum;
		cout<<ans<<" ";
	}
	return 0;
}
