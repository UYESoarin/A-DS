#include<bits/stdc++.h>

using namespace std;

bool issu(int x){
	for(int i = 2 ; i <= sqrt(x) ; i++){
		if(x % i == 0) return 0;
	}
	return 1;
} 


int main(){
	int x ;  cin >> x;
	int count = 0;
	for(int i = 2 ; i <= x/2 ; i++){
		if(issu(i) && issu(x-i)) count++;
	}
	cout << count;
	return 0;
}
