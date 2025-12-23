#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//unordered_map<int,int> pos;
vector<int> pre;
bool isBST(vector<int>& pre,int b,int e){
	if(b>=e)return true;
	int root=pre[b],mid;
	for(mid=b+1;mid<=e;mid++){
		if(pre[mid]>=root)break;
	}
	for(int i=mid;i<=e;i++){
		if(pre[i]<root)return false;
	}
	return isBST(pre,b+1,mid-1)*isBST(pre,mid,e); 
}
bool isBST(vector<int>& pre,int b,int e,bool mirror){
	if(b>=e)return true;
	int root=pre[b],mid;
	for(mid=b+1;mid<=e;mid++){
		if(pre[mid]<root)break;
	}
	for(int i=mid;i<=e;i++){
		if(pre[i]>=root)return false;
	}
	return isBST(pre,b+1,mid-1,1)*isBST(pre,mid,e,1); 
}
void build(vector<int>& pre,int b,int e,int idx){
//	if(b<=e)pos[idx]=pre[b];
//	else return ;
	if(b>e)return ;
	int mid;
	for(mid=b+1;mid<=e;mid++){
		if(pre[mid]>pre[b])break;
	}
	if(b+1<=e && pre[b+1]<pre[b])build(pre,b+1,mid-1,idx*2);
	if(mid<=e && pre[mid]>pre[b])build(pre,mid,e,idx*2+1);
	cout<<pre[b];
	if(idx!=1)cout<<' ';
}
void build(vector<int>& pre,int b,int e,int idx,int mirror){
	if(b>e) return ;
	int mid;
	for(mid=b+1;mid<=e;mid++){
		if(pre[mid]<pre[b])break;
	}
	if(b+1<=e && pre[b+1]>pre[b])build(pre,b+1,mid-1,idx*2,1);
	if(mid<=e && pre[mid]<pre[b])build(pre,mid,e,idx*2+1,1);
	cout<<pre[b];
	if(idx!=1)cout<<' ';
}
//void postorder(int idx){
//	if(pos.count(idx)){
//		postorder(idx*2);
//		postorder(idx*2+1);
//		cout<<pos[idx];
//		if(idx!=1)cout<<' ';
//	}
//}
int main(){
	int n;
	cin>>n;
	pre.resize(n);
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	if(pre.size()==1)cout<<"YES\n"<<pre[0];
	else{
		if(pre[1]>pre[0]){
			if(!isBST(pre,0,pre.size()-1,1)){
				cout<<"NO";
			}else{
				cout<<"YES\n";
				build(pre,0,pre.size()-1,1,1);
//				postorder(1);
			}
		}
		else{
			if(!isBST(pre,0,pre.size()-1)){
				cout<<"NO";
			}else{
				cout<<"YES\n";
				build(pre,0,pre.size()-1,1);
//				postorder(1);
			}
		}
	}
	return 0;
} 
