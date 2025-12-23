#include<iostream>
#include<queue>
using namespace std;
struct Message{
	string name;
	int degree;
	Message(string str,int d):name(str),degree(d){}
	bool operator<(const Message& other)const{
		return degree>other.degree;
	}
};
struct Cmp{
	bool operator()(Message& m1,Message& m2){
		return m1.degree>m2.degree; 
	}
};
int main(){
//	priority_queue<Message,vector<Message>,Cmp> pq;//function object 
	vector<string> result;
	priority_queue<Message> pq;//override less operator 
	int n;
	cin>>n;
	string op;
	while(n--){
		cin>>op;
		if(op=="PUT"){
			string name;
			int d;
			cin>>name>>d;
			Message m(name,d);
			pq.push(m);
		}else if(op=="GET"){
			if(pq.empty())
//			cout<<"EMPTY QUEUE!\n";
			result.push_back("EMPTY QUEUE!"); 
			else{
//				cout<<pq.top().name<<'\n';
				result.push_back(pq.top().name); 
				pq.pop();
			}
		}
	}
	for(auto i:result){
		cout<<i<<endl; 
	}
	return 0;
}
