#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
	vector<ll> a(n+1,0);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	vector<ll> pre(n+1,0);
	for(int i = 1 ; i <= n ; i++) pre[i] = pre[i-1] + a[i];
	
	stack<int> sl;
	vector<int> left(n+1,0);
	for(int i = 1 ; i <= n ; i++){
		while(!sl.empty() && a[sl.top()] >= a[i]) sl.pop();
		if(!sl.empty()) left[i] = sl.top();
		sl.push(i);
	}
	
	stack<int> sr;
	vector<int> right(n+1,n+1);
	for(int i = n ; i >= 1 ; i--){
		while(!sr.empty() && a[sr.top()] >= a[i]) sr.pop();
		if(!sr.empty()) right[i] = sr.top();
		sr.push(i);
	}
	
	ll max = 0;
	for(int i = 1 ; i <= n ;i++)
	{
		ll temp = a[i]*(pre[right[i]-1] - pre[left[i]]);
		if(temp > max) max = temp;
	}
	cout << max;
	return 0;
}
