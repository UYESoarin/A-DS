#include<iostream>
#include<vector>
#include<map>
using namespace std;
//vector<int> pre,in,post;
vector<int> pre,post;
map<int,int>in;
void build(int postl,int postr,int inl,int inr){
	if(postl>postr)return;
	int root=post[postr];
	pre.push_back(root);
//	int i;
//	for(i=inl;i<=inr;i++){
//		if(in[i]==root)break;
//	}
	int i=in[root];
	int leftsize=i-inl;
	build(postl,postl+leftsize-1,inl,i-1);
	build(postl+leftsize,postr-1,i+1,inr);
}
int main(){
	int n;
	cin>>n;
	post.resize(n);
//	in.resize(n);
	for(int i=0;i<n;i++)cin>>post[i];
//	for(int i=0;i<n;i++)cin>>in[i];
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		in[data]=i;
	}
	build(0,n-1,0,n-1);
	cout<<"Preorder:";
	for(int i=0;i<n;i++){
		cout<<' '<<pre[i];
	}
	return 0;
} 
