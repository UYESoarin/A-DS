#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n ; cin >> n;
	vector<ll> a(n+1,0),b(n,0),c(n,0);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i = 1 ; i < n ; i++) b[i] = a[i+1] - a[i];
	sort(b.begin(),b.end());
	for(int i = 1 ; i < n ; i++) c[i] = c[i-1] + b[i];
	int m; cin >>m;
	while(m--){
		ll l,r; cin >> l >> r;
		ll len = r - l + 1;
		int lo = lower_bound(b.begin() , b.end() , len) - b.begin() - 1 ; 
		ll ans = len*(n-lo) + c[lo];
		cout << ans << ' ';
	}
	return 0;
} 
