#include<bits/stdc++.h>
using namespace std;
int answer_RECURSION(int a,int d){
	if(a==1)return d;
	return answer_RECURSION(a/2,++d);
}
int main(){
	int a;cin>>a;
	cout<<answer_RECURSION(a,1);
	return 0;
}
