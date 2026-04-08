#include<bits/stdc++.h>
using namespace std;
int count_MOD(int num,int x){
	int sum=0;
	while(num>0){
		if(num%10==x)sum++;
		num/=10;
	}return sum;
}//O(log10N)
int count_STRING(int num,int x){
	//<algorithm>
	string str=to_string(num);
	int len=str.size(),sum=0;
	char target=x+'0';
	for(int pos=0;pos<len;pos++)if(str[pos]==target)sum++;
	return sum;
} 
int count_CODE(int num,int x){
	int sum=0;
	if(num>=1000000 && num/1000000==x)sum++;
	if(num>=100000 && num/100000%10==x)sum++;
	if(num>=10000 && num/10000%10==x)sum++;
	if(num>=1000 && num/1000%10==x)sum++;
	if(num>=100 && num/100%10==x)sum++;
	if(num>=10 && num/10%10==x)sum++;
	if(num%10==x)sum++;
	return sum;
}//O(7N)
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x,sum=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)sum+=count_CODE(i,x);
	cout<<sum;
	return 0;
}
