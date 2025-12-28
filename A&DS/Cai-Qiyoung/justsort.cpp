#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n; int m; cin >> m;
	int a[100009],b[100009],c[100009];
	int j = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		if(a[i]) b[j++] = a[i];
	}
	sort(b,b+j);
	for(int i = 0 ; i < m ; i++) cin >> c[i];
	sort(c,c+m);
	j=0;
	int x = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i]) a[i] = b[j++];
		else a[i] = c[x++];
	}
	int flag = 0;
	for(int i = 1 ; i < n ; i++){
		if(a[i] <= a[i-1]){
			flag = 1;
			break;
		}
	}
	if(!flag){
		for(int i = 0 ; i < n ; i++) cout << a[i] << ' ';
	} else {
		cout << -1 ;
	}
	return 0;
}
