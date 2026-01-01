#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int val;
	Node* left,*right;
	Node(int x):val(x),left(nullptr),right(nullptr){}
};
//buildBSTbyPost
vector<int> post;
Node* build(int l,int r){
	if(l>r)return nullptr;
	Node* root=new Node(post[r]);//lastAsRootinPost
	int i=l;
	while(i<r && post[i]<post[r])i++;//endWhenBigger
	//Spread: l~i-1(smaller)  i~r-1(bigger)  r(root)
	root->left=build(l,i-1);
	root->right=build(i,r-1);
	return root;
}
//prevSearch
void prev(Node* root){
	if(!root)return ;
	cout<<root->val;
	if(root->left){cout<<"<";prev(root->left);cout<<">";}
	if(root->right){cout<<"<";prev(root->right);cout<<">";}
}
int main(){
	int n;cin>>n;
	post.resize(n);
	for(int i=0;i<n;i++)cin>>post[i];
	Node* root=build(0,n-1);
	prev(root);
	return 0;
}
