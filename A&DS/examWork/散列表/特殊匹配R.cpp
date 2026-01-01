#include<iostream>
#include<string>
#include<unordered_set>
#include<functional>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	unordered_set<string> strSet;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		strSet.insert(s);
	}
	vector<string> res;
	while(m--){
		string s;cin>>s;
		bool value=false;
		for(const string& t:strSet){
			if(s.size()!=t.size())continue;
			
			int sum=0;
			function<void(int,int)> binaryS=[&](int l,int r){
				if(l>r || sum>1)return;
				int mid=(r-l)/2+l;
				if(s[mid]!=t[mid])sum++;
				binaryS(l,mid-1);
				binaryS(mid+1,r);
			};
			
			binaryS(0,s.size()-1);
			if(sum==1){
				value=true;
				break;
			}
		}res.push_back((value?"YES":"NO"));
//	TL
//		bool value=false;
//		for(int i=0;i<s.size();i++){
//			char origin=s[i];
//			for(char ch='a';ch<='c';ch++){
//				if(ch==origin)continue;
//				string t=s;
//				t[i]=ch;
//				if(strSet.count(t)){
//					value=true;
//					break;
//				}
//			}
//			if(value)break;
//		}
	}
	for(const auto& s:res)cout<<s<<endl;
	return 0;
} 
