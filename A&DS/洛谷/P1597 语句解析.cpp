#include<bits/stdc++.h>
using namespace std;
//格式化输入 
int main(){
	map<char,int> mp;
	mp['a']=mp['b']=mp['c']=0;
	char nam,val;
	while(scanf("%c:=%c;",&nam,&val)==2)
		mp[nam]=isalpha(val)?mp[val]:val-'0';
	printf("%d %d %d",mp['a'],mp['b'],mp['c']);
	return 0;
}
