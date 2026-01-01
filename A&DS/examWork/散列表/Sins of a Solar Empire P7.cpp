#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(){
	int n;cin>>n;
	set<int> allnum;
	map<int,int> cnt;
	for(int i=0;i<n;i++){
		int m;cin>>m;
		set<int> unique;
		//同星球可能重复资源 
		while(m--){
			int A;cin>>A;
			unique.insert(A);
		}//统计单种资源 
		for(auto num:unique){
			cnt[num]++;
			allnum.insert(num);
		}
	}
	set<int> res;
	//所有满存资源 
	for(auto num:allnum){
		if(cnt[num]==n)res.insert(num);
	}cout<<res.size()<<endl;
	bool first=true;
	for(auto num:res){
		if(!first)cout<<' ';
		first=false;
		cout<<num;
	}return 0;
}
