#include<bits/stdc++.h>
using namespace std;
int main(){
	int m;
	string n;
	cin>>m>>n;
	bool isfirst=true;
	for(int i=0;i<n.size();i++){
		if(n[i]-'0'){
			if(!isfirst)cout<<"+";
			cout<<n[i]<<"*"<<m<<"^"<<n.size()-1-i;
			isfirst=false;
		}
	}
	return 0;
} 
