#include<bits/stdc++.h>
using namespace std;
void Read(vector<int>& A){
	string s;cin>>s;
	for(int i=s.size()-1;i>=0;i--)
		A.push_back(s[i]-'0');
}//字符串（前高后低）数值转存数组（前低后高）

vector<int> Add(vector<int>& A,vector<int>& B){
	vector<int> C;
	int t=0;//进位 
	for(int i=0;i<A.size() || i<B.size() || t;i++){
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		C.push_back(t%10);
		t/=10;
	}
	return C;
}//拟加法器

void Write(vector<int>& A){
	for(int i=A.size()-1;i>=0;i--)cout<<A[i];
	cout<<'\n';
}

int main(){
	vector<int> A,B;
	Read(A);
	Read(B);
	vector<int> C=Add(A,B);
	Write(C);
	return 0;
}
