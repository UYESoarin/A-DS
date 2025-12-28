#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	list<int> d;
	vector<int> ans;
	
	for(int i = 1 ; i <= n ; i++){
		d.push_back(i);
	}
	
	while(d.size() != 1){
		ans.push_back(d.front());
		d.pop_front();
		d.push_back(d.front());
		d.pop_front();
	}
	
	if(!ans.empty()){
		for(int i : ans){
		cout<<i<<' ';
		}
		cout<<endl;
	}
	
	cout<<d.front();
	return 0;
}
