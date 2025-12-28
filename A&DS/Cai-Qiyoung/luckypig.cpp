#include<bits/stdc++.h>

using namespace std;

int main(){
	int ans[3001];
	vector<int> pig(50000,0);
	int luck = 2 ;
	for(int i = 1 ; i <= 3000 ; i++ ){
		int flag = 1;
		int count = 0;
		for(int j = 2 ; j < 50000 ; j++){
			if(flag){
				if(pig[j]) continue;
				flag = 0;
				ans[i] = j;
				pig[j] = 1;
				luck = j;
			} else {
				if(pig[j]) continue;
				count++;
				if(count % luck == 0) pig[j] = 1; 
			}
		}
	}
	
	int n; cin >> n;
	for(int i = 0 ; i < n ;i++){
		int q; cin>>q;
		cout<<ans[q]<<'\n';
	}
	return 0;
} 
