#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
	vector<ll> a(n+1,0);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a.begin()+1,a.end());
	vector<ll> b(n);
	for(int i = 1 ; i < n ; i++) b[i] = a[i+1] - a[i];
	sort(b.begin()+1,b.end());
	vector<ll> pre(n);
	for(int i = 1 ; i < n ; i++) pre[i] = pre[i-1] + b[i];
	
	int m ; cin >> m;
	while(m--){
		ll l,r; cin>>l>>r;
		ll len = r-l+1;
		ll lo = lower_bound(b.begin()+1,b.end(),len) - b.begin() - 1;
		ll ans = len*(n-lo) + pre[lo];
		cout << ans << ' ';
	}
	
	return 0;
}
