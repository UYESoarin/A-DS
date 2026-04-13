#include<bits/stdc++.h>
using namespace std;
//格式化输入 
int main(){
	int n;cin>>n;
	int arg=1;
	for(int i=n;i>0;i--){
		for(int j=0;j<i;j++){
//			printf("%02d",arg);
			cout<<setw(2)<<setfill('0')<<right<<arg;//<iomanip>
			arg++;
		}cout<<'\n';
	}
	return 0;
}
