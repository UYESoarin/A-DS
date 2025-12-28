#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	stack<int> in;
	string ans[100];
	string s0,s1; cin>>s0>>s1;
	
	int j = 0;
	int x = 0; 

	for(int i = 0 ; i < n ; i++){
		in.push(s0[i]);
		ans[j++] = "in";
		while(!in.empty() && in.top() == s1[x]){
			in.pop();
			ans[j++] = "out";
			x++;
		}
	} 
	if(!in.empty()){
		cout<<"No";
		return 0;
	} else {
		cout << "Yes" << endl;
		for(int i = 0 ; i < j ; i++){
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}
