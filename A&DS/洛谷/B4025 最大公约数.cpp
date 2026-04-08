#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
	//while(b!=0)int t=b,b=a%b,a=t;return a;
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	ll a,b;cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
