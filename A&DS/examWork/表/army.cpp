#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	int N,M;
	cin>>N>>M;
	vector<list<int>> army(N+1);
	
	for(int i=1;i<=N;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			army[i].push_back(x);
		}
	}
	
	while(M--){
		char op;
		cin>>op;
		
		if(op=='U'){
			int a,b;
			cin>>a>>b;
			//connectTail
			army[a].splice(army[a].end(),army[b]);
			army[b].clear();
		}else if(op=='I'){
			int a,x;
			cin>>a>>x;
			//insertHead
			army[a].push_front(x);
		}else if(op=='D'){
			int a,x;
			cin>>a>>x;
			//delete allValue x
			army[a].remove(x);
		}else if(op=='Q'){
			int a;
			cin>>a;
			if(army[a].empty())cout<<-1<<endl;
			else{
				bool first=true;
				for(int val:army[a]){
					if(!first)cout<<" ";
					first=false;
					cout<<val;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
