#include<bits/stdc++.h>
using namespace std;
//试除法
//合数必有不大于其开根因子且对称 
bool isPrime_TryDiv(int x){
	if(x<=1)return false;
	if(x==2||x==3||x==5||x==7)return true;
	if(x%2==0)return false; 
	for(int i=3;i*i<=x;i+=2)if(x%i==0)return false;
	return true;
}

//6k-1 6k+1优化试除法
//大于3整数表示采取：6k, 6k+1, 6k+2, 6k+3, 6k+4, 6k+5（上轮映射6k-1）
//模2模3合数：筛去6k, 6k+2, 6k+3, 6k+4	可能质数:6k-1, 6k+1
bool isPrime_OptTryDiv(int x){
	if(x<=3)return x>1;//<=3
	if(x%2==0 || x%3==0)return false;//>3 mod 2 or 3
	for(int i=5;i*i<=x;i+=6)
		if(x%i==0 || x%(i+2)==0)return false;//6k-1 6k+1
	return true;
}

//预处理小质数表试除法 
//算术基本定理：任何大于1自然数可唯一分解为质数积（素数基底） 
//2 3 ... (6k-1 6k+1) ... 10^6
vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,53,59,61,};
bool isPrime_ListTryDiv(int x){
	for(int p:primes){
		if(p*p>x)break;
		if(x%p==0)return false;
	}return true;
}

//埃式筛
//[2,n]质数性生成：质数倍数标记为合数 ，批量查询 
bool isPrime_Eratosthenes(int n,int x){
	vector<bool> isPrime(n+1,true);
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(isPrime[i]){//质数 
			for(int j=i*i;j<=n;j+=i)isPrime[j]=false;//合数 
		}
	}return isPrime[x];
}

//欧拉筛
bool isPrime_Euler(int n,int x){
	vector<int> primes;
	vector<bool> isPrime(n+1,true);
	for(int i=2;i<=n;i++){
		if(isPrime[i])primes.push_back(i);
		for(int p:primes){
			if(i*p>n)break;
			isPrime[i*p]=false;
			if(i*p==0)break;
		}
	}return isPrime[x];
} 

int main(){
	int n,x;cin>>n>>x;
	cout<<isPrime_Eratosthenes(n,x);s
	return 0;
} 
