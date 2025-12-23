#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//ArraySize 2n-1
struct Node{
	int data;
	Node* L;
	Node* R;
	Node(int d):data(d),L(NULL),R(NULL){}
	Node(int d,Node* l,Node* r):data(d),L(l),R(r){}
};
struct pqNode_Compare{
	bool operator()(const Node* n1,const Node* n2)const{
		return n1->data>n2->data;
	}
};
priority_queue<Node*,vector<Node*>,pqNode_Compare> dataSet;
vector<Node*> huffManT;
void getdata(int data){
	Node* Nd=new Node(data);
	dataSet.push(Nd);
}
Node* buildHuffManT(){
	while(dataSet.size()>1){
		Node* L=dataSet.top();
		dataSet.pop();
		Node* R=dataSet.top();
		dataSet.pop();
		Node* P=new Node(L->data+R->data,L,R);
		dataSet.push(P);
	}
	return dataSet.empty()?NULL:dataSet.top(); 
}
void preOrder(Node* root){
	if(!root)return ;
	cout<<root->data<<' ';
	preOrder(root->L);
	preOrder(root->R);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int data;
		cin>>data;
		getdata(data);
	}
	Node* root=buildHuffManT();
	preOrder(root);
	return 0;
}
