#include<bits/stdc++.h>
using namespace std;

void Read(vector<int>& A,string s){
	for(int i=s.size()-1;i>=0;i--)
		A.push_back(s[i]-'0');
}

vector<int> Add(vector<int>& A,vector<int>& B){
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size() || i<B.size() || t;i++){
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		C.push_back(t%10);
		t/=10;
	}return C;
}

void Write(vector<int>& A){
	for(int i=A.size()-1;i>=0;i--)
		cout<<A[i];
	cout<<'\n';
}//由高及低位输出 

void FibonacciIteration(vector<int>& Fi,vector<int>& Fj,int n){//n-2 times iteration to Fn 
	for(int i=0;i<n-2;i++){
		vector<int> T=Fj;
		Fj=Add(Fi,Fj);
		Fi=T;
	}
}

int main(){
	vector<int> Fi,Fj;
	Read(Fi,"1");
	Read(Fj,"2");
	int n;cin>>n;
	if(n==1)Write(Fi);
	else if(n==2)Write(Fj);
	else{
		FibonacciIteration(Fi,Fj,n);
		Write(Fj);
	}
	return 0;
}
