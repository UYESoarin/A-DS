#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int>> frt;//greater > ×îÐ¡¶Ñ 
	int n,a;cin>>n;
	while(n-- && cin>>a)frt.push(a);
	int ans=0;
	while(frt.size()>1){
		int h1=frt.top();frt.pop();
		int h2=frt.top();frt.pop();
		ans+=h1+h2;
		frt.push(h1+h2);
	}cout<<ans;
	return 0;
}
