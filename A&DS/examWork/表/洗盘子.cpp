#include<iostream>
#include<vector>
#define MAX 50000
//luckyNum <= 3000 ; totalNum < 50000
using namespace std;
int main(){
	vector<int> num;
	for(int i=2;i<MAX;i++)num.push_back(i);
	vector<int> lucky;
	while(!num.empty() && lucky.size()<3000){
		int base=num[0];
		lucky.push_back(base);
		vector<int> newNum;
		//idxCentered
		for(int i=1;i<num.size();i++)
			if(i%base)newNum.push_back(num[i]);
		num=newNum;
	}
	int T,n;
	cin>>T;
	//n :0~n-1 
	while(T-- && cin>>n)cout<<lucky[n-1]<<endl;	
	return 0;
}
