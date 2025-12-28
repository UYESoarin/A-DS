#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m; cin >> n >> m;
	vector<int> a(n);
	vector<int> pre(n+1,0);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	
	for(int i = 1 ; i <= n ; i++){
		pre[i] = pre[i-1] + a[i-1];
	}
	
	while(m--){
		int l,r ; cin >> l >> r;
		if((pre[r] - pre[l-1]) % 2 == 0) cout << 0 << '\n';
		else cout << 1 << '\n';
	}
	return 0;
}
