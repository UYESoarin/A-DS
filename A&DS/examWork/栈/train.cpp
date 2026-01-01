#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	//string simulate in&outQueue
	string in,out;
	cin>>in>>out;
	//stack simulate in&outOperation with stringIdxMove
	stack<int> st;
	vector<string> res;
	int i=0,j=0;
	while(i<n || j<n){
		if(!st.empty() && st.top()==out[j]){
			st.pop();
			res.push_back("out");
			j++;
		}else if(i<n){
			st.push(in[i]);
			res.push_back("in");
			i++;
		}else{//(i==n && j<n) && (st.empty() || st.top()!=out[j]) 
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(const auto& op:res)cout<<op<<endl;
	return 0;
}
