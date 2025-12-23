#include<iostream>
#include<cmath>
using namespace std;
//线性筛 
bool isPrime(int x){
	if(x==0 || x==1)return 0;
	if(x==2 || x==3 || x==5 || x==7)return 1;
	if(x%2==0)return 0;
	for(int i=3;i*i<=x;i+=2){
		if(x%i==0)return 0;
	}return 1;
}
int main(){
	int N;
	cin>>N;
	int sum=0;
	//截半分解 
	for(int i=2;i<=N/2;i++){
		if(isPrime(i) && isPrime(N-i))sum++;
	}cout<<sum;
	return 0;
}
