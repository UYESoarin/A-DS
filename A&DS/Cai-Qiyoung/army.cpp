#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	vector<list<long long>> am(n+1);
	for(int i = 1 ; i<=n ; i++){
		int k ; cin >> k;
		for(int j = 0 ; j < k ; j++){
			long long x ; cin >> x;
			am[i].push_back(x);
		}
	}
	
	int a,b;
	long long x;
	for(int i = 0 ; i < m ; i++){
		char op; cin >> op;
		if(op == 'U'){
			cin >> a >> b;
			am[a].splice(am[a].end(),am[b]);
		} else  if (op == 'I'){
			cin >> a >> x;
			am[a].push_front(x);
		} else if(op == 'D') {
			cin >> a >> x;
			am[a].remove(x);
		} else {
			cin >> a;
			if(am[a].empty()) cout << -1 << endl;
			else{
				auto it = am[a].begin();
				cout << *it ;
				++it;
				for(; it != am[a].end() ; ++it)
				{
					cout << ' ' << *it;
				}
				cout << endl;
			}
		}
	}
	return 0;
} 
