#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	vector<int> a(n),b(m);
	//keepIdx notZero&Zero in array
	vector<int> aNum;
	vector<bool> isZero(n,false);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)isZero[i]=true;
		else aNum.push_back(a[i]);
	}for(int i=0;i<m;i++)cin>>b[i];
	sort(aNum.begin(),aNum.end());
	sort(b.begin(),b.end());
	vector<int> res(n);
	int ai=0,bi=0;
	for(int i=0;i<n;i++){
		if(isZero[i])res[i]=b[bi++];
		else res[i]=aNum[ai++];
	}
	for(int i=1;i<n;i++){
		if(res[i]<=res[i-1]){
			cout<<-1;return 0;
		}
	}for(int i=0;i<n;i++)cout<<res[i]<<' ';
	return 0;
}
