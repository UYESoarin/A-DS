#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int d):data(d),left(NULL),right(NULL){}
}; 


class Tree{
	private:
		
		
		void print(Node* node , string& ans){
			if(node == NULL) return;
			ans += to_string(node->data);
			if(node->left != NULL){
				ans += "<" ;
				print(node->left,ans);
				ans += ">" ;
			}
			
			if(node->right != NULL){
				ans += "<";
				print(node->right,ans);
				ans += ">";
			}
		}
		
		public:
			Node* root;
			string getans(){
				string ans;
				print(root,ans);
				return ans;
			}
			
			Tree():root(NULL){}
};
int main(){
	Tree tree ;
	int n;cin>>n;
	vector<int> a;
	
	for(int i = 0 ; i < n ; i++){
		int t;cin>>t;
		a.push_back(t);
	}
	
	
	for(auto it = a.rbegin() ; it != a.rend() ; ++it){
		Node* p = tree.root;
		while(p!=NULL){
			if(*it > p->data) p = p->right;
			else p = p->left;
		} 
		p = new Node(*it);
	}
	
	cout << tree.getans() ;
	return 0;
}
