#include<bits/stdc++.h>
using namespace std;
int num(const string& str){
	int n=1;
	for(auto ch:str)n*=(ch-'A')+1;
	return n;
}
int main(){
	string s,t;
	cin>>s>>t;
	cout<<((num(s)%47==num(t)%47)?"GO":"STAY");
	return 0;
}
